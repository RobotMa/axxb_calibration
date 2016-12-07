function newsc = subs(sc, old, new)
% @SUPCON/SUBS substitutes variables in a given support constraint
%
% SUBS(SC, OLD, NEW) given the support constraint SC of type supcon, substitutes
%    the vector of variables OLD with the vector of polynomials NEW

% C. Savorgnan, 14 May 2008

newsc=[];

for index=1:length(sc)
    left = subs(sc(index).left, old, new);
    right = subs(sc(index).right, old, new);
    type = sc(index).type;
    newsc = [newsc; supcon(left, right, type)];
end
