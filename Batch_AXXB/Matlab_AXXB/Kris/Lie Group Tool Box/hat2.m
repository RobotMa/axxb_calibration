function [X] = hat2(x)
%[X] = hat2(x)
% this function takes a nx6 vector x and maps it to n Lie algebra matrices of
% SE(3)
%

s = size(x,1);
X = zeros(4,4,s);
X(1,4,:) = x(:,4);
X(2,4,:) = x(:,5);
X(3,4,:) = x(:,6);
X(1,2,:) = -x(:,3);
X(2,1,:) = x(:,3);
X(1,3,:) = x(:,2);
X(3,1,:) = -x(:,2);
X(2,3,:) = -x(:,1);
X(3,2,:) = x(:,1);