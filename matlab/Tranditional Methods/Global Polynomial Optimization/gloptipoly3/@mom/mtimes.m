function z = mtimes(x,y)
% @MOM/MTIMES - Multiply MOM objects
%
% MTIMES(X,Y) or X*Y is the matrix product of X and Y.
% The number of columns of X must equal the number of rows of Y,
% unless X or Y is a scalar.

% D. Henrion, 27 March 2006

if size(x,2) ~= size(y,1)

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

else

 % Matrix times matrix

 z = mom(zeros(size(x,1),size(y,2)),0);
 for r = 1:size(x,1)
  for c = 1:size(y,2)
   % Inner products
   z(r,c) = times(x(r,1),y(1,c));
   for i = 2:size(x,2)
    z(r,c) = plus(z(r,c),times(x(r,i),y(i,c)));
   end
  end
 end
end

