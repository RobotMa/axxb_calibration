function f = isvar(p)
% @MPOL/ISVAR - Scalar monic monomial

% ISVAR(P) returns TRUE if P is a variable,
% i.e. a scalar monic monomial

% D. Henrion, 24 April 2006
  
f = false;
if length(p) == 1
 vp = p.var;
 if length(vp) == 1
  if vp
   pp = p.pow;
   if pp == 1
    cp = p.coef;
    if length(cp) == 1
     f = (cp == 1);
    end
   end
  end
 end
end
