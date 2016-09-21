function [P,M] = msdp(varargin)
% @MSDP/MSDP - Constructor of class MSDP, moment semidefinite problem
%
% The instruction
%  
%   [P,M] = MSDP(VARARGIN)
%
% generates a moment SDP problem P (class MSDP) with its associated
% measures arranged in a vector M (class MEAS). The moment SDP problem
% is a finite-dimensional truncation (also called relaxation) of
% an infinite-dimensional moment optimization problem consisting of
% support constraints, moment constraints and a moment objective function.
%
% Valid input arguments that can be specified in the comma separated list
% VARARGIN are as follows:
% - SUC = support constraints (class SUPCON);
% - MOC = moment constraints (class MOMCON);
% - OBJ = objective function (class MOMCON);
% - ORD = order of the SDP relaxation (integer of class DOUBLE).
%
% All of these input arguments are optional and can be provided in
% arbitrary order. Default values are as follows:
% - SUC = no support constraints, meaning that all the measures M
%   are supported on the whole Euclidean space;
% - MOC = no moment constraints. In this case, when there is only
%   one measure (LENGTH(M) = 1), it is automatically constrained
%   to be a probability measure, i.e. such that MASS(M) == 1;
% - OBJ = no objective function. Then the sum of the traces of the
%   moment matrices of the measures M is minimized. To avoid this,
%   specify a constant objective function, e.g. OBJ = MIN(MPOL(0))
% - ORD = half the minimum degree over all polynomials defining
%   support constraints, moment constraints and objective function.
%
% When a support or moment constraint is specified with a unique
% left handside monomial, then MSDP performs explicitly moment 
% substitutions to reduce the number of variables in the moment SDP
% problem. The degree of the right handside polynomial must then be
% less than or equal to the degree of the left handside monomial.
%
% See also MSOL

% D. Henrion, 9 January 2004
% Last modified on 25 March 2010

global MMM;

mset('init'); % builds up global structure MMM

if MMM.verbose
 disp(['GloptiPoly ' gloptipolyversion]);
 disp('Define moment SDP problem')
end

% ----------------------------------------------------------------------  
% Parse input arguments
% ----------------------------------------------------------------------  
  
% Extract SDP relaxation order
% Check validity of input arguments

ord = []; % SDP relaxation order
pindmeas = []; % measure indices
pindvar = []; % active variable indices
tnmeas = max(MMM.indmeas); % total number of measures
dmax = -ones(1,tnmeas); % maximum degree wrt each measure
rankshift = ones(1,tnmeas); % rank shift for detecting global optimality

ind = 1:nargin;
for k = 1:nargin
 arg = varargin{k};
 if isa(arg,'double')
  if max(size(arg)) == 1
   if (floor(arg) ~= arg) | (arg <= 0)
    error('Relaxation order must be a positive integer')
   end
   ord = arg; % SDP relaxation order
   ind(k) = [];
  else
   error('Invalid input argument')
  end
 elseif isa(arg,'mpol')
  error('Invalid input polynomial')
 elseif ~isa(arg,'supcon') & ~isa(arg,'momcon')
  error('Invalid input argument')
 end
end
arg = {varargin{ind}}; % keep only SUPCON and MOMCON objects

% Detect objective functions (MOMCON objects of type 'min', 'max')

mobj = []; % row vector splitted wrt measures
objsign = 1; % max = +1, min = -1
for k = 1:length(arg)
 m = arg{k}; t = type(m);
 if isa(m,'momcon') & (strcmp(t,'min') | strcmp(t,'max'))
  if ~isempty(mobj)
   error('Moment objective function is not unique')
  end
  if strcmp(t,'min')
   mobj = -left(m); % moment to be minimized
   objsign = -1;
  else
   mobj = left(m); % to be maximized
  end
  if ~consistent(mobj) % check consistency
   error('Invalid objective function with inconsistent variables and measures')
  end   
  mp = indmeas(mobj); % measures
  if mp % non-constant objective function
   % store measure and variable indices
   pindmeas = [pindmeas mp];
   pindvar = [pindvar indvar(mobj)];
   % degree wrt each measure
   p = split(mobj); % polys wrt each measures
   for r = 1:length(mp)
    dmax(mp(r)) = max(dmax(mp(r)),deg(p(r)));
   end
  end
 end 
