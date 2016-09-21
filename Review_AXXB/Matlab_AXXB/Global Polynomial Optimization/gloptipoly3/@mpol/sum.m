function s = sum(x)
% @MPOL/SUM - Sum of elements
%
% SUM(X) returns the sum of the elements of vector X

% D. Henrion, November 30, 2003

if min(size(x)) > 1
 error('Vectors only');
else
 s = x(1);
 for i = 2:length(x)
  s = s+x(i);
 end
end
