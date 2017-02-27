% Implementation of idea  1 X = A^-1 X B

clear; clc; close all;

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

nstd = 0.001; % Gaussian Noise standard deviation Range

n_trials = 2; %60

x = randn(6,1); x = x./norm(x); Xtrue = expm(se3_vec(x)); % Generate a Random X

skip = 100; %10;

perm_rate = 0:skip:100;

n_rate = length(perm_rate);

noiseModel = 2;

opt = 2;

optPDF = 1; % select the distribution for A and B

counter = 1;
%% Computation Loops
%---------------------------------------------------------------------------------------------------------

A_noise = []; Ainv_noise = []; B = [];
cost1 = []; cost2 = [];

[A, B] = generateAB(num, optPDF, Xtrue, gmean, std*cov);

% distribution of noise_on_A ~ (gmean, nstd*cov)
A_noise = sensorNoise(A, gmean, nstd, noiseModel);

% Use the solution from normal Batch method as the initial guess
[Xbatch, ~, ~] = batchSolve(A_noise, B);

costmin = inf;
cost = 0;

X = Xbatch;

diff = 0.0001;
eps  =  0.001;
E(:,:,1) = [0  0 0 0; 0 0 -1 0;  0 1 0 0; 0 0 0 0];
E(:,:,2) = [0  0 1 0; 0 0  0 0; -1 0 0 0; 0 0 0 0];
E(:,:,3) = [0 -1 0 0; 1 0  0 0;  0 0 0 0; 0 0 0 0];
E(:,:,4) = [0  0 0 1; 0 0  0 0;  0 0 0 0; 0 0 0 0];
E(:,:,5) = [0  0 0 0; 0 0  0 1;  0 0 0 0; 0 0 0 0];
E(:,:,6) = [0  0 0 0; 0 0  0 0;  0 0 0 1; 0 0 0 0];

% Compute SigA_noise
[a1,a2,a3]  = size(A_noise);
A_mex = reshape(A_noise, a1, a2*a3);
[MeanA_noise, SigA_noise] = distibutionPropsMex_mex(A_mex);

% Compute MeanB and SigB
B_mex = reshape(B, a1, a2*a3);
[MeanB, SigB] = distibutionPropsMex_mex(B_mex);

% Compute adjoint matrix of Xinv and MeanBinv
adBinv = ad(inv(MeanB));

% Compute Ainv_noise to get Cov_Ainv
for s = 1: a3
    Ainv_noise(:,:,s) = inv(A_noise(:,:,s));
end
Ainv_mex = reshape(Ainv_noise, a1, a2*a3);
[MeanAinv_noise, SigAinv_noise] = distibutionPropsMex_mex(Ainv_mex);


%%
while( abs(costmin) > diff )
    
    for j = 1:6
        
        X1 = X*expm( eps*E(:,:,j));
        X2 = X*expm(-eps*E(:,:,j));
        
        adX1inv = SE3inv_Ad(X1);
        adX2inv = SE3inv_Ad(X2);
        
        costCov1 = adBinv*adX1inv*SigAinv_noise*adX1inv'*adBinv' + SigB;
        costMean1 = MeanA_noise*X1 - X1*MeanB;
        
        costCov2 = adBinv*adX2inv*SigAinv_noise*adX2inv'*adBinv' + SigB;
        costMean2 = MeanA_noise*X2 - X2*MeanB;
        
        cost1(counter) = norm(costCov1, 'fro') + norm(costMean1, 'fro');
        cost2(counter) = norm(costCov2, 'fro') + norm(costMean2, 'fro');
        
        if (cost1 <= cost2)
            cost = cost1;
            if cost < costmin
                costmin = cost;
                X = X1;
            end
        
        else
            cost = cost2;
            if cost < costmin
                costmin = cost;
                X = X2;
            end
        end
        

        
        counter = counter + 1;
        
    end
    
end
