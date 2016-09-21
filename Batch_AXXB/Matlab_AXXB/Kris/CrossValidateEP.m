%Cross Validate Error Propagation
%Author: Kristopher L. Reynolds

%% Clean up Workspace, and Define Initial Conditions
clear
clc
count = 0;
d1 = diag([randn(1) randn(1) randn(1) randn(1) randn(1) randn(1)]);
d2 = diag([randn(1) randn(1) randn(1) randn(1) randn(1) randn(1)]);
v1 = ([randn(1) randn(1) randn(1) randn(1) randn(1) randn(1)]);
v2 = ([randn(1) randn(1) randn(1) randn(1) randn(1) randn(1)]);

%% Loop Through Parameter beta, which scales the Covariances
for jj = 1 : 50
        count = count + 1;
        
        alpha = 1;
        beta = jj;
        mu1 = expm((alpha/sqrt(6))*hat2(v1));
        mu2 = expm((alpha/sqrt(6))*hat2(v2));
        Ad1 = BigAdjoint(mu1,2);
        Ad2 = BigAdjoint(mu2,2);
        sigma1 = beta*Ad1*d1*Ad1';
        sigma2 = beta*Ad2*d2*Ad2';
        
        
        [mu12a,sigma12a] = EP1(mu1,mu2,sigma1,sigma2); %From 2nd Order Paper
        [mu12b,sigma12b] = EP2(mu1,mu2,sigma1,sigma2); %From Xiao's Thesis
        
        
        Error(count) = norm(sigma12a - sigma12b);
        Sigmanorm(count) = norm(sigma1);
end

%% Plot Error vs Norm of Covariance
plot(Sigmanorm,Error,'b*');shg
grid on
xlabel('Norm of Covariance')
ylabel('Error Between 2nd Order EP Methods')
title('Error Between 2nd Order EP Methods vs. Norm of Covariance')

       
    
        
