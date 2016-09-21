function X = park(A,B)
% Calculates the least squares solution of
% AX = XB
% From
% Robot Sensor Calibration: 
% Solving AX=XB on the Euclidean Group
% M. Park
%
% Mili Shah
% July 2014

[~,n] = size(A); n = n/4;
M = zeros(3,3);
a1 = zeros(3,n);
b1 = zeros(3,n);
%Calculate best rotation R
for i = 1:n
    A1 = logm(A(1:3,4*i-3:4*i-1));
    B1 = logm(B(1:3,4*i-3:4*i-1));
    a1(:,i) = [A1(3,2) A1(1,3) A1(2,1)]';
    b1(:,i) = [B1(3,2) B1(1,3) B1(2,1)]';
    M  = M + b1(:,i)*a1(:,i)';
end
[u,v] = eig(M'*M);
v = diag(diag(v).^(-1/2));
R = u*v*u'*M';
%Calculate best translation t
C = zeros(3*n,3);
d = zeros(3*n,1);
I = eye(3);
for i = 1:n
    C(3*i-2:3*i,:) = I - A(1:3,4*i-3:4*i-1);
    d(3*i-2:3*i,:) = A(1:3,4*i)-R*B(1:3,4*i);
end
t = C\d;
%Put everything together to form X
X = [R t;0 0 0 1];
end