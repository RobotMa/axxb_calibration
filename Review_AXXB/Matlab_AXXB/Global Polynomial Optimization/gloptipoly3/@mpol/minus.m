function z = minus(x,y)
% @MPOL/MINUS - Subtract MPOL objects
%
% MINUS(X,Y) or X-Y substracts Y from X.
% X and Y must have the same dimensions unless one is a scalar.

% D. Henrion, November 30, 2003

z = plus(x,uminus(y));
  

