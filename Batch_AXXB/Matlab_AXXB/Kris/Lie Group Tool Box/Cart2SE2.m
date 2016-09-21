function [G] = Cart2SE2(x)

x1 = x(1,:);
x2 = x(2,:);
theta = x(3,:);

n = size(x1,2);
G = zeros(3,3,n);

G(1,1,:) = cos(theta);
G(1,2,:) = -sin(theta);
G(2,1,:) = sin(theta);
G(2,2,:) = cos(theta);
G(3,3,:) = ones(size(x1));
G(1,3,:) = x1;
G(2,3,:) = x2;