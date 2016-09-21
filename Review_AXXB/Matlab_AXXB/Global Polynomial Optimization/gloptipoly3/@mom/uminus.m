function x = uminus(x)
% @MOM/UMINUS - Unary minus for MOM object

% D. Henrion 30 November 2003
% Last modified 15 March 2006
  
[nrows,ncols] = size(x);

for r = 1:nrows
 for c = 1:ncols
  for k = 1:length(x(r,c).split)
   x(r,c).split(k) = -x(r,c).split(k);
  end
 end
end
