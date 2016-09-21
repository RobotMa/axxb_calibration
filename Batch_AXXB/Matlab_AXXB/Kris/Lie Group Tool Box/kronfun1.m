function f = kronfun1(x,K,D)



n = length(x);

X = reshape(x,sqrt(n),sqrt(n));
% 
% K = eye(size(X))*3;
% D = eye(size(X))*2;

f = X'*K + K*X - D;