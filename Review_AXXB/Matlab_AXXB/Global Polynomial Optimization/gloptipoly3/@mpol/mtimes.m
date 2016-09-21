function z = mtimes(x,y)
% @MPOL/MTIMES - Multiply MPOL objects
%
% MTIMES(X,Y) or X*Y is the matrix product of X and Y.
% The number of columns of X must equal the number of rows of Y,
% unless X or Y is a scalar.

% D. Henrion, 30 November 2003
% Last modified on 30 December 2006

if size(x,2) ~= size(y,1)

 % Matrix times scalar

 if prod(size(x)) == 1
  z = mpol(zeros(size(y)));
  for r = 1:size(z,1)
   for c = 1:size(z,2)
    z(r,c) = times(x,y(r,c));
   end
  end
 elseif prod(size(y)) == 1
  z = mpol(zeros(size(x)));
  for r = 1:size(z,1)
   for c = 1:size(z,2)
    z(r,c) = times(x(r,c),y);
   end
  end
 else
  error('Inner matrix dimensions must agree')
 end

else

 % Matrix times matrix

 z = mpol(zeros(size(x,1),size(y,2)));
 for r = 1:size(x,1)
  for c = 1:size(y,2)
   % Inner products
   z(r,c) = times(x(r,1),y(1,c),'noreduce');
   for i = 2:size(x,2)
    z(r,c) = plus(z(r,c),times(x(r,i),y(i,c),'noreduce'),'noreduce');
   end
   % Monomial reduction performed only once at the end
   z(r,c) = reduce(z(r,c));
  end
 end
end




