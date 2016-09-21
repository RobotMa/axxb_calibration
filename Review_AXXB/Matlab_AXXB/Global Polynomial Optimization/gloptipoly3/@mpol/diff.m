function d = diff(p,v)
% @MPOL/DIFF - Differentiate
%
% DIFF(P,V) differentiates a scalar, vector or matrix polynomial P
% with respect to the variable V
%
% If V is a vector of several variables, then DIFF(P,V) returns
% the Jacobian of the scalar or vector polynomial P with respect to V,
% that is, the matrix whose (i,j)-th entry is DIFF(P(i),V(j))
%
% DIFF(P) returns the Jacobian with respect to all variables in P

% D. Henrion, 21 April 2006

if nargin < 2
 v = indvar(p);
else
 if ~isa(v,'mpol')
  error('Invalid second input argument')
 end
 v = indvar(v);
end

[nr,nc] = size(p);
if min(nr,nc) == 0

  d = [];

else
  
 if (min(nr,nc) > 1) & (length(v) > 1)
  error('Cannot generate Jacobian of a matrix polynomial')
 end

 n = nr*nc;
 nv = length(v);
 d = p(:);
 for i = 2:nv % for each variable
  d = [d d(:,1)];
 end
 for ip = 1:n
  vp = indvar(p(ip));
  cp = p(ip).coef;
  pp = p(ip).pow;
  for iv = 1:nv
   ic = find(vp == v(iv));
   if isempty(ic) % not a variable
    d(ip,iv) = mpol(0);
   else % differentiate
    ir = find(pp(:,ic) > 0);
    if isempty(ir) % constant
     d(ip,iv) = mpol(0);
    else     
     d(ip,iv).coef = cp(ir).*pp(ir,ic);
     d(ip,iv).pow = pp(ir,:);
     d(ip,iv).pow(:,ic) = d(ip,iv).pow(:,ic)-1;
     d(ip,iv) = reduce(d(ip,iv));
    end
   end
  end
 end
 if min(nr,nc) > 1 % and hence nv = 1
  d = reshape(d,nr,nc); % matrix
 end
end

 