end

% Detect entrywise support constraints (SUPCON objects) and extract
% support substitutions which are support equality constraints
% with isolated left handside monomial

msupcge = []; % support inequalities (>=0)
msupceq = []; % support equalities (==0)
msups = []; % support substitutions
for k = 1:length(arg)
 m = arg{k}; 
 if isa(m,'supcon')
  for r = 1:size(m,1)
   for c = 1:size(m,2)
    p = m(r,c); t = type(p);
    lp = left(p); rp = right(p); pp = lp-rp; % polynomials
    if ~consistent(pp) % check consistency
     error('Invalid support constraint with inconsistent variables and measures')
    end
    if indmeas(pp) == 0
     % constant support constraint
     % check consistency
     cp = coef(pp);
     if strcmp(t, 'eq') & cp
      error('Inconsistent support equality constraint')
     elseif strcmp(t, 'ge') & cp < 0
      error('Inconsistent support inequality constraint')
     elseif strcmp(t, 'le') & cp > 0
      error('Inconsistent support inequality constraint')
     end
    else
     % store support constraint   
     mp = indmeas(lp);
     cp = coef(lp);
     if strcmp(t, 'eq') & (length(cp)==1) & (cp(1)==1) & mp
      % only one monomial in LHS =
      % support to be explicitly substituted
      msups = [msups struct('left',lp,'right',rp)];
     elseif strcmp(t, 'eq') % equality
      msupceq = [msupceq pp];
     elseif strcmp(t, 'ge') % inequality
      msupcge = [msupcge pp];
     else % reverse inequality
      msupcge = [msupcge -pp];
     end
     % store measure and variable indices
     newpindmeas = [mp indmeas(rp)];
     pindmeas = [pindmeas newpindmeas];
     pindvar = [pindvar indvar(lp) indvar(rp)];
     % degree wrt each measure
     if mp > 0
      dp = deg(lp);
      dmax(mp) = max(dmax(mp),dp);
      rankshift(mp) = max(rankshift(mp),ceil(dp/2));
     end
     mp = indmeas(rp);
     if mp > 0
      dp = deg(rp);
      dmax(mp) = max(dmax(mp),dp);
      rankshift(mp) = max(rankshift(mp),ceil(dp/2));
     end
    end
   end
  end
 end
end


% Detect moment constraints (MOMCON objects) and extract moment
% substitutions which are moment equality constraints
% with isolated left handside monomial

mmomcge = []; % moment inequalities (>=0)
mmomceq = []; % moment equalities (==0)
mmoms = []; % moment substitutions
for k = 1:length(arg)
 m = arg{k}; t = type(m);
 if isa(m,'momcon') & ~(strcmp(t,'min') | strcmp(t,'max'))
  for r = 1:size(m,1)
   for c = 1:size(m,2)
    p = m(r,c); t = type(p);
    lp = left(p); rp = right(p); % scalar moments
    if ~consistent(lp) | ~consistent(rp)
     error('Invalid moment constraint with inconsistent variables and measures')
    end
    % store measure and variable indices
    newpindmeas = [indmeas(lp) indmeas(rp)];
    if all(newpindmeas==0) % no variables
     % constant moment constraint
     % check consistency
     cp = coef(split(lp)) - coef(split(rp));
     if strcmp(t, 'eq') & cp
      error('Inconsistent moment equality constraint')
     elseif strcmp(t, 'ge') & cp < 0
      error('Inconsistent moment inequality constraint')
     elseif strcmp(t, 'le') & cp > 0
      error('Inconsistent moment inequality constraint')
     end
    else
     % store the moment constraint
     pindmeas = [pindmeas newpindmeas];
     pindvar = [pindvar indvar(lp) indvar(rp)];
     % substitution ?
     lpp = split(lp); cp = coef(lpp(1));
     if strcmp(t,'eq') & (length(lpp)==1) & (length(cp)==1) & (cp(1) == 1) & newpindmeas(1)
      % only one monic monomial in LHS =
      % moment to be explicitly substituted
      mmoms = [mmoms struct('left',lp,'right',rp)];
     elseif strcmp(t, 'eq') % equality
      mmomceq = [mmomceq lp-rp];
     elseif strcmp(t, 'ge') % inequality
      mmomcge = [mmomcge lp-rp];
     else % reverse inequality
      mmomcge = [mmomcge -lp+rp];
     end      
     % degree wrt each measure
     mp = indmeas(lp);
     lp = split(lp); % vector polynomial
     for q = 1:length(lp)
      if mp(q) > 0
       dp = deg(lp(q));
       dmax(mp(q)) = max(dmax(mp(q)),dp);
      end
     end
     mp = indmeas(rp);
     rp = split(rp); % vector polynomial
     for q = 1:length(rp)
      if mp(q) > 0
       dp = deg(rp(q));
       dmax(mp(q)) = max(dmax(mp(q)),dp);
      end
     end
    end
   end
  end
 end
