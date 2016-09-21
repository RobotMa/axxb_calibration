function sol = double(M)
% @MEAS/DOUBLE - Extract points for a finitely supported measure
%
% See also @MPOL/ASSIGN

% D. Henrion, 3 April 2006
% Modified on 23 December 2006
  
global MMM

if length(M) > 1
 error('Scalar measures only')
end
if ~isfield(MMM,'M')
 error('Measure with undefined moments')
end
if ~isfield(MMM.M{M.meas},'sol')
 error('Measure with undefined support')
end
if isempty(MMM.M{M.meas}.sol)
 error('Measure with empty support')
end

sol = MMM.M{M.meas}.sol;


