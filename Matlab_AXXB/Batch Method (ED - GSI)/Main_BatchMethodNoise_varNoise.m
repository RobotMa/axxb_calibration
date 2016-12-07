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

num=50;	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

nstd=0;	%Gaussian Noise standard deviation Range

shift=0; %step shift

n=1;      %VP(n)

window=0;    %target correlation area

model=1;        %noise model


t2=(0:(2*pi)/((num+shift)):2*pi);
twist=0.0*sin(16*t2);

ElipseParam=[10, 20, 30];

trials=4;

%------------------------------------------------------


x=randn(6,1); x=x./norm(x); X=expm(se3_vec(x));    %Generate a Random X

Roterror_batch_avg=[];
Roterror_kron_avg=[];
Roterror_batchNoise_avg=[];
Tranerror_batch_avg=[];
Tranerror_kron_avg=[];
Tranerror_batchNoise_avg=[];



%Computation Loops
%---------------------------------------------------------------------------------------------------------

A=[];
B=[];

Mean=[0;0;0;0;0;0];
Cov=0.9*eye(6,6);
[A, B]=AB_genRand(X, Mean, Cov, num);

skip=0.01;
min=0;
max=0.05;


for j=min:skip:max
    
    Roterror_batch=[];
    Roterror_kron=[];
    Roterror_batchNoise=[];
    Tranerror_batch=[];
    Tranerror_kron=[];
    Tranerror_batchNoise=[];
    
    for k=1:trials
        
        waitbar(((j/skip)*trials+k)/((max/skip)*trials))
        
        A=[];
        B=[];
        
        Mean=[0;0;0;0;0;0];
        Cov=0.9*eye(6,6);
        [A, B]=AB_genRand(X, Mean, Cov, num);
        
        
        PA=randperm(size(A,3));
        PB=randperm(size(B,3));
        
        A_perm=A(:,:,PA);
        B_perm=B(:,:,PB);
                
        A_noise=sensorNoise(A_perm,gmean,j,1);
        B_noise=sensorNoise(B_perm,gmean,j,1);
        
        A_noise2=sensorNoise(A,gmean,j,1);
        B_noise2=sensorNoise(B,gmean,j,1);
        
        X
        [X_batch,MeanA,MeanB,SigA,SigB] = batchSolve(A_noise, B_noise);
        
        X_batch
        
        [X_batchNoise,SigX] = batchSolveNoise(MeanA,MeanB,X_batch,SigA,SigB);        
        
        
        [X_kron] = axb_KronSolve(A_noise2,B_noise2);
        
        Roterror_batch = [Roterror_batch roterror(X_batch,X)];
        Roterror_batchNoise = [Roterror_batchNoise roterror(X_batchNoise,X)];
        Roterror_kron = [Roterror_kron roterror(X_kron,X)];
        Tranerror_batch = [Tranerror_batch tranerror(X_batch,X)];
        Tranerror_batchNoise = [Tranerror_batchNoise tranerror(X_batchNoise,X)];        
        Tranerror_kron = [Tranerror_kron tranerror(X_kron,X)];
        
    end
    
    Roterror_batch_avg = [Roterror_batch_avg mean(Roterror_batch)];    
    Roterror_batchNoise_avg = [Roterror_batchNoise_avg mean(Roterror_batchNoise)];
    Roterror_kron_avg = [Roterror_kron_avg mean(Roterror_kron)];
    Tranerror_batch_avg = [Tranerror_batch_avg mean(Tranerror_batch)];
    Tranerror_batchNoise_avg = [Tranerror_batchNoise_avg mean(Tranerror_batchNoise)];
    Tranerror_kron_avg = [Tranerror_kron_avg mean(Tranerror_kron)];
    
    
end
%----------------------------------------------------------------------------------------------------------------




figure(1)
scatter((min:skip:max), Roterror_batch_avg, '+');
xlabel('Noise on the A and B sets')
ylabel('Rotation error of X')
hold on
scatter((min:skip:max), Roterror_kron_avg, 'o');
scatter((min:skip:max), Roterror_batchNoise_avg, 'x');
hold off
legend('Batch Method','Kronecker Product Method','Location', 'SouthOutside')

figure(2)
scatter((min:skip:max), Tranerror_batch_avg, '+');
xlabel('Noise on the A and B sets')
ylabel('Translation error of X')
hold on
scatter((min:skip:max),Tranerror_kron_avg, 'o');
scatter((min:skip:max),Tranerror_batchNoise_avg, 'x');
hold off
legend('Batch Method','Kronecker Product Method','Location', 'SouthOutside')



