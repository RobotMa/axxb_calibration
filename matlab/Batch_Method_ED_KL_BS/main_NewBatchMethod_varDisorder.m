% This main fucntion compares three Batch methods with three 
% corresponding definitions (representations) of mean and the Kronecker
% product method
%
clear; 
clc; 
close all;

%% Add file dependencies
addpath ../../../rvctools/robot
addpath ../../../rvctools/common
addpath ../../../kinematics/kinematics/lie_group
addpath ../../../axxb_calibration/matlab/new_mean

%% Initialize Parameters
num = 50; % Number of steps

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

cov = 0.9*eye(6,6);

nstd = 0; % Gaussian Noise standard deviation Range

n_trials = 2; %60

x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x)); % Generate a Random X

skip = 10; %10;

perm_rate = 0:skip:100;

n_rate = length(perm_rate);

%% Initialize error containers
Roterror_batch_all = zeros(n_trials, n_rate);
Roterror_batch_new_1_all = zeros(n_trials, n_rate);
Roterror_batch_new_2_all = zeros(n_trials, n_rate);
Roterror_kron_all = zeros(n_trials, n_rate);

Tranerror_batch_all = zeros(n_trials, n_rate);
Tranerror_batch_new_1_all = zeros(n_trials, n_rate);
Tranerror_batch_new_2_all = zeros(n_trials, n_rate);
Tranerror_kron_all = zeros(n_trials, n_rate);

t_Error_avg = [];

%% Computation Loops
A_noise = [];
B = [];
j = 0;
opt = 2;
optPDF = 1; % select the distribution for A and B

for j = 1:n_rate
    
    t_Error = [];
    
    for k = 1:n_trials
        
        [A, B] = generateAB(num, optPDF, X, gmean, cov);
        
        % PA=randperm(size(A,3));
        % PB=randperm(size(B,3));
        
        % waitbar((j*k)/(100*trials))
        
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
        
        [X_batch, MA, MB] = batchSolve(A_perm, B_perm, false, 0); %batchSolveNew(A_perm, B_perm, 5); %
        [X_batch_New_1, ~, ~, ~, ~, ~] = batchSolveNew(A_perm, B_perm, 1);
        [X_batch_New_2, MA_New, MB_New, ~, ~, t_error] = batchSolveNew(A_perm, B_perm, 4); % 2 is changing step size ,4 is M=M(I+X)
        [X_kron] = batchSolveNew(A_perm, B_perm, 5); % axb_KronSolve(A_perm,B_perm); %
        
        %% Store Errors
        Roterror_batch_all(k,j) = roterror(X_batch, X);
        Roterror_batch_new_1_all(k, j) = roterror(X_batch_New_1,X);
        Roterror_batch_new_2_all(k, j) = roterror(X_batch_New_2,X);
        Roterror_kron_all(k, j) = roterror(X_kron,X);
        
        Tranerror_batch_all(k,j) = tranerror(X_batch, X);
        Tranerror_batch_new_1_all(k, j) = tranerror(X_batch_New_1,X);
        Tranerror_batch_new_2_all(k, j) = tranerror(X_batch_New_2,X);
        Tranerror_kron_all(k, j) = tranerror(X_kron,X);
        
        t_Error = [t_Error t_error];
        
    end
    
    
