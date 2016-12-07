function X = horaud(A,B)
% Calculates the least squares solution of
% AX = XB
% 
% Hand-Eye Calibration 
% R. Horaud and F. Dornaika
%
% Mili Shah
% July 2014
%
% Uses q2rot.m

[~,n] = size(A); n = n/4;
AA = zeros(4,4);
%Calculate best rotation R
for i = 1:n
    A1 = logm(A(1:3,4*i-3:4*i-1)); 
    B1 = logm(B(1:3,4*i-3:4*i-1));
    a = [A1(3,2) A1(1,3) A1(2,1)]'; a = a/norm(a);
    b = [B1(3,2) B1(1,3) B1(2,1)]'; b = b/norm(b);
    AA = AA + ...
        [0 -a(1)+b(1) -a(2)+b(2) -a(3)+b(3);...
        a(1)-b(1) 0 -a(3)-b(3) a(2)+b(2);...
        a(2)-b(2) a(3)+b(3) 0 -a(1)-b(1);...
        a(3)-b(3) -a(2)-b(2) a(1)+b(1) 0]'*...
        [0 -a(1)+b(1) -a(2)+b(2) -a(3)+b(3);...
        a(1)-b(1) 0 -a(3)-b(3) a(2)+b(2);...
        a(2)-b(2) a(3)+b(3) 0 -a(1)-b(1);...
        a(3)-b(3) -a(2)-b(2) a(1)+b(1) 0];
end

[u,~] = eig(AA);
R = q2rot([u(2:4,1); u(1,1)]);
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
function R = q2rot(q)

% Converting a quaternion q to 
% Rotation R from
%
% http://www.theworld.com/%7Esweetser/quaternions/ps/stanfordaiwp79-salamin.pdf
%
% APPLICATION OF QUATERNIONS TO COMPUTATION WITH ROTATIONS
% Working Paper, Stanford AI Lab, 19791
% by Eugene Salamin
%
% Mili Shah
% Aug 25, 2011

R = zeros(3,3);

R(1,1) = q(4)^2+q(1)^2-q(2)^2-q(3)^2;
R(2,2) = q(4)^2-q(1)^2+q(2)^2-q(3)^2;
R(3,3) = q(4)^2-q(1)^2-q(2)^2+q(3)^2;

R(1,2) = 2*(-q(4)*q(3)+q(1)*q(2));
R(2,1) = 2*(q(4)*q(3)+q(1)*q(2));

R(1,3) = 2*(q(4)*q(2)+q(1)*q(3));
R(3,1) = 2*(-q(4)*q(2)+q(1)*q(3));

R(2,3) = 2*(-q(4)*q(1)+q(2)*q(3));
R(3,2) = 2*(q(4)*q(1)+q(2)*q(3));
end