function [ X, MeanA, MeanB] = batchSolve(A, B, opt, nstd_A, nstd_B)
% BATCHSOLVE: solve for X given the bacths of {A} and {B}
% opt:  
%    - true: the distribution of the noise on {A} and {B} is known to be 
%            Gaussian in Lie algebra
%    - false: no a prior knowledge of the noise is known


% A half mex version of the batchSolve

[a1,a2,a3]  = size(A);
A_mex = reshape(A, a1, a2*a3);
B_mex = reshape(B, a1, a2*a3);

[ MeanA, SigA ] = distibutionPropsMex_mex(A_mex); %_mex
[ MeanB, SigB ] = distibutionPropsMex_mex(B_mex); %_mex

% 
% Update SigA and SigB if the distribution of the noise is used in the
% modeling, namely, (f_A*n_A*delta_X)(H) = (delta_X*f_B*n_B)(H)
% where the Lie algebra of n_A has zero mean and covariance of 
% nstd_A*eye(6,6)
if opt
    if isscalar(nstd_A) && isscalar(nstd_B)
        SigA = SigA - nstd_A*eye(6, 6);
        SigB = SigB - nstd_B*eye(6, 6);
    else
        SigA = SigA - diag(nstd_A);
        SigB = SigB - diag(nstd_B);
    end
end

% New Batch augmented 
% [MeanA, ~] = mean_Taylor_1st_mex( A_mex );
% [MeanB, ~] = mean_Taylor_1st_mex( B_mex );

[ VA, ~ ] = eig( SigA(1:3,1:3) );
[ VB, ~ ] = eig( SigB(1:3,1:3) );

Q1 = eye(3);
Q2 = [-1 0 0; 0 -1 0; 0 0 1];
Q3 = [-1 0 0; 0 1 0; 0 0 -1];
Q4 = [1 0 0; 0 -1 0; 0 0 -1];

Rx_solved(:,:,1) = VA*Q1*VB';
Rx_solved(:,:,2) = VA*Q2*VB';
Rx_solved(:,:,3) = VA*Q3*VB';
Rx_solved(:,:,4) = VA*Q4*VB';
Rx_solved(:,:,5) = VA*-Q1*VB';
Rx_solved(:,:,6) = VA*-Q2*VB';
Rx_solved(:,:,7) = VA*-Q3*VB';
Rx_solved(:,:,8) = VA*-Q4*VB';

[~, Na, ~, ~] = param_extract(MeanA);
[~, Nb, ~, ~] = param_extract(MeanB);
na = so3_vec(Na);
nb = so3_vec(Nb);

min = inf;
for i = 1:8
    if (abs(det(Rx_solved(:,:,i))-1)<0.001) && (norm(na-Rx_solved(1:3,1:3,i)*nb) < min)
        min = norm(na-Rx_solved(1:3,1:3,i)*nb);
        Rx = Rx_solved(:,:,i);
   end
end

tx_temp = so3_vec(((Rx'*SigA(1:3,1:3)*Rx)^-1*(SigB(1:3,4:6)-Rx'*SigA(1:3,4:6)*Rx))');
tx = -Rx*tx_temp;

% An alternate way of computing tx
% tx_temp = so3_vec(((Rx'*SigA(1:3,1:3)*Rx)^-1*(SigB(1:3,4:6)-Rx'*SigA(1:3,4:6)*Rx)));
% tx = Rx*tx_temp;

X = [Rx tx; [0 0 0] 1];

end