function [X] = skew(x)
%[X] = skew(x)
%maps x to the lie algebra of SO(3)
%
s = size(x,1);
X = zeros(3,3,s);
X(1,2,:) = -x(:,3);
X(2,1,:) = x(:,3);
X(1,3,:) = x(:,2);
X(3,1,:) = -x(:,2);
X(2,3,:) = -x(:,1);
X(3,2,:) = x(:,1);