end

% Some statistics

if MMM.verbose
 if isempty(mobj)
  disp('  No objective function')
 else
  disp('  Valid objective function')
 end
 fprintf('  Number of support constraints = %d',... including' ...
      length(msupcge)+length(msupceq)+length(msups));
 if length(msups) == 1
  fprintf(' including 1 substitution');
 elseif length(msups) > 1
  fprintf(' including %d substitutions',length(msups));
 end;
 fprintf('\n');
 fprintf('  Number of moment constraints = %d',... including' ...
       length(mmomcge)+length(mmomceq)+length(mmoms));
 if length(mmoms) == 1
  fprintf(' including 1 substitution');
 elseif length(mmoms) > 1
  fprintf(' including %d substitutions',length(mmoms));
 end;
 fprintf('\n');
end

% ---------------------------------
% Generate moments for each measure
% ---------------------------------

if isempty(pindmeas)
 error('No measure')
end

% Sort and remove duplicate measure indices
m = sort(pindmeas);
d = [m 0]-[0 m];
d = d(2:end-1);
i = 2:length(m);
pindmeas = m([1 i(d>0)]);

% Remove zero measure index
if (length(pindmeas) > 1) & (pindmeas(1) == 0)
 pindmeas = pindmeas(2:end);
end

if pindmeas(end) == 0
 error('No measure');
end

nmeas = length(pindmeas);

% Sort and remove duplicate variable indices
v = sort(pindvar);
d = [v 0]-[0 v];
d = d(2:end-1);
i = 2:length(v);
pindvar = v([1 i(d>0)]);

% Remove zero variable index
if (length(pindvar) > 1 ) & (pindvar(1) == 0)
 pindvar = pindvar(2:end);
end

if pindvar(end) == 0
 error('No variable');
end

% Maximum degree for each measure
dmax = dmax(pindmeas);
rankshift = rankshift(pindmeas);

% Order of SDP relaxation
if isempty(ord)
 ord = ceil(dmax/2);
else
 ord = ord*ones(size(dmax));
end

for m = 1:nmeas % relative measure index
  
  mm = pindmeas(m); % absolute measure index
  
  if MMM.verbose
   disp(['Measure ' int2str(mm)]);
  end

  if dmax(m) > 2*ord(m)
    disp('Some variables are not represented in the relaxation');
    error('Increase relaxation order'); 
  end

  % Generate moments for this measure
  nvm = genmom(mm,pindvar,ord(m));
  if nvm == 0
   error('No active variables for this measure')
  end
  
  if MMM.verbose
   disp(['  Degree = ' int2str(dmax(m))]);
   disp(['  Variables = ' int2str(MMM.M{mm}.nvar)]);
   disp(['  Moments = ' int2str(MMM.M{mm}.nm)]);
  end
 
end

disp(['Relaxation order = ' int2str(max(ord))]);

% ----------------------
% Build the SDP problem
% ----------------------

P = [];

% Algebraic constraints on moments

if isempty(mmomcge) & isempty(mmomceq) & isempty(mmoms)

 % No moment constraints so all measure masses are set to one
 for m = 1:nmeas
  mm = pindmeas(m);
  mmoms = [mmoms struct('left',mass(mm),'right',mom(1,0))];
  if MMM.verbose
   disp(['Mass of measure ' int2str(mm) ' set to one']);
  end
 end

