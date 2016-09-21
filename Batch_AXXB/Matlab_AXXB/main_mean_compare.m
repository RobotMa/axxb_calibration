% This main file is to compare the effectiveness of the three ways of
% defining the mean of a series of rigid body transformations
% Old Batch, 1st Order of Taylor, 2nd Order of Taylor

clc
clear all
close all

%% ----- Add Extra Worksapce ----- %%

addpath('~/Dropbox/2014Summer/Robotics Research/rvctools/robot','-end')
addpath('~/Dropbox/2014Summer/Robotics Research/rvctools/common')
addpath('~/Dropbox/2015Spring/AXXB Journal/Review_AXXB/Matlab_AXXB/Batch Method (ED - GSI)')
addpath('~/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws')
addpath('~/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/util')

%% ---- Initilization ---- %%

gmean = [0; 0; 0; 0; 0; 0];	% Gaussian Noise Mean

n_search = int16(10^2); % Number of iterations for termination of optimization process
n_X = 50;

X_true = trotx(40)*troty(30);
X_true(1:3,4) = 5*rand([3,1]);
gmean_X = se3_vec(logm(X_true));

% X_true = expm(se3_vec(gmean));
X = zeros(4, 4, n_X);

for i = 1:size(X,3)
    X(:,:,i) = X_true;
end


%% ----- Computation Loop ----- %%
M = 10; % Number of noise levels
N = 50; % Number of iterations for each noise level

noise = 0.01:0.1/M:0.09; % standard deviation
% noise = [0.1, 0.2, 0.3 ,0.4, 0.5, 0.6, 0.7 ,0.8, 0.9];
% noise = [0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1];

e_RX  = zeros(N,M);
e_RX1 = zeros(N,M);
e_RX2 = zeros(N,M);
e_RX1_true = zeros(N,M);
e_RX2_true = zeros(N,M);

e_tX  = zeros(N,M);
e_tX1 = zeros(N,M);
e_tX2 = zeros(N,M);
e_tX1_true = zeros(N,M);
e_tX2_true = zeros(N,M);

X_noise = [];

for j = 1:length(noise)
    for i = 1: N
        
        for k = 1:size(X,3)
            X(:,:,k) = expm(se3_vec(mvg(gmean_X, noise(j)*eye(6,6), 1)));
        end
            X_noise = X;
%         X_noise = sensorNoise(X, gmean, noise(j), 1);
        
        %% ------ Distribution Generation ------ %%
        [a1,a2,a3] = size(X_noise);
        X_noise_mex = reshape(X_noise, a1, a2*a3);
        
        [ MX, ~ ] = distibutionPropsMex_mex( X_noise_mex );
%         MX1 = distibutionProps(X_noise);
        [ MX1, ~] = mean_Taylor_1st_mex( X_noise_mex );
        MX2 = mean_Taylor_2nd_adv_mex( X_noise_mex, 1, n_search );
        
        
        %% ----- Rot and Trans Errors ---- %%
        R_X_true = X_true(1:3,1:3);
        R_MX  = MX(1:3,1:3);
        R_MX1 = MX1(1:3,1:3);
        R_MX2 = MX2(1:3,1:3);
        
        t_X_true = X_true(1:3,4);
        t_MX  = MX(1:3,4);
        t_MX1 = MX1(1:3,4);
        t_MX2 = MX2(1:3,4);
        
        e_RX(i,j)  = norm(so3_vec(logm(R_X_true'*R_MX)));
        e_RX1(i,j) = norm(so3_vec(logm(R_X_true'*R_MX1)));
        e_RX2(i,j) = norm(so3_vec(logm(R_X_true'*R_MX2)));
        e_RX1_true(i,j) = norm(so3_vec(logm(R_MX1'*R_MX)));
        e_RX2_true(i,j) = norm(so3_vec(logm(R_MX2'*R_MX)));
        
        
        e_tX(i,j)  = norm(t_X_true - t_MX) /norm(t_X_true);
        e_tX1(i,j) = norm(t_X_true - t_MX1)/norm(t_X_true);
        e_tX2(i,j) = norm(t_X_true - t_MX2)/norm(t_X_true);
        e_tX1_true(i,j) = norm(t_MX - t_MX1)/norm(t_MX);
        e_tX2_true(i,j) = norm(t_MX - t_MX2)/norm(t_MX);
        
        
    end
    
    %% Frame Clouds Visualization
    figure
    if false
        trplot(X(:,:,1), 'color', 'r', 'length', 5)
        for k = 1:size(X_noise,3)
            hold on
            trplot(X_noise(:,:,k), 'color', 'b', 'length', 5)
        end
    end
end

%% ----- Output Display ---- %%
% fprintf('Rotation error e_RX  is %d \n',  sum(e_RX)/N)
% fprintf('Rotation error e_RX1 is %d \n', sum(e_RX1)/N)
% fprintf('Rotation error e_RX2 is %d \n', sum(e_RX2)/N)
%
% fprintf('Translation error e_tX  is %d \n',  sum(e_tX)/N)
% fprintf('Translation error e_tX1 is %d \n', sum(e_tX1)/N)
% fprintf('Translation error e_tX2 is %d \n', sum(e_tX2)/N)


%% ----- Box Plot ------ %%
range = length(noise) ;
% ------ Rotation Error ------ %
figure

subplot(3,1,1)
boxplot(e_RX(:,1:range), noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix X (Old Batch)','interpreter','latex')
ylabel('Rotation Error ', 'interpreter','latex')

subplot(3,1,2)
boxplot(e_RX1(:,1:range), noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix X (Taylor 1st)','interpreter','latex')
ylabel('Rotation Error ', 'interpreter','latex')

subplot(3,1,3)
boxplot(e_RX2(:,1:range), noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix X (Taylor 2nd)','interpreter','latex')
ylabel('Rotation Error ', 'interpreter','latex')

figure

subplot(2,1,1)
boxplot(e_RX1_true(:,1:range), noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix X (Taylor 1st)','interpreter','latex')
ylabel('Relative Rotation Error ', 'interpreter','latex')

subplot(2,1,2)
boxplot(e_RX2_true(:,1:range), noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix X (Taylor 2nd)','interpreter','latex')
ylabel('Relative Rotation Error ', 'interpreter','latex')

% ------ Translational Error ------ %
figure

subplot(3,1,1)
boxplot(e_tX(:,1:range), noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix X (Old Batch)','interpreter','latex')
ylabel('Trans. Error ', 'interpreter', 'latex')

subplot(3,1,2)
boxplot(e_tX1(:,1:range), noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix X (Taylor 1st)','interpreter','latex')
ylabel('Trans. Error ', 'interpreter', 'latex')

subplot(3,1,3)
boxplot(e_tX2(:,1:range), noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix X (Taylor 2nd)','interpreter','latex')
ylabel('Trans.Error ', 'interpreter', 'latex')


figure

subplot(2,1,1)
boxplot(e_tX1_true(:,1:range), noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix X (Taylor 1st)','interpreter','latex')
ylabel('Relative Translation Error ', 'interpreter','latex')

subplot(2,1,2)
boxplot(e_tX2_true(:,1:range), noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix X (Taylor 2nd)','interpreter','latex')
ylabel('Relative Translation Error ', 'interpreter','latex')


