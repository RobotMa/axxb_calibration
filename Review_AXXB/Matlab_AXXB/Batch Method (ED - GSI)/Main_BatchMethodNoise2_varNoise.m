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

num=100;	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

nstd=0;	%Gaussian Noise standard deviation Range

shift=0; %step shift

n=1;      %VP(n)

window=0;    %target correlation area

model=1;        %noise model


t2=(0:(2*pi)/((num+shift)):2*pi);
twist=0.0*sin(16*t2);

ElipseParam=[10, 20, 30];

trials=2;

%------------------------------------------------------


x=randn(6,1); x=x./norm(x); X=expm(se3_vec(x));    %Generate a Random X

Roterror_batch_avg=[];
Roterror_kron_avg=[];
Roterror_batchNoise2_avg=[];
Tranerror_batch_avg=[];
Tranerror_kron_avg=[];
Tranerror_batchNoise2_avg=[];



%Computation Loops
%---------------------------------------------------------------------------------------------------------

A=[];
B=[];

skip=0.01;
min=0.02;
max=0.05;


for j=min:skip:max
    
    Roterror_batch=[];
    Roterror_kron=[];
    Roterror_batchNoise2=[];
    Tranerror_batch=[];
    Tranerror_kron=[];
    Tranerror_batchNoise2=[];
    
    for k=1:trials
        waitbar(((j/skip)*trials+k)/((max/skip)*trials))
        
        
        Mean=[0;0;0;0;0;0];
        Cov=0.3*eye(6,6);
        [A, B]=AB_genRand(X, Mean, Cov, num);
        
        [MeanA, SigA]=distibutionProps(A);
        [MeanB, SigB]=distibutionProps(B);
        
%         PA=randperm(size(A,3));
%         PB=randperm(size(B,3));
        
        
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
        
%         A_perm=A(:,:,PA);
%         B_perm=B(:,:,PB);
        
%         gap=[];
%         for i=1:ceil(100*j)
%             
%             gap=[gap randi(size(A,3),1)];
%             
%         end
%         length(gap)
%         A_perm(:,:,gap)=[];
%         B_perm(:,:,size(A_perm,3)+1:end)=[];
%         A_noise=A_perm;
%         B_noise=B_perm;
%         
        
        [A_noise, A_MeanNoise, A_SigNoise]=sensorNoise2(A,gmean,j,1);
        [B_noise, B_MeanNoise, B_SigNoise]=sensorNoise2(B,gmean,j,1);
        
        X
        [X_batch,~,~,~,~]=batchSolve(A_noise, B_noise);
        
        X_batch
        
        [X_batchNoise2,MeanA_noise,MeanB_noise,MeanA_deconv,MeanB_deconv,SigA_noise,SigB_noise,SigA_deconv,SigB_deconv]=batchSolveNoise2(A_noise,B_noise, A_SigNoise, B_SigNoise, A_MeanNoise, B_MeanNoise);        
        
        
        
        roterror(MeanA_noise, MeanA)
        roterror(MeanA_deconv, MeanA)        
        
        tranerror(MeanA_noise, MeanA)
        tranerror(MeanA_deconv, MeanA)
        
        norm(norm(SigA-SigA_noise))
        norm(norm(SigA-SigA_deconv))
        
        ErrorR1=roterror(X_batch,X)
        ErrorR2=roterror(X_batchNoise2,X)
        
        ErrorT1=tranerror(X_batch,X)
        ErrorT2=tranerror(X_batchNoise2,X)
        
        
        
        X_batchNoise2
        
        [X_kron]=axb_KronSolve(A_noise,B_noise);
        
        Roterror_batch=[Roterror_batch roterror(X_batch,X)];
        Roterror_batchNoise2=[Roterror_batchNoise2 roterror(X_batchNoise2,X)];
        Roterror_kron=[Roterror_kron roterror(X_kron,X)];
        Tranerror_batch=[Tranerror_batch tranerror(X_batch,X)];
        Tranerror_batchNoise2=[Tranerror_batchNoise2 tranerror(X_batchNoise2,X)];        
        Tranerror_kron=[Tranerror_kron tranerror(X_kron,X)];
        
    end
    
    Roterror_batch_avg=[Roterror_batch_avg mean(Roterror_batch)];    
    Roterror_batchNoise2_avg=[Roterror_batchNoise2_avg mean(Roterror_batchNoise2)];
    Roterror_kron_avg=[Roterror_kron_avg mean(Roterror_kron)];
    Tranerror_batch_avg=[Tranerror_batch_avg mean(Tranerror_batch)];
    Tranerror_batchNoise2_avg=[Tranerror_batchNoise2_avg mean(Tranerror_batchNoise2)];
    Tranerror_kron_avg=[Tranerror_kron_avg mean(Tranerror_kron)];
    
    
end
%----------------------------------------------------------------------------------------------------------------




figure(1)
scatter((min:skip:max), Roterror_batch_avg, '+');
xlabel('Noise on the A and B sets')
ylabel('Rotation error of X')
hold on
scatter((min:skip:max), Roterror_kron_avg, 'o');
scatter((min:skip:max), Roterror_batchNoise2_avg, 'x');
hold off
legend('Batch Method','Kronecker Product Method','Batch Noise Method','Location', 'SouthOutside')

figure(2)
scatter((min:skip:max), Tranerror_batch_avg, '+');
xlabel('Noise on the A and B sets')
ylabel('Translation error of X')
hold on
scatter((min:skip:max),Tranerror_kron_avg, 'o');
scatter((min:skip:max),Tranerror_batchNoise2_avg, 'x');
hold off
legend('Batch Method','Kronecker Product Method','Batch Noise Method','Location', 'SouthOutside')



