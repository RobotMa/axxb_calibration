function m = assign(x,v)
% @MPOL/ASSIGN - Assign monomial, or equivalently,
% set discrete support of a measure
%
% M = ASSIGN(X,V) indicates that the measure M associated with MPOL object X
% is now supported on the discrete set of points specified in array V
% 
% MPOL object X should refer to only one measure. Moreover, X should
% contain all the first degree monomials in the measure.
%
% See also @MEAS/DOUBLE, @MPOL/DOUBLE

% D. Henrion, 10 April 2006
% Last modified on 23 December 2006

global MMM

mx = indmeas(x);
if mx(1) == 0
 error('Invalid constant polynomial')
end
if length(mx) > 1
 error('Invalid polynomial associated with several measures')
end
if ~isa(v,'double')
 error('Invalid second input argument')
end

% Check dimensions
[nr,nc] = size(x);
nrv = size(v,1); ncv = size(v,2);
if max(nrv,ncv) == 1 % scalar v
 % assigned to all entries in x
 v = repmat(v,nr,nc);
elseif max(nr,nc) == 1 % scalar x
 % vectorize v
 v = reshape(v,1,1,prod(size(v)));
end
nrv = size(v,1); ncv = size(v,2);
if (nrv ~= nr) | (ncv ~= nc)
 if (size(v,3) == 1) & (min(nr,nc) == 1)
  if nc == 1 % column vector x
   if nr == nrv % 2D to 3D v
    v = reshape(v,nrv,1,ncv);
   elseif nr == ncv
    v = reshape(v',ncv,1,nrv);
   end
  else % row vector x
   if nc == ncv % 2D to 3D v
    v = reshape(v,1,ncv,nrv);
   elseif nc == nrv
    v = reshape(v',1,nrv,ncv);
   end
  end
 end
end
nrv = size(v,1); ncv = size(v,2);
if (size(v,1) ~= nr) | (size(v,2) ~= nc)
 error('Inconsistent dimensions')
end

% Set up the measure
m = set(meas(mx));

% Check number of variables
nvar = MMM.M{mx}.nvar;
ivar = length(indvar(x));
if ivar ~= nvar
 error('All the variables in the measure must be assigned')
end

% Assign support points
if isempty(v)
 N = 0;
else
 N = size(v,3);
end
relvar = MMM.M{mx}.relvar;
MMM.M{mx}.sol = zeros(nvar,1,N);
for r = 1:nr
 for c = 1:nc
  xc = coef(x(r,c));
  if (size(xc,1) > 1) | (xc(1) ~= 1)
   error('Invalid polynomial with several monomials')
  end
  xd = pow(x(r,c));
  if sum(xd) ~= 1
   error('Invalid polynomial with constant or nonlinear monomials')
  end
  ind = relvar(indvar(x(r,c)));
  MMM.M{mx}.sol(ind,1,:) = v(r,c,:);
  end
 end
end

  
  
