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
opt = 0;

%Editable Variables
%------------------------------------------------------

numBound = 10;	% Number of steps

breakPoint = [10 20 30 40 50 60 70 80 90 100];

gmean = [0;0;0;0;0;0];	% Gaussian Noise Mean

nstd = 0.05;  % Gaussian Noise standard deviation Range

shift = 0; % Step shift

model = 1; % Noise model

ElipseParam = [10, 10, 10];

trials = 1;

%%
index = 0; % index that records the number of pairs
markerLie = zeros(1,2); % record the number of pairs and times of simulation when the Lie group method fails
dim = size(breakPoint,2);
N = 1; % Times of simulation
x = randn(6,1); X = expm(se3_vec(x));

for j = 1:N
    
    index = 1;
    
    for i = 1:numBound
        
        if    i == breakPoint(1)
            
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
            
            [nn1, nn2, nn3] = size(A);
            A = reshape(A, nn1, nn2*nn3);
            B = reshape(B, nn1, nn2*nn3);
            
          %% Solution for X
            %-------------------------------------------------------
            
            X_andreff(1:4,1:4,index) = andreff( A, B );
%             X_Kronecker(1:4,1:4,index) = axb_KronSolve(A, B);
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
            
%             rotError_Kronecker(index,j) = roterror(X, X_Kronecker(:,:,index));
%             tranError_Kronecker(index,j) = tranerror(X, X_Kronecker(:,:,index));
            
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

            
        end
    end
end