function varargout = msol(P,options)
% @MSDP/MSOL - Solve moment SDP problem
%
% Given a moment SDP problem P (class MSDP) previously defined by MSDP,
% the instruction
% 
%    [STATUS,OBJ,M] = MSOL(P)
%
% returns a STATUS flag (class DOUBLE), the value OBJ (class DOUBLE)
% of the objective function, the measures M (array of class MEAS)
% associated with P.
%
% Flag STATUS can take the following values:
% -1 if the moment SDP problem is infeasible or could not be solved;
%  0 if the moment SDP problem could be solved but it is impossible
%    to detect global optimality and to extract support points for
%    measures M, in which case OBJ is a suboptimum on the global
%    optimum of the original moment optimization problem;
% +1 if the moment SDP problem could be solved, global optimality
%    is certified and support points are extracted for measures M,
%    in which case OBJ is the global optimum of the original
%    moment optimization problem.
%  
% When STATUS == +1, the global optimizers can be extracted
% with the instruction DOUBLE(M), see @MEAS/DOUBLE.

% D. Henrion, 7 April 2004
% Last modified on 23 April 2010

global MMM

mset('init'); % builds up global structure MMM

if MMM.verbose
 disp(['GloptiPoly ' gloptipolyversion]);
 disp('Solve moment SDP problem')
 disp('*****************************************************')
end

if length(P.indep) == 0

 if MMM.verbose
  disp('No independent variables, solution is explicit')
 end
 
 y = zeros(0,1);

 failure = false;
 infeasibleprimal = false;
 infeasibledual = false;

else
    
% ---------------
% Call SDP solver
% ---------------

if ~MMM.yalmip

 % ------
 % SeDuMi
 % ------

 if exist('sedumi') ~= 2
  error('SeDuMi is not properly installed')
 end

 % parameters
 if isfield(MMM,'pars')
  pars = MMM.pars;
 else
  pars = [];
 end
 if ~isfield(pars,'fid')
  pars.fid = double(MMM.verbose);
 end
 
 if MMM.verbose
  disp('Calling SeDuMi')
 end
 
 % call SeDuMi
 [x,y,info] = sedumi(P.A,P.b,P.c,P.K,pars); 

 % status
 failure = (info.numerr == 2);
 infeasibleprimal = (info.pinf == 1);
 infeasibledual = (info.dinf == 1);
 
else

 % ------
 % YAMLIP
 % ------

 if exist('solvesdp') ~= 2
  error('YALMIP is not properly installed')
 end

 % convert moment SDP problem into YALMIP format
 [F,h,y,s] = myalmip(P);
 
 % In order to retrieve some informations on the dual variables I added the
 % field yalmipdata to the structure MMM.
 % Modified by C. Savorgnan on 15 May 2008
 MMM.yalmipdata.F = F;
 MMM.yalmipdata.h = h;
 MMM.yalmipdata.y = y;
 
 % parameters
 if isfield(MMM,'pars')
  options = MMM.pars;
 else
  options = [];
 end
 if ~isfield(MMM,'verbose')
  options.verbose = MMM.verbose;
 end
 
 if MMM.verbose
  disp('Calling YALMIP')
 end

 % call YALMIP
 if s == +1
  % max problem
  diagnostic = solvesdp(F,-h,options);
 else
  % min problem
  diagnostic = solvesdp(F,h,options);
 end

 % status
 failure = (diagnostic.problem < 0);
 infeasibleprimal = (diagnostic.problem == 2);
 infeasibledual = (diagnostic.problem == 1);
 
 % vector of moments
 y = double(y);
 
 if any(isnan(y))
  failure = true;
  y = zeros(size(y));
 end;

end

end

% Solution of SDP moment problem

% max b'y s.t. z = c-A'*y in K
% x = primal vector
% y = dual vector (moments)
z = P.c-P.A*y; % z = slack variables
P.sdpobj = P.objsign*(P.objshift+P.b*y); % objective function
status = -1; % diagnostic = failure

% Store vectors of moments
mvec = P.Ar(:,1)+P.Ar(:,P.indep)*y;
for mm = P.indmeas
 MMM.M{mm}.mvec = mvec(MMM.M{mm}.begind-1+(1:MMM.M{mm}.nm));
end

% Clear out previous measure supports
for mm = P.indmeas
 MMM.M{mm}.sol = [];
end
  
if MMM.verbose
 disp('*****************************************************')
end

% ----------
% Diagnostic
% ----------

