%AXXB - Batch Method Noise

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num=500;	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

noise=0.05;%[0.01 0.05 0.1];	%Gaussian Noise standard deviation Range

sdevB=0.1;

model=1;        %noise model

trials=3;

meanB=0.5*randn(6,1);

%------------------------------------------------------







x=randn(6,1); X=expm(se3_vec(x));   %Generate a Random X
 
sigX=0.05*abs(randn(6));
SigX=triu(sigX) + triu(sigX,1)';


%Computation Loops
%---------------------------------------------------------------------------------------------------------

RoterrorKL=[];
TranerrorKL=[];
RoterrorBS=[];
TranerrorBS=[];
RoterrorED=[];
TranerrorED=[];
RoterrorKron=[];
TranerrorKron=[];

h = waitbar(0,'Computing...');
for k=1:trials
    
    A=[];
    B=[];
    
%     trajParam=[.5, .5, .5, 0, 0];
%     [A1, B1, X_new1]=AB_genTrajcov(X, nstd, ElipseParam, trajParam, num/3);
%     
%     trajParam=[.5, .5, .5, 0, 0.5*pi];
%     [A2, B2, X_new2]=AB_genTrajcov(X, nstd, ElipseParam, trajParam, num/3);
%     
%     trajParam=[.5, .5, .5, 0, pi];
%     [A3, B3, X_new3]=AB_genTrajcov(X, nstd, ElipseParam, trajParam, num/3);
%     
%     A=cat(3, A1, A2, A3);
%     B=cat(3, B1, B2, B3);
%     
%     for i=1:size(A,3)
%     A_inv(:,:,i)=A(:,:,i)^-1;
%     B_inv(:,:,i)=B(:,:,i)^-1;
%     end
%     
%     A=cat(3,A,A_inv);
%     B=cat(3,B,B_inv);
%     
%     X_new=cat(3, X_new1, X_new2, X_new3);


    [A, B, X_new]=AB_genRandcov(X, noise(m), meanB, sdevB, num(n));
    
    
    [MX, SigMX]=distibutionProps(X_new);
    
    X_kron=axb_KronSolve2(A,B);    
    
    [X_solved(:,:,1), MA, MB, SigA, SigB]=batchEDSolve(X,A,B);
    
    Xerror(1)=norm(MX-X_solved(:,:,1))/norm(MX);
    
    [X_solved(:,:,2)]=batchEDNoiseSolve(X,MA,MB,SigA,SigB,SigMX);
    
    Xerror(2)=norm(MX-X_solved(:,:,2))/norm(MX);
    
%     for i=2:5
%     
%     SigXCalc(:,:,i-1)=sigCalc(MB, X_solved(:,:,i-1), SigA, SigB);   
%     
%     [X_solved(:,:,i)]=batchEDNoiseSolve(X,MA,MB,SigA,SigB,SigXCalc(:,:,i-1));
%     
%     rerror(i)=roterror(X,X_solved(:,:,i));
%     terror(i)=tranerror(X,X_solved(:,:,i));
% 
%     end

    
end

close(h);

% % roterror(X_solved(:,:,1),X)
% % roterror(X_solved(:,:,ind-1),X)
% % tranerror(X_solved(:,:,1),X)
% % tranerror(X_solved(:,:,ind-1),X)
% 
% % figure(1);
% % plot(X_meanroterror)
% % figure(2);
% % plot(X_meantranerror)
% 
% figure;%(3);
% hold on
% plot(X_roterror(1,:),'k')
% % plot(X_roterror(2,:), 'b')
% % plot(X_roterror(3,:), 'r')
% % plot(X_roterror(4,:), 'g')
% % plot(X_roterror(5,:), 'y')
% hold off
% figure;%(4);
% hold on
% plot(X_tranerror(1,:),'k')
% % plot(X_tranerror(2,:), 'b')
% % plot(X_tranerror(3,:), 'r')
% % plot(X_tranerror(4,:), 'g')
% % plot(X_tranerror(5,:), 'y')
% 
% figure;%(5);
% plot(C)




%---------------------------------------------------------------------------------------------------------


