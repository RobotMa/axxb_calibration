function y = coef(x)
% @MPOL/COEF - Internal use only

% Returns the coefficient vector of polynomial X% Performs scaling appropriately

% D. Henrion, 30 November 2003
% Last modified by D. Henrion, 14 January 2008
  
global MMM

x = x(1); % scalar polynomials only

m = indmeas(x); % measure index
if length(m) > 1
 error('Scaling not available for polynomials refering to several measures')
end

% scaling ?
scale = false;
if isfield(MMM,'M')
  if m > 0
   if length(MMM.M) >= m
    if ~isempty(MMM.M{m}) & isfield(MMM.M{m},'indvar') & isfield(MMM.M{m},'scale')
      if any(MMM.M{m}.scale ~= 1)
       scale = true;
     end
    end
   end
  end
end

if scale
 % with scaling
 S = MMM.M{m}.scale(MMM.M{m}.relmask(x.var))';
 y = x.coef.*prod(repmat(S,size(x.pow,1),1).^x.pow,2);
else
 % without scaling
 y = x.coef;
end

