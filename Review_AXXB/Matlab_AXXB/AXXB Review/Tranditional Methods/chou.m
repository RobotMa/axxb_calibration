 function X = chou(A,B)
% Calculates the least squares solution of
% AX = XB
% From
% Finding the Position and Orientation of a
% Sensor on a Robot Manipulator Using Quaternions.
% Chou and Kamel
%
% Mili Shah
% July 2014
%
% Uses q2rot.m and rot2q.m

[~,n] = size(A); n = n/4;
AA = zeros(4*n,4);
%Calculate best rotation R
for i = 1:n
    A1 = (A(1:3,4*i-3:4*i-1));
    B1 = (B(1:3,4*i-3:4*i-1));
    a = rot2q(A1);
    b = rot2q(B1);
    AA(4*i-3:4*i,:) = ...
        [a(4) -a(1:3)';a(1:3) a(4)*eye(3)+skew(a(1:3))]...
        -...
        [b(4) -b(1:3)';b(1:3) b(4)*eye(3)-skew(b(1:3))];
end
[~,~,v]=svd(AA); v = v(:,4); v = [v(2:4);v(1)];
R = q2rot(v);
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

function q = rot2q(R)

% Converting a rotation matrix R to
% quaternion q from
%
% http://www.theworld.com/%7Esweetser/quaternions/ps/stanfordaiwp79-salamin.pdf
%
% APPLICATION OF QUATERNIONS TO COMPUTATION WITH ROTATIONS
% Working Paper, Stanford AI Lab, 19791
% by Eugene Salamin
%
% Mili Shah
% Aug 25, 2011

q = zeros(4,1);

q(4) = 1/2*sqrt(1+R(1,1)+R(2,2)+R(3,3));
q(1) = 1/2*sqrt(1+R(1,1)-R(2,2)-R(3,3));
q(2) = 1/2*sqrt(1-R(1,1)+R(2,2)-R(3,3));
q(3) = 1/2*sqrt(1-R(1,1)-R(2,2)+R(3,3));

[~, in] = max(q);

if in == 1
    q(2) = 1/4/q(1)*(R(1,2)+R(2,1));
    q(3) = 1/4/q(1)*(R(1,3)+R(3,1));
    q(4) = 1/4/q(1)*(R(3,2)-R(2,3));
end
if in == 2
    q(1) = 1/4/q(2)*(R(1,2)+R(2,1));
    q(3) = 1/4/q(2)*(R(2,3)+R(3,2));
    q(4) = 1/4/q(2)*(R(1,3)-R(3,1));
end
if in == 3
    q(1) = 1/4/q(3)*(R(1,3)+R(3,1));
    q(2) = 1/4/q(3)*(R(2,3)+R(3,2));
    q(4) = 1/4/q(3)*(R(2,1)-R(1,2));
end
if in == 4
    q(1) = 1/4/q(4)*(R(3,2)-R(2,3));
    q(2) = 1/4/q(4)*(R(1,3)-R(3,1));
    q(3) = 1/4/q(4)*(R(2,1)-R(1,2));
end
end

