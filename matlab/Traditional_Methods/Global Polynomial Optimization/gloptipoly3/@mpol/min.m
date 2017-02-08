function z = min(x)
% @MPOL/MIN - Moment expression to be minimized
%
% Given a polynomial X, MIN(X) returns its moments
% to be minimized, an MOMCON object

% D. Henrion, 4 December 2003
% Last modified on 15 March 2006

z = momcon(x,'min');
