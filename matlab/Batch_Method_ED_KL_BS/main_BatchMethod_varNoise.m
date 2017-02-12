% AXXB - Fixing Temporal Misalignment

% Required function list:
% AB_gen().m
% noise_Gauss().m
% param_extract().m
% se3_vec().m
% so3_vec().m

% Fist written by M. Kendal Ackerman 
% Edited by Qianli Ma

clear; clc; close all;

addpath ../../../kinematics/kinematics/screws
addpath ../../../kinematics/kinematics/util
%% Editable Variables
% ------------------------------------------------------

num = 50;	% Number of steps

gmean = [0; 0; 0; 0; 0; 0];	% Gaussian Noise Mean

nstd = 0;	% Gaussian Noise standard deviation Range

shift = 0;  % step shift

n = 1;      % VP(n)

window = 0; % target correlation area

model = 1;  % noise model


t2 = (0 : (2*pi)/((num+shift)) : 2*pi);
twist = 0.0*sin(16*t2);

ElipseParam = [10, 20, 30];

trials = 20;

% ------------------------------------------------------


%%
x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x)); % Generate a Random X

Roterror_batch_avg  = [];
Roterror_kron_avg   = []; 
Tranerror_batch_avg = [];
Tranerror_kron_avg  = [];



% Computation Loops
% ---------------------------------------------------------------------------------------------------------


skip = 0.05;
min  = 0;
max  = 0.2;


for j = min:skip:max
     
    Roterror_batch  = [];
    Roterror_kron   = [];
    Tranerror_batch = [];
    Tranerror_kron  = [];
    
    for k = 1:trials
        
        waitbar( ((j/skip)*trials + k) / ((max/skip)*trials) )
        
        A = [];
        B = [];
        
        %         Mean=[0;0;0;0;0;0];
        %         Cov=0.1*eye(6,6);
        %         [A, B]=AB_genRand(X, Mean, Cov, num);
        
        gap_size = 1;
        [A, B] = AB_genTraj_gap(X, ElipseParam, num + shift + 1, twist, gap_size);
        
        [MeanA, SigA] = distibutionProps(A, 1);
        [MeanB, SigB] = distibutionProps(B, 1);
        
        %         PA=randperm(size(A,3));
        %         PB=randperm(size(B,3));
        %
        %         A_perm=A(:,:,PA);
        %         B_perm=B(:,:,PB);
        
        
        % PA=(1:size(A,3));
        % PB=(1:size(B,3));
        %
        % for i=1:length(PA)
        %
        %     if rand<=0.01*j
        %         index=randi(num,1);
        %         PA([i index])=PA([index i]);
        %     end
        %
        % end
        %
        % for i=1:length(PB)
        %
        %     if rand<=0.01*j
        %         index=randi(num,1);
        %         PB([i index])=PB([index i]);
        %     end
        %
        % end
        
        %         A_noise=A;
        
        %         gap=[];
        %         for i=1:ceil(100*j)
        %
        %             gap=[gap randi(size(A,3),1)];
        %
        %         end
        %         length(gap)
        %
        %         A_noise(:,:,gap)=[];
        %         B_noise=B;
        %
        %         A_noise2=A_noise;
        %         B_noise2=B_noise;
        %         B_noise2(:,:,size(A_noise2,3)+1:end)=[];
        
        
        
        
        %         A_noise=sensorNoise(A_perm,gmean,j,1);
        %         B_noise=sensorNoise(B_perm,gmean,j,1);
        %
        A_noise2 = sensorNoise(A,gmean,j,6);
        B_noise2 = B;
        
        
        %         [X_batch]=batchSolve(A_noise, B_noise);
        [X_batch]=batchSolve(A_noise2, B_noise2);
        [X_kron]=axb_KronSolve(A_noise2,B_noise2);
        
        Roterror_batch=[Roterror_batch roterror(X_batch,X)];
        Roterror_kron=[Roterror_kron roterror(X_kron,X)];
        Tranerror_batch=[Tranerror_batch tranerror(X_batch,X)];
        Tranerror_kron=[Tranerror_kron tranerror(X_kron,X)];
        
    end
    
    Roterror_batch_avg=[Roterror_batch_avg mean(Roterror_batch)];
    Roterror_kron_avg=[Roterror_kron_avg mean(Roterror_kron)];
    Tranerror_batch_avg=[Tranerror_batch_avg mean(Tranerror_batch)];
    Tranerror_kron_avg=[Tranerror_kron_avg mean(Tranerror_kron)];
    
    
end
%----------------------------------------------------------------------------------------------------------------




figure(1)
scatter((min:skip:max), Roterror_batch_avg, '+');
xlabel('Noise on the A and B sets')
ylabel('Rotation error of X')
hold on
scatter((min:skip:max), Roterror_kron_avg, 'o');
hold off
legend('Batch Method','Kronecker Product Method','Location', 'SouthOutside')

figure(2)
scatter((min:skip:max), Tranerror_batch_avg, '+');
xlabel('Noise on the A and B sets')
ylabel('Translation error of X')
hold on
scatter((min:skip:max),Tranerror_kron_avg, 'o');
hold off
legend('Batch Method','Kronecker Product Method','Location', 'SouthOutside')



