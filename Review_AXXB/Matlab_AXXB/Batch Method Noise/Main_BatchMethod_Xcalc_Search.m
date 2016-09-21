%AXXB - Batch Method Noise

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num=501;	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

nstd=0;	%Gaussian Noise standard deviation Range

shift=0; %step shift

model=1;        %noise model

ElipseParam=[10, 10, 10];

trials=1;

%------------------------------------------------------







x=randn(6,1); X=expm(se3_vec(x));   %Generate a Random X
 
sigX=0.01*abs(randn(6));
% SigX=triu(sigX) + triu(sigX,1)';
SigX=sigX*sigX';


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

% h = waitbar(0,'Computing...');
for k=1:trials
    
%     waitbar(k/trials);
    
    A=[];
    B=[];
    
    trajParam=[.5, .5, .5, 0, 0];
    [A1, B1, X_new1]=AB_genTrajcov(X, SigX, ElipseParam, trajParam, num/3);
    
    trajParam=[.5, .5, .5, 0, 0.5*pi];
    [A2, B2, X_new2]=AB_genTrajcov(X, SigX, ElipseParam, trajParam, num/3);
    
    trajParam=[.5, .5, .5, 0, pi];
    [A3, B3, X_new3]=AB_genTrajcov(X, SigX, ElipseParam, trajParam, num/3);
    
    A=cat(3, A1, A2, A3);
    B=cat(3, B1, B2, B3);
    X_new=cat(3, X_new1, X_new2, X_new3);

    
    
    
    [MX, SigMX]=distibutionProps(X_new);
    
%     X_kron=axb_KronSolve2(A,B);

    [X_calc, MA, MB, SigA, SigB]=batchEDSolve(X,A,B);
    
%     SigX_calc=zeros(6,6);
    SigX_calc=SigXcalc(SigA, MB, SigB, X_calc);
    
    SigX_initial=SigMX;%zeros(6,6);
    
    %[X_solved, SigX_solved, COST, MA, MB, SigA, SigB]=batchKLNoiseSolve(A,B,X_calc, SigX_calc);
%     [X_solved, SigX_solved, COST, MA, MB, SigA, SigB]=batchKLNoiseSolve3(A,B,X_calc, SigX_initial);
    [X_solved, SigX_solved, COST, MA, MB, SigA, SigB]=batchNormNoiseSolve(A,B,X_calc, SigX_initial);
    
    rerror(k)=roterror(X,X_solved(:,:,1));
    terror(k)=tranerror(X,X_solved(:,:,1));
    
    
    
%     rerror(1)=roterror(X,X_solved(:,:,1));
%     terror(1)=tranerror(X,X_solved(:,:,1));
%     
%     
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

for i=1:size(X_solved,3)
    
    rerror(i)=roterror(X,X_solved(:,:,i));
    
end

figure
plot(rerror);

for i=1:size(X_solved,3)
    
    terror(i)=tranerror(X,X_solved(:,:,i));
    
end

figure
plot(terror);

figure
plot(COST);



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


