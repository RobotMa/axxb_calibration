function [Kn,bn] = Compute_Kn_and_bn(epsilon,Sigma_n,order)

[M] = ComputeMMatrix2(epsilon,Sigma_n);
if order ~= 2
    M = M*0;
else
end

ade = little_adjoint(hat2(epsilon'),2);
ev = epsilon;

I = eye(6,6);

Msym = (M+M')/2;

Kn = [I - (1/2)*ade + (1/12)*ade*ade]'*inv2(Sigma_n)*[I - (1/2)*ade ...
    + (1/12)*ade*ade] + Msym;
bnt = -ev'*inv2(Sigma_n)*[I - (1/2)*ade + (1/12)*ade*ade];
bn = bnt';