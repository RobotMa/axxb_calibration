function [varargout] = locate(p, x)
% @MPOL/LOCATE locates the specified elements inside a polynomial
%
% I = LOCATE(P, X) when P is a vector of type mpol and X is a scalar (numeric or of mpol type),
%    the function returns the indices of the elements of P equal to X.
% [I,J] = LOCATE(P, X) when P is a matrix of type mpol and X is a scalar (numeric or of type mpol),
%    the function returns the row indices (I) and column indices (J) of the elements of P equal to X.

% C. Savorgnan, 14 May 2008

%checking input
msg = 'the second input must be a scalar (possibly of type mpol)';

if ~(isa(x, 'mpol') || isnumeric(x))
    error(msg);
end

if ~( size(x,1)==1 && size(x,2)==1 )
    error(msg);
end

%finding
if nargout<=1
    i = [];
    for index = 1:length(p)
        if isequal(p(index), x)
            i = [i index];
        end
    end
    varargout = {i};
else
    i = [];
    j = [];
    [nrows, ncols] = size(p);
    for rind = 1:nrows
        for cind = 1:ncols
            if isequal(p(rind, cind), x)
                i = [i rind];
                j = [j cind];
            end
        end
    end
    varargout = {i ,j};
end
