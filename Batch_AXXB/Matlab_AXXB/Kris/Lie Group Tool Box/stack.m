function [B] = stack(A)
% [B] = stack(A)
% turns matrices and column vectors into row vectors
m = size(A,1);
n = size(A,2);

B = reshape(A,m*n,1);