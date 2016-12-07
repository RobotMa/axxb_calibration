clc
clear
close all;

owner = 1;

if owner == 1
    addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/robot')
    addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/common')
    addpath('/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws')
elseif owner == 2
    addpath('/home/rpk/Dropbox/2014Summer/Robotics Research/rvctools/robot')
    addpath('/home/rpk/Dropbox/2014Summer/Robotics Research/rvctools/common')
    addpath('/home/rpk/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws')
end

%------------------------------------------------------
% opt == 1 : Use distribution of As and Bs
% opt == 2 : Use distribution of Xs
opt = 2;

%Editable Variables
%------------------------------------------------------

numBound = 100;	% Number of steps

breakPoint = [10 20 30 40 50 60 70 80 90 100];

gmean = [0;0;0;0;0;0];	% Gaussian Noise Mean

nstd = 0.05;  % Gaussian Noise standard deviation Range

shift = 0; % Step shift

model = 1; % Noise model

ElipseParam = [10, 10, 10];

trials = 1;

% t2 = (0:(2*pi)/((num + shift)):2*pi);
% twist = 0.0*sin(16*t2);

%     trajParam=[.5, .5, .5, 0, 0];
%     [A1, B1, X_new1]=AB_genTrajcov(X, nstd, ElipseParam, trajParam, num/3);
%
%     trajParam=[.5, .5, .5, 0, 0.5*pi];
%     [A2, B2, X_new2]=AB_genTrajcov(X, nstd, ElipseParam, trajParam, num/3);
%
%     trajParam=[.5, .5, .5, 0, pi];
%     [A3, B3, X_new3]=AB_genTrajcov(X, nstd, ElipseParam, trajParam, num/3);


%%
index = 0; % index that records the number of pairs
markerLie = zeros(1,2); % record the number of pairs and times of simulation when the Lie group method fails
dim = size(breakPoint,2);
N = 50; % Times of simulation
x = randn(6,1); X = expm(se3_vec(x));

for j = 1:N
    
    index = 0;
    
    for i = 1:numBound
        
        if    i == breakPoint(1) || i == breakPoint(2) || i == breakPoint(3)...
                || i == breakPoint(4) || i == breakPoint(5) || i == breakPoint(6)...
                || i == breakPoint(7) || i == breakPoint(8) || i == breakPoint(9)...
                || i == breakPoint(10)
            
            index = index + 1;
            numPair = i;
            
            %Trajectory Generation
            %------------------------------------------------------
            
            
            A = zeros(4,4,numPair);
            B = zeros(4,4,numPair);
            
            num = numPair + 2;
            t2 = (0:(2*pi)/((num + shift)):2*pi);
            twist = 0.0*sin(16*t2);
            
            trajParam = [.5, .5, .5, 0, 0];
            [A1, B1] = AB_genTraj(X, ElipseParam, trajParam, num/2, twist);
            
            trajParam = [.5, .5, .5, 0, 0.5*pi];
            [A2, B2] = AB_genTraj(X, ElipseParam, trajParam, num/2, twist);
            
            A = cat(3, A1, A2);
            B = cat(3, B1, B2);
            
            figure
            for i = 1:size(A1,3)
                trplot(A1(:,:,i));
                hold on
            end
            %-------------------------------------------------------
            if  opt == 1
                
                B = sensorNoise(B, gmean, nstd, 1);
                
            elseif opt ==2
                
                [A, X_dist] = A_NoiseX(B, X, gmean, nstd, 1);
                
            end
            
            %% Solution for X
            %-------------------------------------------------------
            
            X_andreff(1:4,1:4,index) = andreff( A, B );
            X_chou(1:4,1:4,index) = chou( A, B );
            X_horaud(1:4,1:4,index) = horaud( A, B );
            X_lu8(1:4,1:4,index) = lu8( A, B );
            X_park(1:4,1:4,index) = park( A, B );
            X_shiu(1:4,1:4,index) = shiu( A, B );
            X_tasi(1:4,1:4,index) = tsai( A, B );
            
            
            % roterror and tranerror
            %--------------------------------------------------------
            rotError_andreff(index,j) = roterror(X, X_andreff(:,:,index));
            tranError_andreff(index,j) = tranerror(X, X_andreff(:,:,index));
            
            rotError_chou(index,j) = roterror(X, X_chou(:,:,index));
            tranError_chou(index,j) = tranerror(X, X_chou(:,:,index));
            
            rotError_horaud(index,j) = roterror(X, X_horaud(:,:,index));
            tranError_horaud(index,j) = tranerror(X, X_horaud(:,:,index));
            
            rotError_lu8(index,j) = roterror(X, X_lu8(:,:,index));
            tranError_lu8(index,j) = tranerror(X, X_lu8(:,:,index));
            
            rotError_park(index,j) = roterror(X, X_park(:,:,index));
            tranError_park(index,j) = tranerror(X, X_park(:,:,index));
            
            rotError_shiu(index,j) = roterror(X, X_shiu(:,:,index));
            tranError_shiu(index,j) = tranerror(X, X_shiu(:,:,index));
            
            rotError_tsai(index,j) = roterror(X, X_tasi(:,:,index));
            tranError_tsai(index,j) = tranerror(X, X_tasi(:,:,index));
            
            %             % error covariance matrix for the twist
            %             % the 6 parameters for the Lie Group
            %             %--------------------------------------------------------
            %             % display('Kronecker')
            %             S_kron = errorCovariance(A, B, X_kron(:,:,index));
            %             S_Lie = errorCovariance(A, B, X_Lie(:,:,index));
            %             S_quat = errorCovariance(A, B, X_andreff(:,:,index));
            %             S_dual = errorCovariance(A, B, X_chou(:,:,index));
            %
            %             % trace of the error covariance matrix
            %             %-------------------------------------------------------
            %             tr_kron(index,j) = trace(S_kron);
            %             tr_Lie(index,j) = trace(S_Lie);
            %             tr_quat(index,j) = trace(S_quat);
            %             tr_dual(index,j) = trace(S_dual);
            
            
        end
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
plot([breakPoint],rotErrorAndreff,'c')
hold on
plot([breakPoint],rotErrorChou,'r')
hold on
plot([breakPoint],rotErrorHoraud,'b')
hold on
% plot([breakPoint],rotErrorLu8,'g')
hold on
plot([breakPoint],rotErrorPark,'m')
hold on
plot([breakPoint],rotErrorShiu,'k')
hold on
plot([breakPoint],rotErrorTsai,'y')

xlabel('Number of AB Pairs')
ylabel('Rotation Error')
title('Rotation Error')

legend('Andreff','Chou','Horaud','Lu8','Park','Shiu','Tsai')


%%
figure
plot([breakPoint],tranErrorAndreff,'c')
hold on
plot([breakPoint],tranErrorChou,'r')
hold on
plot([breakPoint],tranErrorHoraud,'b')
hold on
% plot([breakPoint],tranErrorLu8,'g')
hold on
plot([breakPoint],tranErrorPark,'m')
hold on
plot([breakPoint],tranErrorShiu,'k')
hold on
plot([breakPoint],tranErrorTsai,'y')

xlabel('Number of AB Pairs')
ylabel('tranation Error')
title('tranation Error')

legend('Andreff','Chou','Horaud','Lu8','Park','Shiu','Tsai')



%%