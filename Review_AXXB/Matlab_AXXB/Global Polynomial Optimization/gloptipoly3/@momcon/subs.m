function newmc = subs(mc, old, new)
% @MOMCON/SUBS substitutes variables in a given moment constraint
%
% SUBS(MC, OLD, NEW) given the moment constraint MC of type momcon, substitutes
%   the vector of variables OLD with the vector of polynomials NEW

% C. Savorgnan, 14 May 2008

left = subs(mc.left, old, new);
right = subs(mc.right, old, new);
type = mc.type;

newmc = momcon(left, right, type);
