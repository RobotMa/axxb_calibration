%TSylv Equation
clear

Perm6b6;
clearvars -except E
A = randn(6,6)*10;
C = randn(6,6)*20;
B = randn(6,6)*3;

c = stack(C);

Q = kron(eye(size(A)),A) + kron(B',eye(size(A)))*E;

x = inv2(Q)*c;
X = reshape(x,6,6);

err = A*X + X'*B - C;
