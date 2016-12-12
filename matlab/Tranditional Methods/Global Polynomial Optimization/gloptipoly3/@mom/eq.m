function z = eq(x,y)
% @MOM/EQ - Equal
%
% Given moments X and Y, EQ(X,Y) returns
% the corresponding moment constraint X == Y
% which is an object of type MOMCON

% D. Henrion, December 4, 2003
% Last modified on 15 March 2006

z = momcon(x,y,'eq');
