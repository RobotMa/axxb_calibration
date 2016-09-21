%Symbolic Solver 1
clear

% syms a11 a12 a13 a14 a21 a22 a23 a24 a31 a32 a33 a34 a41 a42 a43 a44 real
% syms x11 x12 x13 x21 x22 x23 x31 x32 x33 real
% syms c11 c12 c21 c22 real
% 
% % A = [a11 a12 a13 ;a21 a22 a23; a31 a32 a33];
% % X = [x11 x12 x13 ;x21 x22 x23; x31 x32 x33];
% % C = [c11 c12 ;c21 c22];
% % 
% % 
% % 
% % A = [a11 a12; a21 a22];
% % X = [x11 x12; x21 x22];
% % O = zeros(2,2);
% % I = eye(2,2);
% % 
% % 
% % Q = kron(I,A) - kron(I,A');
% % c1 = reshape(C,4,1);
% % c2 = reshape(C',4,1);
% % 
% % x = inv(Q)*(c1-c2);
% % 
% % Xnew = reshape(x,2,2)
% 
% A = [a11 a12 a13 a14; a21 a22 a23 a24; a31 a32 a33 a34 ;a41 a42 a43 a44];
% I = eye(4,4);


n = 8;
I = eye(n,n);
A = randn(n,n);

Q = kron(I,A) - kron(I,A');
rank(Q)
det(Q)
