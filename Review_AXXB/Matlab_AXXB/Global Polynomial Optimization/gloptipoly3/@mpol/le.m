function z = le(x,y)
% @MPOL/LE - Less than or equal
%
% Given polynomials X and Y, LE(X,Y) returns
% the corresponding measure support inequality X <= Y
% which is an object of type SUPCON

% D. Henrion, December 4, 2003
% Last modified on 15 March 2006

z = supcon(x,y,'le');

