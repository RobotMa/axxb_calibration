function z = plus(x,y)
% @MOM/PLUS - Add MOM objects
%
% PLUS(X,Y) or X+Y adds X and Y
%
% X and Y must have the same dimensions unless one is a scalar,
% in which case it is repeated entrywise

% D. Henrion, 15 March 2006

if any(size(x) ~= size(y))

 % Matrix plus scalar
 
 if max(size(x)) == 1
  z = mom(zeros(size(y)),0);
  for r = 1:size(z,1)
   for c = 1:size(z,2)
    z(r,c) = plus(x,y(r,c));
   end
  end
 elseif max(size(y)) == 1
  z = mom(zeros(size(x)),0);
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
 
 z = mom(zeros(size(x)),0);
 for r = 1:size(x,1)
  for c = 1:size(x,2)
   z(r,c) = plus(x(r,c),y(r,c));
  end
 end

else

 % Scalar plus scalar

 if ~isa(x,'mom')
      
  if ~isa(x,'double')
   error('Invalid first input argument')
  end
  
  x = mom(x,0);
 
 elseif ~isa(y,'mom')
   
  if ~isa(y,'double')
   error('Invalid second input argument')
  end

  y = mom(y,0);
  
 end

 z = x;
 measy = y.meas;
 for k = 1:length(measy)
  indmeas = find(z.meas == measy(k));
  if isempty(indmeas) 
    % moments of new measure
    z.meas = [z.meas measy(k)];
    z.split = [z.split y.split(k)];
    % sort out according to measure indices
    [v,ind] = sort(z.meas);
    z.meas = z.meas(ind);
    z.split = z.split(ind);
  else
    % moments of existing measure
    z.split(indmeas) = z.split(indmeas) + y.split(k);
  end
 end
 z = reduce(z);
 
end


