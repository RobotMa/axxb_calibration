%AXXB - Fixing Temporal Misalignment

%Required function list:
%AB_gen().m
%noise_Gauss().m
%param_extract().m
%se3_vec().m
%so3_vec().m

clear; clc; close all;


% Editable Variables
%------------------------------------------------------

num = 50;	% Number of steps

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

nstd = 0;	% Gaussian Noise standard deviation Range

shift = 0;  % Step shift

n = 1;      % VP(n)

window = 0; % target correlation area

model = 5;  % Noise model


t2 = (0:(2*pi)/((num+shift)):2*pi);
twist = 0.0*sin(16*t2);

ElipseParam = [10, 20, 30];

%------------------------------------------------------


x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x)); % Generate a Random X



%% Computation Loops
%---------------------------------------------------------------------------------------------------------

A = [];
B = [];

Mean = [0;0;0;0;0;0];

z = randn(6,6);
Cov = 0.9*eye(6,6); % why choose 0.9 ??

% x=randn(3,1);
% x=x/norm(x);
% X=[expm(so3_vec((pi/2)*x)) [1;2;3]; [0 0 0] 1];

[A, B] = AB_genRand(X, Mean, Cov, num);

% PA=randperm(size(A,3));
% PB=randperm(size(B,3));

PA = (1:size(A,3));
PB = (1:size(B,3));

% probably a different way for permutation from that in Main_BatchMethod.m
for i = 1:length(PA)

    if rand <= 0.05
        index = randi(50,1);
        PA([i index]) = PA([index i]);       
    end
end

for i = 1:length(PB)

    if rand <= 0.05
        index = randi(50,1);
        PB([i index]) = PB([index i]);       
    end
    
end

A_perm = A(:,:,PA);
B_perm = B(:,:,PB);

[MA, SigA] = distibutionProps(A_perm);
[MB, SigB] = distibutionProps(B_perm);


[VA, DA] = eig(SigA(1:3,1:3));
[VB, DB] = eig(SigB(1:3,1:3));

Q1 = eye(3);
Q2 = [-1 0 0; 0 -1 0; 0 0  1];
Q3 = [-1 0 0; 0  1 0; 0 0 -1];
Q4 = [ 1 0 0; 0 -1 0; 0 0 -1];

Rx_solved(:,:,1) =  VA*Q1*VB';
Rx_solved(:,:,2) =  VA*Q2*VB';
Rx_solved(:,:,3) =  VA*Q3*VB';
Rx_solved(:,:,4) =  VA*Q4*VB';
Rx_solved(:,:,5) = VA*-Q1*VB';
Rx_solved(:,:,6) = VA*-Q2*VB';
Rx_solved(:,:,7) = VA*-Q3*VB';
Rx_solved(:,:,8) = VA*-Q4*VB';

[~, Na, ~, ~] = param_extract(MA); % Ill condition: theta_A = 0
[~, Nb, ~, ~] = param_extract(MB); % Ill condition: theta_B = 0
na = so3_vec(Na);
nb = so3_vec(Nb);

for i = 1:8
    if ( abs(det(Rx_solved(:,:,i))-1) < 0.001 ) && ( norm(na-Rx_solved(1:3,1:3,i)*nb) < 0.1 )
        Rx = Rx_solved(:,:,i);       
   end
end


tx_temp = so3_vec(((Rx'*SigA(1:3,1:3)*Rx)^-1*(SigB(1:3,4:6)-Rx'*SigA(1:3,4:6)*Rx))');
tx1 = -Rx*tx_temp

tx_temp = so3_vec((SigB(4:6,1:3)-Rx'*SigA(4:6,1:3)*Rx)*(Rx'*SigA(1:3,1:3)*Rx)^-1);
tx2 = -Rx*tx_temp


[X_kron] = axb_KronSolve(A_perm,B_perm)


%----------------------------------------------------------------------------------------------------------------