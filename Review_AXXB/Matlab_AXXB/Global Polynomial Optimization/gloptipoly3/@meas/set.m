function m = set(m)
% @MEAS/SET - Internal use only
  
% Set up internally a new measure
% Modifies the global structure MMM.M{}
% Used in @MPOL/SCALE, @MPOL/ASSIGN

% D. Henrion, 22 May 2006
% Last modified on 27 November 2006
  
global MMM

% Measure index
mx = m.meas;

erase = true;
if isfield(MMM,'M')
 if length(MMM.M) >= mx
  if isfield(MMM.M{mx},'nvar') % already existing measure
   erase = false; % keep measure data
  end
 end
end

if erase
  
 % Variables associated with this measure
 pindvar = (MMM.indmeas == mx);
 nvar = sum(pindvar);
 pindvar = find(pindvar);

 % Relative indices wrt this measure
 relvar = zeros(size(MMM.indmeas));
 relvar(pindvar) = 1:nvar;

 % Mask variables in this measure
 mask = false(size(MMM.indmeas));
 mask(pindvar) = true;
 mask = mask(MMM.indmeas == mx);

 % Relative indices wrt this mask
 relmask = relvar;
 relmask(find(relvar)) = find(mask);

 % Update measure fields
 MMM.M{mx}.tnvar = nvar; % total number of variables
 MMM.M{mx}.nvar = nvar; % number of active variables
 MMM.M{mx}.indvar = pindvar; % indices of active variables
 MMM.M{mx}.mask = mask; % mask active variables
 MMM.M{mx}.relvar = relvar; % relative indices of variables
 MMM.M{mx}.relmask = relmask; % relative indices in this mask
 
end
