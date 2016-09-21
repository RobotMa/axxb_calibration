function z = plus(x,y,flag)
% @MPOL/PLUS - Add MPOL objects
%
% PLUS(X,Y) or X+Y adds X and Y
%
% X and Y must have the same dimensions unless one is a scalar,
% in which case it is repeated entrywise

% D. Henrion, 29 November 003
% Last modified 15 March 2006

% With a third input argument reduction is not carried out
% Used to speed up repeated matrix operations
noreduce = (nargin == 3);

if any(size(x) ~= size(y))

 % Matrix plus scalar
 
 if max(size(x)) == 1
  z = mpol(zeros(size(y)));
  for r = 1:size(z,1)
   for c = 1:size(z,2)
    z(r,c) = plus(x,y(r,c));
   end
  end
 elseif max(size(y)) == 1
  z = mpol(zeros(size(x)));
  for r = 1:size(z,1)
   for c = 1:size(z,2)
    z(r,c) = plus(x(r,c),y);
   end
  end
 else
  error('Matrix dimensions must agree')
 end

elseif max(size(x)) > 1

 % Matrix plus matrix
 
 z = mpol(zeros(size(x)));
 for r = 1:size(x,1)
  for c = 1:size(x,2)
   z(r,c) = plus(x(r,c),y(r,c));
  end
 end

else

 % Scalar plus scalar

 if ~isa(x,'mpol')
      
  if ~isa(x,'double')
   error('Invalid first input argument')
  end
  
  % First argument is constant
  z = y;
  z.var = [z.var 0];
  z.pow = [z.pow zeros(size(z.pow,1),1);
	   zeros(1,size(z.pow,2)) 0];
  z.coef = [z.coef; x];
 
 elseif ~isa(y,'mpol')
   
  if ~isa(y,'double')
   error('Invalid second input argument')
  end
  
  % Second argument is constant
  z = x;
  z.var = [z.var 0];
  z.pow = [z.pow zeros(size(z.pow,1),1);
	   zeros(1,size(z.pow,2)) 0];
  z.coef = [z.coef; y];
 
 else
   
  % Both arguments are polynomial
  z = x;
  z.var = [z.var y.var];
  z.pow = [z.pow zeros(size(x.coef,1),size(y.pow,2));
           zeros(size(y.coef,1),size(x.pow,2)) y.pow];
  z.coef = [z.coef; y.coef];
 end
 
 if ~noreduce
  z = reduce(z);
 end
 
end


