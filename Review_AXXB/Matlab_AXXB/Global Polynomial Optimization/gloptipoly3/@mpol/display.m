function [id,str] = display(x)
% @MPOL/DISPLAY - Display MPOL object
%
% [ID,STR] = DISPLAY(X) returns the string identifier ID
% as well as a cell array STR of character strings

% D. Henrion, 29 November 2003
% Last modified on 16 May 2007

global MMM;
  
%disp('display'), keyboard

% Spacing
if isequal(get(0,'FormatSpacing'),'compact')
 cr = '';
else
 cr = '\n';
end

% Threshold for displaying zeros or ones
tol = 1e-8;

% No screen output ?
silent = nargout>0;

[nrows,ncols] = size(x);

% Identifier

if isempty(x) % empty

 id = 'Empty polynomial';

else

 if (nrows == 1) & (ncols == 1)
  id = 'Scalar polynomial';
 elseif min(nrows,ncols) == 1
  id = [int2str(nrows) '-by-' int2str(ncols) ...
       ' polynomial vector'];
 else
  id = [int2str(nrows) '-by-' int2str(ncols) ...
       ' polynomial matrix'];  
 end
 
end

if ~silent
 fprintf([cr id '\n' cr]);
end

% Polynomial as a character string

str = cell(nrows,ncols);

for c = 1:ncols
 for r = 1:nrows

  nmon = size(x(r,c).coef,1);
  nvar = size(x(r,c).pow,2);

  str{r,c} = '';
  noterm = true;
  for m = 1:nmon
   % Non-zero coef
   if abs(x(r,c).coef(m)) > tol
    % Sign   
    if ~noterm & (x(r,c).coef(m) > 0)
     str{r,c} = [str{r,c} '+'];
    elseif (x(r,c).coef(m) < 0)
     str{r,c} = [str{r,c} '-'];
    end
    noterm = false;
    % Litteral coef
    strval = num2str(abs(x(r,c).coef(m)));
    if (sum(x(r,c).pow(m,:)) == 0) % constant term
     str{r,c} = [str{r,c} strval];
    elseif ~strcmp(strval,'1')
     str{r,c} = [str{r,c} strval]; % non-unit coef
    end
    % Monomial 
    for p = 1:nvar
     if x(r,c).pow(m,p) > 0 % non-constant
      if x(r,c).pow(m,p) > 1
       str{r,c} = [str{r,c} MMM.var{x(r,c).var(p)} ...
		   '^' int2str(x(r,c).pow(m,p))];
      else
       str{r,c} = [str{r,c} MMM.var{x(r,c).var(p)}];
      end
     end
    end
   end
  end
  
  if isempty(str{r,c})
   str{r,c} = '0';
  end

  if ~silent
   if (nrows > 1) | (ncols > 1)
    disp(['(' int2str(r) ',' int2str(c) '):' str{r,c}]);
   else
    disp(str{r,c}); 
   end
  end
  
 end
end

if ~silent
 fprintf(cr)
end

   
