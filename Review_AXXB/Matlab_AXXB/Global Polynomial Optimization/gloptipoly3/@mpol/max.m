function z = max(x)
% @MPOL/MAX - Moment expression to be maximized
%
% Given a polynomial X, MIN(X) returns its moments
% to be maximized, a MOMCON object

% D. Henrion, 4 December 2003
% Last modified on 15 March 2006

z = momcon(x,'max');
