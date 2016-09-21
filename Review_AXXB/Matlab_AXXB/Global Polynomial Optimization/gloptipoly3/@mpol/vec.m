function x = vec(X)
% @MPOL/VEC - Vector of the columns of a matrix
%
% Given an M-by-N matrix Y, the instruction X = VEC(Y)
% returns a vector X with M*N entries such that Y = MAT(X), i.e. such that
% the columns of matrix Y are stacked within vector X.

% D. Henrion, December 31, 2003

[m n] = size(X);
x = reshape(X,m*n,1);
