function z = mldivide(y,x)
% @MPOL/MLDIVIDE - Left matrix divide
%
% MLDIVIDE(Y,X) or Y\X is the matrix division of Y into X
% Divisor Y must be a non-singular DOUBLE

% D. Henrion, January 23, 2004

if ~isa(y,'double')
 error('Divisor must be a DOUBLE')
end 
z = inv(y)*x;

  
  
  
