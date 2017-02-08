function [SigX]=SigXcalc(SigA, MB, SigB, MX)

% C1=kron(SE3_Ad(MX)*SE3_Ad(MB^-1),SE3_Ad(MX)*SE3_Ad(MB^-1))+kron(SE3_Ad(MX^-1),SE3_Ad(MX^-1));
% c2=vec(SigA)-kron(SE3_Ad(MX),SE3_Ad(MX))*vec(SigB);

C1=kron(SE3_Ad(MB^-1),SE3_Ad(MB^-1))+eye(36);
c2=vec(SE3_Ad(MX^-1)*SigA*SE3_Ad(MX^-1)'-SigB);


sigx=pinv(C1)*c2;

SigX=real(vecsq(sigx));


end