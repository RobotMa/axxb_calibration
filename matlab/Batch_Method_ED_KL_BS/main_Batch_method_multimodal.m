% This main fucntion compares with three Batch methods with three 
% corresponding definition (representations) of mean
% 
clear; 
clc; 
close all;

%% Add file dependencies
addpath ../../../rvctools/robot
addpath ../../../rvctools/common
addpath ../../../kinematics/kinematics/lie_group
addpath ../../../axxb_calibration/matlab/new_mean/codegen/mex/distibutionPropsMex

%% Initialize Parameters
num = 50; % No. of data for each set

gmean = [0; 0; 0; 0; 0; 0];	% Gaussian Noise Mean

coeff1 = 0.1; % std 

cov = coeff1*eye(6,6);

noise_on_cov = 0.10; % 20% noise level

coeff2 = coeff1*noise_on_cov;

cov_noise = coeff2*eye(6,6);

n_trials = 60; %60

x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x)); % Generate a Random X

skip = 10; %10;

perm_rate = 0:skip:100;

n_rate = length(perm_rate);

optPDF = 3; % select the distribution for A and B

optNoise = true; % apply noise onto the data

%% Initialize error containers
Roterror_batch_all = zeros(n_trials, n_rate);
Roterror_kron_all = zeros(n_trials, n_rate);
Roterror_kron_2_all = zeros(n_trials, n_rate);

Tranerror_batch_all = zeros(n_trials, n_rate);
Tranerror_kron_all = zeros(n_trials, n_rate);
Tranerror_kron_2_all = zeros(n_trials, n_rate);

A_mean = zeros(4,4,3);
B_mean = zeros(4,4,3);

%% Computation Loops


for j = 1:n_rate
    
    t_Error = [];
    
    for k = 1:n_trials
        
        [A, B] = generateAB(num, 4, X, gmean, cov);
        [A1, B1] = generateAB(num, optPDF, X, gmean, cov);
        [A2, B2] = generateAB(num, optPDF, X, gmean, cov);
        
        if optNoise
            A_noise = sensorNoise(A, gmean, coeff2, 6);
            A1_noise = sensorNoise(A1, gmean, coeff2, 6);
            A2_noise = sensorNoise(A2, gmean, coeff2, 6);
            B_noise = sensorNoise(B, gmean, coeff2, 6);
            B1_noise = sensorNoise(B1, gmean, coeff2, 6);
            B2_noise = sensorNoise(B2, gmean, coeff2, 6);
        else
            A_noise = A;
            A1_noise = A1;
            A2_noise = A2;
            B_noise = B;
            B1_noise = B1;
            B2_noise = B2;
        end
        
        % waitbar((j*k)/(100*trials))
        
        PA = (1:size(A,3));
        PB = (1:size(B,3));
        
        for i = 1:length(PA)
            if rand <= 0.01*perm_rate(j)
                index = randi(num,1);
                PA([i index]) = PA([index i]);
            end
        end
        
        A_perm = A_noise(:, :, PA);
        B_perm = B_noise(:, :, PB);
        
        [X_batch, MA, MB] = batchSolve(A_perm, B_perm); %batchSolveNew(A_perm, B_perm, 5); %
        
        [A_mean(:,:,1), SigA] = getMeanCov(A_noise);
        [A_mean(:,:,2), SigA1] = getMeanCov(A1_noise);
        [A_mean(:,:,3), SigA2] = getMeanCov(A2_noise);
        [B_mean(:,:,1), SigB] = getMeanCov(B_noise);
        [B_mean(:,:,2), SigB1] = getMeanCov(B1_noise);
        [B_mean(:,:,3), SigB2] = getMeanCov(B2_noise);
        
        [X_kron] = axb_KronSolve(A_mean, B_mean); %
        [X_kron_2] = axb_KronSolve(A_perm, B_perm); %
        
        %% Store Errors
        Roterror_batch_all(k,j) = roterror(X_batch, X);
        Roterror_kron_all(k, j) = roterror(X_kron, X);
        Roterror_kron_2_all(k, j) = roterror(X_kron_2, X);
        
        Tranerror_batch_all(k,j) = tranerror(X_batch, X);
        Tranerror_kron_all(k, j) = tranerror(X_kron,X);
        Tranerror_kron_2_all(k, j) = tranerror(X_kron_2,X);
                
    end    
end

%%
Roterror_batch_avg = mean(Roterror_batch_all);
Roterror_kron_avg = mean(Roterror_kron_all);
Roterror_kron_2_avg = mean(Roterror_kron_2_all);

Tranerror_batch_avg = mean(Tranerror_batch_all);
Tranerror_kron_avg = mean(Tranerror_kron_all);
Tranerror_kron_2_avg = mean(Tranerror_kron_2_all);

%%
figure
scatter((0:skip:100), Roterror_batch_avg, '+');
hold on
scatter((0:skip:100), Roterror_kron_avg, '^');
% hold on
scatter((0:skip:100), Roterror_kron_2_avg, '*');
hold off
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Rotation error of X')
legend('Batch Method', 'Kronecker Product', 'Kronecker Product 2', 'Location', 'SouthOutside')

figure
scatter((0:skip:100), Tranerror_batch_avg, '+');
hold on
scatter((0:skip:100), Tranerror_kron_avg,'^');
% hold on
scatter((0:skip:100), Tranerror_kron_2_avg,'*');
hold off
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Translation error of X')
legend('Batch Method', 'Kronecker Product', 'Kronecker Product 2', 'Location', 'SouthOutside')
