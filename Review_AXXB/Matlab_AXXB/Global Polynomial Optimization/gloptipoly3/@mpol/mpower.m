function z = mpower(x,y)
% @MPOL/MPOWER - Matrix power
%
% MPOWER(X,Y) or X^Y is the Y-th power of X if Y is a non-negative integer
% and X is a square matrix

% D. Henrion, November 30, 2003.

if nargin < 1
 y = 1;
end

if (max(size(y)) > 1) | (y < 0) | (abs(round(y)-y) > 0)
 error('Exponent must be a nonnegative integer')
end

if size(x,1) ~= size(x,2)
 error('Matrix must be square')
end

if y == 0

 % Zero exponent
 z = mpol(eye(size(x)));

elseif (max(size(x)) == 1) & (size(coef(x),1) == 1)

 % Only one scalar monomial
 z = x;
 z.pow = x.pow*y;
 z.coef = z.coef^y;

else

 % Matrix power computed by repeated squarings
 z = x;
 for i = 2:y
   z = mtimes(z,x);
 end
 
end


    
