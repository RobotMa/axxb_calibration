function [x,maxerr] = mext(mm,nvar,degm)
% MEXT - Extract the discrete support of a measure from its moment matrix
%
% With the calling syntax
%
%    X = MEXT(M,N,D)
%
% where M is the moment matrix (class DOUBLE), N the number of variables
% and D the degree (necessarily even) the function returns the support points
% in cell array X (empty if the extraction algorithm fails).
%
% See also @MEAS/MEXT
  
% Internally function MEXT builds a fake measure via MMM.M
% and then calls @MEAS/MEXT
  
% D. Henrion, 4 August 2004
% Last modified on 12 May 2006
  
global MMM

if nargin < 3
 error('Invalid calling syntax')
end

if (degm < 0) | rem(degm,2)
 error('Degree must be even and positive')
end
ord = degm/2;

% Create fake measure
m = max(MMM.indmeas)+1;

% Already existing indexing tables ?
create = true;
if isfield(MMM,'T')
 [v,o] = size(MMM.T);
 if (v >= nvar) & (o >= ord)
  create = ~empty(MMM.T(v,o));
 end
end

% Generate indexing tables
if create
 [bin,pow,bas] = genind(nvar,degm);
else
 bin = MMM.T(nvar,ord).bin;
 pow = MMM.T(nvar,ord).pow;
 bas = MMM.T(nvar,ord).bas;
end

% Size of moment matrix
dmm = bin(nvar,2+degm/2);
if size(mm) ~= [dmm dmm]
 disp(['Moment matrix should have dimension ' int2str(dmm)]);
 error('Incompatible input arguments')
end

% Extract mass
if mm(1,1) < eps
 error('Nonpositive mass');
end
mmass = mm(1,1);

% Normalize
% mm = mm/mmass;

% Extract Cholesky factor of moment matrix
[U,S] = svd(mm);
S = diag(S); r = length(S);
drop = find(S(2:r) ./ S(1:r-1) < ranktol);
if ~isempty(drop)
 rankM = drop(1);
else
 rankM = r;
end
U = U(:,1:rankM)*diag(sqrt(S(1:rankM)));
nb = rankM;

% Apply @MEAS/MEXT
% on the fake measure

MMM.M{m}.nvar = nvar;
MMM.M{m}.U = U;
MMM.M{m}.mass = mmass;

measx = mext(meas(m));

% Output arguments

x = MMM.M{m}.sol;
maxerr = MMM.M{m}.maxerr;

% Remove fake measure

MMM.M = {MMM.M{1:m-1}};

