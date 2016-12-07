function z = times(x,y,flag)
% @MOM/TIMES - Multiply entrywise MOM objects
%
% TIMES(X,Y) or X.*Y is the entrywise product.
% X and Y must have the same dimensions unless one is a scalar.
%
% If X or Y is a moment, then X.*Y is a moment

% D. Henrion, 27 March 2006

if any(size(x) ~= size(y))

 % Matrix times scalar

 if max(size(x)) == 1
  z = mom(zeros(size(y)),0);
  for r = 1:size(z,1)
   for c = 1:size(z,2)
    z(r,c) = times(x,y(r,c));
   end
  end
 elseif max(size(y)) == 1
  z = mom(zeros(size(x)),0);
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

 z = mom(zeros(size(x)),0);
 for r = 1:size(x,1)
  for c = 1:size(x,2)
   z(r,c) = times(x(r,c),y(r,c));
  end
 end
 
else

 % Scalar times scalar

 if ~isa(x,'mom')
   
  if ~isa(x,'double')
   error('Invalid first input argument')
  end
  
  % First argument is constant
  z = y;
  z.split = z.split*x; % use @MPOL/TIMES

 elseif ~isa(y,'mpol')
  
  if isa(y,'mom')
   error('Invalid product of moments')
  elseif ~isa(y,'double')
   error('Invalid second input argument')
  end
  
  % Second argument is constant
  z = x;
  z.split = z.split*y; % use @MPOL/TIMES
  
 end

 z = reduce(z);
 
end
