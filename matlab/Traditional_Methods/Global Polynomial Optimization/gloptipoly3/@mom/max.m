function z = max(x)
% @MOM/MAX - Moment expression to be maximized
%
% MAX(X) returns the MONCON object corresponding
% to the maximization of moments X

% D. Henrion, 4 December 2003
% Last modified on 15 March 2006

z = momcon(x,'max');
