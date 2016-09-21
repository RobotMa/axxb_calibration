function [y,varargout] = mvg(mu,Sigma,N)
%MVG    Multivariate Gaussian random number generator.
%
%   y = mvg(mu,Sigma,N), where mu is mx1 and Sigma is mxm and SPD, produces 
%   an mxN matrix y whose columns are samples from the multivariate 
%   Gaussian distribution parameterized by mean mu and covariance Sigma.
%
%   [y,R] = mvg(mu,Sigma,N) also returns the Cholesky factor of the
%   covariance matrix Sigma such that Sigma = R'*R.
%
%   See also RAND, RANDN, SPRANDN, SPRANDN, RANDPERM.

%   Chad Lieberman, MIT 2008.
%   Questions/Comments:  celieber@mit.edu
%   $Revision: 1.0.0 $  $Date: 2008/09/01 $
%   $Revision: 1.0.1 $  $Date: 2008/09/03 $

%   References:  
%   [1] I.T. Hernadvolgyi (1998) "Generating random vectors from the 
%       multivariate normal distribution."
%   Available on-line at http://www.csi.uottawa.ca/~istvan/work.html.
%
%   Acknowledgements:  
%       I would like to acknowledge John D'Errico for his helpful comments 
%       and suggestions.

if nargin<3
  error('MVG must be called with three arguments.');
elseif nargin>4
  error('MVG called with too many arguments.');
end
if length(mu)~=size(Sigma,1)
  error('Length(mu) must equal size(Sigma,1).');
end
if size(Sigma,1)~=size(Sigma,2)
  error('Sigma must be square.'); 
end
if norm(Sigma-Sigma')>1e-15
  error('Sigma must be symmetric.');
end
try
  R = chol(Sigma);
catch
  error('Sigma must be positive definite.');
end
if (N<1 || mod(N,1)~=0)
  error('A positive integer number of samples must be requested.');
end
m = length(mu);
y = R'*randn(m,N) + repmat(mu,1,N);
if nargout>1
  varargout{1} = R;
end

