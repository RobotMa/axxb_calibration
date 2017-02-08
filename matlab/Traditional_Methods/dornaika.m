function [X,Y]=dornaika(AA,BB)
% Solves the problem AX=YB
% using the formulation of
%
% Simultaneous robot-world and hand-eye calibration
% F. Dornaika and R. Horaud
%
% Mili Shah
% July 2014

[~,n]=size(AA); n = n/4;

%Building quaternion representation for A and B
C = zeros(4,4);
for i = 1:n
    A = AA(1:3,4*i-3:4*i-1);
    B = BB(1:3,4*i-3:4*i-1);
    
    qa = rot2q(A);
    qb = rot2q(B);
    q0 = qa(4);
    qx = qa(1);
    qy = qa(2);
    qz = qa(3);
    
    QA = [...
        [q0 -qx -qy -qz]; ...
        [qx  q0 -qz  qy]; ...
        [qy  qz  q0 -qx]; ...
        [qz -qy  qx  q0]; ...
        ];
    q0 = qb(4);
    qx = qb(1);
    qy = qb(2);
    qz = qb(3);
    
    WB = [...
        [q0 -qx -qy -qz]; ...
        [qx  q0  qz -qy]; ...
        [qy -qz  q0  qx]; ...
        [qz  qy -qx  q0]; ...
        ];
    
    
    C = C - QA'*WB;
end

[u,s,v]=svd(C); diag(s);
[~,in] = min(n-diag(s));
x = [u(2:4,in);u(1,in)];
y = [v(2:4,in);v(1,in)];

X = q2rot(x);
Y = q2rot(y);

A = zeros(3*n,6);
b = zeros(3*n,1);
for i = 1:n
    A(3*i-2:3*i,:) = [-AA(1:3,4*i-3:4*i-1) eye(3)];
    b(3*i-2:3*i,:) = AA(1:3,4*i) - kron(BB(1:3,4*i)',eye(3))*reshape(Y,9,1);
end
t = A\b;

X = [X t(1:3);[0 0 0 1]];
Y = [Y t(4:6);[0 0 0 1]];
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

