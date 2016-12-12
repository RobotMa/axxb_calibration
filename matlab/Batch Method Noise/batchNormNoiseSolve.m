function [X_solved, SigX_solved, COST, MeanA, MeanB, SigA, SigB]=batchNormNoiseSolve(A,B,X_initial, SigX_initial)

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

z=(X_initial(1:3,1:3)*vb-va)/thetab;

ma=1/sqrt(na(1,1)^2+na(2,1)^2)*[-na(2,1); na(1,1); 0];

b=dot(z, ma);
a=-dot(z, cross(ma, na));

q=a*ma+b*cross(ma,na);



% phi=norm(so3_vec(logm(R_nanb'*X_initial(1:3,1:3))/norm(logm(R_nanb'*X_initial(1:3,1:3)))));
phi=pi;
% s=norm(X_initial(1:3,4)-q)/norm(na);
s=1;
SigX_solved=SigX_initial;
% SigX_solved=zeros(6,6);

% X_solved(:,:,1)=X_initial;


delta_phi=0.001;
delta_s=0.001;
delta_SigX=zeros(6,6);
for i=1:6
    delta_SigX(i,i,i)=0.000001;
end

alpha=0.001;
coord=[1 1 1 1 1 1 2 2 2 2 2 3 3 3 3 4 4 4 5 5 6; 1 2 3 4 5 6 2 3 4 5 6 3 4 5 6 4 5 6 5 6 6];

COST(1)=L2cost(s, phi, SigX_solved, R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);


h = waitbar(0,'Computing KL...');

for k=1:2000
    
    waitbar(k/2000);
    
    s1=s(k)+delta_s;
    s2=s(k)-delta_s;
    COST_temps1=KLcost(s1, phi(k), SigX_solved(:,:,k), R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
    COST_temps2=KLcost(s2, phi(k), SigX_solved(:,:,k), R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
    
    if COST_temps1<COST_temps2
        s(k+1)=s1;
    else
        s(k+1)=s2;
    end
    
    
    phi1=phi(k)+delta_phi;
    phi2=phi(k)-delta_phi;
    COST_tempphi1=KLcost(s(k), phi1, SigX_solved(:,:,k), R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
    COST_tempphi2=KLcost(s(k), phi2, SigX_solved(:,:,k), R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
    
    if COST_tempphi1<COST_tempphi2
        phi(k+1)=phi1;
    else
        phi(k+1)=phi2;
    end
    
    
%     for i=1:6
%         
%         SigX1=SigX_solved(:,:,k)+delta_SigX(:,:,i);
%         SigX2=SigX_solved(:,:,k)-delta_SigX(:,:,i);
%         
%         COST_tempsig1=KLcost(s(k), phi(k), SigX1, R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
%         COST_tempsig2=KLcost(s(k), phi(k), SigX2, R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
%         
%         if COST_tempsig1<COST_tempsig2
%              SigX_solved(i,i,k+1)=SigX1(i,i);
%         else
%              SigX_solved(i,i,k+1)=SigX2(i,i);
%         end
%         
%     end

    SigX_solved(:,:,k+1)=SigX_initial;
    
    COST(k+1)=KLcost(s(k+1), phi(k+1), SigX_solved(:,:,k+1), R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
    
    R_nbphi=eye(3)+sin(phi(end))*so3_vec(nb)+(1-cos(phi(end)))*so3_vec(nb)*so3_vec(nb);
    
    Rx_solved=R_nanb*R_nbphi;
    
    z=(Rx_solved*vb-va)/thetab;
    
    ma=1/sqrt(na(1,1)^2+na(2,1)^2)*[-na(2,1); na(1,1); 0];
    
    b=dot(z, ma);
    a=-dot(z, cross(ma, na));
    
    q=a*ma+b*cross(ma,na);
    
    tx_solved=s(end)*na+q;
    
    X_solved(:,:,k)=[Rx_solved tx_solved; [0 0 0] 1];
    
end


close(h);












