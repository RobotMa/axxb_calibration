function z = eq(x,y)
% @MPOL/EQ - Equal
%
% Given polynomials X and Y, EQ(X,Y) returns
% the corresponding measure support equality X == Y
% which is an object of type SUPCON

% D. Henrion, December 4, 2003
% Last modified on 15 March 2006

z = supcon(x,y,'eq');
