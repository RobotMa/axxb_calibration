% AXXB - Fixing Temporal Misalignment

% Required function list:
% AB_gen().m
% noise_Gauss().m
% param_extract().m
% se3_vec().m
% so3_vec().m

clear; clc; close all;

%%

addpath('/home/rpk/Dropbox/2014Summer/Robotics Research/rvctools/robot')
addpath('/home/rpk/Dropbox/2015Spring/AXXB Journal/Review_AXXB/Matlab_AXXB/Batch Method (ED - GSI)')

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

x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x));  % Generate a Random X

n_search = int16(10^4); % Number of iterations


%%  Computation Loops: No noise  %% 
% ------------------------------- %
% --      Without Noise        -- %
% ------------------------------- %

A = [];
B = [];

[A, B] = AB_genTraj(X, ElipseParam, num+shift+1, twist);


%% --------- Batch Distribution ------ %%
fprintf('\n')
fprintf('\n')
fprintf('-----------------------------------------------------\n')
fprintf('\n')
fprintf('\n')
fprintf('===================================================== \n')
fprintf('=      Mean of Batch Distribution Without Noise     = \n')
fprintf('===================================================== \n')

[a1,a2,a3] = size( A );
A_mex = reshape(A, a1, a2*a3);
[b1,b2,b3] = size( B );
B_mex = reshape(B, b1, b2*b3);

[ MA, ~ ] = distibutionPropsMex( A_mex );
[ MB, ~ ] = distibutionPropsMex( B_mex );

