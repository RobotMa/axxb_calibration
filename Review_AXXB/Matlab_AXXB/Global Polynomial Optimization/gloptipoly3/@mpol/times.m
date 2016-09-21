function z = times(x,y,flag)
% @MPOL/TIMES - Multiply entrywise MPOL objects
%
% TIMES(X,Y) or X.*Y is the entrywise product.
% X and Y must have the same dimensions unless one is a scalar.

% D. Henrion, 30 November 2003
% Last modified on 27 March 2006

% With a third input argument reduction is not carried out
% Used to speed up repeated matrix operations
noreduce = (nargin == 3);

if any(size(x) ~= size(y))

 % Matrix times scalar

 if max(size(x)) == 1
  z = mpol(zeros(size(y)));
  for r = 1:size(z,1)
   for c = 1:size(z,2)
    z(r,c) = times(x,y(r,c));
   end
  end
 elseif max(size(y)) == 1
  z = mpol(zeros(size(x)));
  for r = 1:size(z,1)
   for c = 1:size(z,2)
    z(r,c) = times(x(r,c),y);
   end
  end
 else
  error('Inner matrix dimensions must agree')
 end

elseif max(size(x)) > 1

 % Matrix times matrix

 z = mpol(zeros(size(x)));
 for r = 1:size(x,1)
  for c = 1:size(x,2)
   z(r,c) = times(x(r,c),y(r,c));
  end
 end
 
else

 % Scalar times scalar

 if ~isa(x,'mpol')
   
  if ~isa(x,'double')
   error('Invalid first input argument')
  end
  
  % First argument is constant
  z = y;
  z.coef = z.coef*x;

 elseif ~isa(y,'mpol')
  
  if ~isa(y,'double')
   error('Invalid second input argument')
  end
  
  % Second argument is constant
  z = x;
  z.coef = z.coef*y;
  
 else
  
  % Both arguments are polynomial
 
  z = mpol(0);
  z.var = [x.var y.var];
  nvarx = size(x.pow,2); nvary = size(y.pow,2); nvarz = nvarx+nvary;
  nmonx = size(x.coef,1); nmony = size(y.coef,1); nmonz = nmonx*nmony;
  z.pow = zeros(nmonz,nvarz);
  z.coef = zeros(nmonz,1);
  for i = 1:size(x.coef,1)
   z.pow(1+(i-1)*nmony:i*nmony,1:nvarx) = ones(nmony,1)*x.pow(i,:);
   z.pow(1+(i-1)*nmony:i*nmony,nvarx+1:nvarz) = y.pow;
   z.coef(1+(i-1)*nmony:i*nmony) = x.coef(i)*y.coef;
  end
  if ~noreduce
   z = reduce(z);
  end
  
 end
 
end
