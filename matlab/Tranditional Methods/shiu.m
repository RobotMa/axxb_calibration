function X = shiu(A,B)
% Calculates the least squares solution of
% AX = XB
% From
% Calibration of Wrist-Mounted Robotic Sensors 
% by Solving Homogeneous Transform Equations of the Form AX = XB
% Shiu and Ahmad
%
% Mili Shah
% July 2014

[~,n] = size(A); n = n/4;
AA = zeros(9*(n-1),2*n);
bb = zeros(9*(n-1),1);
%Calculate best rotation R
for i = 1:n
    A1 = logm(A(1:3,4*i-3:4*i-1));
    B1 = logm(B(1:3,4*i-3:4*i-1));
    a1 = [A1(3,2) A1(1,3) A1(2,1)]'; a1 = a1/norm(a1);
    b1 = [B1(3,2) B1(1,3) B1(2,1)]'; b1 = b1/norm(b1);
    v = cross(b1,a1);
    w = atan2(norm(v),b1'*a1);
    v = v/norm(v);
    XP = (eye(3)*cos(w) + sin(w)*skew(v) + (1-cos(w))*(v)*v');
    [Ai,bi] = shiuMatrix(a1,XP);
    if i == 1
        AA(:,1:2) = repmat(-Ai,n-1,1);
        bb(:,1) = repmat(-bi,n-1,1);
    else
        AA(9*(i-2)+1:9*(i-1),2*i-1:2*i) = Ai;
        bb(9*(i-2)+1:9*(i-1),1) = bb(9*(i-2)+1:9*(i-1),1) + bi;
    end
end
beta = AA\bb;
theta = atan2(beta(2*n),beta(2*n-1));
RA = (eye(3)*cos(theta) + sin(theta)*skew(a1) + (1-cos(theta))*(a1)*a1');
R = RA*XP;
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

function [A,b] = shiuMatrix(ka1,X)
A = zeros(9,2);
b = zeros(9,1);


A(1,1) = X(1,1)-ka1(1)*X(:,1)'*ka1;
A(2,1) = X(1,2)-ka1(1)*X(:,2)'*ka1;
A(3,1) = X(1,3)-ka1(1)*X(:,3)'*ka1;

A(4,1) = X(2,1)-ka1(2)*X(:,1)'*ka1;
A(5,1) = X(2,2)-ka1(2)*X(:,2)'*ka1;
A(6,1) = X(2,3)-ka1(2)*X(:,3)'*ka1;

A(7,1) = X(3,1)-ka1(3)*X(:,1)'*ka1;
A(8,1) = X(3,2)-ka1(3)*X(:,2)'*ka1;
A(9,1) = X(3,3)-ka1(3)*X(:,3)'*ka1;

n = cross(X(:,1),ka1);
o = cross(X(:,2),ka1);
a = cross(X(:,3),ka1);

A(1,2) = -n(1);
A(2,2) = -o(1);
A(3,2) = -a(1);

A(4,2) = -n(2);
A(5,2) = -o(2);
A(6,2) = -a(2);

A(7,2) = -n(3);
A(8,2) = -o(3);
A(9,2) = -a(3);

n = X(:,1);
o = X(:,2);
a = X(:,3);

b(1) = -ka1(1)*n'*ka1;
b(2) = -ka1(1)*o'*ka1;
b(3) = -ka1(1)*a'*ka1;

b(4) = -ka1(2)*n'*ka1;
b(5) = -ka1(2)*o'*ka1;
b(6) = -ka1(2)*a'*ka1;

b(7) = -ka1(3)*n'*ka1;
b(8) = -ka1(3)*o'*ka1;
b(9) = -ka1(3)*a'*ka1;
end