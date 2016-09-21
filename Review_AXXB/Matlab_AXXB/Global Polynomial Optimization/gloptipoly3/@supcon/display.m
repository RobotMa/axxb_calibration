function [id,str] = display(x)
% @SUPCON/DISPLAY - Display measure support constraint
%
% [ID,STR] = DISPLAY(X) returns the string identifier ID
% as well as a cell array STR of character strings

% D. Henrion, 21 January 2004
% Last modified on 12 December 2006

% No screen output ?
silent = nargout>0;

[nrows,ncols] = size(x);

if (min(nrows,ncols) < 1) | isempty(type(x))
 
 id = 'Empty support constraint';
 if ~silent
  disp(id);
 end

else
 
 if (nrows == 1) & (ncols == 1)
  id = 'Scalar';
 elseif min(nrows,ncols) == 1
  id = [int2str(nrows) '-by-' int2str(ncols) ...
       ' vector'];
 else
  id = [int2str(nrows) '-by-' int2str(ncols) ...
        ' matrix'];
 end

 switch type(x)
 case {'ge','le'}
  id = [id ' measure support inequality'];
 case 'eq'
  id = [id ' measure support equality'];
 end

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
   switch type(x(r,c))
    case 'ge'
     op = ' >= ';
    case 'eq'
     op = ' == ';
    case 'le'
     op = ' <= ';
   end
   
   % right hand-side
   [u,rhs] = display(right(x(r,c)));

   str{r,c} = [lhs{:} op rhs{:}];
  
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
