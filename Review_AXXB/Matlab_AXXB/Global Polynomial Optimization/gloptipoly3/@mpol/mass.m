function y = mass(x)
% @MPOL/MASS - Measure mass
%
% MASS(X) returns the mass (type MOM) of the unique measure associated
% with the polynomial X
%
% Equivalent to MASS(MEAS(X))

% D. Henrion, 15 March 2006
  
global MMM

measx = indmeas(x);

if length(measx) > 1
 error('More than one measure associated with input argument')
elseif measx == 0
 error('Undefined measure')
else
 ind = find(MMM.indmeas == measx);
 if isempty(ind)
  error('Undefined measure')
 end
 % Create moment of zeroth power of this measure
 y = mom(1,measx);
end
