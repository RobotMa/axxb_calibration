%AXXB - Fixing Temporal Misalignment

%Required function list:
%AB_gen().m
%noise_Gauss().m
%param_extract().m
%se3_vec().m
%so3_vec().m

clear; clc; close all;

addpath('/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws')
addpath('/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/util')

%Editable Variables
%------------------------------------------------------

num = 100;	%Number of steps

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

nstd = 0;	%Gaussian Noise standard deviation Range

shift = 0; %step shift

n = 1;      %VP(n)

window = 0;    %target correlation area

model = 1;        %noise model


t2 = (0:(2*pi)/((num+shift)):2*pi);
twist = 0.0*sin(16*t2);

ElipseParam = [10, 20, 30];

trials = 80;

%------------------------------------------------------


x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x));    %Generate a Random X

Roterror_batch_all = [];
Roterror_batch_all_New = [];

Roterror_batch_avg = [];
Roterror_batch_avg_New = [];
Roterror_kron_avg = [];
% Roterror_batchNoise_avg = [];
Tranerror_batch_avg = [];
Tranerror_batch_avg_New = [];
Tranerror_kron_avg = [];
% Tranerror_batchNoise_avg = [];



%Computation Loops
%---------------------------------------------------------------------------------------------------------

A = [];
B = [];

Mean = [0;0;0;0;0;0];
Cov = 0.9*eye(6,6);
[A, B] = AB_genRand(X, Mean, Cov, num);

skip = 0.001;
min = 0;
max = 0.01;
% noise_level = min:skip:max;
noise_level = [0, 0.001, 0.002, 0.005, 0.01, 0.02, 0.05];

opt = 2;


% for j = min:skip:max
for j = 1:length(noise_level)
    
    Roterror_batch = [];
    Roterror_batch_New = [];
    Roterror_kron = [];
    %     Roterror_batchNoise = [];
    Tranerror_batch = [];
    Tranerror_batch_New = [];
    Tranerror_kron = [];
    %     Tranerror_batchNoise = [];
    
    for k = 1:trials
        
        %         waitbar(((j/skip)*trials+k)/((max/skip)*trials))
        
        A = [];
        B = [];
        
        %         Mean = [0.5; 0.5; 0.5; 0.5; 0.5; 0.5];
        Mean = [0; 0; 0; 0; 0; 0];
        Cov = 0.9*eye(6,6);
%         [A, B] = AB_genRand(X, Mean, Cov, num);
        
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
        
        
        PA = randperm(size(A, 3));
        PB = randperm(size(B, 3));
        
        A_perm = A(:, :, PA);
        B_perm = B(:, :, PB);
        
        n_j = noise_level(j);
        
        A_noise = sensorNoise(A_perm, gmean, n_j, 1);
        B_noise = sensorNoise(B_perm, gmean, n_j, 1);
        
        A_noise2 = sensorNoise(A,gmean, n_j, 1);
        B_noise2 = sensorNoise(B,gmean, n_j, 1);
        
        %         X
        [X_batch, MeanA, MeanB] = batchSolve(A_noise, B_noise);
        
        %         X_batch
        
        %         [X_batchNoise, SigX] = batchSolveNoise(MeanA, MeanB, X_batch, SigA, SigB);
        
        [X_batch_New] = batchSolveNew(A_noise, B_noise, 2);
        
        [X_kron] = axb_KronSolve(A_noise2, B_noise2);
        
        Roterror_batch = [Roterror_batch roterror(X_batch,X)];
        Roterror_batch_New = [Roterror_batch_New roterror(X_batch_New,X)];
        %         Roterror_batchNoise = [Roterror_batchNoise roterror(X_batchNoise,X)];
        Roterror_kron = [Roterror_kron roterror(X_kron,X)];
        Tranerror_batch = [Tranerror_batch tranerror(X_batch,X)];
        Tranerror_batch_New = [Tranerror_batch_New tranerror(X_batch_New,X)];
        %         Tranerror_batchNoise = [Tranerror_batchNoise tranerror(X_batchNoise,X)];
        Tranerror_kron = [Tranerror_kron tranerror(X_kron,X)];
        
    end
    
    Roterror_batch_all = [Roterror_batch_all Roterror_batch'];
    Roterror_batch_all_New = [Roterror_batch_all_New Roterror_batch_New'];
    
    Roterror_batch_avg = [Roterror_batch_avg mean(Roterror_batch)];
    Roterror_batch_avg_New = [Roterror_batch_avg_New mean(Roterror_batch_New)];
    %     Roterror_batchNoise_avg = [Roterror_batchNoise_avg mean(Roterror_batchNoise)];
    Roterror_kron_avg = [Roterror_kron_avg mean(Roterror_kron)];
    Tranerror_batch_avg = [Tranerror_batch_avg mean(Tranerror_batch)];
    Tranerror_batch_avg_New = [Tranerror_batch_avg_New mean(Tranerror_batch_New)];
    %     Tranerror_batchNoise_avg = [Tranerror_batchNoise_avg mean(Tranerror_batchNoise)];
    Tranerror_kron_avg = [Tranerror_kron_avg mean(Tranerror_kron)];
    
    
end
%----------------------------------------------------------------------------------------------------------------

%%


figure(1)
% scatter((min:skip:max), Roterror_kron_avg, 'o');
scatter(noise_level, Roterror_kron_avg, 'o');
hold on
% scatter((min:skip:max), Roterror_batch_avg, '+');
scatter( noise_level, Roterror_batch_avg, '+');

hold on
% scatter((min:skip:max), Roterror_batch_avg_New, 'x');
scatter(noise_level, Roterror_batch_avg_New, 'x');

hold off
xlabel('Noise on the A and B sets')
ylabel('Rotation error of X')
legend('Kronecker Product Method','Batch Method','New Batch Method','Location', 'SouthOutside')

figure(2)
% scatter((min:skip:max),Tranerror_kron_avg, 'o');
scatter( noise_level,Tranerror_kron_avg, 'o');

hold on
% scatter((min:skip:max), Tranerror_batch_avg, '+');
scatter( noise_level, Tranerror_batch_avg, '+');

hold on
% scatter((min:skip:max),Tranerror_batch_avg_New, 'x');
scatter( noise_level,Tranerror_batch_avg_New, 'x');
hold off
xlabel('Noise on the A and B sets')
ylabel('Translation error of X')
legend('Kronecker Product Method','Batch Method','New Batch Method','Location', 'SouthOutside')


%%
range =  length(noise_level);
figure(3)
boxplot(Roterror_batch_all(:,1:range),noise_level)
ylabel('Old Batch Method')
axis([0 12 0 0.08])

%%
figure(4)
boxplot(Roterror_batch_all_New(:,1:range), noise_level)
ylabel('New Batch Method')
axis([0 12 0 0.08])
