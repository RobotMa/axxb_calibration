function z = momcon(x,y,op)
% Constructor of class @MOMCON, moment constraint or
% moment objective function
%
% If X and Y are MOM moments
% MOMCON(X,Y,'ge') returns the moment constraint X >= Y
% MOMCON(X,Y,'le') returns the moment constraint X <= Y
% MOMCON(X,Y,'eq') returns the moment constraint X == Y
%
% If X is a MOM moment
% MOMCON(X,'min') returns the moment objective function MIN X
% MOMCON(X,'max') returns the moment objective function MAX X
%
% X and Y must have the same dimensions, unless one is a scalar, in which
% case it is repeated entrywise
  
% A MOMCON object X has the following internal structure:
%
% X.LEFT = left hand-side MOM object
% X.RIGHT = right hand-side MOM object
% X.TYPE = inequality type 'ge','le','eq' or objective type 'min','max'

% D. Henrion, 21 January 2004
% Last modified on 11 December 2006

if nargin > 0

if nargin == 1

 error('Invalid syntax')

elseif nargin == 2 % moment objective function

 if ~strcmp(y,'min') & ~strcmp(y,'max')
  error('Invalid second input argument');
 else
  if isempty(x)
   error('Empty first input argument')  
  end
  if isa(x,'double')
keyboard
   % constant objective function
   x = mom(x,0);
  elseif isa(x,'mpol')
   % min(x) is the same as min(mom(x))
   x = mom(x,indmeas(x));
  end
 end
 
 if max(size(x))>1
  error('First input argument must be scalar')
 end
 
 sleft = x; % objective function
 sright = mpol(0); % zero right hand-side
 stype = y; % operator = 'min' or 'max'
 
else % moment constraint

 % Filter constants
 if isa(x,'double')
  x = mom(x,0);
 end
 if isa(y,'double')
  y = mom(y,0);
 end
 
 % Check dimensions
 % X and Y must have the same dimensions unless one is a scalar
 
 if any(size(x) ~= size(y))
  if max(size(x)) == 1
   t = x; x = mom(zeros(size(y)),0);
   for r = 1:size(y,1)
    for c = 1:size(y,2)
     x(r,c) = t;
    end
   end
  elseif max(size(y)) == 1
   t = y; y = mom(zeros(size(x)),0);
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
 
end

else % empty output

 sleft = []; sright = []; stype = [];

end

% Build MCON object
superiorto('mom');
z = struct('left',sleft,'right',sright,'type',stype);
z = class(z,'momcon');

