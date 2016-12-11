function MM = mext(MM)
% @MEAS/MEXT - Extract the discrete support of a measure
% from its moment matrix
%
% The command M = MEXT(M) attempts to extract the discrete support
% of measure M from its moment matrix
%
% The support points can then be retrieved with the instruction DOUBLE(M)
%
% See also MEXT

% D. Henrion, 4 August 2004
% Last modified on 27 October 2009

global MMM
  
ind = MM.meas; % measure index
nvar = MMM.M{ind}.nvar; % number of active variables
ord = MMM.M{ind}.ord; % order

% Relative tolerance for pivoting
pivotol = MMM.pivotol;

% Relative tolerance for rank detection
ranktol = MMM.ranktol;

if ~isfield(MMM.M{ind},'U')
 error('Cannot extract discrete support of this measure')
end

% Retrieve Cholesky factor of moment matrix
U = MMM.M{ind}.U; % Cholesky factor
nb = size(U,2); % rank of moment matrix

% Retrieve indexing tables
bin = MMM.T(nvar,ord).bin; % binomial coef table
pow = MMM.T(nvar,ord).pow; % matrix of powers of monomials

% output arguments
x = [];
maxerr = [];

% Reduce U to column echelon form via Gaussian elimination with
% column pivoting, identify monomial basis B(1)..B(NB) in U (pivots)

[U,basis] = cef(U,pivotol);

nm = size(pow,1); % total number of monomials
indepu = MMM.M{ind}.indepu; % independent monomials

if ~all(indepu)

 % Basis w.r.t. all monomials
 basind = find(indepu)';
 basis = basind(basis); 

 % Add rows corresponding to linearly dependent monomials
 oldU = U; U = zeros(nm,nb); U(indepu,:) = oldU;
 rm = sum(~indepu); % dependent monomials
 Ar = MMM.M{ind}.Ar(1:rm,1:(nm+1)); % linear dependence pattern
 Ar(:,2) = Ar(:,2)+Ar(:,1); % assume mass is one and combine with constant term
 Ar = Ar(:,2:end); % remove constant term
 U(~indepu,:) = Ar*U;

end

% For each first degree monomial C(I), I=1..NB extract the coefficient
% matrix N(I) of monomials C(I)*B(1)..C(I)*B(NB) in basis B(1)..B(NB)

N = cell(1,nvar);
i = 0; fail = 0;
while ~fail & (i < nvar)
 i = i + 1;
 % build multiplication matrix
 % for monomial C(I) in basis B(1)..B(NB)
 mpow = pow(basis,:); % power basis
 mpow(:,i) = mpow(:,i) + 1; % monomial C(I)
 % retrieve indices
 mind = ones(size(basis));
 for k = 1:nvar
  mind = mind + bin(nvar+1-k,1+sum(mpow(:,k:nvar),2));
 end
 fail = any(mind > size(U,1)); % moment not available - incomplete basis
 if ~fail
  N{i} = U(mind,:);
 end;
end;

