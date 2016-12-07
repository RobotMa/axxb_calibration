function out = mpol(varargin)
% @MPOL/MPOL - Constructor of class MPOL, multivariable polynomial
%
% MPOL X      creates in the working space a scalar variable X
% MPOL X Y Z  creates scalar variables X,Y,Z
% MPOL X 3    creates a 3x1 vector X of variables X(1),X(2),X(3)
% MPOL X 2 3  creates a 2x3 matrix X of variables X(1,1),X(1,2)..X(2,3)
%
% Equivalently, MPOL('X',N,M) where N and M are DOUBLE integers
% creates an NxM matrix X
%
% MPOL can also be used as a convertor:
% - given a DOUBLE X, MPOL(X) returns the corresponding MPOL object
% - given a scalar measure X (class MEAS), MPOL(X) returns a row vector
%   of all the variables of the measure

% An MPOL object X has the following internal structure:
%
% X.VAR = double vector, variable indices
% X.POW = double array, row = monomial index, column = variable power
% X.COEF = double vector, row = monomial coefficient

% D. Henrion, 29 November 2003
% Last modified on 21 December 2006

global MMM

if nargin > 0

if isa(varargin{1},'char')

 % Create new variable(s)

 if nargout > 0
  error('No output argument allowed')
 end

 % How many variables ?
 nvar = 0;
 while (nvar < nargin) & isvarname(varargin{nvar+1})
   nvar = nvar+1;
 end
 if nvar == 0
  error('Missing input argument')
 end
 
 % Dimensions
 if nvar == nargin
  nrows = 1;
  ncols = 1;
 elseif nvar == nargin-1
  nrows = varargin{nvar+1};
  ncols = 1;
 elseif nvar == nargin-2
  nrows = varargin{nvar+1};
  ncols = varargin{nvar+2};
 else
  error('Invalid number of input arguments')
 end
 
 if isa(nrows,'char')
  nrows = str2num(nrows);
 end
 if isa(ncols,'char')
  ncols = str2num(ncols);
 end
 
 if min([nrows ncols]) < 1
  error('Invalid dimension')
 end
 
 for k = 1:nvar
   
  x = varargin{k};

  % Fields for Matlab variable
  var = cell(nrows,ncols);
  pow = var;
  coef = var;
  
  if isempty(MMM)
   MMM.var = {};
   MMM.indmeas = [];
  end
  
  % Existing variable with new row or column ranges ?
  for i = 1:length(MMM.var)
   % compare with created variable
   i1 = strfind(MMM.var{i},'(');
   if isempty(i1)
    i1 = length(MMM.var{i})+1;
   end
   y = MMM.var{i}(1:i1-1);
   if strcmp(x,y)
    % extract row and column indices
    i3 = strfind(MMM.var{i},')');
    if isempty(i3)
     r = 1;
     c = 1;
    else
     i2 = strfind(MMM.var{i},',');
     if isempty(i2)
      % only row index
      r = eval(MMM.var{i}(i1+1:i3-1));
      c = 1;
     else
      % both
      r = eval(MMM.var{i}(i1+1:i2-1));
      c = eval(MMM.var{i}(i2+1:i3-1));
     end
    end
    if nrows == 1 % scalar or row vector
     if r <= ncols
      var{c,r} = i;
     end
    elseif (r <= nrows) & (c <= ncols) % column vector or matrix
     var{r,c} = i;
    end
   end
  end
  
  % Determine current measure
  if isempty(MMM.indmeas)
   mymeas = 1;
  else
   mymeas = max(MMM.indmeas);
  end;  

  % Generate new variables if required
  newvar = false; m = mymeas;
  for c = 1:ncols
   for r = 1:nrows
    if isempty(var{r,c})
     % new variable
     newvar = true;
     var{r,c} = length(MMM.var)+1;
    else
     mymeas = MMM.indmeas(var{r,c});
    end
    % variable name
    if min(ncols,nrows) > 1 % matrix
     y = [x '(' int2str(r) ',' int2str(c) ')'];
    elseif ncols > 1 % column vector
     y = [x '(' int2str(c) ')']; 
    elseif nrows > 1 % row vector
     y = [x '(' int2str(r) ')']; 
    else % scalar
     y = x;
    end
    MMM.var{var{r,c}} = y;
    % Set measure
    MMM.indmeas(var{r,c}) = mymeas;
    % Set remaining fields
    pow{r,c} = 1;
    coef{r,c} = 1;
   end 
  end

  % If new variables were generated,
  % initialize moments of current measure
  if newvar
   if isfield(MMM,'M')
    if length(MMM.M) >= m
      MMM.M{m} = [];
     end
   end
  end

  y = struct('var',var,'pow',pow,'coef',coef);
  y = mpol(y); % call constructor

  assignin('caller',x,y);

 end % for k 

 % no output argument assigned
 
elseif nargin == 1

 x = varargin{1};

 if isa(x,'double')
 
  % Convert from DOUBLE to MPOL

  if isreal(x)
     
   [nrows,ncols] = size(x);
   var = cell(nrows,ncols);
   pow = var;
   coef = var;
   for r = 1:nrows
    for c = 1:ncols
     var{r,c} = 0;
     pow{r,c} = 0;
     coef{r,c} = x(r,c);
    end
   end
   
   x = struct('var',var,'pow',pow,'coef',coef);
   x = mpol(x); % call constructor

  else
    
   error('Complex coefficients not implemented')
   
  end

 elseif isa(x,'meas')

   % Return variables of a measure
   if max(size(x)) > 1
    error('Conversion possible only for scalar measure')
   end
   im = indmeas(x);
   iv = find(MMM.indmeas==im);
   nv = length(iv);
   var = cell(nv,1); pow = var; coef = var;
   for r = 1:nv
    var{r} = iv(r);
    pow{r} = 1;
    coef{r} = 1;
   end
   x = struct('var',var,'pow',pow,'coef',coef);
   x = mpol(x); % call constructor

 elseif isa(x,'struct') 
   
   % Constructor - internal use only
   
   superiorto('double');
   x = class(x,'mpol');
   
 end
 
 out = x;

else

  error('Invalid syntax')

end

else % empty output

 out = struct('var',[],'pow',[],'coef',[]); 
 out = class(out,'mpol');

end


  
