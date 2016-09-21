function y = mmat(m,x)
% @MEAS/MMAT - Moment matrix
%
% MMAT(M) returns the matrix of moments defined for measure X
%
% If X is an MPOL object, MMAT(M,X) returns the moment matrix
% defined for the marginal of M with respect to variables in X.
%
% See also @MEAS/MVEC

% D. Henrion, 10 April 2004
% Last modified on 4 January 2007

global MMM

if length(m) > 1
 error('Specify only one measure')
end
m = m.meas;

marginal = false;
if nargin == 2
 if ~isa(x,'mpol')
  error('Invalid second input argument')
 end
 % subset of variables
 marginal = true;
 im = indmeas(x);
 if (length(im) > 1) | (im ~= m)
  error('Inconsistent measure in second input argument')
 end
 iv = indvar(x);
 nvar = length(iv); % number of variables
else
 % all variables
 iv = (MMM.indmeas == m);  
 nvar = sum(iv);
 iv = find(iv);
end

if nvar == 0
 error('Undefined measure')
end

undefined = false;
if ~isfield(MMM,'M')
 undefined = true;
elseif length(MMM.M) < m
 undefined = true;
elseif ~isfield(MMM.M{m},'ord')
 undefined = true;
end
if undefined
 error('Measure with undefined moments')
end

% Half the degree
ord = MMM.M{m}.ord;

% Are the powers already stored in the MMM.T tables ?
generate = true;
if isfield(MMM,'T')
 if (size(MMM.T,1) >= nvar) & (size(MMM.T,2) >= ord)
  if ~isempty(MMM.T(nvar,ord))
   vpow = MMM.T(nvar,ord).pow;
   mpow = MMM.T(nvar,ord).bas;
   dmm = MMM.T(nvar,ord).bin(nvar,2+ord);
   generate = false;
  end
 end
end

% Generate powers
if generate
 % Generate first column
 vpow = [];
 for k = 0:ord
  vpow = [vpow;genpow(nvar,k)];
 end
 % Generate remaining columns
 % from first row and first column
 dmm = size(vpow,1);
 mpow = zeros(dmm,dmm,nvar);
 vpow = reshape(vpow,dmm,1,nvar);
 for c = 1:dmm
  for k = 1:nvar
   mpow(:,c,k) = vpow(c,1,k)+vpow(:,1,k);
  end
 end
end

% Build moment matrix entrywise
% by calling constructor @MPOL/MPOL
var = cell(dmm,dmm);
pow = var;
coef = var;
for r = 1:dmm
 for c = 1:r
  var{r,c} = iv;
  pow{r,c} = reshape(mpow(r,c,:),1,nvar);
  coef{r,c} = 1;
  if c < r % symmetric
   var{c,r} = var{r,c};
   pow{c,r} = pow{r,c};
   coef{c,r} = coef{r,c};
  end
 end
end
y = struct('var',var,'pow',pow,'coef',coef);
y = mom(mpol(y));

