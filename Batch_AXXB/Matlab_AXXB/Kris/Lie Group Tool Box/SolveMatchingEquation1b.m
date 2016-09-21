function [ev,Sigma_n,fval] = SolveMatchingEquation1b(b,K)

Kinv = inv(K);

ev0 = Kinv*b;
Sigma0 = Kinv;

a = 0;
x = zeros(42,1);
s0 = reshape(Sigma0,36,1);
x(1:6) = ev0;
x(7:end) = s0;

x0 = x; clear x

options=optimset('Display','iter')
[x,fval] = fsolve(@(x) myfun2(x,a,b,K),x0,options);


ev = x(1:6);
sigman = x(7:end);
Sigma_n = reshape(sigman,6,6);

