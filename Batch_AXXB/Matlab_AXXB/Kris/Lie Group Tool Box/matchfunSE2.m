function F = matchfunSE2(x,a,b,K)


x = stack(x); %forces x to be a row vector
I = eye(size(K));
e = se2hat(x(1:3)');

ev = vee(e); %maps the lie algebra of SE(2) to a 3x1 vector

s = x(4:12); %Covariance as a row vector

Sigma_n = reshape(s,3,3); %reshape Covariance into a matrix
S = inv2(Sigma_n); %Take inverse of covariance matrix

ad = little_adjoint(e,1); %little adjoint matrix [ad] for SE(2)


F = zeros(12,1); %9 for Sigma0 and 3 more elements for ev0

F(1:3) = (-ev'*S*(I -0.5*ad + (1/12)*ad*ad) - b')';

M = ComputeMMatrixSE2(ev,Sigma_n);

Msym = (M+M')/2; %symmetric version of M

F3 = (I -0.5*ad + (1/12)*ad*ad)'*S*(I -0.5*ad + (1/12)*ad*ad) + Msym - K;

f3  = reshape(F3,9,1);


F(4:end) = f3;