if ~fail

 % Compute common eigenvalues of multiplication matrices
	
 % Random combinations of multiplication matrices
 coef = rand(nvar,1); coef = coef / sum(coef);
 M = zeros(nb);
 for i = 1:nvar
  M = M + coef(i)*N{i};
 end;
	
 % Ordered Schur decomposition of M      
 [Q,T] = orderschur(M);
 if isempty(T)

  x = []; % complex eigenvalues = failure

 else
	
  % Retrieve optimal vectors
  % It is assumed than there is no multiple root
  x = zeros(nvar,1,nb);
  maxerr = -Inf;
  for i = 1:nb
    for j = 1:nvar
     x(j,1,i) = Q(:,i)'*N{j}*Q(:,i);
    end
  end

  % Compute maximum relative error
  for i = 1:nb
   % Evaluate all the monomials
   nm = size(U,1);
   u = prod(repmat(x(:,:,i)',nm,1).^pow(1:nm,:),2);
   % Compare with the monomials from the basis
   v = prod(repmat(x(:,:,i)',nb,1).^pow(basis,:),2);
   err = max(abs(u-U*v)./(1+abs(u))); % 1+abs(u) to avoid zero dividend
   if err > maxerr,
    maxerr = err;
   end
  end
 end
 
end;

if ~isempty(x)
 for i = 1:size(x,3)
  % assign active variables in cell array of solutions
  MMM.M{ind}.sol(:,:,i) = zeros(MMM.M{ind}.tnvar,1);
  MMM.M{ind}.sol(MMM.M{ind}.mask,:,i) = x(:,:,i);
 end
end

MMM.M{ind}.maxerr = maxerr;

% End of main function MEXT
  
% *******************
% Auxiliary functions
% *******************

function [A,basis] = cef(A,tol)
% The instruction
%
%  [E,BASIS] = CEF(A)
%
% computes a column echelon form E of matrix A
% and returns basis row indices in vector BASIS
%
% The relative threshold for column pivoting can be specified
% as an additional input argument
%
% The reduction is performed by Gaussian elimination with
% column pivoting, based on Matlab's RREF routine
  
[n,m] = size(A);

% Loop over the entire matrix.
i = 1; j = 1; basis = [];
while (i <= m) & (j <= n)
 % Find value and index of largest element in the remainder of row j
 [p,k] = max(abs(A(j,i:m))); k = k+i-1;
 if (p <= tol)
  % The row is negligible, zero it out
  A(j,i:m) = zeros(1,m-i+1,1);
  j = j + 1;
 else
  % Remember row index
  basis = [basis j];
  % Swap i-th and k-th columns
  A(j:n,[i k]) = A(j:n,[k i]);
  % Find a non-negligible pivot element in the column
  found = 0;
  while ~found
   if abs(A(j,i)) < tol*max(abs(A(:,i)))
    j = j + 1;
    found = (j == n);
   else
    found = 1;
   end;
  end;
  if j <= n,
   % Divide the pivot column by the pivot element
   A(j:n,i) = A(j:n,i)/A(j,i);
   % Subtract multiples of the pivot column from all the other columns
   for k = [1:i-1 i+1:m]
    A(j:n,k) = A(j:n,k) - A(j,k)*A(j:n,i);
   end
   i = i + 1;
   j = j + 1;
  end
 end
end

function [U,T] = orderschur(X)
% [U,T] = ORDERSCHUR(X) computes the real Schur decomposition X = U*T*U'
% of a matrix X with real eigenvalues sorted in increasing order along
% the diagonal of T
%
% Algorithm: perform unordered Schur decomposition with Matlab's SCHUR
% function, then order the eigenvalues with Givens rotations, see
% [Golub, Van Loan. Matrix computations. 1996]

[U,T] = schur(X,'complex');
if norm(imag(diag(T))) > 1e-8 % should be real
 T = []; % otherwise return empty matrix
else
 U = real(U); T = real(T);
 n = size(X,1);

 order = 0;
 while ~order, % while the order is not correct
  order = 1;
  for k = 1:n-1,
   if T(k,k) - T(k+1,k+1) > 0,
    order = 0; % diagonal elements to swap
    % Givens rotation
    [c,s] = givens(T(k,k+1),T(k+1,k+1)-T(k,k));
    T(k:k+1,k:n) = [c s;-s c]'*T(k:k+1,k:n);
    T(1:k+1,k:k+1) = T(1:k+1,k:k+1)*[c s;-s c];
    U(1:n,k:k+1) = U(1:n,k:k+1)*[c s;-s c];
   end;
  end;
 end; % while
end
 
function [c,s] = givens(a,b)
% Givens rotation for ordered Schur decomposition
if b == 0
 c = 1; s = 0;
else
 if abs(b) > abs(a)
  t = -a/b; s = 1/sqrt(1+t^2); c = s*t;
 else
  t = -b/a; c = 1/sqrt(1+t^2); s = c*t;
 end
end

