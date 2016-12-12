% Hand-Eye Calibration Using Dual Quaternions
clc
clear all
close all

%%
opt = 1;
if opt == 1
    A1 = [-0.87179487  0.48717949 -0.05128205  5;
           0.33333333  0.66666667  0.66666666 -4;
           0.35897436  0.56410256 -0.74358974  3;
                    0           0           0  1];
    A2 = [-0.70114943  0.02298850 -0.71264368  2;
           0.66666667 -0.33333333 -0.66666667 -3;
          -0.25287356 -0.94252874  0.21839080  9;
                    0           0           0  1];      
    X_known = [-0.88405797   -0.40579710   -0.23188406   11.0000;
               -0.40579710    0.42028986    0.81159420   49.0000;
               -0.23188406    0.81159420   -0.53623188  100.0000;
                     0         0         0    1.0000];
    B1 = X_known\A1*X_known;
    B2 = X_known\A2*X_known;
elseif opt == 2
    A1 = [-0.989992 -0.141120  0         0;
           0.141120 -0.989992  0         0;fdff
           0         0         1         0;
           0         0         0         1];
    A2 = [ 0.070737  0         0.997495 -400.000;
           0         1         0         0;
          -0.997495  0         0.070737  400.000;
           0         0         0         1];
    X_known = [
        1.0000         0         0   10.0000;
             0    0.9801   -0.1987   50.0000;
             0    0.1987    0.9800  100.0000;
             0         0         0    1.0000];
    B1 = X_known\A1*X_known;
    B2 = X_known\A2*X_known;
end

%%
% % Test that multiplication between dual quaternion and its inverse produces
% % a unit quaternion
% b1 = Dual_Quaternion(B1);
% b1_bar = QBar(b1);
% e = DQTimes2(b1,b1_bar);

%%
% Test for AX = XB in dual quaternion form
% x = Dual_Quaternion(X_known);
% a1_cal = DQTimes3(x,b1);

% %%
% % solve for X using two pairs of A and B without noise
% a1 = Dual_Quaternion(A1);
% a2 = Dual_Quaternion(A2);
% b1 = Dual_Quaternion(B1);
% b2 = Dual_Quaternion(B2);
%%
N = 100; 
n = 100;
X_e = zeros(4,4,N);
error = zeros(N,2,n);

gmean = zeros(6,1);
std = 0.01;
model = 2;

for j = 1:n
    for i = 2:N
        X_e(:,:,i) = dualQuaternion(X_known,i,gmean,std,model);
    end
    error(:,:,j) = errorCal(X_known,X_e,N);
end

%%
errorTotal = zeros(N,2);
for i = 1:n
    errorTotal = errorTotal + error(:,:,i);
end
errorMean = errorTotal/n;

figure
plot(1:N,errorMean(:,1),'O')
xlabel('n/Pairs')
ylabel('Error')
title('Rotation Error - Dual Quaternion')

figure
plot(1:N,errorMean(:,2),'O')
xlabel('n/Pairs')
title('Translation Error - Dual Quaternion')
ylabel('Error')