feas = true; % feasibility

if failure

 feas = false;  
 if MMM.verbose
  disp('Failure when solving SDP problem');
 end

else

 if infeasibleprimal
  if MMM.verbose
   disp('Solver suspects primal infeasibility')
   disp('SDP problem may be unbounded')
   disp('Try to enforce additional bound constraints')
  end
  % unbounded SDP problem
  % update objective value accordingly
  P.sdpobj = P.objsign*Inf;
 end
 
 if infeasibledual
  if MMM.verbose
   disp('Solver suspects dual infeasibility')
   disp('SDP problem may be infeasible')
   disp('Try to scale problem variables')
  end
 end

end

if feas

 % Check feasibility

 if MMM.verbose
  fprintf('Check feasibility (eps = %.4e):\n',MMM.testol);
 end
 res = checksdp(P,y); % check dual only

 if res < -MMM.testol
  feas = false;
  if MMM.verbose
   fprintf('  Infeasible SDP: residual = %.4e\n',res);
  end
 elseif res < 0
  if MMM.verbose
   fprintf('  Marginally feasible SDP: residual = %.4e\n',res);
  end
 elseif MMM.verbose
  disp('  Feasible SDP');
 end

 % Check norm of solution

 nm = norm(y);
 if MMM.verbose
  fprintf('Check Euclidean norm of solution (max = %.4e):\n',MMM.maxnorm);
  fprintf('  Norm = %.4e\n', nm);
 end
 if nm > MMM.maxnorm
  feas = false;
  if MMM.verbose
   disp('  SDP problem may be unbounded');
   disp('  Try to enforce additional bound constraints')
  end
 end

end;

globopt = false;

