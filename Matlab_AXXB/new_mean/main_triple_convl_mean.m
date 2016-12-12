% This main file is to compare the effectiveness of the two ways of
% defining the mean of a series of rigid body transformations

clc
clear all;
close all;

%% ----- Add Extra Worksapce ----- %%

addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/robot')
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

% x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x));  % Generate a Random X

%% ---- Define True X ---- %%
X_true = trotx(40)*troty(30);
X_true(1:3,4) = 5*rand([3,1]);
X = zeros(4,4,50);

for i = 1:num
    X(:,:,i) = X_true;
end

%%  Computation Loops: No noise  %%
% ------------------------------- %
% --      Without Noise        -- %
% ------------------------------- %

A = [];
B = [];
M = 10;
N = 20;
e_RX  = zeros(N,M);
e_RX1 = zeros(N,M);
e_RX2 = zeros(N,M);

e_tX  = zeros(N,M);
e_tX1 = zeros(N,M);
e_tX2 = zeros(N,M);

noise = 0:1/M:1;

[A, B] = AB_genTraj(X_true, ElipseParam, num+shift+1, twist);

%% ---- Noisy Cell A, B, X and X_inv Generation ---- %%
for j = 1:length(noise)
    for i = 1: N
        
        % -- X -- %
        X_noise = sensorNoise(X, gmean, noise(j), 1);
        
        % -- B -- %
        B_noise = sensorNoise(B, gmean, noise(j), 1);
        
        % -- X_inv -- %
        N_inv = size(X_noise, 3);
        X_noise_inv = zeros(4, 4, N_inv);
        for m = 1:size(X_noise,3)
            X_noise_inv(:,:,m) = inv(X_noise(:,:,m));
        end
        
        % -- A -- %
        A_noise = zeros(4,4,num);
        for k = 1:size(B_noise, 3)
            A_noise(:,:,k) = X_noise(:,:,k)*B_noise(:,:,k)*X_noise(:,:,k);
        end
        
        %% ------ Convert Cell into mex-compatible A, B, X, X_inv ------ %%
        fprintf('------ Convert Cell into mex-compatible A, B, X, X_inv ------ \n')
        
        [a1,a2,a3]  = size(X_noise);
        X_noise_mex = reshape(X_noise, a1, a2*a3);
        B_noise_mex = reshape(B_noise, a1, a2*a3);
        A_noise_mex = reshape(A_noise, a1, a2*a3);
        X_noise_inv_mex = reshape(X_noise_inv, a1, a2*a3);
        
        %% ----- Mean under Convolution ----- %%
        fprintf('------ Calculate the Mean of Convolution  ------ \n')
        
        s1 = int8(0); % For compatibility with input data tpyes of mex functions
        s2 = int8(0);
        s3 = int8(0);
        sd = int8(0);
        diff = 10^-3;
        n_search = int16(10^2); % Number of iterations
        
        % ------ Old Batch ------ %
        [ MA, ~ ] = distibutionPropsMex_mex( A_noise_mex );
        [ MB, ~ ] = distibutionPropsMex_mex( B_noise_mex );
        [ MX, ~ ] = distibutionPropsMex_mex( X_noise_mex );
        
        % ------ 2nd Order Taylor ------ %
        M_X = mean_Taylor_2nd_mex( X_noise_mex, 0, n_search );
        M_A = mean_Taylor_2nd_mex( A_noise_mex, 0, n_search );
        M_B = mean_Taylor_2nd_mex( B_noise_mex, 0, n_search );
        
        % ------ 2nd Order of Triple Convolution ------ %
