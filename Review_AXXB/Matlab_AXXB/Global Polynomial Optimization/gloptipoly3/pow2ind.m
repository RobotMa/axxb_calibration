function mind = pow2ind(mpow,measp)
% POW2IND - Internal use only

% MIND = POW2IND(MPOW,MEASP) converts 3D matrix of powers MPOW
% into 2D matrix of indices MIND *relative* to measure MEASP

% D. Henrion, 27 April 2004
% Last modified on 16 March 2006

global MMM
  
nvar = size(mpow,3);
mind = ones(1,size(mpow,1)*size(mpow,2));
bin = MMM.T(nvar,MMM.M{measp}.ord).bin;
for k = 1:nvar
 mind = mind + bin(nvar+1-k,1+sum(mpow(:,:,k:nvar),3));
end
mind = reshape(mind,size(mpow,1),size(mpow,2));
mind = mind + MMM.M{measp}.begind - 1;

