function x = reduce(x)
% @MPOL/REDUCE - Internal use only

% Order variables and monomials, remove redundant variables,
% remove almost zero monomials.

% D. Henrion, 29 November 2003
% Last modified on 28 April 2006

% Absolute value threshold for removing almost zero monomials
% (set TOL = 0 to prevent removing almost zero monomials)
tol = 0;

for r = 1:size(x,1)
 for c = 1:size(x,2)

  % Ordering of monomials (column-wise)
  [x(r,c).var,indc] = sort(x(r,c).var);
  x(r,c).pow = x(r,c).pow(:,indc);
  
  % Remove redundant variables (column-wise)
  nvar = size(x(r,c).pow,2);
  ind = 1:nvar;
  old = x(r,c).var(1); oldi = 1;
  for i = 2:nvar
   new = x(r,c).var(i); 
   if new == old
    ind(i) = 0;
    x(r,c).pow(:,oldi) = x(r,c).pow(:,oldi)+x(r,c).pow(:,i);
   else
    old = new; oldi = i;
   end
  end
  mask = (ind>0);
  if ~all(mask)
   ind = ind(mask);
   x(r,c).var = x(r,c).var(ind);
   x(r,c).pow = x(r,c).pow(:,ind);
  end

  % Ordering of monomials (row-wise)
  [void,indr] = sortrows([sum(x(r,c).pow,2) -x(r,c).pow]);
  x(r,c).pow = x(r,c).pow(indr,:);
  x(r,c).coef = x(r,c).coef(indr);

  % Remove redundant monomials (row-wise)
  nmon = size(x(r,c).pow,1);
  ind = 1:nmon;
  old = x(r,c).pow(1,:); oldi = 1;
  for i = 2:nmon
   new = x(r,c).pow(i,:);
   if ~any(old-new)
    ind(i) = 0;
    x(r,c).coef(oldi) = x(r,c).coef(oldi)+x(r,c).coef(i);
   else
    old = new; oldi = i; 
   end
  end
  mask = (ind>0);
  if ~all(mask)
   ind = ind(mask);
   x(r,c).pow = x(r,c).pow(ind,:);
   x(r,c).coef = x(r,c).coef(ind,:);
  end

  % Remove almost zero monomials (row-wise)
  mask = (abs(x(r,c).coef)>tol);
  if ~all(mask)
   ind = 1:size(ind,2);
   ind = ind(mask);
   if ~isempty(ind)
    x(r,c).pow = x(r,c).pow(ind,:);
    x(r,c).coef = x(r,c).coef(ind,:);
   else % all zero
    x(r,c).pow = 0;
    x(r,c).coef = 0;
   end
  end
  
  % Remove extra variables (column-wise)
  mask = (max(x(r,c).pow,[],1)>0);
  if ~all(mask)
   ind = 1:size(x(r,c).pow,2);
   ind = ind(mask);
   if ~isempty(ind)
    x(r,c).var = x(r,c).var(ind);
    x(r,c).pow = x(r,c).pow(:,ind);
   else % all zero
    x(r,c).var = 0;
    x(r,c).pow = 0;
   end
  end
  
  %if isempty(x(r,c).coef)
  % % Zero monomial
  % x(r,c).var = 0;
  % x(r,c).pow = 0;
  % x(r,c).coef = 0;    
  %elseif isempty(x(r,c).pow)
  % % Constant monomial
  % x(r,c).var = 0;
  % x(r,c).pow = 0;
  %end
  
 end
end

% disp('reduce - end'), keyboard

      
