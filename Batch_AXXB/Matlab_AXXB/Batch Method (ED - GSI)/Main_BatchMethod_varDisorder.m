%AXXB - Fixing Temporal Misalignment

%Required function list:
%AB_gen().m
%noise_Gauss().m
%param_extract().m
%se3_vec().m
%so3_vec().m

clear; clc; close all;

addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/robot')
addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/common')

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

trials = 1;

%------------------------------------------------------


x = randn(6,1); x = x./norm(x); X= expm(se3_vec(x));    %Generate a Random X

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

opt = 1; % A & B generation method

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

skip = 50;
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
    
    
    Roterror_batch_avg = [Roterror_batch_avg mean(Roterror_batch)];
    Roterror_batch_avg_New_2 = [Roterror_batch_avg_New_2 mean(Roterror_batch_New_2)];
    Roterror_batch_avg_New_1 = [Roterror_batch_avg_New_1 mean(Roterror_batch_New_1)];
    Roterror_kron_avg = [Roterror_kron_avg mean(Roterror_kron)];
    Tranerror_batch_avg = [Tranerror_batch_avg mean(Tranerror_batch)];
    Tranerror_batch_avg_New_2 = [Tranerror_batch_avg_New_2 mean(Tranerror_batch_New_2)];
    Tranerror_batch_avg_New_1 = [Tranerror_batch_avg_New_1 mean(Tranerror_batch_New_1)];
    Tranerror_kron_avg = [Tranerror_kron_avg mean(Tranerror_kron)];
    
    t_Error_avg = [t_Error_avg mean(t_Error)];
    
    
end
%----------------------------------------------------------------------------------------------------------------



%%
figure(1)
scatter((0:skip:100), Roterror_batch_avg, '+');
hold on
scatter((0:skip:100), Roterror_batch_avg_New_2, '*');
hold on
scatter((0:skip:100), Roterror_batch_avg_New_1, 'o');
hold off
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Rotation error of X')
legend('Batch Method','New Batch Method 2nd Order', 'New Batch Method 1st Order', 'Location', 'SouthOutside')

figure(2)
scatter((0:skip:100), Tranerror_batch_avg, '+');
hold on
scatter((0:skip:100), Tranerror_batch_avg_New_2, '*');
hold on
scatter((0:skip:100), Tranerror_batch_avg_New_1, 'o');
hold off
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Translation error of X')
legend('Batch Method','Ned Batch Method 2nd Order', 'New Batch Method 1st Order','Location', 'SouthOutside')


%%
% By improving the accuracy of the translation of the new means of A and B,
% using the 2nd order constraint, the translation of the solved X does
% improve a lot compared to the pure 1st order approximation. However, it
% is still not comparable to that of the old Batch
