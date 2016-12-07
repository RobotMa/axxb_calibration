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

trials = 50;

%------------------------------------------------------


x = randn(6,1); x = x./norm(x); X= expm(se3_vec(x));    %Generate a Random X

Roterror_batch_avg = [];
Roterror_kron_avg = [];
Tranerror_batch_avg = [];
Tranerror_kron_avg = [];

%Computation Loops
%---------------------------------------------------------------------------------------------------------

A_noise = [];
B = [];

Mean = [0;0;0;0;0;0];
Cov = 0.9*eye(6,6);
[A, B] = AB_genRand(X, Mean, Cov, num);

skip = 20;
for j = 1:skip:101
    
    Roterror_batch=[];
    Roterror_kron=[];
    Tranerror_batch=[];
    Tranerror_kron=[];
    
    for k = 1:trials
        % PA=randperm(size(A,3));
        % PB=randperm(size(B,3));
        
        waitbar((j*k)/(100*trials))
        
        PA = (1:size(A,3));
        PB = (1:size(B,3));
        
        for i = 1:length(PA)
            
            if rand <= 0.01*j
                index = randi(num,1);
                PA([i index]) = PA([index i]);
            end
            
        end
        
%         for i=1:length(PB)
%             
%             if rand<=0.01*j
%                 index=randi(num,1);
%                 PB([i index])=PB([index i]);
%             end
%             
%         end
        
        A_perm = A(:,:,PA);
        B_perm = B(:,:,PB);
        
%         gap=[];
%         for i=1:floor(0.05*j)
%             
%             gap=[gap randi(size(A,3),1)];
%             
%         end
%         length(gap)
%         A_perm(:,:,gap)=[];
%         B_perm(:,:,size(A_perm,3)+1:end)=[];
        
        
        
        [X_batch] = batchSolve(A_perm, B_perm);
        [X_kron] = axb_KronSolve(A_perm,B_perm);
        
        Roterror_batch = [Roterror_batch roterror(X_batch,X)];
        Roterror_kron = [Roterror_kron roterror(X_kron,X)];
        Tranerror_batch = [Tranerror_batch tranerror(X_batch,X)];
        Tranerror_kron = [Tranerror_kron tranerror(X_kron,X)];
        
    end
    
    
    Roterror_batch_avg = [Roterror_batch_avg mean(Roterror_batch)];
    Roterror_kron_avg = [Roterror_kron_avg mean(Roterror_kron)];
    Tranerror_batch_avg = [Tranerror_batch_avg mean(Tranerror_batch)];
    Tranerror_kron_avg = [Tranerror_kron_avg mean(Tranerror_kron)];
    
    
    
end
%----------------------------------------------------------------------------------------------------------------




figure(1)
scatter((0:skip:100), Roterror_batch_avg, '+');
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Rotation error of X')
hold on
scatter((0:skip:100), Roterror_kron_avg, 'o');
hold off
legend('Batch Method','Kronecker Product Method','Location', 'SouthOutside')

figure(2)
scatter((0:skip:100), Tranerror_batch_avg, '+');
xlabel('Percentage of scrambling in the A and B sets')
ylabel('Translation error of X')
hold on
scatter((0:skip:100),Tranerror_kron_avg, 'o');
hold off
legend('Batch Method','Kronecker Product Method','Location', 'SouthOutside')