end

% ----------------------------------------------
% Perform substitutions on the vector of moments
% in order to reduce the SDP problem

% Count monomials
for m = 1:nmeas % for each measure..
 mm = pindmeas(m);
 if m == 1
  % Starting indices in vector of all moments
  MMM.M{mm}.begind = 1;
  tnm = MMM.M{mm}.nm; % total number of moments
 else
  MMM.M{mm}.begind = tnm+1;
  tnm = tnm+MMM.M{mm}.nm;
 end
 MMM.M{mm}.indep = true(MMM.M{mm}.nm,1); % independent monomials
end

if MMM.verbose
 disp(['Total number of moments = ' int2str(tnm)]);
end

% Basis matrix of linear relations between moments
Ar = [sparse(tnm,1) speye(tnm)]; % first column = constant term
subs = zeros(tnm,1); % number of substitutions for each variable
conflict = 0; % conflicting substitutions

if ~isempty(mmoms) | ~isempty(msups)

 % --------------------
 % Support substitutions

 if ~isempty(msups)

  if MMM.verbose
   disp('Perform support substitutions');
  end

  % Scalar substitutions

  for i = 1:length(msups)

   % LHS
   lp = msups(i).left;
   mp = indmeas(lp); % scalar measure index
   lp = mpol(lp); % scalar polynomial
   
   % index of variable to be substituted
   lpow = locpow(lp,mp);

   % RHS
   rp = msups(i).right;

   % localization
   degp = max(deg(lp),deg(rp));
   nvar = MMM.M{mp}.nvar;
   nord = MMM.M{mp}.ord;
   % number of localization monomials
   nlm = MMM.T(nvar,nord).bin(nvar,2+2*nord-degp);
   % powers for localization
   mpow = MMM.T(nvar,nord).pow(1:nlm,:);
   % index of variables to be substituted
   lpow = reshape(lpow,1,nvar);
   lpow = reshape(repmat(lpow,nlm,1)+mpow,nlm,1,nvar);
   rind = pow2ind(lpow,mp);

   % powers for linear substitutions
   rpow = locpow(rp,mp);
   rpow = repmat(rpow,1,nlm)+...
	  repmat(reshape(mpow,1,nlm,nvar),size(rpow,1),1);
   % indices of columns for substitutions
   cind = pow2ind(rpow,mp);

   for k = 1:length(rind)
    subs(rind(k)) = subs(rind(k))+1;
    if subs(rind(k)) == 1 % new substitution
     Ar(rind(k),:) = sparse(1,tnm+1);
     Ar(rind(k),cind(:,k)+1) = coef(rp);
    end
    % otherwise discard, hoping that subs. are consistent
   end
  
   % remove linearly dependent monomials
   MMM.M{mp}.indep(rind-MMM.M{mp}.begind+1) = false; 

  end % for i ..

 end % if ~isempty(msups)
 
 % --------------------
 % Moment substitutions

 if ~isempty(mmoms)

  if MMM.verbose
   disp('Perform moment substitutions');
  end

  % Scalar substitutions
  
  for i = 1:length(mmoms)

   % LHS
   lp = mmoms(i).left;
   mlp = indmeas(lp); % scalar measure index
   lp = split(lp); % scalar polynomial
   
   % index of variable to be substituted
   lpow = locpow(lp,mlp); rind = pow2ind(lpow,mlp);

   % RHS
   rp = mmoms(i).right;
   mrp = indmeas(rp); % vector measure indices
   rp = split(rp); % vector polynomial
   
   subs(rind) = subs(rind)+1; 
   if subs(rind) == 1 % new substitution
    Ar(rind,:) = sparse(1,tnm+1);
    for k = 1:length(rp) % linear combination of moments
     if mrp(k) == 0 % constant term     
      Ar(rind,1) = Ar(rind,1)+coef(rp(k));
     else % monomial
      % index for substitution
      rpow = locpow(rp(k),mrp(k)); cind = pow2ind(rpow,mrp(k));
      cp = coef(rp(k))';
      Ar(rind,cind+1) = Ar(rind,cind+1)+cp;
     end
    end
   else % old subs.
    % transform potentially conflicting subs. into
    % explicit moment equality constraint
    mmomceq = [mmomceq mmoms(i).left-mmoms(i).right];
    conflict = conflict+1;   
   end % if
   
  end % for i = ..

 end % if ~isempty(mmoms)
 
 % display substitution mask for debugging
 % char(logical(full(Ar))+char('0'))

 % Detect triangular structure
 if ~any(any(triu(Ar(:,2:end),1))) | ~any(any(tril(Ar(:,2:end),-1)))
  % propagate linear dependence relations
  for c = 1:tnm
   if Ar(c,c+1) == 0
    ind = find(Ar(:,c+1))';
    if ~isempty(ind)
     for r = ind
      k = Ar(r,c+1); Ar(r,c+1) = 0;
      Ar(r,:) = Ar(r,:) + k*Ar(c,:);
     end
    end
   end
  end
 else
  error(['Invalid cyclic substitutions' 13 ...
  'Monomial substitutions should have triangular structure' 13 ...
  'Modify accordingly the sequence of substitutions' 13 ...
  'or replace substitutions constraints with equality constraints']);
 end

 % display substitution mask for debugging
 % char(logical(full(Ar))+char('0'))
  
 if MMM.verbose
  if conflict > 0
   warning([int2str(conflict) ' potentially conflicting moment substitutions' 13 ...
           'replaced with explicit moment equality constraints'])
  end
 end

