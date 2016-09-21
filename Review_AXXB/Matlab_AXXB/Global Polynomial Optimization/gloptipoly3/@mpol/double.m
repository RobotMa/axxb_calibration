function v = double(p)
% @MPOL/DOUBLE - Evaluate polynomial
%
% DOUBLE(P) evaluates polynomial P at the point(s)
% on which the measure of P is supported.
%
% If the measure is supported on several points,
% then V = DOUBLE(P) returns a 3D array such
% that V(:,:,K) is the value of P at point number K
%
% See also @MPOL/ASSIGN

% D. Henrion, 11 April 2004
% Last modified on 5 January 2007
  
global MMM

if isempty(p)
 v = [];
 return
end

% Only one measure
measp = indmeas(p);
if length(measp) > 1
 error('Several measures associated with input polynomial')
end

if ~isfield(MMM,'M')
 error('Undefined measure: cannot evaluate polynomial')
elseif length(MMM.M) < measp
 error('Undefined measure: cannot evaluate polynomial')
elseif measp > 0
 if ~isfield(MMM.M{measp},'sol')
  error('Measure with undefined support: cannot evaluate polynomial')
 end
end

if measp == 0 % constant
  
 [nr,nc] = size(p);
 v = zeros(nr,nc);  
 for r = 1:nr
  for c = 1:nc
   v(r,c) = coef(p(r,c));
  end
 end
 
else % polynomial
 
 % Finite support
 x = MMM.M{measp}.sol;   

 if isempty(x)
  error('Empty measure support: cannot evaluate polynomial')
 end

 N = size(x,3);
 [nr,nc] = size(p);
 v = zeros(nr,nc,N);

 for k = 1:N
  for r = 1:nr
   for c = 1:nc 

    measp = indmeas(p(r,c));
    
    if measp == 0 % constant
    
     v(r,c,k) = coef(p(r,c));
   
    else % polynomial
      
     varp = indvar(p(r,c));
     coefp = coef(p(r,c));
     nmon = size(coefp,1);
     nvar = MMM.M{measp}.tnvar;
     powp = zeros(nmon,nvar);
     ind = MMM.M{measp}.relmask(varp);
     if ~all(ind)
      error(['Measure with some unassigned variables. ' 13 ...
            'Cannot evaluate polynomial']);
     end
     powp(:,ind) = pow(p(r,c));
     v(r,c,k) = coefp'*prod(repmat(reshape(x(:,:,k),1,nvar),nmon,1).^powp,2);

    end % if measp
   
   end % for r
  end % for c
 end % for k

end

 
