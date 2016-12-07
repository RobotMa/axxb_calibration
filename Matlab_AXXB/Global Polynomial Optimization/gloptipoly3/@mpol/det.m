function y = det(x)
% @MPOL/DET - Determinant
%
% DET(X) is the determinant of the square matrix X

% D. Henrion, August 3, 2004

% Evaluate all the minors recursively wrt first row

[nr,nc] = size(x);
if nr ~= nc
 error('Matrix must be square')
end

if nr == 1
 % scalar
 y = x;
else
 % matrix, evaluate recursively wrt first row
 y = mpol(0);
 for r = 1:nr
  y = y + (-1)^(r+1)*x(r,1)*det(x([1:r-1 r+1:nr],2:nc));
 end
end