end % if moment substitutions

% Global mask of independent monomials
indep = 1+find(sum(abs(Ar(:,2:tnm+1))));
nvarlmi = length(indep);

% Linear dependence patterns of monomials for each measure
for m = 1:nmeas % relative measure index
 mm = pindmeas(m); % absolute measure index
 MMM.M{mm}.Ar = Ar(~MMM.M{mm}.indep,:);
end

if MMM.verbose
 if tnm ~= nvarlmi
  disp(['Number of moments after substitutions = ' ...
       int2str(nvarlmi)]);
 end
end
    
% -----------
% Constraints

% first column = constant term
Af = sparse(0,tnm+1); % equality constraints
Al = sparse(0,tnm+1); % scalar inequality constraints
As = sparse(0,tnm+1); % SDP constraints
K = struct('f',0,'l',0,'q',0,'s',[]); % cone structure

% indices for retrieving dual variables
indmomeq = []; % moment equality constraints
indmomge = []; % moment inequality constraints

if MMM.verbose
 disp('Generate moment and support constraints')
end

% indices in moment matrix
indmmat = zeros(nmeas,2); % indices of moment matrices in z

% Moment matrix SDP constraints

for m = 1:nmeas % relative measure index
 
 mm = pindmeas(m); % absolute measure index
 
 nord = MMM.M{mm}.ord;
 nvar = MMM.M{mm}.nvar;
 nmm = MMM.T(nvar,nord).bin(end,nord+2); 
 ind = MMM.M{mm}.indep(1:nmm); % only independent monomials
 nmm = sum(ind); % size of moment matrix
 nmm2 = nmm^2; % number of entries in moment matrix
 mpow = MMM.T(nvar,nord).bas(ind,ind,:); % powers in 3D matrix
 cind = pow2ind(mpow,mm); % indices in vector of moments
 % update SDP constraints
 As = [As;sparse(1:nmm2,cind(:)+1,ones(1,nmm2),nmm2,tnm+1)];
 K.s = [K.s nmm];
 indmmat(m,:) = size(As,1)-[nmm2-1 0];

end

% Bound on the sum of all moments

% if MMM.bound
%  disp(['Bound on the sum of all moments = ' num2str(MMM.bound)]);
%  Alrow = [MMM.bound -ones(1,tnm)];
%  % update inequality constraints
%  indmomeq = [indmomeq; size(Al,1)+[1 size(Alrow,1)]];
%  Al = [Al; Alrow];
%  K.l = K.l + 1;   
% end
 
% Equality moment constraints
 
