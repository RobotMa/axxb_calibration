function [X_solved, SigX_solved, COST, MeanA, MeanB, SigA, SigB]=batchL2NoiseSolve(A,B,X_initial, SigX_initial)

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
phi=pi/2;
% s=norm(X_initial(1:3,4)-q)/norm(na);
s=1;
% SigX_solved=SigX_initial;
SigX_solved=zeros(6,6);

% X_solved(:,:,1)=X_initial;


delta_phi=0.01;
delta_s=0.001;
delta=zeros(6,6,21);
alpha=0.01;
coord=[1 1 1 1 1 1 2 2 2 2 2 3 3 3 3 4 4 4 5 5 6; 1 2 3 4 5 6 2 3 4 5 6 3 4 5 6 4 5 6 5 6 6];

COST(1)=L2cost(s, phi, SigX_solved, R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);



for i=1:21
    
    delta_SigX(coord(1,i),coord(2,i),i)=0.00001;
    
end

h = waitbar(0,'Computing KL...');

for k=1:2000
    
    waitbar(k/2000);
    
    s1=s(k)+delta_s;
    COST_temps=L2cost(s1, phi(k), SigX_solved(:,:,k), R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
    s(k+1)=s(k)-alpha*(COST_temps-COST(k));
    
    
    
    phi1=phi(k)+delta_phi;
    COST_tempphi=L2cost(s(k), phi1, SigX_solved(:,:,k), R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
    phi(k+1)=phi(k)-alpha*(COST_tempphi-COST(k));    
    
    
    for i=1:21
        
        SigX1=SigX_solved(:,:,k)+delta_SigX(:,:,i);
        SigX1=triu(SigX1) + triu(SigX1,1)';        
        
        COST_tempsig=L2cost(s(k), phi(k), SigX1, R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
        
        SigX_solved(coord(1,i),coord(2,i),k+1)=SigX1(coord(1,i),coord(2,i))-alpha*(COST_tempsig-COST(k));
        SigX_solved(coord(2,i),coord(1,i),k+1)=SigX1(coord(2,i),coord(1,i))-alpha*(COST_tempsig-COST(k));
        
    end
    
    COST(k+1)=L2cost(s(k+1), phi(k+1), SigX_solved(:,:,k+1), R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb);
    
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












