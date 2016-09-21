function C=L2calc(SigA, MB, SigB, X_solved, SigX)


Sig1=SigA;

Sig2=SE3_Ad(X_solved)*(SE3_Ad(MB^-1)*SigX*SE3_Ad(MB^-1)'+SigB+SigX)*SE3_Ad(X_solved)';


K1=-2*sqrt(norm((Sig1^-1+Sig2^-1)^-1))/(sqrt(norm(Sig1))*sqrt(norm(Sig2)));
K2=sqrt(norm(Sig1))/(sqrt(2)*norm(Sig1));
K3=sqrt(norm(Sig2))/(sqrt(2)*norm(Sig2));

C=(2*pi)^(-3)*K1*K2*K3;