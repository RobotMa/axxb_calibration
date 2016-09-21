function v = indvar(x)
% @MPOL/INDVAR - Internal use only

% INDVAR(X) returns a row vector of sorted problem variable indices in X
%
% If X is a constant polynomial, then INDVAR(X) = 0
  
% D. Henrion, 30 November 2003
% Last modified on 21 April 2006

% Retrieve variable indices
v = [];
[nr,nc] = size(x);
for r = 1:nr
 for c = 1:nc
  v = [v x(r,c).var];
 end
end

% Sort and remove duplicate variable indices
v = sort(v);
d = [v 0]-[0 v];
d = d(2:end-1);
i = 2:length(v);
v = v([1 i(d>0)]);

% Remove zero variable index
if (length(v) > 1) & (v(1) == 0)
 v = v(2:end);
end

