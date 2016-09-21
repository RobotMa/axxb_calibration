function x = reduce(x)
% @MOM/REDUCE - Internal use only

% Remove zero moments

% D. Henrion, 28 April 2006

% Absolute value threshold for removing almost zero moments
% (set TOL = 0 to prevent removing almost zero moments)
tol = 0;

for r = 1:size(x,1)
 for c = 1:size(x,2)
   p = x(r,c).split; % polynomial vector
   keep = true(length(p),1);
   for k = 1:length(p)
    if deg(p(k)) == 0
     if abs(coef(p(k))) <= tol
      keep(k) = false;
     end
    end
   end
   % remove zero polynomials
   x(r,c).meas = x(r,c).meas(keep);
   x(r,c).split = x(r,c).split(keep);
   if isempty(x(r,c).meas) % zero moment
    x(r,c).meas = 0;
    x(r,c).split = mpol(0);
   end
 end
end

