function y = prod(x)
% @MPOL/PROD - Product of elements
%
% For vectors, PROD(X) is the product of the elements of X.
% For matrices, PROD(X) is a row vector with the product over each column.
  
% D. Henrion, August 3, 2004

[nr,nc] = size(x);
if min(nr,nc) == 1
 y = x(1);
 for i = 2:max(nr,nc)
  y = y*x(i);
 end
else
 y = x(1,:);
 for j = 1:nc
  for i = 2:nr
   y(j) = y(j)*x(i,j);
  end
 end
end

