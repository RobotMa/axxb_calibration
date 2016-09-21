function d = deg(x, varargin)
% @MPOL/DEG - Degree of a polynomial
%
% DEG(X) returns the overall degree of polynomial X
% DEG(X,V) returns the maximal degree of the variable V (of type mpol) in X

% D. Henrion, 2 December 2003
% Last modified on 14 May 2008 by C. Savorgnan

%input checking
if nargin > 2
    error('only one or two input arguments');
end

if nargin == 2 && ~(isa(varargin{1}, 'mpol') && isvar(varargin{1}) )
    error('the second argument must be a variable of type mpol');
end


x = x(:);
d = 0;
if nargin == 1
    for k = 1:length(x)
        d = max([d;full(sum(x(k).pow,2))]);
    end
else
    for k = 1:length(x)
        vind = find(x(k).var==varargin{1}.var);
        if ~isempty(vind)
            d = max(d, max(x(k).pow(:, vind)));
        end
    end
end
        

        
