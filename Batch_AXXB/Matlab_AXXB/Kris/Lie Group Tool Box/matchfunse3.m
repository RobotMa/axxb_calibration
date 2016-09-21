function F = matchfunse3(x,a,b,K)

x = stack(x); %forces x to be a row vector
I = eye(size(K));
e = hat2(x(1:6)');

ev = vee(e); %maps the lie algebra of SE(3) to a 6x1 vector

s = x(7:end); %Covariance as a row vector

Sigma_n = reshape(s,6,6); %reshape Covariance into a matrix
S = inv2(Sigma_n); %Take inverse of covariance matrix

ad = little_adjoint(e,2); %little adjoint matrix [ad] for SE(3)


F = zeros(42,1); %36 for Sigma0 and 6 more for ev0

F(1:6) = (-ev'*S*(I -0.5*ad + (1/12)*ad*ad) - b')';

M = ComputeMMatrix2(ev,Sigma_n);


Msym = (M+M')/2; %symmetric version of M

F3 = (I -0.5*ad + (1/12)*ad*ad)'*S*(I -0.5*ad + (1/12)*ad*ad) + Msym - K;

f3  = reshape(F3,36,1);


F(7:end) = f3;

