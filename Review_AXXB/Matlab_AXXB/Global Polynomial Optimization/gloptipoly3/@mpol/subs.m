function newp = subs(p, old, new)
% @MPOL/SUBS substitutes variables in a given polynomial
%
% SUBS(P, OLD, NEW) given the variable P of type mpol, substitutes
%   the variable (or vector of variables) OLD with the polynomial (or
%   vector of polynomials) NEW

% C. Savorgnan, 14 May 2008

if ~isvector(old)
    error('the second argument must be a vector of variables of type mpol');
end

for index = 1:length(old)
    if ~isa(old(index), 'mpol') || ~isvar(old(index))
        error('the second argument must be a vector of variables of type mpol');
    end
end

if ~isvector(new)
    error('the third argument must be a vector of variables of type mpol or a numeric vector');
end

if ~isa(new, 'mpol') && ~isnumeric(new)
    error('the third argument must be a vector of variables of numeric or mpol type');
end

if length(old)~=length(new)
    error('the second and third argument must have equal size');
end

[nrows, ncols] = size(p);

%substitution

newp = p;

for rind = 1:nrows
    for cind = 1:ncols
        var = listvar(p(rind, cind));
        pow = p(rind, cind).pow;
        coef = p(rind, cind).coef;
        newp(rind, cind) = 0;
        for mind = 1:length(coef) % for all the monomials in p(rind, cind)
            tmp = coef(mind);
            for vind = 1:length(var) % for all the variables in p(rind, cind)
                ind = locate(old, var(vind));
                if isempty(ind)
                    tmp = tmp * var(vind)^pow(mind, vind);
                else
                    tmp = tmp * new(ind)^pow(mind, vind);
                end
            end
            newp(rind, cind) = newp(rind, cind) + tmp;
        end
    end
end
