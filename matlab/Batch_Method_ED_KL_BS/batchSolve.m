function [ X, MeanA, MeanB] = batchSolve(A, B)

% A half mex version of the batchSolve

[a1,a2,a3]  = size(A);
A_mex = reshape(A, a1, a2*a3);
B_mex = reshape(B, a1, a2*a3);

[ MeanA, SigA ] = distibutionPropsMex_mex(A_mex); %_mex
[ MeanB, SigB ] = distibutionPropsMex_mex(B_mex); %_mex

% New Batch augmented 
% [MeanA, ~] = mean_Taylor_1st_mex( A_mex );
% [MeanB, ~] = mean_Taylor_1st_mex( B_mex );

% [ MeanA, SigA ] = distibutionProps(A, 0);
% [ MeanB, SigB ] = distibutionProps(B, 0);

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

X = [Rx tx; [0 0 0] 1];

end