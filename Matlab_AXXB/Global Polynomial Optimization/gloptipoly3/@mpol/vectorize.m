function str = vectorize(p)
% @MPOL/VECTORIZE Vectorize polynomial
%
% IF P is a univariate or bivariate polynomial (class MPOL), the instruction
%
%   VECTORIZE(P) 
%
% returns a character string (class CHAR) corresponding to the polynomial
% with variable X or variables X and Y.

% D. Henrion, 6 April 2010

N = length(p);
if N > 1
 error('Scalar polynomials only')
end
n = length(indvar(p));
if n > 2
 error('Univariate or bivariate polynomials only')
end
pp = pow(p); cp = coef(p);
[q,m] = size(pp);
str = '';
for k = 1:q
 str = [str '+(' num2str(cp(k)) ').*x.^(' int2str(pp(k,1)) ')'];
 if m > 1
  str = [str '.*y.^(' int2str(pp(k,2)) ')'];
 end
end 


 




