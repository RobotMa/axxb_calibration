function y = right(x)
% @MOMCON/RIGHT - Extract right hand-side

% D. Henrion, January 21, 2004
% Last modified on 19 December 2006

[nr,nc] = size(x);
y = mom(zeros(nr,nc),0);
for r = 1:nr
 for c = 1:nc
  if strcmp(x(r,c).type,'min') | strcmp(x(r,c).type,'max')
   y(r,c) = x(r,c).left;
  else
   y(r,c) = x(r,c).right;
  end
 end
end

