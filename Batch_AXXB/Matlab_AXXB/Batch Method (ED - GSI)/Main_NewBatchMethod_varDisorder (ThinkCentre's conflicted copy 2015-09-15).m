    %AXXB - Fixing Temporal Misalignment

%Required function list:
%AB_gen().m
%noise_Gauss().m
%param_extract().m
%se3_vec().m
%so3_vec().m

clear; clc; close all;

addpath('~/Dropbox/2014Summer/Robotics Research/rvctools/robot')
addpath('~/Dropbox/2014Summer/Robotics Research/rvctools/common')

%Editable Variables
%------------------------------------------------------

num = 50;	%Number of steps

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

nstd = 0;	%Gaussian Noise standard deviation Range

shift = 0; %step shift

n = 1;      %VP(n)

window = 0;    %target correlation area

model = 5;        %noise model


t2 = (0:(2*pi)/((num+shift)):2*pi);
twist = 0.0*sin(16*t2);

ElipseParam = [10, 20, 30];

trials = 60;

%------------------------------------------------------


x = randn(6,1); x = x./norm(x); X= expm(se3_vec(x));    %Generate a Random X

Roterror_batch_all = [];
Roterror_batch_all_New_1 = [];
Roterror_batch_all_New_2 = [];
Roterror_kron_all = [];

Tranerror_batch_all = [];
Tranerror_batch_all_New_1 = [];
Tranerror_batch_all_New_2 = [];
Tranerror_kron_all = [];


Roterror_batch_avg = [];
Roterror_kron_avg = [];
Roterror_batch_avg_New_2 = [];
Roterror_batch_avg_New_1 = [];

Tranerror_batch_avg = [];
Tranerror_batch_avg_New_2 = [];
Tranerror_batch_avg_New_1 = [];
Tranerror_kron_avg = [];

t_Error_avg = [];
%Computation Loops
%---------------------------------------------------------------------------------------------------------

A_noise = [];
B = [];

Mean = [0; 0; 0; 0; 0; 0];
% Mean = [0.5; 0.5; 0.5; 0.5; 0.5; 0.5];

Cov = 0.9*eye(6,6);

% [A, B] = AB_genRand(X, Mean, Cov, num);
opt = 2;

skip = 10;
for j = 1:skip:101
    
    Roterror_batch = [];
    Roterror_batch_New_2 = [];
    Roterror_batch_New_1 = [];
    Roterror_kron = [];
    Tranerror_batch = [];
    Tranerror_batch_New_2 = [];
    Tranerror_batch_New_1 = [];
    Tranerror_kron = [];
    
    t_Error = [];
    
    
    if opt == 1
        
        [A, B] = AB_genRand(X, Mean, Cov, num);
        
    elseif opt == 2
        
        B_true = trotx(40)*troty(30);
        B_true(1:3,4) = 5*rand([3,1]);
        
        A = zeros(4, 4, num);
        B = zeros(4, 4, num);
        
        for i = 1:size(B,3)
            B(:,:,i) = B_true;
        end
        
        B = sensorNoise(B, Mean, 0.9, 1);
        for s = 1:size(A,3)
            A(:,:,s) = X*B(:,:,s)/X;
        end
    end
    
    for k = 1:trials
        % PA=randperm(size(A,3));
        % PB=randperm(size(B,3));
        
        %          waitbar((j*k)/(100*trials))
        
        PA = (1:size(A,3));
        PB = (1:size(B,3));
        
        for i = 1:length(PA)
            
            if rand <= 0.01*j
                index = randi(num,1);
                PA([i index]) = PA([index i]);
            end
            
        end
        
        A_perm = A(:,:,PA);
        B_perm = B(:,:,PB);
        
        [X_batch, MA, MB] = batchSolve(A_perm, B_perm);
        [X_batch_New_2, MA_New, MB_New, ~, ~, t_error] = batchSolveNew(A_perm, B_perm, 2);
        [X_batch_New_1, ~, ~, ~, ~, ~] = batchSolveNew(A_perm, B_perm, 1);
        [X_kron] = axb_KronSolve(A_perm,B_perm);
        
        Roterror_batch = [Roterror_batch roterror(X_batch,X)];
        Roterror_batch_New_2 = [Roterror_batch_New_2 roterror(X_batch_New_2,X)];
        Roterror_batch_New_1 = [Roterror_batch_New_1 roterror(X_batch_New_1,X)];
        Roterror_kron = [Roterror_kron roterror(X_kron,X)];
        Tranerror_batch = [Tranerror_batch tranerror(X_batch,X)];
        Tranerror_batch_New_2 = [Tranerror_batch_New_2 tranerror(X_batch_New_2,X)];
        Tranerror_batch_New_1 = [Tranerror_batch_New_1 tranerror(X_batch_New_1,X)];
        Tranerror_kron = [Tranerror_kron tranerror(X_kron,X)];
        
        t_Error = [t_Error t_error];
        
    end
    
    Roterror_batch_all = [Roterror_batch_all Roterror_batch'];
    Roterror_batch_all_New_1 = [Roterror_batch_all_New_1 Roterror_batch_New_1'];
    Roterror_batch_all_New_2 = [Roterror_batch_all_New_2 Roterror_batch_New_2'];
    Roterror_kron_all = [Roterror_kron_all Roterror_kron'];
    
    Tranerror_batch_all = [Tranerror_batch_all Tranerror_batch'];
    Tranerror_batch_all_New_1 = [Tranerror_batch_all_New_1 Tranerror_batch_New_1'];
    Tranerror_batch_all_New_2 = [Tranerror_batch_all_New_2 Tranerror_batch_New_2'];
    Tranerror_kron_all = [Tranerror_kron_all Tranerror_kron'];
    
    Roterror_batch_avg = [Roterror_batch_avg mean(Roterror_batch)];
    Roterror_batch_avg_New_1 = [Roterror_batch_avg_New_1 mean(Roterror_batch_New_1)];
    Roterror_batch_avg_New_2 = [Roterror_batch_avg_New_2 mean(Roterror_batch_New_2)];
    Roterror_kron_avg = [Roterror_kron_avg mean(Roterror_kron)];
    
    Tranerror_batch_avg = [Tranerror_batch_avg mean(Tranerror_batch)];
    Tranerror_batch_avg_New_1 = [Tranerror_batch_avg_New_1 mean(Tranerror_batch_New_1)];
    Tranerror_batch_avg_New_2 = [Tranerror_batch_avg_New_2 mean(Tranerror_batch_New_2)];
    Tranerror_kron_avg = [Tranerror_kron_avg mean(Tranerror_kron)];
    
    t_Error_avg = [t_Error_avg mean(t_Error)];
    
    
end
%----------------------------------------------------------------------------------------------------------------


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
scatter((0:skip:100), Roterror_batch_avg_New_1, 'o');
hold on
scatter((0:skip:100), Roterror_batch_avg_New_2, '*');
hold on
scatter((0:skip:100), Roterror_kron_avg, '^');
hold off
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Rotation error of X')
legend('Batch Method','New Batch Method 1st Order','New Batch Method 2nd Order', 'Kronecker Product' ,'Location', 'SouthOutside')
% axis([0 100 0 4])

%%
figure
scatter((0:skip:100), Tranerror_batch_avg, '+');
hold on
scatter((0:skip:100), Tranerror_batch_avg_New_1, 'o');
hold on
scatter((0:skip:100), Tranerror_batch_avg_New_2, '*');
hold on
scatter((0:skip:100), Tranerror_kron_avg,'^');
hold off
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Translation error of X')
legend('Batch Method','New Batch Method 1st Order', 'Ned Batch Method 2nd Order', 'Kronecker Product','Location', 'SouthOutside')
axis([0 100 0 0.5])

%%
figure
scatter((0:skip:100), Roterror_batch_avg, '+');
hold on
scatter((0:skip:100), Roterror_batch_avg_New_1, 'o');
hold on
scatter((0:skip:100), Roterror_batch_avg_New_2, '*');
hold off
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Rotation error of X')
legend('Batch Method', 'New Batch Method 1st Order','New Batch Method 2nd Order','Location', 'SouthOutside')

%%
figure
% scatter((0:skip:100), Tranerror_batch_avg, '+');
% hold on
scatter((0:skip:100), Tranerror_batch_avg_New_1, 'o');
hold on
scatter((0:skip:100), Tranerror_batch_avg_New_2, '*');
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