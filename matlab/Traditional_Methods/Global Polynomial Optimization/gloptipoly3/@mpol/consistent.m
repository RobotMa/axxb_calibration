function f = consistent(x)
% @MPOL/CONSISTENT - Internal use only
  
% Check whether a scalar polynomial object is consistent with the
% defined measures and variables - used in MDEF

% D. Henrion, 15 May 2006

m = indmeas(x(1));
% should correspond to one measure only
f = (length(m) == 1);
