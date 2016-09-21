function z = min(x)
% @MOM/MIN - Moment expression to be minimized
%
% MIN(X) returns the MONCON object corresponding
% to the minimization of moments X

% D. Henrion, 4 December 2003
% Last modified on 15 March 2006

z = momcon(x,'min');
