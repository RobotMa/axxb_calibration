function C=L2calc(SigA, MB, SigB, X_solved, SigX)


Sig1=SigA;

Sig2=SE3_Ad(X_solved)*(SE3_Ad(MB^-1)*SigX*SE3_Ad(MB^-1)'+SigB+SigX)*SE3_Ad(X_solved)';


K1=-2*det(Sig1^-1+Sig2^-1)^(-1/2)/det(Sig1*Sig2)^(1/2);
K2=det(2*Sig1)^(1/2)/det(Sig1);
K3=det(2*Sig2)^(1/2)/det(Sig2);

C=(2*pi)^(-3)*(K1+K2+K3);