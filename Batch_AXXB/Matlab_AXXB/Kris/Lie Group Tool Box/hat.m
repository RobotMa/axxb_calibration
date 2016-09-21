function [X] = hat(x)
%[X] = hat(x)
% this function takes a 3x1 vector x and maps it to the Lie algebra of
% SE(2)

X = zeros(3,3);
X(1,3) = x(1);
X(2,3) = x(2);
X(1,2) = -x(3);
X(2,1) = x(3);