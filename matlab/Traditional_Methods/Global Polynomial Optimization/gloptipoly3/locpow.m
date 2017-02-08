function lpow = locpow(p,measp)
% LOCPOW - Internal use only

% LPOW =  LOCPOW(P,MEASP) returns a 3D vector of powers of scalar
% polynomial P with variables indexed *relatively* to measure MEASP

% D. Henrion, 27 April 2004
% Last modified on 5 January 2007

global MMM
  
varp = indvar(p);
powp = pow(p);
nmon = size(powp,1);
nvar = MMM.M{measp}.nvar;
lpow = zeros(nmon,1,nvar);
if varp(1) > 0
 ind = MMM.M{measp}.relvar(varp);
 if all(ind)
  lpow(:,:,MMM.M{measp}.relvar(varp)) = reshape(powp,nmon,1,length(varp));
 else
  lpow = []; % some variables are not assigned
 end
end
