function [X_new, MeanA, MeanB, SigA, SigB]=batchKLSolve(A,B,X)

[MeanA, SigA]=distibutionProps(A);
[MeanB, SigB]=distibutionProps(B);
SigAinv=SigA^-1;
SigBinv=SigB^-1;


meanA=se3_vec(logm(MeanA));
thetaa=norm(meanA(1:3,1));
na=meanA(1:3,1)/thetaa;
va=meanA(4:6,1);

meanB=se3_vec(logm(MeanB));
thetab=norm(meanB(1:3,1));
nb=meanB(1:3,1)/thetab;
vb=meanB(4:6,1);

R_nanb=eye(3)+so3_vec(cross(nb, na))+(1-dot(nb,na))/norm(cross(nb,na))^2*so3_vec(cross(nb, na))^2;

ang=norm(so3_vec(logm(R_nanb'*X(1:3,1:3))));
so3_vec(logm(R_nanb'*X(1:3,1:3)))/norm(so3_vec(logm(R_nanb'*X(1:3,1:3))));
nb;

R_nbphi=eye(3)+sin(ang)*so3_vec(nb)+(1-cos(ang))*so3_vec(nb)*so3_vec(nb);
Rx=R_nanb*R_nbphi;
X(1:3,1:3);


% nb1=so3_vec(logm(R_nanb'*X(1:3,1:3))/norm(logm(R_nanb'*X(1:3,1:3))))
% nb
%
% va
% va2=thetab*so3_vec(X(1:3,4))*X(1:3,1:3)*nb+X(1:3,1:3)*vb
%
%
% Sigcheck=norm(SigA-SE3_Ad(X)*SigB*SE3_Ad(X)')
%
%
% Costf1=se3_vec(logm(MeanA))
% costf2=SE3_Ad(X)*se3_vec(logm(MeanB))
%
% costf=norm(se3_vec(logm(MeanA))-SE3_Ad(X)*se3_vec(logm(MeanB)))
% AXXB=norm(MeanA*X-X*MeanB)

phimin=0;
phimax=2*pi;
phistep=(phimax-phimin)/(3600*2);
C2_min=inf;
ind=0;

% smax=1;
% smin=-1;
% sstep=(smax-smin)/500;

% for s=smin:sstep:smax
%     waitbar((s-smin)/(smax-smin))
    
    for phi=phimin:phistep:phimax
        
        ind=ind+1;
        
        R_nbphi=eye(3)+sin(phi)*so3_vec(nb)+(1-cos(phi))*so3_vec(nb)*so3_vec(nb);
        
        Rx_solved(1:3,1:3,ind)=R_nanb*R_nbphi;
        
        %Rx_solved(:,:,ind)=X(1:3,1:3);
        
        z=(Rx_solved(:,:,ind)*vb-va)/thetab;
        
        ma=1/sqrt(na(1,1)^2+na(2,1)^2)*[-na(2,1); na(1,1); 0];
 
         b=dot(z, ma);
         a=-dot(z, cross(ma, na));
         
         
         M1=Rx_solved(:,:,ind)*SigB(1:3,1:3)*Rx_solved(:,:,ind)'*SigAinv(1:3,4:6);
         M2=SigAinv(4:6,1:3)*Rx_solved(:,:,ind)*SigB(1:3,1:3)*Rx_solved(:,:,ind)';
         M3=Rx_solved(:,:,ind)*SigB(1:3,4:6)*Rx_solved(:,:,ind)'*SigAinv(4:6,4:6);
         M4=SigAinv(4:6,4:6)*Rx_solved(:,:,ind)*SigB(4:6,1:3)*Rx_solved(:,:,ind)';
         M5=SigAinv(4:6,4:6);
         M6=Rx_solved(:,:,ind)*SigB(1:3,1:3)*Rx_solved(:,:,ind)';
         
        q=a*ma+b*cross(ma,na);
        s=trace(so3_vec(na)*(M1-M2+M3-M4)-so3_vec(q)*M5*so3_vec(na)*M6-so3_vec(na)*M5*so3_vec(q)*M6)/(2*trace(so3_vec(na)*M5*so3_vec(na)*M6));
        
%         s= norm(X(1:3,4)-q)/norm(na);
        
        tx_solved(:,ind)=s*na+q;
        
%         tx_solved(:,ind)=[s;(z(3)+s*na(2))/na(1);(z(2)-s*na(3))/-na(1)];


%         tx_solved(:,ind)=pinv(so3_vec(-Rx_solved(:,:,ind)*nb))*((va-Rx_solved(:,:,ind)*vb)/thetab);
        
        
        X_solved(1:4,1:4,ind)=[Rx_solved(:,:,ind) tx_solved(:,ind); [0 0 0] 1];
        
%         C2(ind)=tranerror(X_solved(:,:,ind),X);
%         C2(ind)=roterror(X_solved(:,:,ind),X);
        C2(ind)=trace(SigAinv*SE3_Ad(X_solved(:,:,ind))*SigB*SE3_Ad(X_solved(:,:,ind))');
        
    end
    
    
    
% end

[~,ind]=min(C2);
X_new=X_solved(:,:,ind);

