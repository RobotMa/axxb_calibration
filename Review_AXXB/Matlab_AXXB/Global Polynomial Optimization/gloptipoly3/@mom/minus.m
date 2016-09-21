function z = minus(x,y)
% @MOM/MINUS - Subtract moments
%
% MINUS(X,Y) or X-Y substracts Y from X.
% X and Y must have the same dimensions unless one is a scalar.

% D. Henrion, November 30, 2003
% Last modified 15 March 2006
  
z = plus(x,uminus(y));
  
