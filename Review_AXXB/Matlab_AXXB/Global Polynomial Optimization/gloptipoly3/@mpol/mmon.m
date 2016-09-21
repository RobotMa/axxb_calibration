function y = mmon(x,degmin,degmax)
% @MPOL/MMON - Generate monomials
%
% MMON(X,DEG) returns a column vector containing all
% the monomials of degrees up to DEG of the variables in X
%
% MMON(X,DEGMIN,DEGMAX) returns all the monomials of degrees
% between DEGMIN and DEGMAX

% D. Henrion, 10 April 2004
% Last modified on 23 November 2006

if nargin < 2
 error('Missing second input argument')
end
if ~isa(x,'mpol')
 error('Invalid first input argument')
end
if ~isa(degmin,'double')
 error('Invalid second input argument')
end
if nargin == 2
 degmax = degmin;
 degmin = 0;
elseif ~isa(degmax,'double')
 error('Invalid third input argument')
elseif degmax < degmin
 tmp = degmax;
 degmax = degmin;
 degmin = degmax;
end
degmin = floor(max(degmin,0));
degmax = floor(max(degmax,0));

iv = indvar(x);
nvar = length(iv); % number of variables
if nvar == 0
 error('No variables in first input argument')
end

% Generate powers
vpow = [];
for k = degmin:degmax
 vpow = [vpow;genpow(nvar,k)];
end

% Build monomial vector entrywise
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
y = struct('var',var,'pow',pow,'coef',coef);y = reduce(mpol(y));
