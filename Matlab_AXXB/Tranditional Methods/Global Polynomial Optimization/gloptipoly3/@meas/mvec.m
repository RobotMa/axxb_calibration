function y = mvec(m,x)
% @MEAS/MVEC - Moment vector
%
% MVEC(M) returns the vector of moments defined for measure M
%
% If X is an MPOL object, MVEC(M,X) returns the vector of moments
% defined for the marginal of M with respect to variables in X.
%
% See also @MEAS/MMAT

% D. Henrion, 10 April 2004
% Last modified on 26 March 2010
  
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
  if ~isempty(MMM.T(nvar,ord).pow)
   vpow = MMM.T(nvar,ord).pow;
   generate = false;
  end
 end
end

% Generate powers
if generate
 vpow = [];
 for k = 0:ord*2
  vpow = [vpow;genpow(nvar,k)];
 end
end

% Build moment vector entrywise
% by calling constructor @MPOL/MPOL
dm = size(vpow,1);
var = cell(dm,1);
pow = var;
coef = var;
for k = 1:dm
 var{k} = iv;
 pow{k} = vpow(k,:);
 coef{k} = 1;
end
y = struct('var',var,'pow',pow,'coef',coef);
% y = mom(reduce(mpol(y)));
% do not use reduce, unless measure index is removed for masses
y = mom(mpol(y));
