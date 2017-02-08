function X = mat(x)
% @MPOL/MAT - Matrix whose columns are stacked within a vector
%
% Given a vector X with N^2 entries, the instruction Y = MAT(X)
% returns an N-by-N matrix such that X = VEC(Y), i.e. such that
% the columns of matrix Y are stacked within vector X.

% D. Henrion, December 31, 2003

n = floor(sqrt(length(x)));
if n^2 ~= length(x)
 error('Invalid dimension of input vector')
end
X = reshape(x,n,n);