if feas % If SDP problem is feasible
    
 % ***********************
 % Check global optimality
 %
 % 1. Check first order moments - objective function and feasibility
 % 2. If not successful, check successive ranks of moment matrices
 %
 % ***********************

 status = 0; % SDP problem could be solved
 
 % 1. Check first order moments for problems with only one measure
 % and with no moment or support substitutions:
 % if reaching the SDP objective and feasible,
 % then global optimum was reached

 globopt = false;
 nmeas = length(P.indmeas);

 if (nmeas == 1) & (size(P.Ar,1) == length(P.indep)+1)
     
  mm = P.indmeas;
  nvar = MMM.M{mm}.nvar; % active variables
  % first order moment vector
  sol = zeros(MMM.M{mm}.tnvar,1);
  MMM.M{mm}.mass = MMM.M{mm}.mvec(1); % mass
  zeromass = false;
  if MMM.M{mm}.mass < eps % mass
   zeromass = true;
   reach = false;
   feas = false;
   if MMM.verbose
    disp(['Nonpositive mass for measure ' int2str(P.indmeas)]);
   end
  else
   % extract solution
   x = MMM.M{mm}.mvec(1+(1:nvar)) / MMM.M{mm}.mass;
   sol(MMM.M{mm}.mask) = x;
   MMM.M{mm}.sol = sol;
  end
 
  if ~zeromass
   if MMM.verbose
    fprintf('Check first order moments (abs tol = %.4e):\n',MMM.testol);
   end
   % Testing objective and constraints at the solution
   [reach,feas] = checkpoly(P,1);
   globopt = all(reach & feas);
  end
  
 end

 if ~globopt
  
  % 2. Check ranks of moment matrices to detect global optimality
  
  for mm = P.indmeas
   MMM.M{mm}.sol = []; % remove previously computed solution
   MMM.M{mm}.mass = 1;
  end
  
  if MMM.verbose
   fprintf('Check ranks of moments matrices (rel gap svd = %.4e):\n',...
	   MMM.ranktol);
  end

  rankcheck = false(1,nmeas);
  
  for m = 1:nmeas
   
   mm = P.indmeas(m); % measure
   if MMM.verbose
    disp(['  Measure ' int2str(mm)]);
    disp(['    Rank shift = ' int2str(P.rankshift(m))]);
   end

   % largest moment matrix
   ind = P.indmmat(m,1):P.indmmat(m,2);
   nmm = sqrt(length(ind));
   MM = reshape(z(ind),nmm,nmm);
   % mmass = MM(1,1);
   
   if MMM.M{mm}.mass < eps
     
    disp('    Nonpositive moment matrix');

   else
  
    nvar = MMM.M{mm}.nvar;
    kmax = MMM.M{mm}.ord; % number of embedded moment matrices 
  
    U = cell(1,kmax); S = cell(1,kmax);
    rankM = zeros(1,kmax);

    oldrank = 1;
    rankdiff = 0;
    
    k = 0;
    while (k < kmax) & ~rankcheck(m)
     k = k + 1;
     nm = MMM.T(nvar,kmax).bin(nvar,k+2); % all monomials
     indepu = MMM.M{mm}.indep(1:nm);
     nm = sum(indepu); % keep only independent monomials
     % SVD of reduced moment matrix
     [U{k},S{k}] = svd(MM(1:nm,1:nm)); 
     % Detect rank drop
     S{k} = diag(S{k}); n = length(S{k});
     drop = find(S{k}(2:n) ./ S{k}(1:n-1) < MMM.ranktol);
     if ~isempty(drop)
      rankM(k) = drop(1);
     else
      rankM(k) = n;
     end
     if MMM.verbose
      fprintf(['    Moment matrix of order %2d has size %2d ' ...
 	      'and rank %2d\n'], k, size(U{k},1),rankM(k));
     end
     % Store Cholesky factor
     MMM.M{mm}.U = U{k}(:,1:rankM(k))*diag(sqrt(S{k}(1:rankM(k))));
     MMM.M{mm}.indepu = indepu; 
     % Check rank condition (flat extension)
     if rankM(k) <= oldrank,
      rankdiff = rankdiff + 1;
     else
      rankdiff = 0;
     end
     if (rankdiff >= P.rankshift(m)) & ~rankcheck(m)
      rankcheck(m) = true;
     end
     oldrank = rankM(k);
    end; % while

   end; % if mass
    
  end; % for all measures
  
  globopt = all(rankcheck);
   
  if MMM.verbose
   if globopt
    disp('  Rank conditions may ensure global optimality');
   else
    disp('  Rank conditions cannot ensure global optimality');
   end
  end

  % *****************
  % Extract solutions
  % *****************

  if MMM.verbose
   fprintf('Try to extract solutions (rel tol basis detection = %.4e):\n',...
       MMM.pivotol);
  end;

  nbsol = zeros(nmeas,1);
  
  for m = 1:nmeas % for each measure..
 
   mm = P.indmeas(m);
   
   if MMM.verbose
    disp(['  Measure ' int2str(mm)]);
   end

   if MMM.M{mm}.mass < eps

    disp('    Nonpositive mass');

   else

    mext(meas(mm)); % extract solutions
   
    sol = MMM.M{mm}.sol; % retrieve solutions
    maxerr = MMM.M{mm}.maxerr; % relative error
    if isempty(sol)
     nbsol(m) = 0;
    else
     nbsol(m) = size(sol,3);
    end
   
    if nbsol(m) == 0
 
     % no solution could be extracted
  
     if MMM.verbose
      disp('    Incomplete basis - no solution extracted');
      disp('    Global optimality cannot be ensured');
     end
  
    else
   
     if MMM.verbose
      fprintf('    Maximum relative error = %.4e\n',maxerr);
      if nbsol(m) == 1
       disp('    1 solution extracted');
      elseif nbsol(m) > 1
       disp(['    ' int2str(nbsol(m)) ' solutions extracted']);
      end
     end
   
    end
  
   end % zero mass
 
  end % for each measure
  
  % *************************************
  % Check validity of extracted solutions
  % *************************************

  if ~all(nbsol==nbsol(1))
    
   if MMM.verbose
    disp('Inconsistent number of solutions amongst respective measures')
   end
   
   % Remove all solutions
   for mm = P.indmeas
    MMM.M{mm}.sol = [];
   end
   nbsol = 0;

  else
    
   nbsol = nbsol(1);
    
  end

  if nbsol > 0

   if MMM.verbose
    fprintf('Check extracted solutions (abs tol = %.4e):\n',MMM.testol);
   end

   % Test objective and constraints at the solutions
   [reach,feas] = checkpoly(P,nbsol);
   
   % Keep only valid solutions
   for mm = P.indmeas
    MMM.M{mm}.sol = MMM.M{mm}.sol(:,:,(reach & feas));
   end
   if isempty(MMM.M{mm}.sol)
    nbsol = 0;
   else
    nbsol = size(MMM.M{mm}.sol,3);
   end
   
  end
  
  if nbsol == 0
   if MMM.verbose
    disp('No globally optimal solution could be extracted')
   end
   globopt = false;
  elseif nbsol == 1
   if MMM.verbose
    disp('1 globally optimal solution extracted')
   end
   globopt = true;
  elseif nbsol > 1
   if MMM.verbose
    disp([int2str(nbsol) ' globally optimal solutions extracted'])
   end
   globopt = true;
  end

 end % if globopt

 if globopt
  status = 1;
 end
 
