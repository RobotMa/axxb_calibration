function [bin,pow,bas] = genind(nvar,d)
% GENIND - Internal use only

% [BIN,POW,BAS] = GENIND(N,D) generates indexing tables for
% a moment problems of N variables and degree D:
% - BIN = binomial coef table
% - POW = vector of powers of monomials
% - BAS = powers of moment matrix
%
% Updates/reads index tables MMM.T
% Used by GENMOM, MSDP
% Uses GENPOW
  
% D. Henrion, 4 August 2004
% Last modified on 14 December 2006

global MMM

if nargin < 2
 error('Invalid syntax')
elseif rem(d,2)
 error('Degree must be even');
end

% Order = half the degree
ord = d/2;

% Already existing tables ?
create = true;
if isfield(MMM,'T')
 [maxnvar,maxord] = size(MMM.T);
 if (maxnvar >= nvar) & (maxord >= ord)
  create = isempty(MMM.T(nvar,ord).bin);
 end
end
if create

 % Generate binomial coefficient table
 % used to locate a variable from its powers

 bin = zeros(nvar,d+2);
 bin(1,:) = 0:d+1;
 for k = 2:nvar
  bin(k,:) = cumsum(bin(k-1,:));
 end

 % Generate column vectors of powers, arranged in a matrix

 pow = genpow(nvar+1,d);
 pow = pow(:,2:nvar+1);

 % Generate matrix of powers
 % to construct the moment and localization matrices

 dmm = bin(nvar,ord+2); % dimension of moment matrix
 bas = zeros(dmm,dmm,nvar);
 bas(:,1,:) = pow(1:dmm,:); % first column
 for c = 2:dmm % generate remaining columns from first row and first column
  for k = 1:nvar
   bas(:,c,k) = bas(c,1,k)+bas(:,1,k);
  end
 end

 % Store index tables
 MMM.T(nvar,ord).bin = bin;
 MMM.T(nvar,ord).pow = pow;
 MMM.T(nvar,ord).bas = bas;

 % to optimize we may here also store index tables
 % for smaller number of variables and degrees
 % - generation of BAS should be done carefully -

else

 % Retrieve existing tables

 bin = MMM.T(nvar,ord).bin;
 pow = MMM.T(nvar,ord).pow;
 bas = MMM.T(nvar,ord).bas;

end
