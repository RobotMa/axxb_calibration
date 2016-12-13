%AXXB - Batch Method (KL - Information Theoretic)

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num = 50;	%Number of steps

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

nstd = 0;	%Gaussian Noise standard deviation Range

shift = 0; %step shift

n = 1;      %VP(n)

window = 0;    %target correlation area

model = 1;        %noise model

ElipseParam = [10, 10, 10];

trials = 10;


t2 = (0:(2*pi)/((num+shift)):2*pi);
twist = 0.0*sin(16*t2);
%------------------------------------------------------


x = randn(6,1); 
% x = x; 
X = expm(se3_vec(x));   %Generate a Random X


%% Computation Loops
%---------------------------------------------------------------------------------------------------------

RoterrorKL  = [];
TranerrorKL = [];
RoterrorBS  = [];
TranerrorBS = [];
RoterrorED  = [];
TranerrorED = [];
RoterrorKron  = [];
TranerrorKron = [];

h = waitbar(0,'Computing...');
for k = 1:trials
A = [];
B = [];

trajParam = [.5, .5, .5, 0, 0];
%[A1, B1] = AB_genTraj(X, ElipseParam, trajParam, num*0.5+shift+1, twist);
[A1, B1] = AB_genTraj(X, ElipseParam, trajParam, num*0.5+shift+1);


trajParam = [.5, .5, .5, 0, 0.5*pi];
%[A2, B2]=AB_genTraj(X, ElipseParam, trajParam, num*0.5+shift+1, twist);
[A2, B2] = AB_genTraj(X, ElipseParam, trajParam, num*0.5+shift+1);

% concatanate A1 and A2 together, B1 and B2 together
A(:,:,1:size(A1,3)) = A1;
A(:,:,size(A1,3)+1:size(A1,3)+size(A2,3)) = A2;
B(:,:,1:size(B1,3)) = B1;
B(:,:,size(B1,3)+1:size(B1,3)+size(B2,3)) = B2;

PA=(1:size(A,3));
% 
% for i=1:length(PA)
%     imin=
%     imax=
%     index=randi([],1);
%     PA([i index])=PA([index i]);
% end

for i = 1:length(PA)
    index = round(5*randn(1,1));
    if (i+index) > length(PA)
        index = -index;
    end
    if (i+index) < 1
        index = -index;
    end
    
    PA([i i+index]) = PA([index+i i]);
end

A_perm = A(:,:,PA);
B_perm = B;

[X_batchKL1,~,~,~,~] = batchKLSolve(A, B, X);
[X_batchBS1,~,~,~,~] = batchBSSolve(A, B, X);
[X_kron1] = axb_KronSolve2(A,B);

[X_batchKL2,~,~,~,~] = batchKLSolve(A_perm, B_perm, X);
[X_batchBS2,~,~,~,~] = batchBSSolve(A_perm, B_perm, X);
[X_kron2] = axb_KronSolve2(A_perm, B_perm);

RoterrorKron  = [RoterrorKron;  roterror(X_kron1, X)     roterror(X_kron2, X)];
RoterrorKL    = [RoterrorKL;    roterror(X_batchKL1, X)  roterror(X_batchKL2, X)];
RoterrorBS    = [RoterrorBS;    roterror(X_batchBS1, X)  roterror(X_batchBS2, X)];

TranerrorKron = [TranerrorKron; tranerror(X_kron1, X)    tranerror(X_kron2, X)];
TranerrorKL   = [TranerrorKL;   tranerror(X_batchKL1, X) tranerror(X_batchKL2, X)];
TranerrorBS   = [TranerrorBS;   tranerror(X_batchBS1, X) tranerror(X_batchBS2, X)];

waitbar(k / trials)

end

avgrKron = [mean(RoterrorKron(:,1)),  mean(RoterrorKron(:,2))]
avgrBS   = [mean(RoterrorBS(:,1)),    mean(RoterrorBS(:,2))]
avgrKL   = [mean(RoterrorKL(:,1)),    mean(RoterrorKL(:,2))]

avgtKron = [mean(TranerrorKron(:,1)), mean(TranerrorKron(:,2))]
avgtBS   = [mean(TranerrorBS(:,1)),   mean(TranerrorBS(:,2))]
avgtKL   = [mean(TranerrorKL(:,1)),   mean(TranerrorKL(:,2))]
%----------------------------------------------------------------------------------------------------------------


% 
% hold on
% figure;%(3)
% scatter(noise, RoterrorBSavg, '+');
% xlabel('Noise on the A and B sets')
% ylabel('Rotation error of X')
% hold on
% scatter(noise, RoterrorKLavg, '.');
% scatter(noise, RoterrorEDavg, 'x');
% scatter(noise, RoterrorKronavg, 'o');
% hold off
% legend('BS Batch Method','KL Batch Method', 'ED Batch Method', 'Kronecker Product Method','Location', 'SouthOutside')
% 
% figure;%(4)
% scatter(noise, TranerrorBSavg, '+');
% xlabel('Noise on the A and B sets')
% ylabel('Translation error of X')
% hold on
% scatter(noise,TranerrorKLavg, '.');
% scatter(noise,TranerrorEDavg, 'x');
% scatter(noise,TranerrorKronavg, 'o');
% hold off
% legend('BS Batch Method','KL Batch Method', 'ED Batch Method', 'Kronecker Product Method','Location', 'SouthOutside')




