function [g] = Cart2Group(cc)
n = length(cc);
g = zeros(4,4,n);
g(1,4,:) = cc(1,:);
g(2,4,:) = cc(2,:);
g(3,4,:) = cc(3,:);

a = cc(4,:);
b = cc(5,:);
g1 = cc(6,:);

Rx = zeros(3,3,n);
Rx(1,1,:) = 1;
Rx(1,2,:) = 0;
Rx(1,3,:) = 0;
Rx(2,1,:) = 0;
Rx(2,2,:) = cos(a);
Rx(2,3,:) = -sin(a);
Rx(3,1,:) = 0;
Rx(3,2,:) = sin(a);
Rx(3,3,:) = cos(a);

Ry = zeros(3,3,n);
Ry(1,1,:) = cos(b);
Ry(1,2,:) = 0;
Ry(1,3,:) = sin(b);
Ry(2,1,:) = 0;
Ry(2,2,:) = 1;
Ry(2,3,:) = 0;
Ry(3,1,:) = -sin(b);
Ry(3,2,:) = 0;
Ry(3,3,:) = cos(b);

Rz = zeros(3,3,n);
Rz(1,1,:) = cos(g1);
Rz(1,2,:) = -sin(g1);
Rz(1,3,:) = 0;
Rz(2,1,:) = sin(g1);
Rz(2,2,:) = cos(g1);
Rz(2,3,:) = 0;
Rz(3,1,:) = 0;
Rz(3,2,:) = 0;
Rz(3,3,:) = 1;

Rzy = RotationMult3D(Rz,Ry);
R = RotationMult3D(Rzy,Rx);


g(1:3,1:3,:) = R;
g(4,4,:) = 1;

% Rx = [1 0 0; 0 cos(a) -sin(a); 0 sin(a) cos(a)];
% Ry = [cos(b) 0 sin(b); 0 1 0; -sin(b) 0 cos(b)];
% Rz = [cos(g1) -sin(g1) 0; sin(g1) cos(g1) 0; 0 0 1];