if ~isempty(mmomceq)
   
  for i = 1:length(mmomceq)
     
   p = split(mmomceq(i)); % scalar moment to vector polynomial
   mp = indmeas(mmomceq(i)); % measure indices
   Afrow = sparse(1,tnm+1); % new equality constraint in A

   for k = 1:length(p) % linear combination of moments
   
    dp = deg(p(k));
    cp = coef(p(k))'; % row vector
    if mp(k) == 0 % scalar constant
     Afrow(1) = Afrow(1) + cp;
    else % polynomial
     nmon = length(cp);
     ppow = locpow(p(k),mp(k)); % powers
     cind = pow2ind(ppow,mp(k)); % indices
     Afrow(cind+1) = Afrow(cind+1) + cp; % constraints
    end;
    
   end

   % update equality constraints
   indmomeq = [indmomeq; size(Af,1)+[1 size(Afrow,1)]];
   Af = [Af; Afrow];
   K.f = K.f + 1;
  end
   
end
 
% Inequality moment constraints
 
if ~isempty(mmomcge)
  
  for i = 1:length(mmomcge)
     
   p = split(mmomcge(i)); % scalar moment to vector polynomial
   mp = indmeas(mmomcge(i)); % measure indices
   Alrow = sparse(1,tnm+1); % new inequality constraint in A
   
   for k = 1:length(p) % linear combination of moments
   
    dp = deg(p(k));
    cp = coef(p(k))'; % row vector
    if mp(k) == 0 % scalar constant
     Alrow(1) = Alrow(1) + cp;
    else
     nmon = length(cp);
     ppow = locpow(p(k),mp(k)); % powers
     cind = pow2ind(ppow,mp(k)); % indices
     Alrow(cind+1) = Alrow(cind+1) + cp; % constraints
    end
    
   end
   
   % update inequality constraints
   indmomge = [indmomge; size(Al,1)+[1 size(Alrow,1)]];
   Al = [Al; Alrow];
   K.l = K.l + 1;
   
  end
   
end
 
% Localize equality support constraints

if ~isempty(msupceq)
  
  for i = 1:length(msupceq)
    
   p = msupceq(i); % scalar polynomial

   dp = deg(p);
   mp = indmeas(p);
   cp = coef(p);
   nmon = size(cp,1);
   ppow = locpow(p,mp);
   nvar = MMM.M{mp}.nvar;
   nord = MMM.M{mp}.ord;
   nlm = MMM.T(nvar,nord).bin(nvar,2+2*nord-dp); % size of loc. vector
   ind = MMM.M{mp}.indep(1:nlm); % keep independent monomials only
   nlm = sum(ind); % number of localization monomials
   % 2D powers for localization
   mpow = MMM.T(nvar,nord).pow(ind,:);
   mpow = reshape(mpow,1,nlm,nvar); % 3D columnwise
   ppow = repmat(mpow,nmon,1)+repmat(ppow,1,nlm); % localize
   cind = pow2ind(ppow,mp); % indices in vector of moments
   cind = reshape(cind,nmon*nlm,1); % columwise
   rind = repmat(1:nlm,nmon,1); % row indices
   cp = repmat(cp,1,nlm); % coefs
   % update equality constraints
   Af = [Af;sparse(rind(:),cind+1,cp(:),nlm,tnm+1)];
   K.f = K.f+nlm;
  end 

end

% Localize inequality support constraints
 
if ~isempty(msupcge)
 
  for i = 1:length(msupcge)

   p = msupcge(i); % scalar polynomial
   
   dp = deg(p);
   mp = indmeas(p);
   cp = coef(p);
   nmon = size(cp,1);
   ppow = locpow(p,mp);
   nvar = MMM.M{mp}.nvar;
   nord = MMM.M{mp}.ord;
   nlm = MMM.T(nvar,nord).bin(nvar,2+(nord-ceil(dp/2))); % size of loc. mat.
   ind = MMM.M{mp}.indep(1:nlm); % keep independent monomials
   nlm = sum(ind); % number of localization monomials
   mpow = MMM.T(nvar,nord).bas(ind,ind,:); % 3D powers for localization
   nlm2 = nlm^2; % total number of elements (with repeated entries)
   mpow = reshape(mpow,1,nlm2,nvar); % 3D columnwise
   ppow = repmat(mpow,nmon,1)+repmat(ppow,1,nlm2); % localize
   cind = pow2ind(ppow,mp); % indices in vector of moments
   cind = reshape(cind,nmon*nlm2,1); % columwise
   rind = repmat(1:nlm2,nmon,1); % row indices
   cp = repmat(cp,1,nlm2); % coefs
   % update SDP constraints
   if nlm2 == 1 % scalar SDP = linear constraint
    Al = [Al;sparse(rind(:),cind+1,cp(:),nlm2,tnm+1)];
    K.l = K.l+nlm2;
   else % matrix SDP
    As = [As;sparse(rind(:),cind+1,cp(:),nlm2,tnm+1)];
    K.s = [K.s nlm];
   end 
  
  end
  
