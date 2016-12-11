function m = scale(x,y)
% @MPOL/SCALE - Scale variables in a measure
%
% Given a vector X of isolated first degree monomials
% and a vector Y of positive real numbers of the same dimension,
% the instruction M = SCALE(X,Y) indicates that variable X(i)
% will be replaced with Y(i)*X(i) when defining a moment SDP problem
% with function MDEF.
%
% Scaling is useful to improve the numerical behavior of the SDP solver
% invoked with MSOL. If possible, it is recommended that all variables
% are scaled within the interval [-1,1].

% D. Henrion, 2 May 2006
% Last modified on 30 October 2009
  
global MMM

mx = indmeas(x);
if mx(1) == 0
 error('Invalid constant polynomial')
end
if length(mx) > 1
 error('Invalid polynomial associated with several measures')
end

[nr,nc] = size(x);
if isa(y,'double')
 if (max(size(y)) == 1) & (min(size(x)) == 1)
  y = repmat(y,size(x,1),size(x,2));
 end
 if ~all(size(x)==size(y))
  error('Input arguments must share the same dimensions')
 end
 if ~all(y > 0)
  error('Entries in second input argument must be positive')
 end
else
 error('Invalid second input argument')
end

% Set up measure
m = set(meas(mx));

% Default scaling = ones
nvar = MMM.M{mx}.nvar;
MMM.M{mx}.scale = ones(nvar,1);

% Alter default scaling
relvar = MMM.M{mx}.relvar;
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
  ind = relvar(indvar(x(r,c))); % call @MPOL/INDVAR
  MMM.M{mx}.scale(ind) = y(r,c);
 end
end

   
  
  