G = MA*X - X*MB;
R_X = X(1:3,1:3);
R_A = MA(1:3,1:3);
R_B = MB(1:3,1:3);
nor_rot_d = norm(G(1:3,1:3));
nor_rot_r = norm(logm((R_A*R_X)'*(R_X*R_B)));
nor_trans = norm(G(1:3,4));

fprintf('MA*X = \n')
disp(MA*X)
fprintf('X*MB = \n')
disp(X*MB)
fprintf('Error in rotation difference : %d \n', nor_rot_d)
fprintf('Error in rotation relative   : %d \n', nor_rot_r)
fprintf('Error in translation         : %d \n', nor_trans)
fprintf('\n')

%% --------- 1st order ---------- %%
fprintf('\n')
fprintf('\n')
fprintf('-----------------------------------------------------\n')
fprintf('\n')
fprintf('\n')
fprintf('===================================================== \n')
fprintf('=    1st Order Taylor Approximation Without Noise   = \n')
fprintf('===================================================== \n')

[MA1,~] = mean_Taylor_1st_mex( A_mex );
[MB1,~] = mean_Taylor_1st_mex( B_mex );
Sigma1 = cov_Taylor_1st(A_mex);

G1 = MA1*X - X*MB1;
nor_rot1 = norm(G1(1:3,1:3));
nor_trans1 = norm(G1(1:3,4));

% When there is NO noise, the result shows that the approximation of
% rotation is fine while that of translation is very inaccurate

fprintf('MA1*X = \n')
disp(MA1*X)
fprintf('X*MB1 = \n')
disp(X*MB1)
fprintf('Error in rotation    : %d \n', nor_rot1)
fprintf('Error in translation : %d \n', nor_trans1)
fprintf('\n')

%% --------- 2nd order ---------- %%
fprintf('===================================================== \n')
fprintf('=    2nd order Taylor approximation without noise   = \n')
fprintf('===================================================== \n')

s_d = 0; % Specify search directions

if s_d == 0
    fprintf('-----------------------------------\n')
    fprintf('-  Gradient search from 4 to 6    -\n')
    fprintf('-----------------------------------\n')
elseif s_d == 1
    fprintf('-----------------------------------\n')
    fprintf('-  Gradient search from 1 to 6    -\n')
    fprintf('-----------------------------------\n')
end

MA2 = mean_Taylor_2nd_mex( A_mex, s_d, n_search );
MB2 = mean_Taylor_2nd_mex( B_mex, s_d, n_search );

G2 = MA2*X - X*MB2;
R_X = X(1:3,1:3);
R_A2 = MA2(1:3,1:3);
R_B2 = MB2(1:3,1:3);
nor_rot2_d = norm(G2(1:3,1:3));
nor_rot2_r = norm(logm((R_A2*R_X)'*(R_X*R_B2)));
nor_trans2 = norm(G2(1:3,4));


fprintf('MA2*X = \n')
disp(MA2*X)
fprintf('X*MB2 = \n')
disp(X*MB2)
fprintf('Error in rotation difference : %d \n', nor_rot2_d)
fprintf('Error in rotation relative   : %d \n', nor_rot2_r)
fprintf('Error in translation         : %d \n', nor_trans2)
fprintf('\n')
fprintf('\n')
fprintf('-----------------------------------------------------\n')
fprintf('\n')
fprintf('\n')


%%  Computation Loops: With noise  %% 
% --------------------------------- %
% --          With Noise         -- % 
% --------------------------------- %

A_noise = [];
A_noise = sensorNoise(A, gmean, 0.3, 1);

%% --------- Batch Distribution ------ %%
fprintf('\n')
fprintf('\n')
fprintf('-----------------------------------------------------\n')
fprintf('\n')
fprintf('\n')
fprintf('===================================================== \n')
fprintf('=       Mean of Batch Distribution With Noise       = \n')
fprintf('===================================================== \n')
[a1,a2,a3] = size( A_noise );
A_noise_mex = reshape(A_noise, a1, a2*a3);

[b1,b2,b3] = size( B );
B_mex = reshape(B, b1, b2*b3);

[ MA, ~ ] = distibutionPropsMex( A_noise_mex );
[ MB, ~ ] = distibutionPropsMex( B_mex );

G = MA*X - X*MB;
R_X = X(1:3,1:3);
R_A = MA(1:3,1:3);
R_B = MB(1:3,1:3);
nor_rot_d = norm(G(1:3,1:3));
nor_rot_r = norm(logm((R_A*R_X)'*(R_X*R_B)));
nor_trans = norm(G(1:3,4));

fprintf('MA*X = \n')
disp(MA*X)
fprintf('X*MB = \n')
disp(X*MB)
fprintf('Error in rotation difference : %d \n', nor_rot_d)
fprintf('Error in rotation relative   : %d \n', nor_rot_r)
fprintf('Error in translation         : %d \n', nor_trans)
fprintf('\n')

%% --------- 1st order ---------- %%
fprintf('===================================================== \n')
fprintf('=     1st order Taylor approximation with noise     = \n')
fprintf('===================================================== \n')
[MA1,~] = mean_Taylor_1st_mex( A_noise_mex );
[MB1,~] = mean_Taylor_1st_mex( B_mex );
Sigma1 = cov_Taylor_1st( A_noise_mex );

G1 = MA1*X - X*MB1;
nor_rot1   = norm(G1(1:3,1:3));
nor_trans1 = norm(G1(1:3,4));

% When there is NO noise, the result shows that the approximation of
% rotation is fine while that of translation is very inaccurate


fprintf('MA1*X = \n')
disp(MA1*X)
fprintf('X*MB1 = \n')
disp(X*MB1)
fprintf('Error in rotation    : %d \n', nor_rot1)
fprintf('Error in translation : %d \n', nor_trans1)
fprintf('\n')

%% --------- 2nd order ---------- %%
fprintf('===================================================== \n')
fprintf('=    2nd order Taylor approximation with noise      = \n')
fprintf('===================================================== \n')

s_d = 0; % Specify search directions

if s_d == 0
    fprintf('-----------------------------------\n')
    fprintf('-  Gradient search from 4 to 6    -\n')
    fprintf('-----------------------------------\n')
elseif s_d == 1
    fprintf('-----------------------------------\n')
    fprintf('-  Gradient search from 1 to 6    -\n')
    fprintf('-----------------------------------\n')
end


MA2 = mean_Taylor_2nd_mex( A_noise_mex, s_d, n_search );
MB2 = mean_Taylor_2nd_mex( B_mex,       s_d, n_search );

G2 = MA2*X - X*MB2;
R_X = X(1:3,1:3);
R_A2 = MA2(1:3,1:3);
R_B2 = MB2(1:3,1:3);
nor_rot2_d = norm(G2(1:3,1:3));
nor_rot2_r = norm(logm((R_A2*R_X)'*(R_X*R_B2)));
nor_trans2 = norm(G2(1:3,4));


fprintf('MA2*X = \n')
disp(MA2*X)
fprintf('X*MB2 = \n')
disp(X*MB2)
fprintf('Error in rotation difference : %d \n', nor_rot2_d)
fprintf('Error in rotation relative   : %d \n', nor_rot2_r)
fprintf('Error in translation         : %d \n', nor_trans2)
fprintf('\n')
fprintf('\n')
fprintf('-----------------------------------------------------\n')
fprintf('\n')
fprintf('\n')


