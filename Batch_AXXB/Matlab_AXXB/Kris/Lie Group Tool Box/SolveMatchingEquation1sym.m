function [ev,Sigma_n,fval] = SolveMatchingEquation1sym(b,K)

Kinv = inv2(K);

ev0 = -Kinv*b;
Sigma0 = Kinv;

a = 0;
x = zeros(6+21,1);
s0 = SymMat2Vec(Sigma0);
x(1:6) = ev0;
x(7:end) = s0;

x0 = x; clear x

options=optimset('Display','iter');
%[x,fval] = fsolve(@(x) myfun2sym(x,a,b,K),x0,options);
[x,fval] = lsqnonlin(@(x) myfun2sym(x,a,b,K),x0,options);



ev = x(1:6);
sigman = x(7:end);
Sigma_n = Vec2SymMat(sigman);

