% This main fucntion tests the new idea for handling noise by using the
% distribution as a priori known information
%
clear;
clc;
close all;

%% Add file dependencies
addpath ../../../rvctools/robot
addpath ../../../rvctools/common
addpath ../../../kinematics/kinematics/screws
addpath ../../../kinematics/kinematics/util
addpath ../../../kinematics/kinematics/lie_group
addpath ../../../axxb_calibration/matlab/new_mean/codegen/mex/distibutionPropsMex

%% Initialize Parameters
num = 50; % Number of steps

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

cov = eye(6,6);

std = 0.1;

nstd = 0.01; % Gaussian Noise standard deviation Range

n_trials = 2; %60

x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x)); % Generate a Random X

skip = 100; %10;

perm_rate = 0:skip:100;

n_rate = length(perm_rate);

A_noise = [];
Ainv_noise = [];
noiseModel = 2;
B = [];
j = 0;
opt = 2;
optPDF = 1; % select the distribution for A and B

%% Initialize error containers
Roterror_batch_all = zeros(n_trials, n_rate);
Roterror_batch_new_1_all = zeros(n_trials, n_rate);
Roterror_batch_new_2_all = zeros(n_trials, n_rate);

Tranerror_batch_all = zeros(n_trials, n_rate);
Tranerror_batch_new_1_all = zeros(n_trials, n_rate);
Tranerror_batch_new_2_all = zeros(n_trials, n_rate);

t_Error_avg = [];

%% Computation Loops


rotErr1 = [];
tranErr1 = [];
covErr1 = [];
covErr1Rot = [];

rotErr2 = [];
tranErr2 = [];
covErr2 = [];
covErr2Rot = [];

covX1Err = [];
meanX1Err = [];

