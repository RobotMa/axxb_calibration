function [cost]=L2cost(s, phi, SigX, R_nanb, MeanA, SigA, thetaa, na, va, MeanB, SigB, thetab, nb, vb)


R_nbphi=eye(3)+sin(phi)*so3_vec(nb)+(1-cos(phi))*so3_vec(nb)*so3_vec(nb);

Rx_solved=R_nanb*R_nbphi;

z=(Rx_solved*vb-va)/thetab;

ma=1/sqrt(na(1,1)^2+na(2,1)^2)*[-na(2,1); na(1,1); 0];

b=dot(z, ma);
a=-dot(z, cross(ma, na));

q=a*ma+b*cross(ma,na);

tx_solved=s*na+q;

X_solved=[Rx_solved tx_solved; [0 0 0] 1];


Sig1=SigA;
Sig2=SE3_Ad(X_solved)*(SE3_Ad(MeanB^-1)*SigX*SE3_Ad(MeanB^-1)+SigB+SigX)*SE3_Ad(X_solved)';


K1=-2*sqrt(norm((Sig1^-1+Sig2^-1)^-1))/(sqrt(norm(Sig1))*sqrt(norm(Sig2)));
K2=sqrt(norm(Sig1))/(sqrt(2)*norm(Sig1));
K3=sqrt(norm(Sig2))/(sqrt(2)*norm(Sig2));

cost=(2*pi)^(-3)*K1*K2*K3;