end

% Objective function

objshift = 0; % constant shift
obj = sparse(1,tnm);

if ~isempty(mobj)

  if any([indvar(mobj) indmeas(mobj)]) % not a constant
    
   mo = indmeas(mobj); % vector measure indices
   po = split(mobj); % vector polynomial
  
   for k = 1:length(po) % linear combination of moments
    if mo(k) == 0 % constant term
     objshift = objshift + double(po(k));
    else % monomial
     % powers to indices
     powo = locpow(po(k),mo(k)); cind = pow2ind(powo,mo(k));
     % store coeffs
     obj(cind) = coef(po(k));
    end
   end
  
  else % constant
    
   if MMM.verbose
    disp('Constant objective function: generate feasibility problem')
   end
    
   objshift = coef(split(mobj));

  end
 
else % no objective function
     % so minimize trace of moment matrix of first measure 

 if MMM.verbose
  disp('No objective function')
  disp(['Minimize trace of moment matrix of measure ' ...
	int2str(pindmeas(1))])
 end

 mo = pindmeas(1); % first measure
 powb = MMM.T(MMM.M{mo}.nvar,MMM.M{mo}.ord).bas; % 3D powers
 nr = size(powb,1);
 powo = zeros(nr,1,size(powb,3)); 
 for r = 1:nr % extract diagonal entries
  powo(r,1,:) = powb(r,r,:); % in 3D power vector
 end
 cind = pow2ind(powo,mo); % indices
 obj(cind) = 1; % all ones
 
end


% Reduce constraints
A = [Af;Al;As];
c = A(:,1)+A(:,2:end)*Ar(:,1);
A = A(:,2:end)*Ar(:,indep);
b = obj*Ar(:,indep);
objshift = objshift + obj*Ar(:,1);

% Update indices
indmmat = indmmat + K.f + K.l + K.q;
indmomge = indmomge + K.f;

% Display some info on SDP problem

if MMM.verbose
 disp('Generate moment SDP problem')
end

% --------------------------------------
% Parameters relative to the SDP problem
% --------------------------------------

% SDP problem data in SeDuMi dual format
% max b'*y s.t. z = c-A*y \in K
P.A = -A; P.b = b; P.c = c; P.K = K;

% Linearly independent monomials
P.indep = indep;
% Dependence pattern
P.Ar = Ar;

% Indices of measures
P.indmeas = pindmeas;
% Indices of moment matrices in z
P.indmmat = indmmat;
% Indices of moment equality constraints in z
P.indmomeq = indmomeq;
% Indices of moment inequality constraints in z
P.indmomge = indmomge;

% Support constraints used to check feasibility in MSOL
P.msupceq = msupceq;
P.msupcge = msupcge;
% Moment constraints used when retrieving multipliers
P.mmomceq = mmomceq;
P.mmomcge = mmomcge;
% Data used to check optimality in MSOL
P.mobj = mobj; % objective function
P.objshift = objshift; % constant shift
P.objsign = objsign; % max = +1, min = -1
% Rank shift to detect global optimality in MSOL
P.rankshift = rankshift;
% SDP relaxation orders
P.order = ord;

% Numerical value of the objective function
P.sdpobj = [];

% Measures in vectorized MEAS format
M = [];
for k = 1:nmeas
 M = [M meas(pindmeas(k))];
end

% Constructor
P = class(P,'msdp');

% End of main function MDEF
% -----------------------------------------------------------------

% Auxillary functions


