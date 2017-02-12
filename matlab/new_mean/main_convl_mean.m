% This main file is to compare the effectiveness of the four ways of
% defining the mean of the convolution of two highly focused distributions
% on SE(3)

clc
clear all;
close all;

%% ----- Add Extra Worksapce ----- %%

addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/robot')
addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/common')
addpath('/home/roma/Dropbox/2015Spring/AXXB Journal/Review_AXXB/Matlab_AXXB/Batch Method (ED - GSI)')

%%              Editable Variables             %%
% --------------------------------------------- %
% --      A & B trajectory generation        -- %
% --------------------------------------------- %

num = 50;	% Number of steps

gmean = [0; 0; 0; 0; 0; 0];	% Gaussian Noise Mean

nstd  = 0;	% Gaussian Noise standard deviation Range

shift = 0;  % Step shift

n = 1;      % VP(n)

window = 0; % Target correlation area ??

model = 5;  % Noise model

t2 = (0:(2*pi)/((num+shift)):2*pi);

twist = 0.0*sin(16*t2);

ElipseParam = [10, 20, 30];

n_search = int16(100); % Number of iterations

%% ---- Define True X ---- %%
X_true = trotx(40)*troty(30);
X_true(1:3,4) = 5*rand([3,1]);
X = zeros(4,4,50);

for i = 1:num
    X(:,:,i) = X_true;
end

B_true = trotx(20)*troty(40)*trotz(10);
B_true(1:3,4) = 5*rand([3,1]);
B = zeros(4,4,50);

for i = 1:num
    B(:,:,i) = B_true;
end

%%  Computation Loops: No noise  %%
% ------------------------------- %
% --      Without Noise        -- %
% ------------------------------- %

% B = [];
M = 10; % Number of noise levels
N = 5;  % Number of iterations for each noise level

% [A, B] = AB_genTraj(X_true, ElipseParam, num+shift+1, twist);

%% ---- Noisy Cell A, B, X and X_inv Generation ---- %%
% noise = 0:1/M:1;
noise = [0, 0.01, 0.02, 0.05, 0.1, 0.2, 0.3 0.5];

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



%% ----- Computation Loop ----- %%

for i = 1:length(noise)
    
    for j = 1:N
        
        % -- Noisy X -- %
        X_noise = sensorNoise(X, gmean, noise(i), 1);
        
        % -- Noisy B -- %
        B_noise = sensorNoise(B, gmean, noise(i), 1);
        
        %% ------ Convert Cell into mex-compatible B and X ------ %%
        fprintf('------ Convert Cell into mex-compatible B and X ------ \n')
        
        [a1,a2,a3]  = size(X_noise);
        X_noise_mex = reshape(X_noise, a1, a2*a3);
        B_noise_mex = reshape(B_noise, a1, a2*a3);
        
        %% ----- Mean under Convolution ----- %%
        fprintf('------ Calculate the Mean of Convolution  ------ \n')
        
        s1 = int8(0); % For compatibility with input data tpyes of mex functions
        s2 = int8(0);
        
        % -- Old Batch -- %
        [ MB, ~ ] = distibutionPropsMex_mex( B_noise_mex );
        [ MX, ~ ] = distibutionPropsMex_mex( X_noise_mex );
        MXMB = MX*MB;
        
        % -- 1st Taylor -- %
        M_X = mean_Taylor_1st_mex(X_noise_mex);
        M_B = mean_Taylor_1st_mex(B_noise_mex);
        M_XM_B = M_X*M_B;
        
        % -- 2nd Taylor --%
        M_XB = mean_convl_2nd_mex(X_noise_mex, B_noise_mex, s1, s2, n_search);
        
        
        %% ----- Rot and Trans Errors ---- %%
        XB = X_true*B_true;
        
        R_XB_true = XB(1:3,1:3);
        R_MX  = MXMB(1:3,1:3);
        R_MX1 = M_XM_B(1:3,1:3);
        R_MX2 = M_XB(1:3,1:3);
        
        t_XB_true = XB(1:3,4);
        t_MX  = MXMB(1:3,4);
        t_MX1 = M_XM_B(1:3,4);
        t_MX2 = M_XB(1:3,4);
        
        e_RX(i,j)  = norm(so3_vec(logm(R_XB_true'*R_MX)));
        e_RX1(i,j) = norm(so3_vec(logm(R_XB_true'*R_MX1)));
        e_RX2(i,j) = norm(so3_vec(logm(R_XB_true'*R_MX2)));
        e_RX1_true(i,j) = norm(so3_vec(logm(R_MX1'*R_MX)));
        e_RX2_true(i,j) = norm(so3_vec(logm(R_MX2'*R_MX)));
        
        e_tX(i,j)  = norm(t_XB_true - t_MX) /norm(t_XB_true);
        e_tX1(i,j) = norm(t_XB_true - t_MX1)/norm(t_XB_true);
        e_tX2(i,j) = norm(t_XB_true - t_MX2)/norm(t_XB_true);
        e_tX1_true(i,j) = norm(t_MX - t_MX1)/norm(t_MX);
        e_tX2_true(i,j) = norm(t_MX - t_MX2)/norm(t_MX);
        
    end
    
    %% Frame Clouds Visualization
    figure
    
    trplot(XB, 'color', 'r', 'length', 5)
    for k = 1:size(X_noise,3)
        hold on
        trplot(X_noise(:,:,k)*B_noise(:,:,k), 'color', 'b', 'length', 5)
    end
    
end

%% ----- Box Plot Complete ------ %%
range = length(noise);

% ------ Rotation Error ------ %
figure

subplot(3,1,1)
boxplot(e_RX(1:range,:)', noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix B and X (Old Batch)','interpreter','latex')
ylabel('Rotation Error ', 'interpreter','latex')

subplot(3,1,2)
boxplot(e_RX1(1:range,:)', noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix B and X (Taylor 1st)','interpreter','latex')
ylabel('Rotation Error ', 'interpreter','latex')

subplot(3,1,3)
boxplot(e_RX2(1:range,:)', noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix B and X (Taylor 2nd)','interpreter','latex')
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
boxplot(e_tX(1:range,:)', noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix B and X (Old Batch)','interpreter','latex')
ylabel('Trans. Error ', 'interpreter', 'latex')

subplot(3,1,2)
boxplot(e_tX1(1:range,:)', noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix B and X (Taylor 1st)','interpreter','latex')
ylabel('Trans. Error ', 'interpreter', 'latex')

subplot(3,1,3)
boxplot(e_tX2(1:range,:)', noise(1:range))
xlabel('Standard Deviation on the Lie Algebra of Matrix B and X (Taylor 2nd)','interpreter','latex')
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
