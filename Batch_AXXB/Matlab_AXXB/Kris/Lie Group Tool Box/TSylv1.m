function F = TSylv1(x,K,D)

d = reshape(D,36,1);

X = reshape(x,6,6);

F0 = X'*K + K*X - D;

F = reshape(F0,36,1);