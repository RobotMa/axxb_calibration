function m = meas(varargin)
% @MEAS/MEAS - Constructor of class MEAS, measure
%
% MEAS returns a vector of all existing measures
%
% When M is positive integer, MEAS(M) returns the measure number M 
%
% MEAS(X,Y,..) creates a new measure associated with all the variables
% in MPOL objects X,Y... The corresponding variables are automatically
% affected to the new measure. A given variable cannot be affected to
% several measures. If the variables were already affected to a
% measure, this has the result of initializing the measure scaling
% and discrete support.
%
% MEAS(X,Y,..,M) associates the variables in MPOL objects X,Y...
% with measure number M. If the variables were already affected to a
% measure, this has the result of initializing the measure scaling
% and discrete support.
% 
% Use the command MSET RESETMEAS to delete all the existing measures
% and to associate all the existing variables to one unique measure.

% A MEAS object M has the following internal structure
% X.MEAS = measure indices (DOUBLE vector)
% Relevant information on M can be found in the fields MMM.M{M}

% D. Henrion, 31 March 2006
% Last modified on 23 December 2006
  
global MMM

if nargin < 1
  
 % Displays all existing measures
 if isfield(MMM,'indmeas')
  mi = MMM.indmeas;
 else
  mi = [];
 end
 
 if ~isempty(mi)
   
  mi = sort(mi);
  d = [mi 0]-[0 mi];
  d = d(2:end-1);
  i = 2:length(mi);
  mi = mi([1 i(d>0)]); 

  m = [];
  for k = 1:length(mi)
   m = [m meas(mi(k))];
  end

 else
   
   m = [];
   
 end
 
else

 x = [];
 m = 0;
 
 for k = 1:nargin

  y = varargin{k};
  if isa(y,'mpol')
   x = [x;y(:)];
  elseif isa(y,'double')
   if max(size(y)) > 1
    error('Invalid input argument')
   end
   m = y;
  elseif isa(y,'meas')
   m = y.meas;
  else
   error('Invalid input argument')
  end
  
 end

 if ~isempty(x)

  if isempty(find(MMM.indmeas == m)) % Create new measure

   v = indvar(x); % variable indices
   if ~isempty(v)
    if isempty(MMM.indmeas)
     m = 1;
    elseif m == 0
     % create new measure only if a subset of variables
     % can be extracted
     m = indmeas(x);
     if m(1) == 0
      error('Invalid constant')
     end
     newmeas = false;
     ind = find(MMM.indmeas == m(1));
     if length(m) > 1
      newmeas = true;
     elseif length(ind) ~= length(v)
      newmeas = true;
     elseif ~all(ind == v)
      newmeas = true;
     end
     % make obsolete measures of these variables
     for mm = m
      MMM.M{mm} = [];
     end
     % index of new measure
     if newmeas
      m = max(MMM.indmeas)+1;
     end
    end
    MMM.indmeas(v) = m; % associate variables
   end

  else  % existing measure
    
   % Assign variables to existing measure
   v = indvar(x); % variable indices
   if ~isempty(v)
    MMM.indmeas(v) = m; % associate variables
   end

  end
  
  % Initialize moments of corresponding measure

  if isfield(MMM,'M')
   if length(MMM.M) >= m
    MMM.M{m} = [];
   end
  end
 
 end
 
 % Build the @MEAS object

 superiorto('mpol')
 m = class(struct('meas',m),'meas');

 % Set up internally the measure

 m = set(m);

end






