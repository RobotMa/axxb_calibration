function y = left(x)
% @MOMCON/LEFT - Extract left hand-side

% D. Henrion, January 21, 2004
% Last modified on 16 March 2006

[nr,nc] = size(x);
y = mom(zeros(nr,nc),0);
for r = 1:nr
 for c = 1:nc
  y(r,c) = x(r,c).left;
 end
end
