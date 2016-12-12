function y = mpol(x)
% @MOM/MPOL - Convert moment to polynomial

% D. Henrion, 16 March 2006

[nrows,ncols] = size(x);

if max(nrows,ncols) > 1
 
  % Matrix
  
  y = mpol(zeros(nrows,ncols));
  for r = 1:nrows
   for c = 1:ncols
     y(r,c) = mpol(x(r,c));
   end
  end

else

  % Scalar
  y = sum(x.split); % vector to scalar

end



