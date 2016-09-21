function y = mom(x,measx)
% @MOM/MOM - Constructor of class MOM, linear combination of moments
%
% MOM(X) converts an MPOL polynomial X corresponding to a unique measure

% MOM(X,MEASX) converts a DOUBLE X into a weighted mass of
% the measure index MEASX, which can be zero - Internal use only
  
% An MOM object X has the following internal structure:
% X.MEAS = double vector, measure indices, zero points to a constant
% X.SPLIT = double vector, MPOL objects corresponding to these measures

% D. Henrion, 15 March 2006
% Last modified on 1 March 2007
  
global MMM

if isa(x,'mpol')
  
 measx = indmeas(x);
 if (measx==0) & (nargin < 2)
  y = mom(x,measx); % constant
 end
 if length(measx) > 1
  error('Invalid partitioning of measures in moments')
 end
 
elseif isa(x,'double')
  
 if nargin < 2
  measx = 0;
  y = mom(x,measx); % constant
 end
 if measx > 0
  ind = find(MMM.indmeas == measx);
  if isempty(ind)
   error('Undefined measure')
  end
 end
 
else
  
 error('Invalid conversion')
 
end
  
[nrows,ncols] = size(x);
measy = cell(nrows,ncols);
splity = cell(nrows,ncols);

for r = 1:nrows
 for c = 1:ncols
  measy{r,c} = measx;
  splity{r,c} = mpol(x(r,c));
 end
end
   
superiorto('mpol');
y = struct('meas',measy,'split',splity);
y = class(y,'mom');

y = reduce(y); % remove zero moments
