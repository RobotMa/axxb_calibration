clc
clear all
close all


addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/robot')
addpath('/home/roma/Dropbox/2014Summer/Robotics Research/rvctools/common')
%------------------------------------------------------
% opt == 1 : Use distribution of As and Bs
% opt == 2 : Use distribution of Xs
opt = 2;

%Editable Variables
%------------------------------------------------------

numBound = 100;	%Number of steps

breakPoint = [10 20 30 40 50 60 70 80 90 100];

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

nstd = 0.05;  %Gaussian Noise standard deviation Range

shift = 0; %step shift

model = 1; %noise model

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
            
            %-------------------------------------------------------
            if  opt == 1
                
                B = sensorNoise(B, gmean, nstd, 1);
                
            elseif opt ==2
                
                [A, X_dist] = A_NoiseX(B, X, gmean, nstd, 1);
                
            end
            
            %% Solution for X
            %-------------------------------------------------------
            X_kron(1:4,1:4,index) = axb_KronSolve2( A, B );
            
            X_Lie(1:4,1:4,index) = axb_LieGroup( A, B );
            THETA_hat = X_Lie(1:3,1:3,index);
            if -0.99 > det(THETA_hat) && det(THETA_hat) > - 1.01
                if markerLie(1,1) == 0
                    markerLie = [index, j];
                else
                    markerLie = [markerLie; index j]
                end
            end
            
            X_quat(1:4,1:4,index) = axb_quaternionNoise( A, B );
            
            X_dual(1:4,1:4,index) = axb_dualQuaternion( A, B );
            
            % roterror and tranerror
            %--------------------------------------------------------
            % display('Kronecker')
            rotErrorKron(index,j) = roterror(X, X_kron(:,:,index));
            tranErrorKron(index,j) = tranerror(X, X_kron(:,:,index));
            
            %             % display('Lie Group')
            rotErrorLie(index,j) = roterror(X, X_Lie(:,:,index));
            tranErrorLie(index,j) = tranerror(X, X_Lie(:,:,index));
            %
            %             % display('Quaternion')
            rotErrorQuat(index,j) = roterror(X, X_quat(:,:,index));
            tranErrorQuat(index,j) = tranerror(X, X_quat(:,:,index));
            %
            %             % display('Dual Quaternion')
            rotErrorDual(index,j) = roterror(X, X_dual(:,:,index));
            tranErrorDual(index,j) = tranerror(X, X_dual(:,:,index));
            
            % error covariance matrix for the twist
            % the 6 parameters for the Lie Group
            %--------------------------------------------------------
            % display('Kronecker')
            S_kron = errorCovariance(A, B, X_kron(:,:,index));
            
            %             % display('Lie Group')
            S_Lie = errorCovariance(A, B, X_Lie(:,:,index));
            %
            %             % display('Quaternion')
            S_quat = errorCovariance(A, B, X_quat(:,:,index));
            %
            %             % display('Dual Quaternion')
            S_dual = errorCovariance(A, B, X_dual(:,:,index));
            
            % trace of the error covariance matrix
            %-------------------------------------------------------
            % display('Kronecker')
            tr_kron(index,j) = trace(S_kron);
            
            % display('Lie Group')
            tr_Lie(index,j) = trace(S_Lie);
            %
            %             % display('Quaternion')
            tr_quat(index,j) = trace(S_quat);
            %
            %             % display('Dual Quaternion')
            tr_dual(index,j) = trace(S_dual);
            
            
        end
    end
end


%%
countMarker = 1;
rotErrorLieBar = zeros(10,1);
tranErrorLieBar = zeros(10,1);
tr_LieBar = zeros(10,1);

for i = 1: dim
    count = 0;
    for j = 1:N
        if [i j] == markerLie(countMarker,:)
            countMarker = countMarker + 1;
        else
            count = count + 1;
            rotErrorLieBar(i) = (rotErrorLieBar(i) + rotErrorLie(i,j))/count;
            tranErrorLieBar(i) = (tranErrorLieBar(i) + tranErrorLie(i,j))/count;
            tr_LieBar(i) = (tr_LieBar(i) + tr_Lie(i,j))/count;
            
        end
    end
end



%%
rotErrorKronBar = sum(rotErrorKron,2)/N;
% rotErrorLieBar = sum(rotErrorLie,2)/N;
rotErrorQuat = sum(rotErrorQuat,2)/N;
rotErrorDual = sum(rotErrorDual,2)/N;

tranErrorKronBar = sum(tranErrorKron,2)/N;
% tranErrorLieBar = sum(tranErrorLie,2)/N;
tranErrorQuat = sum(tranErrorQuat,2)/N;
tranErrorDual = sum(tranErrorDual,2)/N;

tr_kronBar = sum(tr_kron,2)/N;
% tr_LieBar = sum(tr_Lie,2)/N;
tr_quat = sum(tr_quat,2)/N;
tr_dual = sum(tr_dual,2)/N;


%%
figure
plot([breakPoint],rotErrorKronBar,'c')
hold on
plot([breakPoint],rotErrorLieBar,'r')
hold on
plot([breakPoint],rotErrorQuat,'b')
hold on
plot([breakPoint],rotErrorDual,'g')

xlabel('Number of AB Pairs')
ylabel('Rotation Error')
title('Rotation Error')

legend('Kron','Lie*','Quat','Dual Quat')


%%
figure
plot([breakPoint],tranErrorKronBar,'c')
hold on
plot([breakPoint],tranErrorLieBar,'r')
hold on
plot([breakPoint],tranErrorQuat,'b')
hold on
plot([breakPoint],tranErrorDual,'g')

xlabel('Number of AB Pairs')
ylabel('Rotation Error')
title('Translation Error')

legend('Kron','Lie*','Quat','Dual Quat')


%%
figure
plot([breakPoint],tr_kronBar,'c')
hold on
plot([breakPoint],tr_LieBar,'r')
hold on
plot([breakPoint],tr_quat,'b')
hold on
plot([breakPoint],tr_dual,'g')

xlabel('Number of AB Pairs')
ylabel('Trace')
title('Trace of Error Covariance')

legend('Kron','Lie*','Quat','Dual Quat')


%%