end % if feas

if MMM.verbose
 if status == -1
  disp('Moment SDP could not be solved')
 elseif status == 0
  disp('Global optimality cannot be ensured')
 else
  disp('Global optimality certified numerically')
 end
end

% Output measures
M(1) = meas(P.indmeas(1));
for m = 2:length(P.indmeas)
 M = [M meas(P.indmeas(m))];
end

% Output arguments
if nargout > 0
 varargout = {status,P.sdpobj,M};
end


% End of main function MSOL

% *******************
% Auxiliary functions
% *******************

function res = checksdp(P,y)
% Compute dual residual of an SDP problem
  
z = P.c-P.A*y;
res = inf;
shift = 0;
if P.K.f > 0
 % equalities
 res = min(res,-max(abs(z(shift+(1:P.K.f)))));
 shift = shift+P.K.f;
end
if P.K.l > 0 
 % LP
 res = min(res,min(z(shift+(1:P.K.l))));
 shift = shift+P.K.l;
end
if sum(P.K.q) > 0
 % QP
 for k = 1:length(P.K.q)
  res = min(res,z(shift+1)-norm(z(shift+(2:P.K.q(k)))));
  shift = shift+P.K.q(k);
 end
end
if sum(P.K.s) > 0
 for k = 1:length(P.K.s) 
  % SDP
  Z = zeros(P.K.s(k));
  Z(:) = z(shift+(1:P.K.s(k)^2));
  res = min(res,min(eig(Z)));
  shift = shift+P.K.s(k)^2;
 end
end

function [reach,feas] = checkpoly(P,nbsol)
% Test objective and constraints at the solution(s)
% of an already solved SDP moment problem
%
% Evaluate objective function
% Check support constraints
% Discard moment constraints

global MMM

% Evaluate objective at the solution
if ~isempty(P.mobj)
 p = split(P.mobj); 
 mp = indmeas(P.mobj);
 n = length(p);
 m = ones(n,1);
 v = zeros(n,1,nbsol);
 for k = 1:n
  if mp(k) > 0
   m(k) = double(mass(mp(k))); % mass
  end
  w = double(p(k));
  v(k,:,:) = w; % value(s)
 end
 polyobj = zeros(1,1,nbsol);
 for k = 1:nbsol
  polyobj(:,:,k) = P.objsign*m'*v(:,:,k);
 end
else
 polyobj = [];
end

% Evaluate equality constraints entrywise
neq = length(P.msupceq);
polyceq = zeros(neq,1,nbsol);
if neq > 0
 for k = 1:neq
  w = double(P.msupceq(k));
  polyceq(k,:,:) = w;
 end
else
 polyceq = []; 
end

% Evaluate inequality constraints entrywise
nge = length(P.msupcge);
polycge = zeros(nge,1,nbsol);
if nge > 0
 for k = 1:nge
  w = double(P.msupcge(k));
  polycge(k,1,:) = w;
 end
 else
 polycge = [];
end

reach = true(nbsol,1);
feas = true(nbsol,1);

% Check each solution
for i = 1:nbsol
  
 if MMM.verbose
  disp(['  Solution ' int2str(i)])
 end

 % Reaching the objective to absolute tolerance ?
 reach(i) = true;
 if ~isempty(polyobj)
   reach(i) = (abs(polyobj(:,:,i)-P.sdpobj) < MMM.testol);
   if MMM.verbose
    fprintf('    SDP objective = %.4e\n',P.sdpobj);
    if reach
     disp('    Solution reaches same objective');
    else
     fprintf('    Solution reaches different objective = %.4e\n',polyobj(:,:,i));
    end
   end
 end

 % Check feasibility of support equality constraints
 if ~isempty(polyceq)
  feas(i) = feas(i) & all(abs(polyceq(:,:,i)) < MMM.testol) ;
 end
 
 % Check feasibility of support inequality constraints
 if ~isempty(polycge)
  feas(i) = feas(i) & all(-polycge(:,:,i) < MMM.testol);
 end
 
 if ~isempty(polyceq) | ~isempty(polycge)
  if MMM.verbose
   if feas(i)
    disp('    Solution is feasible');
   else
    disp('    Solution is infeasible');
   end;
  end
 end

end % for all solutions
