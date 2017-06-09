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
num = 50; % number of samples in a cloud

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

cov = eye(6,6);

std = 0.1;    % std for generating the noise-free sample cloud

% ratio_std = 0:0.005:0.05; % noise level 0.5% - 5% on std
ratio_std   = [0, 0.001, 0.002, 0.005, 0.01, 0.02];
ratio_std_B = 2*[0, 0.001, 0.002, 0.005, 0.01, 0.02];

nstd = ratio_std*std; % Gaussian Noise standard deviation Range
nstd_B = ratio_std_B*std; % Gaussian Noise standard deviation Range

n_trials = 50; %60

x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x)); % Generate a Random X

noiseModel = 7; % Select the noise model which has zero mean and nstd as the
% standard deviation on lie aglebra

optPDF = 1; % Select the distribution for generating {A} and {B} sample cloud.
% They will have zero mean and std as the standard deviation in
% lie algebra

std_vec = [1, 1, 1, 1, 1, 1];

%% Data Initialization
% For simplicity, we only apply noise onto {A}
A_noise = zeros(4, 4, num); % A with noise
B = zeros(4, 4, num);       % B will be kept noise free
Ainv_noise = zeros(4, 4, num); % Calculate {A^-1}

rotErr1 = [];
tranErr1 = [];
covErr1 = [];
covErr1Rot = [];

rotErr2 = [];
tranErr2 = [];
covErr2 = [];
covErr2Rot = [];

covErr3 = [];

covX1Err = [];
meanX1Err = [];

%% Apply noise on Ai only
for m = 1:length(nstd)
    
    for k = 1: n_trials
        
        % Generate num samples of A and B given the ground truth X,
        % type of distribution optPDF, mean gmean and covariance std*cov
        [A, B] = generateAB(num, optPDF, X, gmean, std*cov);
        
        % Apply noise onto A
        A_noise = sensorNoise(A, gmean, nstd(m)*std_vec, noiseModel);
        
        % Apply noise onto B
        B_noise = sensorNoise(B, gmean, nstd_B(m)*std_vec, noiseModel);
        
        [ X1, ~, ~] = batchSolve(A_noise, B_noise, false, 0, 0);
        
        [ X2, ~, ~] = batchSolve(A_noise, B_noise, true, nstd(m)*std_vec, nstd_B(m)*std_vec);
        
        
        %% Verification of the mean and covariance equations
        % ------- Mean Equation Error Analysis ------- %
        % Rotation error of the new model
        rotErr1(k,m) = roterror(X1, X);
        % Translation error of the new model
        tranErr1(k,m) = tranerror(X1, X);
        % Rotation error of the no-noise model
        rotErr2(k,m) = roterror(X2, X);
        % Translation error of the no-noise model
        tranErr2(k,m) = tranerror(X2, X);
        
    end
    
end
%%
figure
plot(ratio_std, mean(rotErr1, 1),'b')
hold on
plot(ratio_std, mean(rotErr2, 1),'r')
hold on
scatter(ratio_std, mean(rotErr1, 1),'b')
hold on
scatter(ratio_std, mean(rotErr2, 1),'r')
legend('noisy model','noise-free model')
xlabel('$\sigma_{noise}/ \sigma_{model}$','Interpreter','latex')
ylabel('Error in R')

figure
plot(ratio_std, mean(tranErr1, 1),'b')
hold on
plot(ratio_std, mean(tranErr2, 1),'r')
hold on
scatter(ratio_std, mean(tranErr2, 1),'r')
hold on
scatter(ratio_std, mean(tranErr1, 1),'b')
legend('noisy model','noise-free model')
xlabel('$\sigma_{noise}/ \sigma_{model}$','Interpreter','latex')
ylabel('Error in t')

%%
fprintf('Rotation error of the noise correction method is %d \n', mean(rotErr1, 1));
fprintf('Translation error of the noise correction method is %d \n', mean(tranErr1, 1));
fprintf('Rotation error of the normal method is %d \n', mean(rotErr2, 1));
fprintf('Translation error of the normal method is %d \n', mean(tranErr2, 1));
fprintf('##-----------------------------------------------------## \n')
fprintf('Norm of covariance difference for the noise correction method is %d \n', mean(covErr1, 1));
fprintf('Norm of covariance difference is %d \n', mean(covErr2, 1));
fprintf('##-----------------------------------------------------## \n')
