function z = mrdivide(x,y)
% @MPOL/MRDIVIDE - Right matrix divide
%
% MRDIVIDE(X,Y) or X/Y is the matrix division of Y into X
% Divisor Y must be a non-singular DOUBLE

% D. Henrion, January 23, 2004

if ~isa(y,'double')
 error('Divisor must be a DOUBLE')
end 
z = x*inv(y);

  
  
  
