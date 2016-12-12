%AXXB - Fixing Temporal Misalignment

%Required function list:
%AB_gen().m
%noise_Gauss().m
%param_extract().m
%se3_vec().m
%so3_vec().m

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num = 300;	% Number of steps

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

nstd  = 0;	% Gaussian Noise standard deviation Range

shift = 0;  % Step shift

n = 1;      % VP(n)

window = 0; % Target correlation area

model  = 1; % Noise model


t2 = (0:(2*pi)/((num+shift)):2*pi);
twist = 0.0*sin(16*t2);

ElipseParam = [10, 20, 30];

trials = 1;

%------------------------------------------------------


x=randn(6,1); x=x./norm(x); X = expm(se3_vec(x));    %Generate a Random X

Roterror_batch_avg = [];
Roterror_kron_avg  = [];
Tranerror_batch_avg = [];
Tranerror_kron_avg  = [];



%% Computation Loops
%---------------------------------------------------------------------------------------------------------


skip = 0.25;
min = 0.1; % where do these thresholds come from ??
max = 1.6;


for j = min:skip:max
    
    Roterror_batch = [];
    Roterror_kron  = [];
    Tranerror_batch = [];
    Tranerror_kron  = [];
    
    for k = 1:trials
        
        waitbar(((j/skip)*trials+k)/((max/skip)*trials))
        
        A = [];
        B = [];
        
        Mean = [0; 0; 0; 0; 0; 0];
        Cov = j*eye(6,6);
        [A, B] = AB_genRand(X, Mean, Cov, num);
        
        gap_size = 1;
%         [A, B]=AB_genTraj_gap(X, ElipseParam, num+shift+1, twist, gap_size);
        
        [MeanA, SigA] = distibutionProps(A);
        [MeanB, SigB] = distibutionProps(B);
        
        PA = randperm(size(A,3));
        PB = randperm(size(B,3));
        
        A_perm = A(:,:,PA);
        B_perm = B(:,:,PB);
        
        
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
%         
%         gap=[];
%         for i=1:ceil(100*j)
%             
%             gap=[gap randi(size(A,3),1)];
%             
%         end
%         length(gap)

%         A_noise(:,:,gap)=[];
%         B_noise=B;
        
%         A_noise2=A_noise;
%         B_noise2=B_noise;
%         B_noise2(:,:,size(A_noise2,3)+1:end)=[];
        
        
        
        
        %         A_noise=sensorNoise(A_perm,gmean,j,1);
        %         B_noise=sensorNoise(B_perm,gmean,j,1);
        %
        %         A_noise2=sensorNoise(A,gmean,j,1);
        %         B_noise2=sensorNoise(B,gmean,j,1);
        
        
        [X_batch] = batchSolve(A_perm, B_perm)
%         [X_kron]=axb_KronSolve(A_perm,B_perm)
        
        Roterror_batch = [Roterror_batch roterror(X_batch,X)];
%         Roterror_kron=[Roterror_kron roterror(X_kron,X)];
        Tranerror_batch = [Tranerror_batch tranerror(X_batch,X)];
%         Tranerror_kron=[Tranerror_kron tranerror(X_kron,X)];
        
    end
    
    Roterror_batch_avg = [Roterror_batch_avg mean(Roterror_batch)];
%     Roterror_kron_avg=[Roterror_kron_avg mean(Roterror_kron)];
    Tranerror_batch_avg = [Tranerror_batch_avg mean(Tranerror_batch)];
%     Tranerror_kron_avg=[Tranerror_kron_avg mean(Tranerror_kron)];
    
    
end
%----------------------------------------------------------------------------------------------------------------




figure(1)
scatter((min:skip:max), Roterror_batch_avg, '+');
xlabel('Noise on the A and B sets')
ylabel('Rotation error of X')
% hold on
% scatter((min:skip:max), Roterror_kron_avg, 'o');
% hold off
legend('Batch Method','Kronecker Product Method','Location', 'SouthOutside')

figure(2)
scatter((min:skip:max), Tranerror_batch_avg, '+');
xlabel('Noise on the A and B sets')
ylabel('Translation error of X')
% hold on
% scatter((min:skip:max),Tranerror_kron_avg, 'o');
% hold off
legend('Batch Method','Kronecker Product Method','Location', 'SouthOutside')



