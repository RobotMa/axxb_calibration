function [X] = lu8(AA,BB)
% Solves the problem AX=XB
% using the formulation of
%
% Eight-Space Quaternion Approach 
% for Robotic Hand-eye Calibration.
% Y. Lu, J. C. K. Chou 
%
% Mili Shah
% July 2014

[~,n] = size(AA); n = n/4;

A = zeros(8*n,8);
for i = 1:n
    Ra = AA(1:3,4*i-3:4*i-1);
    Rb = BB(1:3,4*i-3:4*i-1);
    qa = rot2q(Ra); qa = [qa(4); qa(1:3)];
    qb = rot2q(Rb); qb = [qb(4); qb(1:3)];
    ta = [0; AA(1:3,4*i)];
    tb = [0; BB(1:3,4*i)];
    Qc = [qb(1) -qb(2:4)';qb(2:4) qb(1)*eye(3)-skew(qb(2:4))];
    Ql = [qa(1) -qa(2:4)';qa(2:4) qa(1)*eye(3)+skew(qa(2:4))];
    Tc = [tb(1) -tb(2:4)';tb(2:4) tb(1)*eye(3)-skew(tb(2:4))];
    Tl = [ta(1) -ta(2:4)';ta(2:4) ta(1)*eye(3)+skew(ta(2:4))];
    A(8*i-7:8*i-4,:) = [Qc*(Tl-Tc) Ql-Qc];
    A(8*i-3:8*i,1:4) = Ql-Qc;
end
[~,~,v]=svd(A);
v = v(:,8);
nv = norm(v(1:4));
v = v/nv;
R = q2rot(v([2 3 4 1]));
E = [-v(2:4) v(1)*eye(3)+skew(v(2:4))];
t = E*v(5:8);
X = [R t; 0 0 0 1];
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