%     Roterror_batch_all = [Roterror_batch_all Roterror_batch'];
%     Roterror_batch_all_New_1 = [Roterror_batch_all_New_1 Roterror_batch_New_1'];
%     Roterror_batch_all_New_2 = [Roterror_batch_all_New_2 Roterror_batch_New_2'];
%     Roterror_kron_all = [Roterror_kron_all Roterror_kron'];
%     
%     Tranerror_batch_all = [Tranerror_batch_all Tranerror_batch'];
%     Tranerror_batch_all_New_1 = [Tranerror_batch_all_New_1 Tranerror_batch_New_1'];
%     Tranerror_batch_all_New_2 = [Tranerror_batch_all_New_2 Tranerror_batch_New_2'];
%     Tranerror_kron_all = [Tranerror_kron_all Tranerror_kron'];
    
%     Roterror_batch_avg = [Roterror_batch_avg mean(Roterror_batch)];
%     Roterror_batch_new_1_avg = [Roterror_batch_new_1_avg mean(Roterror_batch_New_1)];
%     Roterror_batch_new_2_avg = [Roterror_batch_new_2_avg mean(Roterror_batch_New_2)];
%     Roterror_kron_avg = [Roterror_kron_avg mean(Roterror_kron)];
%     
%     Tranerror_batch_avg = [Tranerror_batch_avg mean(Tranerror_batch)];
%     Tranerror_batch_avg_New_1 = [Tranerror_batch_avg_New_1 mean(Tranerror_batch_New_1)];
%     Tranerror_batch_avg_New_2 = [Tranerror_batch_avg_New_2 mean(Tranerror_batch_New_2)];
%     Tranerror_kron_avg = [Tranerror_kron_avg mean(Tranerror_kron)];

    t_Error_avg = [t_Error_avg mean(t_Error)];
    
end

%%
Roterror_batch_avg = mean(Roterror_batch_all);
Roterror_batch_new_1_avg = mean(Roterror_batch_new_1_all);
Roterror_batch_new_2_avg = mean(Roterror_batch_new_2_all);
Roterror_kron_avg = mean(Roterror_kron_all);

Tranerror_batch_avg = mean(Tranerror_batch_all);
Tranerror_batch_new_1_avg = mean(Tranerror_batch_new_1_all);
Tranerror_batch_new_2_avg = mean(Tranerror_batch_new_2_all);
Tranerror_kron_avg = mean(Tranerror_kron_all);
    
%% Correspondence Recovering New Batch
Rx = X_batch_New_2(1:3,1:3);
a_cp = zeros(size(A_perm,3)); % To record the corresponding B_i w.r.t. A_i
eps = 10^-4;

for i = 1:size(A_perm,3)
    RB = Rx'*A_perm(1:3,1:3,i)*Rx; % RB corresponds to the current A_i
    for j = 1:size(B_perm,3)
        if roterror(RB, B_perm(1:3,1:3,j)) < eps
            a_cp(i,j) = 1;
        end
    end
end


%% Correspondence Recovering Old Batch
% Rx_old = X_batch(1:3,1:3);
% a_cp_old = zeros(size(A_perm, 3)); % To record the corresponding B_i w.r.t. A_i
% eps = 10^-1;
%
% for i = 1:size(A_perm,3)
%     RB_old = Rx_old'*A_perm(1:3,1:3,i)*Rx_old; % RB corresponds to the current A_i
%     for j = 1:size(B_perm,3)
%          if roterror(RB_old, B_perm(1:3,1:3,j)) < eps
%              a_cp_old(i,j) = 1;
%          end
%     end
% end

%%
figure
scatter((0:skip:100), Roterror_batch_avg, '+');
hold on
scatter((0:skip:100), Roterror_batch_new_1_avg, 'o');
hold on
scatter((0:skip:100), Roterror_batch_new_2_avg, '*');
hold on
scatter((0:skip:100), Roterror_kron_avg, '^');
hold off
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Rotation error of X')
legend('Batch Method','New Batch Method 1st Order','New Batch Method 2nd Order', 'Original 2nd Product' ,'Location', 'SouthOutside')
% axis([0 100 0 4])

figure
scatter((0:skip:100), Tranerror_batch_avg, '+');
hold on
scatter((0:skip:100), Tranerror_batch_new_1_avg, 'o');
hold on
scatter((0:skip:100), Tranerror_batch_new_2_avg, '*');
hold on
scatter((0:skip:100), Tranerror_kron_avg,'^');
hold off
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Translation error of X')
legend('Batch Method','New Batch Method 1st Order', 'Ned Batch Method 2nd Order', 'Original 2nd Product','Location', 'SouthOutside')
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
% scatter((0:skip:100), Tranerror_batch_avg, '+');
% hold on
scatter((0:skip:100), Tranerror_batch_new_1_avg, 'o');
hold on
scatter((0:skip:100), Tranerror_batch_new_2_avg, '*');
hold off
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Translation error of X')
legend('New Batch Method 1st Order', 'Ned Batch Method 2nd Order','Location', 'SouthOutside')
% axis([0 100 0 0.18])

%%
% By improving the accuracy of the translation of the new means of A and B,
% using the 2nd order constraint, the translation of the solved X does
% improve a lot compared to the pure 1st order approximation. However, it
% is still not comparable to that of the old Batch
%%
% range =  length(0:skip:100);
% figure
% boxplot(Roterror_batch_all(:,1:range),(0:skip:100))
% ylabel('Old Batch Method')
% 
% figure
% boxplot(Roterror_batch_all_New_1(:,1:range), (0:skip:100))
% ylabel('New Batch Method')
% 
% figure
% boxplot(Roterror_batch_all_New_2(:,1:range), (0:skip:100))
% ylabel('New Batch Method')
% 
% figure
% boxplot(Roterror_kron_all(:,1:range), (0:skip:100))
% ylabel('New Batch Method')
% 
% 
% %%
% figure
% boxplot(Tranerror_batch_all(:,1:range), (0:skip:100))
% ylabel('New Batch Method')
% 
% figure
% boxplot(Tranerror_batch_all_New_1(:,1:range), (0:skip:100))
% ylabel('New Batch Method')
% 
% figure
% boxplot(Tranerror_batch_all_New_2(:,1:range), (0:skip:100))
% ylabel('New Batch Method')
% 
% %%
% figure
% boxplot(Roterror_batch_all(:,1:range),(0:skip:100))
% hold on
% boxplot(Roterror_batch_all_New_1(:,1:range),(0:skip:100))
% hold on
% boxplot(Roterror_batch_all_New_2(:,1:range),(0:skip:100))
% hold on
% boxplot(Roterror_kron_all(:,1:range),(0:skip:100))
% ylabel('Old Batch Method')