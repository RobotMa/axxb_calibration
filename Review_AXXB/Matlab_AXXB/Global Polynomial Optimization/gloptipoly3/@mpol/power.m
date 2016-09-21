function z = power(x,y)
% @MPOL/POWER - Array power
%
% POWER(X,Y) or X.^Y is the element-by-element power

% D. Henrion, December 2, 2003
% Last modified on August 13, 2004

if nargin < 1
 y = 1;
end


if any(size(x) ~= size(y))

 % One scalar argument
  
 if max(size(y)) == 1
  z = mpol(zeros(size(x)));
  for r = 1:size(z,1)
   for c = 1:size(z,2)
    z(r,c) = mpower(x(r,c),y);
   end
  end
 elseif max(size(x)) == 1
  z = mpol(zeros(size(y)));
  for r = 1:size(z,1)
   for c = 1:size(z,2)
    z(r,c) = mpower(x,y(r,c));
   end
  end
 else
  error('Matrix dimensions must agree')
 end

else
  
 z = mpol(zeros(size(x)));
 for r = 1:size(x,1)
  for c = 1:size(x,2)
   z(r,c) = mpower(x(r,c),y(r,c));
  end
 end

end

    
