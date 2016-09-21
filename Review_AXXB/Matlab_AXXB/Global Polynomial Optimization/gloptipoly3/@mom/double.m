function v = double(m)
% @MOM/DOUBLE - Evaluate moment
%
% DOUBLE(M) returns the linear moment expression
% last obtained by solving an SDP moment problem

% D. Henrion, 28 March 2006
% Last modified on 5 January 2007

global MMM

if isempty(m)
 v = [];
 return
end

[nr,nc] = size(m);
v = zeros(nr,nc);

for r = 1:nr
 for c = 1:nc
 
  % Scalar
  p = m(r,c).split; % scalar moment -> polynomial vector
  imp = m(r,c).meas; % measure indices
  nmom = length(p); % number of moments
  w = ones(1,nmom); % weights
  for k = 1:nmom 
   mm = imp(k);
   if mm > 0 % not a constant
    if ~isfield(MMM,'M')
     error('Undefined measure: cannot evaluate moment')
    elseif length(MMM.M) < mm
     error('Undefined measure: cannot evaluate moment')
    elseif ~isfield(MMM.M{mm},'mass')
     error('Unassigned moments')
    end
    % convert powers to indices
    powp = locpow(p(k),mm);
    if isempty(powp)
     error(['Measure with some unassigned variables. ' 13 ...
            'Cannot evaluate moment']);
    end
    mind = pow2ind(powp,mm);
    % retrieve numerical value of moment
    momp = MMM.M{mm}.mvec(mind-MMM.M{mm}.begind+1);
    w(k) = momp'*coef(p(k));
   else
    % constant
    w(k) = coef(p(k));
   end
  end

  v(r,c) = sum(w);
 
 end
end

 
 