%         M_XB_mex = repmat(M_XB, 1, N_inv);
%         M_XBXinv = mean_convl_2nd_mex(M_XB_mex, X_noise_inv_mex, s1, s2, n_search);
        M_XBXinv = mean_double_convl_2nd_mex...
            (X_noise_mex, B_noise_mex, X_noise_inv_mex, s1, s2, s3, n_search, diff);
        
        
    %% ----- Rot and Trans Errors ---- %%    
    
    % --- Old Batch --- %
    MXMBMX = MX*MB/MX;
    RXBX = MXMBMX(1:3,1:3);    
    tXBX = MXMBMX(1:3,4);
    RA = MA(1:3,1:3);
    tA = MA(1:3,4);
    
    % --- 2nd Order Taylor --- %
    M_XM_BM_X = M_X*M_B/M_X;
    R_X_B_X = M_XM_BM_X(1:3,1:3);
    t_X_B_X = M_XM_BM_X(1:3,  4);
    
    R_A = M_A(1:3, 1:3);
    t_A = M_A(1:3,   4);
    
    % --- 2nd Order of Triple Convolution --- %
    
    e_RX(i,j)  = norm(so3_vec(logm(RA'*RXBX)));
    e_RX1(i,j) = norm(so3_vec(logm(R_A'*R_X_B_X)));   
    e_RX2(i,j) = norm(so3_vec(logm(R_A'*M_XBXinv(1:3,1:3))));
    
    e_tX(i,j)  = norm(tA - tXBX) /norm(tA);
    e_tX1(i,j) = norm(t_A - t_X_B_X) /norm(t_A);
    e_tX2(i,j) = norm(t_A - M_XBXinv(1:3,4))/norm(M_A(1:3,4));
        
    end
end

%% ----- Box Plot ------ %%
range = 11;
% ------ Rotation Error ------ %
figure 

subplot(3,1,1)
boxplot(e_RX(:,1:range), noise(1:range))
xlabel('Standard Deviation on Lie Algebra (Old Batch)','interpreter','latex')
ylabel('Rotation Error ', 'interpreter','latex')

subplot(3,1,2)
boxplot(e_RX1(:,1:range), noise(1:range))
xlabel('Standard Deviation on Lie Algebra (Taylor 2nd Separate)','interpreter','latex')
ylabel('Rotation Error ', 'interpreter','latex')

subplot(3,1,3)
boxplot(e_RX2(:,1:range), noise(1:range))
xlabel('Standard Deviation on Lie Algebra (Taylor 2nd Complete)','interpreter','latex')
ylabel('Rotation Error ', 'interpreter','latex')

% ------ Translational Error ------ %
figure 

subplot(3,1,1)
boxplot(e_tX(:,1:range), noise(1:range))
xlabel('Standard Deviation on Lie Algebra (Old Batch)','interpreter','latex')
ylabel('Trans. Error ', 'interpreter', 'latex')


subplot(3,1,2)
boxplot(e_tX1(:,1:range), noise(1:range))
xlabel('Standard Deviation on Lie Algebra (Taylor 2nd Separate)','interpreter','latex')
ylabel('Trans.Error ', 'interpreter', 'latex')

subplot(3,1,3)
boxplot(e_tX2(:,1:range), noise(1:range))
xlabel('Standard Deviation on Lie Algebra (Taylor 2nd complete)','interpreter','latex')
ylabel('Trans.Error ', 'interpreter', 'latex')


%% --- Error Calculation and Display: A - XBX_inv --- %%
invPlot = false;

if invPlot
    
    diff = 10^-8;
    diff2 = 1;
    
    M_XBX_inv = mean_double_convl_2nd_mex...
        ( X_noise_mex, B_noise_mex, X_noise_inv_mex, s1, s2, s3, n_search, diff);
    
    M_XBX_inv2 = mean_double_convl_2nd_mex...
        ( X_noise_mex, B_noise_mex, X_noise_inv_mex, s1, s2, s3, n_search, diff2);
    
    fprintf(' ----------------------------------- \n')
    fprintf(' -          A - XBX_inv            - \n')
    fprintf(' ----------------------------------- \n')
    % -- A - XBX_inv -- %
    % ------------------------ %
    % -   2nd order Taylor   - %
    % ------------------------ %
    fprintf('---- 2nd order Taylor ---- \n')
    
    G3 = M_A - M_XBXinv;
    R_A3 = M_A(1:3,1:3);
    R_XBXinv = M_XBXinv(1:3,1:3);
    nor_rot_r = norm(logm(R_A3'*R_XBXinv));
    nor_trans = norm(G3(1:3,4));
    
    fprintf('Error in rotation relative   : %d \n', nor_rot_r)
    fprintf('Error in translation         : %d \n', nor_trans)
    fprintf('\n')
    fprintf('\n')
    fprintf('\n')
    
    % ---------------------------- %
    % -   2nd order Taylor New   - %
    % ---------------------------- %
    fprintf('---- 2nd order Taylor New ---- \n')
    
    G3 = M_A - M_XBX_inv;
    R_A3 = M_A(1:3,1:3);
    R_XBX_inv = M_XBX_inv(1:3,1:3);
    nor_rot_r = norm(logm(R_A3'*R_XBX_inv));
    nor_trans = norm(G3(1:3,4));
    
    fprintf('Error in rotation relative   : %d \n', nor_rot_r)
    fprintf('Error in translation         : %d \n', nor_trans)
    fprintf('\n')
    fprintf('\n')
    fprintf('\n')
    
    % ---------------------------- %
    % -   2nd order Taylor New 2   - %
    % ---------------------------- %
    fprintf('---- 2nd order Taylor New 2 ---- \n')
    
    G3 = M_A - M_XBX_inv2;
    R_A3 = M_A(1:3,1:3);
    R_XBX_inv2 = M_XBX_inv2(1:3,1:3);
    nor_rot_r = norm(logm(R_A3'*R_XBX_inv2));
    nor_trans = norm(G3(1:3,4));
    
    fprintf('Error in rotation relative   : %d \n', nor_rot_r)
    fprintf('Error in translation         : %d \n', nor_trans)
    fprintf('\n')
    fprintf('\n')
    fprintf('\n')
    
    
    
    % ------------------------ %
    % -       Old Batch      - %
    % ------------------------ %
    fprintf('---- Old Batch ---- \n')
    
    G_XBX = MX*MB/MX;
    G4 = MA - G_XBX;
    nor_rot_r = norm(logm(MA(1:3,1:3)'*G_XBX(1:3,1:3)));
    nor_trans = norm(G4(1:3,4));
    
    fprintf('Error in rotation relative   : %d \n', nor_rot_r)
    fprintf('Error in translation         : %d \n', nor_trans)
    fprintf('\n')
    fprintf('\n')
    fprintf('\n')
    
end