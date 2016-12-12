clc
clear all
close all

addpath('H:/Dropbox/2014Summer/Robotics Research/rvctools/robot')
addpath('H:/Dropbox/2014Summer/Robotics Research/rvctools/common')
addpath('H:/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws')

% addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/robot')
% addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/common')
% addpath('/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws')

%------------------------------------------------------
% opt == 1 : Use distribution of As and Bs
% opt == 2 : Use distribution of Xs
opt = 1;

%Editable Variables
%------------------------------------------------------

numPair = 40;	%Number of steps

breakPoint = [10 20 30 40 50 60 70 80 90 100];

gmean = [0; 0; 0; 0; 0; 0];	%Gaussian Noise Mean

nstd = [0.001 0.005 0.01 0.02 0.05 0.1];  %Gaussian Noise standard deviation Range

shift = 0; %step shift

model = 1; %noise model

ElipseParam = [10, 10, 10];

trials = 1;

% t2 = (0:(2*pi)/((num + shift)):2*pi);
% twist = 0.0*sin(16*t2);

%%
i = 0; % i that records the number of pairs
markerLie = zeros(1,2); % record the number of pairs and times of simulation when the Lie group method fails
dim = size(nstd,2);
N = 100; % Times of simulation
x = randn(6,1); X = expm(se3_vec(x));

for i = 1:dim
    
    nstdChosen = nstd(1,i);
    for j = 1:N
        
        %Trajectory Generation
        %------------------------------------------------------
        
        
        A = zeros(4,4,numPair);
        B = zeros(4,4,numPair);
        
        for k = 1:numPair
            [A(:,:,k), B(:,:,k)] = ABPair1(X);
        end
        
        %-------------------------------------------------------
        if  opt == 1
            
            B = sensorNoise(B, gmean, nstdChosen, 1);
            
        elseif opt ==2
            
            [A, X_dist] = A_NoiseX(B, X, gmean, nstdChosen, 1);
            
        end
        
        %% Solution for X
        %-------------------------------------------------------
        
        X_andreff(1:4,1:4,j) = andreff( A, B );
        X_chou(1:4,1:4,j) = chou( A, B );
        X_horaud(1:4,1:4,j) = horaud( A, B );
        X_lu8(1:4,1:4,j) = lu8( A, B );
        X_park(1:4,1:4,j) = park( A, B );
        X_shiu(1:4,1:4,j) = shiu( A, B );
        X_tasi(1:4,1:4,j) = tsai( A, B );
        
        
        % roterror and tranerror
        %--------------------------------------------------------
        rotError_andreff(i,j) = roterror(X, X_andreff(:,:,j));
        tranError_andreff(i,j) = tranerror(X, X_andreff(:,:,j));
        
        rotError_chou(i,j) = roterror(X, X_chou(:,:,j));
        tranError_chou(i,j) = tranerror(X, X_chou(:,:,j));
        
        rotError_horaud(i,j) = roterror(X, X_horaud(:,:,j));
        tranError_horaud(i,j) = tranerror(X, X_horaud(:,:,j));
        
        rotError_lu8(i,j) = roterror(X, X_lu8(:,:,j));
        tranError_lu8(i,j) = tranerror(X, X_lu8(:,:,j));
        
        rotError_park(i,j) = roterror(X, X_park(:,:,j));
        tranError_park(i,j) = tranerror(X, X_park(:,:,j));
        
        rotError_shiu(i,j) = roterror(X, X_shiu(:,:,j));
        tranError_shiu(i,j) = tranerror(X, X_shiu(:,:,j));
        
        rotError_tsai(i,j) = roterror(X, X_tasi(:,:,j));
        tranError_tsai(i,j) = tranerror(X, X_tasi(:,:,j));
        
        
    end
end

%%
rotErrorAndreff = sum(rotError_andreff,2)/N;
rotErrorChou = sum(rotError_chou,2)/N;
rotErrorHoraud = sum(rotError_horaud,2)/N;
rotErrorLu8 = sum(rotError_lu8,2)/N;
rotErrorPark = sum(rotError_park,2)/N;
rotErrorShiu = sum(rotError_shiu,2)/N;
rotErrorTsai = sum(rotError_tsai,2)/N;


tranErrorAndreff = sum(tranError_andreff,2)/N;
tranErrorChou = sum(tranError_chou,2)/N;
tranErrorHoraud = sum(tranError_horaud,2)/N;
tranErrorLu8 = sum(tranError_lu8,2)/N;
tranErrorPark = sum(tranError_park,2)/N;
tranErrorShiu = sum(tranError_shiu,2)/N;
tranErrorTsai = sum(tranError_tsai,2)/N;


%%
figure
plot(nstd,rotErrorAndreff,'c')
hold on
plot(nstd,rotErrorChou,'r')
hold on
plot(nstd,rotErrorHoraud,'b')
hold on
plot(nstd,rotErrorLu8,'g')
hold on
plot(nstd,rotErrorPark,'m')
hold on
plot(nstd,rotErrorShiu,'k')
hold on
plot(nstd,rotErrorTsai,'y')

xlabel('Noise Level')
ylabel('Rotation Error')
title('Rotation Error vs Noise Level')

legend('Andreff','Chou','Horaud','Lu8','Park','Shiu','Tsai')
% legend('Andreff','Horaud','Park','Shiu','Tsai')


%%
figure
plot(nstd,tranErrorAndreff,'c')
hold on
plot(nstd,tranErrorChou,'r')
hold on
plot(nstd,tranErrorHoraud,'b')
hold on
plot(nstd,tranErrorLu8,'g')
hold on
plot(nstd,tranErrorPark,'m')
hold on
plot(nstd,tranErrorShiu,'k')
hold on
plot(nstd,tranErrorTsai,'y')

xlabel('Noise Level')
ylabel('Translation Error')
title('Translation Error vs Noise Level')

legend('Andreff','Chou','Horaud','Lu8','Park','Shiu','Tsai')
% legend('Andreff','Horaud','Park','Shiu','Tsai')
