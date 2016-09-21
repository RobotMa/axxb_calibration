% Experiments part : "SEPA" solution based on Quaternion 

% Note : Instead of using the method described in this paper, we employed a
% slightly different method introduced in Hand-Eye Calibration
% by Radu Horadu and Fadi Dornaika

clc
close all 
clear all

%% solve for R_x for X
%  true X value
X = [-0.8841   -0.4058   -0.2319   11.0000;
     -0.4058    0.4203    0.8116   49.0000;
     -0.2319    0.8116   -0.5362  100.0000;
           0         0         0    1.0000];
       
XX = [ 0.5000   -0.7071    0.5000  11;
       0.5000    0.7071    0.5000  21;
      -0.7071         0    0.7071 -18;
            0         0         0   1];
       
%%
A1 = [-0.87179487  0.48717949 -0.05128205  5;
       0.33333333  0.66666667  0.66666666 -4;
       0.35897436  0.56410256 -0.74358974  3;
                0           0           0  1];
A2 = [-0.70114943  0.02298850 -0.71264368  2;
       0.66666667 -0.33333333 -0.66666667 -3;
      -0.25287356 -0.94252874  0.21839080  9;
                0           0           0  1];
B1 = [-0.13831397 -0.61660716 -0.77502572  0.1311780;
      -0.84328869 -0.33704404  0.41864724  34.399851;
      -0.51935868  0.71147518 -0.47335994 -41.570048;
                0           0           0  1];
B2 = [-0.69307617  0.66439727 -0.27968142  7.6275196;
       0.01005777 -0.37903029 -0.92532961 -3.1216059;
      -0.72079419 -0.64413687  0.25601450 -8.9446943;
                0           0           0  1];

%% Error Analysis
% Generate estimated X given different number of pairs N
N = 100; % Number of pairs
n = 100; % Times of measurements for each pair N
X_e = zeros(4,4,N);
error = zeros(100,2,n);

gmean = zeros(6,1);
std = 0.01;
model = 2;

%%
% Note that at least 2 pairs are need to solve for a unique X_e 
% So i starts from 2 and X_e(:,:,1) is 04*4
for j = 1:n
    for i = 2:N
        X_e(:,:,i) = axb_quaternionNoise(X,i,gmean,std,model);
    end
    error(:,:,j) = errorCal(X,X_e,N);
end

%%
errorTotal = zeros(N,2);
for i = 1:n
    errorTotal = errorTotal + error(:,:,i);
end

errorMean = errorTotal/n;
% errorRot = error(1,:);
% errorTranslation = error(2,:);
% errorTransformation = error(3,:);

%% Plot
% plot([1:N],errorRot,'O')
% figure
% plot([1:N],errorTranslation,'O')

figure
plot(1:N,errorMean(:,1),'O')
xlabel('n/Pairs')
ylabel('Error')
title('Rotation Error - Quaternion')

figure
plot(1:N,errorMean(:,2),'O')
xlabel('n/Pairs')
title('Translation Error - Quaternion')
ylabel('Error')