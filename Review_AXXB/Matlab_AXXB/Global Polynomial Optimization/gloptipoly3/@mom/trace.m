function t = trace(x)
% @MOM/TRACE - Sum of diagonal elements
%
% TRACE(X) returns the sum of the diagonal elements of matrix X

% D. Henrion, 27 November 2006

t = x(1,1);
for i = 2:min(size(x))
 t = t+x(i,i);
end
