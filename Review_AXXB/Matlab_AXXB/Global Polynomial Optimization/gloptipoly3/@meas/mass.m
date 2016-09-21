function y = mass(x)
% @MEAS/MASS - Measure mass
%
% MASS(X) returns the mass (type MOM) of measure X

% D. Henrion, 15 March 2006
% Last modified on 20 April 2006

[nr,nc] = size(x);

for r = 1:nr
 for c = 1:nc
  % Create moment of zeroth power of this measure
  y(r,c) = mom(1,x(r,c).meas);
 end
end

 
