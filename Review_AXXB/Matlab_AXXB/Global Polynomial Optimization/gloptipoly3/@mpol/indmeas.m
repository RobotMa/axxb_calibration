function m = INDMEAS(x)
% @MPOL/INDMEAS - Internal use only

% INDMEAS(X) returns indices of measures associated with variables in X
%
% If there is no measure associated with X, then INDMEAS(X) = 0
  
% D. Henrion, 4 August 2004
% Last modified on 31 March 2006
  
global MMM

m = 0;
[nr,nc] = size(x);
for r = 1:nr
 for c = 1:nc
  % Variable indices
  v = indvar(x(r,c));
  % Measure indices
  if v
   m = [m MMM.indmeas(v)];
  end
 end
end

% Sort and remove duplicate measure indices
m = sort(m);
d = [m 0]-[0 m];
d = d(2:end-1);
i = 2:length(m);
m = m([1 i(d>0)]);

% Remove zero measure index
if (length(m) > 1) & (m(1) == 0)
 m = m(2:end);
end

