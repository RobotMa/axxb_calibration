function y = pow(x)
% @MPOL/POW - Internal use only

% POW(X) returns a matrix of powers of monomials in scalar polynomial X.
%
% Note that powers corresponding to the zero variable
% are indices of the mass of the measures

% D. Henrion, November 30, 2003

if max(size(x)) > 1
 error('Scalar polynomials only')
end

y = x.pow;

