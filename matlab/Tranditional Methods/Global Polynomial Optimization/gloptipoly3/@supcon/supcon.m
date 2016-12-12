function z = supcon(x,y,op)
% Constructor of class @SUPCON, measure support constraint,
% moment constraint, or moment objective function
%
% If X and Y are MPOL polynomials
% SUPCON(X,Y,'ge') returns the measure support constraint X >= Y
% SUPCON(X,Y,'le') returns the measure support constraint X <= Y
% SUPCON(X,Y,'eq') returns the measure support constraint X == Y
%
% X and Y must have the same dimensions, unless one is a scalar,
% in which case it is repeated entrywise
%
% X and Y must refer to the same unique measure
  
% A SUPCON object X has the following internal structure:
%
% X.LEFT = left hand-side MPOL object
% X.RIGHT = right hand-side MPOL object
% X.TYPE = inequality type 'ge','le','eq'

% D. Henrion, 21 January 2004
% Last modified on 15 November 2006

if nargin > 0

if nargin < 3
 error('Invalid syntax')
end

% Check third input argument

if ~strcmp(op,'ge') & ~strcmp(op,'le') & ~strcmp(op,'eq')
 error('Invalid operator')
end

% Filter out constants
x = mpol(x); y = mpol(y);

% Check measures
 
measx = indmeas(x); measy = indmeas(y);
if (length(measx) > 1) | (length(measy) > 1) | ...
        (measx & measy & (measx ~= measy))
 error('Invalid reference to several measures')
end
     
% Check dimensions
% X and Y must have the same dimensions unless one is a scalar

if any(size(x) ~= size(y))
 if max(size(x)) == 1
  t = x; x = mpol(zeros(size(y)));
  for r = 1:size(y,1)
   for c = 1:size(y,2)
    x(r,c) = t;
   end
  end
 elseif max(size(y)) == 1
  t = y; y = mpol(zeros(size(x)));
  for r = 1:size(x,1)
   for c = 1:size(x,2)
    y(r,c) = t;
   end
  end
 else
  error('Matrix dimensions must agree')
 end 
end

[nrows,ncols] = size(x);
sleft = cell(nrows,ncols);
sright = sleft;
stype = sleft;
for r = 1:nrows
 for c = 1:ncols
  sleft{r,c} = x(r,c);
  sright{r,c} = y(r,c);
  stype{r,c} = op;
 end
end

else % empty output

 sleft = []; sright = []; stype = [];

end

% Build SUPCON object
superiorto('mpol');
z = struct('left',sleft,'right',sright,'type',stype);
z = class(z,'supcon');
