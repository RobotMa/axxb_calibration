function [ev,Sigma_n,fval] = SolveMatchingEquationSE3(b,K)
b = stack(b);
Kinv = inv2(K);

%Initial Conditions
ev0 = -Kinv*b;
Sigma0 = Kinv;

a = 0; %arbitrary
x0 = zeros(12,1);
s0 = reshape(Sigma0,9,1); %9 elements in SE(2) Covariance matrix
x0(1:3) = ev0;
x0(4:12) = s0;

% 
% options=optimset('Display','iter','MaxFunEvals',200000);
[x,fval] = lsqnonlin(@(x) matchfunSE2(x,a,b,K),x0);



ev = x(1:3);
sigma_n = x(4:12);
Sigma_n = reshape(sigma_n,3,3);
