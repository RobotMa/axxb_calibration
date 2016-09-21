function [id,str] = display(x)
% @MOM/DISPLAY - Display MOM object
%
% [ID,STR] = DISPLAY(X) returns the string identifier ID
% as well as a cell array STR of character strings

% D. Henrion, 29 November 2003
% Last modified on 15 March 2006

% disp('@mom/display'); keyboard

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

 id = 'Empty moment';

else

 if (nrows == 1) & (ncols == 1)
  id = 'Scalar moment';
 elseif min(nrows,ncols) == 1
  id = [int2str(nrows) '-by-' int2str(ncols) ...
       ' moment vector'];
 else
  id = [int2str(nrows) '-by-' int2str(ncols) ...
       ' moment matrix'];  
 end
 
end

if ~silent
 fprintf([cr id '\n' cr]);
end

% Moment as a character string

str = cell(nrows,ncols);

for c = 1:ncols
 for r = 1:nrows

  str{r,c} = '';
  splitm = x(r,c).split; % vector polynomial
  for m = 1:length(x(r,c).meas)
   mypol = splitm(m);
   if isa(mypol,'mpol')
    [id,strpol] = display(mypol);
    strpol = strpol{1}; % character string of polynomial expression
   else
    strpol = num2str(mypol); % constant
   end
   measm = x(r,c).meas(m); % measure index
   if m > 1
    str{r,c} = [str{r,c} '+'];
   end
   if measm == 0 % constant term
    str{r,c} = [str{r,c} strpol];
   else % moment
    str{r,c} = [str{r,c} 'I[' strpol ']d[' int2str(x(r,c).meas(m)) ']'];
   end
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
 
