function [id,str] = display(x)
% @MOMCON/DISPLAY - Display moment constraint
%
% [ID,STR] = DISPLAY(X) returns the string identifier ID
% as well as a cell array STR of character strings

% D. Henrion, 21 January 2004
% Last modified on 11 September 2008

% No screen output ?
silent = nargout>0;

% disp('@moncon/display'); keyboard

[nrows,ncols] = size(x);

if (min(nrows,ncols) < 1) | isempty(type(x))
 
 id = 'Empty moment constraint';
 str = [];
 if ~silent
  disp(id);
 end

else
 
 if (nrows == 1) & (ncols == 1)
  id = 'Scalar';
 else
  id = [int2str(nrows) '-by-' int2str(ncols) ...
        ' matrix'];
 end

 switch type(x)
 case {'ge','le'}
  id = [id ' moment inequality constraint'];
 case 'eq'
  id = [id ' moment equality constraint'];
 case {'min','max'}
  id = [id ' moment objective function'];
 end

if ~silent
  disp(id);
end

str = cell(nrows,ncols);

for r = 1:nrows
 for c = 1:ncols
  
  if ~isempty(x(r,c).left)
   
   % left hand-side
   [u,lhs] = display(x(r,c).left); 
  
   % operator
   op = '';
   switch type(x(r,c))
    case 'ge'
     op = ' >= ';
    case 'eq'
     op = ' == ';
    case 'le'
     op = ' <= ';
   end
  
   % right hand-side
   if ~isempty(op)
    [void,rhs] = display(x(r,c).right);
    str{r,c} = [lhs{:} op rhs{:}];
   else % min or max
    str{r,c} = [x(r,c).type ' ' lhs{:}];
   end
  
  else
   str{r,c} = 'empty';
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

end
