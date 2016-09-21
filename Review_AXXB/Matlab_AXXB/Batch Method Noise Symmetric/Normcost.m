function [cost]=Normcost(s, phi, SigX, R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb)


R_nbphi=eye(3)+sin(phi)*so3_vec(nb)+(1-cos(phi))*so3_vec(nb)*so3_vec(nb);

Rx_solved=R_nanb*R_nbphi;

z=(Rx_solved*vb-va)/thetab;

ma=1/sqrt(na(1,1)^2+na(2,1)^2)*[-na(2,1); na(1,1); 0];

b=dot(z, ma);
a=-dot(z, cross(ma, na));

q=a*ma+b*cross(ma,na);

tx_solved=s*na+q;

X_solved=[Rx_solved tx_solved; [0 0 0] 1];


Sig2=SE3_Ad(X_solved)*(SE3_Ad(MeanB^-1)*SigX*SE3_Ad(MeanB^-1)+SigB+SigX)*SE3_Ad(X_solved)';

% cost = norm(MeanA-X_solved*MeanB*X_solved^-1)^2+norm(SigA-Sig2)^2;
% cost = norm(SigA-Sig2)^2;
cost = norm(MeanA-X_solved*MeanB*X_solved^-1);
a=0;
