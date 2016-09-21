function [G] = R3toSE2(v)

n = size(v,2);
G = zeros(3,3,n);
G(1,1,:) = cos(v(3,:));
G(1,2,:) = -sin(v(3,:));
G(2,1,:) = sin(v(3,:));
G(2,2,:) = cos(v(3,:));
G(3,3,:) = ones(1,n);

a = v(3,:);

v1 = v(1,:);
v2 = v(2,:);

t1 = (v2.*(-1+cos(a)) + v1.*sin(a))./a;
t2 = (v1.*(1-cos(a)) + v2.*sin(a))./a;

G(1,3,:) = t1;
G(2,3,:) = t2;