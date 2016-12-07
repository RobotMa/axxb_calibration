function x = uminus(x)
% @MPOL/UMINUS - Unary minus for MPOL object

% D. Henrion, November 30, 2003

[nrows,ncols] = size(x);

for r = 1:nrows
 for c = 1:ncols

  x(r,c).coef = -x(r,c).coef;
  
 end
end

