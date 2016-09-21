function X = tsai(A,B)
% Calculates the least squares solution of
% AX = XB
% 
% A New Technique for Fully Autonomous 
% and Efficient 3D Robotics Hand/Eye Calibration
% Lenz Tsai
%
% Mili Shah
% July 2014

[~,n] = size(A); n = n/4;
S = zeros(3*n,3);
v = zeros(3*n,1);
%Calculate best rotation R
for i = 1:n
    A1 = logm(A(1:3,4*i-3:4*i-1)); 
    B1 = logm(B(1:3,4*i-3:4*i-1));
    a = [A1(3,2) A1(1,3) A1(2,1)]'; a = a/norm(a);
    b = [B1(3,2) B1(1,3) B1(2,1)]'; b = b/norm(b);
    S(3*i-2:3*i,:) = skew(a+b);
    v(3*i-2:3*i,:) = a-b;
end
x = S\v;
theta = 2*atan(norm(x));
x = x/norm(x);
R = (eye(3)*cos(theta) + sin(theta)*skew(x) + (1-cos(theta))*(x)*x')';
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