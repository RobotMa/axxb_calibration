function d = diag(x)
% @MOM/DIAG - Diagonal
%
% If X is a matrix, D = diag(X) returns the vector of its diagonal entries.
% If X is a vector, D = diag(X) returns a square matrix such that diag(D) = X.

% D. Henrion, 27 November 2006

if length(x) > 1
 % Matrix
 d = x(1,1);
 for k = 2:min(size(x))
  d = [d;x(k,k)];
 end
else
 % Vector
 n = length(x);
 d(n,n) = x(n);
 for k = 1:n-1
  d(k,k) = x(k);
 end
end
