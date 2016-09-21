clc
clear all
close all



%------------------------------------------------------
% opt == 1 : Use distribution of As and Bs
% opt == 2 : Use distribution of Xs
opt = 0;

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
%         X_kron(1:4,1:4,j) = axb_KronSolve2( A, B );
%         
%         X_Lie(1:4,1:4,j) = axb_LieGroup( A, B );
%         THETA_hat = X_Lie(1:3,1:3,i);
%         if -0.99 > det(THETA_hat) && det(THETA_hat) > - 1.01
%             if markerLie(1,1) == 0
%                 markerLie = [i, j];
%             else
%                 markerLie = [markerLie; i j];
%             end
%         end
%         
%         X_quat(1:4,1:4,j) = axb_quaternionNoise( A, B );
        
        X_dual(1:4,1:4,j) = axb_dualQuaternion( A, B );
        
        % roterror and tranerror
        %--------------------------------------------------------
%         rotErrorKron(i,j) = roterror(X, X_kron(:,:,j));
%         tranErrorKron(i,j) = tranerror(X, X_kron(:,:,j));
%         
%         rotErrorLie(i,j) = roterror(X, X_Lie(:,:,j));
%         tranErrorLie(i,j) = tranerror(X, X_Lie(:,:,j));
%         
%         rotErrorQuat(i,j) = roterror(X, X_quat(:,:,j));
%         tranErrorQuat(i,j) = tranerror(X, X_quat(:,:,j));
        
        rotErrorDual(i,j) = roterror(X, X_dual(:,:,j));
        tranErrorDual(i,j) = tranerror(X, X_dual(:,:,j));
        
        % error covariance matrix for the twist
        % the 6 parameters for the Lie Group
        %--------------------------------------------------------
%         S_kron = errorCovariance(A, B, X_kron(:,:,j));
%         
%         S_Lie = errorCovariance(A, B, X_Lie(:,:,j));
%         
%         S_quat = errorCovariance(A, B, X_quat(:,:,j));
        
        S_dual = errorCovariance(A, B, X_dual(:,:,j));
        
        % trace of the error covariance matrix
        %-------------------------------------------------------
%         tr_kron(i,j) = trace(S_kron);
%         
%         tr_Lie(i,j) = trace(S_Lie);
%         
%         tr_quat(i,j) = trace(S_quat);
        
        tr_dual(i,j) = trace(S_dual);
        
        
    end
end

%%
% countMarker = 1;
% rotErrorLieBar = zeros(dim,1);
% tranErrorLieBar = zeros(dim,1);
% tr_LieBar = zeros(dim,1);
% 
% for i = 1: dim
%     count = 0;
%     for j = 1:N
%         if [i j] == markerLie(countMarker,:)
%             countMarker = countMarker + 1;
%         else
%             count = count + 1;
%             rotErrorLieBar(i) = (rotErrorLieBar(i) + rotErrorLie(i,j))/count;
%             tranErrorLieBar(i) = (tranErrorLieBar(i) + tranErrorLie(i,j))/count;
%             tr_LieBar(i) = (tr_LieBar(i) + tr_Lie(i,j))/count;
%             
%         end
%     end
% end



%%
% rotErrorKronBar = sum(rotErrorKron,2)/N;
% rotErrorLieBar = sum(rotErrorLie,2)/N;
% rotErrorQuat = sum(rotErrorQuat,2)/N;
rotErrorDual = sum(rotErrorDual,2)/N;

% tranErrorKronBar = sum(tranErrorKron,2)/N;
% tranErrorLieBar = sum(tranErrorLie,2)/N;
% tranErrorQuat = sum(tranErrorQuat,2)/N;
tranErrorDual = sum(tranErrorDual,2)/N;

% tr_kronBar = sum(tr_kron,2)/N;
% tr_LieBar = sum(tr_Lie,2)/N;
% tr_quat = sum(tr_quat,2)/N;
tr_dual = sum(tr_dual,2)/N;


%%
figure
% plot(nstd,rotErrorKronBar,'c')
% hold on
% plot(nstd,rotErrorLieBar,'r')
% hold on
% plot(nstd,rotErrorQuat,'b')
% hold on
plot(nstd,rotErrorDual,'g')

xlabel('Noise Level')
ylabel('Rotation Error')
title('Rotation Error vs Noise Level')

legend('Kron','Lie*^{1}','Quat','Dual Quat')


%%
figure
% plot(nstd,tranErrorKronBar,'c')
% hold on
% plot(nstd,tranErrorLieBar,'r')
% hold on
% plot(nstd,tranErrorQuat,'b')
% hold on
plot(nstd,tranErrorDual,'g')

xlabel('Noise Level')
ylabel('Translation Error')
title('Translation Error vs Noise Level')

legend('Kron','Lie*^{1}','Quat','Dual Quat*^{2}')


%%
figure
% plot(nstd,tr_kronBar,'c')
% hold on
% plot(nstd,tr_LieBar,'r')
% hold on
% plot(nstd,tr_quat,'b')
% hold on
plot(nstd,tr_dual,'g')

xlabel('Noise Level')
ylabel('Trace')
title('Trace of Error Covariance vs Noise Level')

legend('Kron','Lie*^{1}','Quat','Dual Quat')


%%