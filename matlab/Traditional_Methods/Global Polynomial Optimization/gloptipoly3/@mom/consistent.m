function f = consistent(x)
% @MOM/CONSISTENT - Internal use only
  
% Check whether a scalar moment object is consistent with the
% defined measures and variables - used in MDEF

% D. Henrion, 23 March 2006

p = x(1).split;
m = x(1).meas;
n = length(p);

f = true(1,n);

for k = 1:length(p)
 % Each polynomial should correspond to one measure only
 mp = indmeas(p(k));
 if (length(mp) > 1) | ((mp ~= 0) & (mp ~= m(k)))
  f(k) = false;
 end
end

f = all(f);

