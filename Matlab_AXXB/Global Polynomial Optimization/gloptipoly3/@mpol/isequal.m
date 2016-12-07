function out = isequal(a, b)
% @MPOL/ISEQUAL compares two variables of type mpol
%
% ISEQUAL(A, B) returns true if the polynomials A and B are equal,
%   false otherwise.

% C. Savorgnan, 14 May 2008

[nrowa, ncola]=size(a);
[nrowb, ncolb]=size(b);


if nrowa~=nrowb || ncola~=ncolb
    % a and b have different dimension
    out = false;
else
    % checking for differencies
    for rind = 1:nrowa
        for cind = 1:ncola
            diff=a-b;
            if diff.coef(1)~=0
                out = false;
                return
            end
        end
    end
    % if this point is reached all the elements are equal
    out = true;
end
