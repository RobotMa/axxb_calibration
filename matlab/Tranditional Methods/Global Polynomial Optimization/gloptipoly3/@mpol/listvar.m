function list = listvar(p)
% @MPOL/LISTVAR builds a vector containing the variables defining the specified polynomial
%
% LISTVAR(P) returns a column vector containing the variables in
%   the polynomial P

% C. Savorgnan, 14 May 2008

[nrows, ncols] = size(p);

var = []; %var will contain the id of all the variables in p

for rind = 1:nrows
    for cind = 1:ncols
        tmpvar=p(rind, cind).var;
        for ind = 1:length(tmpvar)
            if isempty(find(var==tmpvar(ind))) && tmpvar(ind)~=0
                var=[var tmpvar(ind)];
            end
        end
    end
end

% reordering of the elements in var (it is not necessary)
[sv, iv]=sort(var);
var=var(iv);

list=[];

for ind = 1:length(var)
    % building the list element
    el = struct('var', var(ind), 'pow', 1, 'coef', 1);
    list = [list; mpol(el)];
end