%% Apply noise on Ai only
for k = 1: 200
    [A, B] = generateAB(num, optPDF, X, gmean, std*cov);
    
    % distribution of noise_on_A ~ (gmean, nstd*cov)
    A_noise = sensorNoise(A, gmean, nstd, noiseModel);
    
    % Compute SigA_noise
    [a1,a2,a3]  = size(A_noise);
    A_mex = reshape(A_noise, a1, a2*a3);
    [MeanA_noise, SigA_noise] = distibutionPropsMex_mex(A_mex);
    
    % Compute MeanB and SigB
    B_mex = reshape(B, a1, a2*a3);
    [MeanB, SigB] = distibutionPropsMex_mex(B_mex);
    
    % Compute adjoint matrix of Xinv and MeanBinv
    adXinv = SE3inv_Ad(X);
    adBinv = SE3inv_Ad(MeanB);
    
    % Compute the covariance of the noise correcting term: n_A_prime
    % Lie algebra basis
    E1(:,:,1)=[0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0];
    E1(:,:,2)=[0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0];
    E1(:,:,3)=[0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
    E1(:,:,4)=[0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0];
    E1(:,:,5)=[0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0];
    E1(:,:,6)=[0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
    N_A_prime = [];
    
    for i = 1:a3
        
        temp_se3 = zeros(4,4);
        twist = mvg(gmean, nstd*cov, 1);
        
        % Assume the noise is really small
        for j = 1:6
            temp_se3 = temp_se3 + twist(j)*A_noise(:,:,i)*E1(:,:,j)/A_noise(:,:,i);
        end
        N_A_prime(:,:,i) = expm(temp_se3);
    end
    
    N_A_mex = reshape(N_A_prime, a1, a2*a3);
    [MeanN_A_prime, SigN_A_prime] = distibutionPropsMex_mex(N_A_mex);
    
    % Compute Ainv_noise to get Cov_Ainv
    for s = 1: a3
        Ainv_noise(:,:,s) = inv(A_noise(:,:,s));
    end
    Ainv_mex = reshape(Ainv_noise, a1, a2*a3);
    [MeanAinv_noise, SigAinv_noise] = distibutionPropsMex_mex(Ainv_mex);    
    
    %% Verification of the mean and covariance equations
    % mean
    rotErr1(k) = roterror(MeanA_noise*X, MeanN_A_prime*X*MeanB);
    tranErr1(k) = tranerror(MeanA_noise*X, MeanN_A_prime*X*MeanB);
    rotErr2(k) = roterror(MeanA_noise*X, X*MeanB);
    tranErr2(k) = tranerror(MeanA_noise*X, X*MeanB);
    
    covDiff1 = adXinv*SigA_noise*adXinv' - adBinv*adXinv*SigN_A_prime*adXinv'*adBinv' + SigB;
    covErr1(k) = norm(covDiff1, 'fro');
    covErr1Rot(k) = norm(covDiff1(1:3,1:3), 'fro');
    
    covDiff2 = adXinv*SigA_noise*adXinv' - SigB;
    covErr2(k) = norm(covDiff2, 'fro');
    covErr2Rot(k) = norm(covDiff2(1:3,1:3), 'fro');
    
    covX1 = adBinv*adXinv*SigAinv_noise*adXinv'*adBinv' + SigB;
    covX1Err(k) = norm(covX1, 'fro');
    
    meanX1 = X - MeanAinv_noise*X*MeanB;
    meanX1Err(k) = norm(meanX1, 'fro');
    % covariance
end

fprintf('Rotation error of the noise correction method is %d \n', mean(rotErr1));
fprintf('Translation error of the noise correction method is %d \n', mean(tranErr1));
fprintf('Rotation error of the normal method is %d \n', mean(rotErr2));
fprintf('Translation error of the normal method is %d \n', mean(tranErr2));
fprintf('##-----------------------------------------------------## \n')
fprintf('Norm of covariance difference for the noise correction method is %d \n', mean(covErr1));
fprintf('Norm of covariance difference is %d \n', mean(covErr2));
fprintf('##-----------------------------------------------------## \n')
fprintf('Norm of rotation part of covariance difference for the noise correction method is %d \n', mean(covErr1Rot));
fprintf('Norm of rotation part of covariance difference is %d \n', mean(covErr2Rot));
fprintf('##-----------------------------------------------------## \n')

%%
if false
    for j = 1:n_rate
        
        t_Error = [];
        
        for k = 1:n_trials
            
            [A, B] = generateAB(num, optPDF, X, gmean, cov);
            
            PA = (1:size(A,3));
            PB = (1:size(B,3));
            
            for i = 1:length(PA)
                if rand <= 0.01*perm_rate(j)
                    index = randi(num,1);
                    PA([i index]) = PA([index i]);
                end
            end
            
            A_perm = A(:, :, PA);
            B_perm = B(:, :, PB);
            
            [X_batch, MA, MB] = batchSolve(A_perm, B_perm); %batchSolveNew(A_perm, B_perm, 5); %
            [X_batch_New_1, ~, ~, ~, ~, ~] = batchSolveNew(A_perm, B_perm, 1);
            [X_batch_New_2, MA_New, MB_New, ~, ~, t_error] = batchSolveNew(A_perm, B_perm, 4); % 2 is changing step size ,4 is M=M(I+X)
            
            %% Store Errors
            Roterror_batch_all(k,j) = roterror(X_batch, X);
            Roterror_batch_new_1_all(k, j) = roterror(X_batch_New_1,X);
            Roterror_batch_new_2_all(k, j) = roterror(X_batch_New_2,X);
            
            Tranerror_batch_all(k,j) = tranerror(X_batch, X);
            Tranerror_batch_new_1_all(k, j) = tranerror(X_batch_New_1,X);
            Tranerror_batch_new_2_all(k, j) = tranerror(X_batch_New_2,X);
            
        end
        
    end
    
    %%
    Roterror_batch_avg = mean(Roterror_batch_all);
    Roterror_batch_new_1_avg = mean(Roterror_batch_new_1_all);
    Roterror_batch_new_2_avg = mean(Roterror_batch_new_2_all);
    
    Tranerror_batch_avg = mean(Tranerror_batch_all);
    Tranerror_batch_new_1_avg = mean(Tranerror_batch_new_1_all);
    Tranerror_batch_new_2_avg = mean(Tranerror_batch_new_2_all);
    
    %%
    figure
    scatter((0:skip:100), Roterror_batch_avg, '+');
    hold on
    scatter((0:skip:100), Roterror_batch_new_1_avg, 'o');
    hold on
    scatter((0:skip:100), Roterror_batch_new_2_avg, '*');
    hold off
    xlabel('Percentage of scrambling in the A and B sets')
    ylabel('Rotation error of X')
    legend('Batch Method','New Batch Method 1st Order','New Batch Method 2nd Order', 'Location', 'SouthOutside')
    % axis([0 100 0 4])
    
    figure
    scatter((0:skip:100), Tranerror_batch_avg, '+');
    hold on
    scatter((0:skip:100), Tranerror_batch_new_1_avg, 'o');
    hold on
    scatter((0:skip:100), Tranerror_batch_new_2_avg, '*');
    hold off
    xlabel('Percentage of scrambling in the A and B sets')
    ylabel('Translation error of X')
    legend('Batch Method','New Batch Method 1st Order', 'Ned Batch Method 2nd Order', 'Location', 'SouthOutside')
    axis([0 100 0 0.5])
    
    %%
    figure
    scatter((0:skip:100), Roterror_batch_avg, '+');
    hold on
    scatter((0:skip:100), Roterror_batch_new_1_avg, 'o');
    hold on
    scatter((0:skip:100), Roterror_batch_new_2_avg, '*');
    hold off
    xlabel('Percentage of scrambling in the A and B sets')
    ylabel('Rotation error of X')
    legend('Batch Method', 'New Batch Method 1st Order','New Batch Method 2nd Order','Location', 'SouthOutside')
    
    %%
    figure
    scatter((0:skip:100), Tranerror_batch_new_1_avg, 'o');
    hold on
    scatter((0:skip:100), Tranerror_batch_new_2_avg, '*');
    hold off
    xlabel('Percentage of scrambling in the A and B sets')
    ylabel('Translation error of X')
    legend('New Batch Method 1st Order', 'Ned Batch Method 2nd Order','Location', 'SouthOutside')
end