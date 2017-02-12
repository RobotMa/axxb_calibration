function [ X, MeanA, MeanB, SigA, SigB, t_error ] = batchSolveNew(A, B, opt)
%% Mixed version for solving AX = XB

%%
[a1,a2,a3]  = size(A);
A_mex = reshape(A, a1, a2*a3);
B_mex = reshape(B, a1, a2*a3);

n_search = int16(2*10^2);

if opt == 1

    [MeanA, ~] = mean_Taylor_1st_mex( A_mex ); %_mex
    [MeanB, ~] = mean_Taylor_1st_mex( B_mex ); %_mex

elseif opt == 2

    MeanA = mean_Taylor_2nd_adv( A_mex, 0, n_search ); %_mex
    MeanB = mean_Taylor_2nd_adv( B_mex, 0, n_search ); %_mex
    
elseif opt == 3
    
    [ MeanA, ~ ] = distibutionProps( A, 1 );
    [ MeanB, ~ ] = distibutionProps( B, 1 );
    
elseif opt == 4
    
    MeanA = mean_Taylor_2nd_adv_recursive( A_mex, 1, n_search ); %_mex
    MeanB = mean_Taylor_2nd_adv_recursive( B_mex, 1, n_search ); %_mex
    
elseif opt == 5
    
    MeanA = mean_Taylor_2nd_adv_original( A_mex, 0, n_search ); %_mex
    MeanB = mean_Taylor_2nd_adv_original( B_mex, 0, n_search ); %_mex
    
end
% Use the rotation of 2nd Taylor approximation and the 
% translation of the old Batch 
% Integrated version
% [ MeanA_old, ~ ] = distibutionPropsMex_mex(A_mex);
% [ MeanB_old, ~ ] = distibutionPropsMex_mex(B_mex);
% MeanA(1:3,4) = MeanA_old(1:3,4);
% MeanB(1:3,4) = MeanB_old(1:3,4);

SigA = zeros(6,6);
SigB = zeros(6,6);


for i = 1:size(A,3)
    
    SigA = SigA + se3_vec(logm(MeanA^(-1)*A(:,:,i)))*se3_vec(logm(MeanA^(-1)*A(:,:,i)))';
    SigB = SigB + se3_vec(logm(MeanB^(-1)*B(:,:,i)))*se3_vec(logm(MeanB^(-1)*B(:,:,i)))';
    
end


% 2nd order approximation of the covariance doesn't give a reasonable
% result
% for i = 1:size(A, 3)
% 
%     A_i = A(:,4*(i-1)+1:4*i);
%     P_A = ( MeanA\A_i - eye(4) ) - 1/2*( MeanA\A_i - eye(4) )^2;
%     SigA = SigA + se3_vec( P_A )*se3_vec( P_A )';
% end
% 
% for i = 1:size(B, 3)
% 
%     B_i = B(:,4*(i-1)+1:4*i);
%     P_B = ( MeanB\B_i - eye(4) ) - 1/2*( MeanB\B_i - eye(4) )^2;
%     SigB = SigB + se3_vec( P_B )*se3_vec( P_B )';
% end

SigA = SigA*(1/size(A,3));
SigB = SigB*(1/size(B,3));

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
% Rx = Rx_solved(:,:,1); % added by haiyuan
for i = 1:8
    if (abs(det(Rx_solved(:,:,i))-1)<0.001) && (norm(na-Rx_solved(1:3,1:3,i)*nb) < min)
        min = norm(na-Rx_solved(1:3,1:3,i)*nb);
        Rx = Rx_solved(:,:,i);
%         fprintf('1 current counter is %d \n',i);
    else
%         fprintf('2 current counter is %d \n',i);
    end
    
end

tx_temp = so3_vec(((Rx'*SigA(1:3,1:3)*Rx)^-1*(SigB(1:3,4:6)-Rx'*SigA(1:3,4:6)*Rx))');
tx = -Rx*tx_temp;

X = [Rx tx; [0 0 0] 1];

t_error = (MeanA(1:3,1:3) - eye(3))*tx - Rx*MeanB(1:3,4) + MeanA(1:3,4);
t_error = norm(t_error);

end