function nvar = genmom(im,iv,ord)
% GENMOM - Internal use only

% GENMOM(IM,IV,ORD) generates moments for a measure.
%
% Updates measure info MMM.M
% Used by MSDP
% Uses GENIND

% D. Henrion, 9 January 2004
% Last modified on 27 April 2007

global MMM
  
% Total number of variables in this measure
tnvar = sum(MMM.indmeas == im);
  
% Variables associated with this measure
iv = iv(MMM.indmeas(iv) == im);
nvar = length(iv);

if nvar
    
% Relative indices wrt this measure
relvar = zeros(size(MMM.indmeas));
relvar(iv) = 1:nvar;

% Mask variables in this measure
mask = false(size(MMM.indmeas));
mask(iv) = true;
mask = mask(MMM.indmeas == im);

% Relative indices wrt this mask
relmask = relvar;
relmask(find(relvar)) = find(mask);

% Generate the moments and store index tables in MMM.T
% or retrieve them from MMM.T if they already exist
genind(nvar,2*ord); % generate indexing tables
nm = MMM.T(nvar,ord).bin(end,2*ord+2); % number of moments
 
% Store data relative to the measure
MMM.M{im}.tnvar = tnvar; % total number of variables
MMM.M{im}.nvar = nvar; % number of active variables
MMM.M{im}.indvar = iv; % indices of active variables
MMM.M{im}.mask = mask; % mask active variables
MMM.M{im}.relvar = relvar; % relative indices of variables
MMM.M{im}.relmask = relmask; % relative indices in this mask
MMM.M{im}.ord = ord; % half maximum degree
MMM.M{im}.nm = nm; % number of moments
MMM.M{im}.sol = {}; % discrete support

end

