function mset(varargin)
% MSET - GloptiPoly parameters settings
%
% MSET = displays parameters
% MSET CLEAR = delete all existing variables and set default parameters
% MSET CLEARMEAS = delete all existing measures
% MSET DEFAULT = set default parameters
% MSET(PARAMETER,VALUE) = set a given parameter  
%
% If PARAMETER is a character string, it can take the following values:
%
% - 'VERBOSE': VALUE = FALSE for no screen output (default TRUE)
% - 'YALMIP': VALUE = TRUE for using YALMIP as an interface (default FALSE).
%   The SDP solver is then the one configured under YALMIP with the
%   parameter structure PARS, see below. If VALUE = 0 the SDP solver
%   SeDuMi is used directly without calling YALMIP.
% - 'RANKTOL': VALUE = relative gap between singular values for
%   evaluating ranks of moment matrices when detecting global optimality
%   and extracting solutions (default 1e-3)
% - 'PIVOTOL': VALUE = relative accuracy for basis computation by Gaussian
%   elimination with pivoting when extracting solutions (default 1e-6)
% - 'TESTOL': VALUE = absolute accuracy for checking objective function
%   and feasibility of constraints in SDP problem (default 1e-3)
% - 'MAXNORM': VALUE = maximum allowed norm of the vector of moments.
%   Useful to detect unbounded or ill-scaled problems (default 1e6)
%
% IF PARAMETER is a structure, it is forwarded to SeDuMi or YALMIP.

% D. Henrion, 11 April 2004
% Last modified on 30 September 2008
  
global MMM

% default parameter values

verbosedefault = true; % display information
yalmipdefault = false; % do not use YALMIP
ranktoldefault = 1e-3; % rel acc for evaluating ranks of moment matrices
pivotoldefault = 1e-6; % rel acc for basis computation via Gaussian elim
testoldefault = 1e-3; % abs acc for testing feas of poly ineq
maxnormdefault = 1e6;  % maximum norm to detect unbounded problems
  
kmax = length(varargin); k = 1;

if isempty(MMM)
 MMM.var = {};
 MMM.indmeas = [];
 MMM.meas = 1;
 MMM.M = {};
 MMM.T = [];
end

% initialisation
    
if ~isfield(MMM,'verbose')
 MMM.verbose = verbosedefault;
end
if ~isfield(MMM,'yalmip')
 MMM.yalmip = yalmipdefault;
end
if ~isfield(MMM,'ranktol')
 MMM.ranktol = ranktoldefault;
end
if ~isfield(MMM,'pivotol')
 MMM.pivotol = pivotoldefault;
end
if ~isfield(MMM,'testol')
 MMM.testol = testoldefault;
end
if ~isfield(MMM,'maxnorm')
 MMM.maxnorm = maxnormdefault;
end

if kmax == 0
 % display parameter values
 disp(['VERBOSE = ' int2str(MMM.verbose)]);
 disp(['YALMIP = ' num2str(MMM.yalmip)]);
 disp(['RANKTOL = ' num2str(MMM.ranktol)]);
 disp(['PIVOTOL = ' num2str(MMM.pivotol)]);
 disp(['TESTOL = ' num2str(MMM.testol)]);
 disp(['MAXNORM = ' num2str(MMM.maxnorm)]);
end

while k <= kmax

 par = varargin{k};
 if isstruct(par)

  % Parameter structure to forward to SeDuMi or YALMIP
  MMM.pars = par;
  k = k+1;

 else

  % Other parameter
  par = lower(par);
  switch par
  
  case 'default' 
   
   % Default parameters

   MMM.verbose = verbosedefault; 
   MMM.yalmip = yalmipdefault; 
   MMM.ranktol = ranktoldefault;
   MMM.pivotol = pivotoldefault;
   MMM.testol = testoldefault;
   MMM.maxnorm = maxnormdefault;

   k = k+1;
       
  case {'reset','clear'}
 
   % Delete all the existing variables and measures

   for i = 1:length(MMM.var)
    i1 = strfind(MMM.var{i},'(');
     if isempty(i1)
      i1 = length(MMM.var{i})+1;
     end
     evalin('caller',['clear ' MMM.var{i}(1:i1-1)]);
   end
   MMM.var = {};
   MMM.indmeas = [];
   MMM.meas = 1;
   MMM.M = {};
   MMM.T = [];
   mset default

   k = k+1;
  
  case {'clearmeas','resetmeas'}
  
   % Delete all the existing measures
  
   MMM.indmeas = ones(1,length(MMM.var));
   MMM.meas = 1;
   MMM.M = {};
   MMM.T = [];
  
   k = k+1;

  case {'verbose','ranktol','pivotol',...
	'testol','maxnorm','yalmip'}
  
   % Set a parameter
  
   if length(varargin) <= k
    error('Invalid syntax')
   end
  
   par2 = varargin{k+1};
   if isa(par2,'char')
    par2 = str2num(lower(par2));
   elseif ~isa(par2,'double') & ~isa(par2, 'logical')
    error('Invalid parameter value')
   end
   MMM = setfield(MMM,par,par2);
   k = k+2; 

  case 'init'

   k = k+1;

  otherwise
   
   error('Invalid argument')
  
  end
 end
end
