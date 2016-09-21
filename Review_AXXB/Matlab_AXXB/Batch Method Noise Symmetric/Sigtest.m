clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num=201;%[9,15,21,27,33,51,102];	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

noise=0.05;%(0.01:0.02:0.09);	%Gaussian Noise standard deviation Range

spread=1;

shift=0; %step shift

model=1;        %noise model

ElipseParam=[10, 10, 10];

trials=1;

%------------------------------------------------------







x=randn(6,1);
% x(4:6)=x(4:6)*100;
X=expm(se3_vec(x));   %Generate a Random X
Xinv=X^-1;
SigX=zeros(6,6);
SigXinv=zeros(6,6);

%Computation Loops
%---------------------------------------------------------------------------------------------------------


SigBtrue=eye(6);
T=0.1*randn(6,6);
SigBtrue=T*SigBtrue*T';

bmean=randn(6,1);


m=1;

A=[];
B=[];
X_solved=[];
SigX=[];
C=[];


E1(:,:,1)=[0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0]; E1(:,:,2)=[0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0]; E1(:,:,3)=[0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
E1(:,:,4)=[0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0]; E1(:,:,5)=[0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]; E1(:,:,6)=[0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];

indx=0;
for i=1:6
    for j=1:6
        indx=indx+1;
        E2(:,:,indx)=zeros(6,6);
        E2(i,j,indx)=1;
    end
end


[A, B]=AB_genRand(X, bmean, SigBtrue, num);

[MAtrue, SigAtrue]=distibutionProps(A);

[Anoise, DA]=sensorNoise2(A, gmean, noise, model);

[MDA, SigDA]=distibutionProps(DA);


% trajParam=[.5, .5, .5, 0, 0];
% [A1, B1, X_new1]=AB_genTrajcov(X, noise(m), ElipseParam, trajParam, num/3);
% % [A1, B1, X_new1]=AB_genTrajcov2(X, SigXtrue, ElipseParam, trajParam, num/3);
% 
% trajParam=[.5, .5, .5, 0, 0.5*pi];
% [A2, B2, X_new2]=AB_genTrajcov(X, noise(m), ElipseParam, trajParam, num/3);
% % [A2, B2, X_new2]=AB_genTrajcov2(X, SigXtrue, ElipseParam, trajParam, num/3);
% 
% trajParam=[.5, .5, .5, 0, pi];
% [A3, B3, X_new3]=AB_genTrajcov(X, noise(m), ElipseParam, trajParam, num/3);
% % [A3, B3, X_new3]=AB_genTrajcov2(X, SigXtrue, ElipseParam, trajParam, num/3);
% 
% A=cat(3, A1, A2, A3);
% B=cat(3, B1, B2, B3);
% X_new=cat(3, X_new1, X_new2, X_new3);

%For the set of X inverse------------
% for i=1:size(X_new,3)
%     Xinv_new(:,:,i)=X_new(:,:,i)^-1;  
% end
%------------------------------------

% %For Symmetric Data----------------
% for i=1:size(A,3)
%     Ainv(:,:,i)=A(:,:,i)^-1;
%     Binv(:,:,i)=B(:,:,i)^-1;
% end
% A=cat(3, A, Ainv);
% B=cat(3, B, Binv);
% %-----------------------------------




% [MX, SigMX]=distibutionProps(X_new);


% 
% [MXinv, SigMXinv]=distibutionProps(Xinv_new);


[X_solved(:,:,1), MAnoise, MB, SigAnoise, SigB]=batchEDSolve(X,Anoise,B);
[X_solved2(:,:,1), MAnoise2, MA, MB2, SigAnoise2, SigA, SigB2]=batchEDSolve2(X,Anoise,MDA,SigDA,B);
X_kron=axb_KronSolve2(A,B);
%         X_solved(:,:,1)=X_kron;
%
%     X_solved(:,:,1)=X_kron;




SigXhypoth=diag(noise^2*ones(6,1));
SigAtest1=SE3_Ad(X)*(SE3_Ad(MB^-1)*SigXhypoth*SE3_Ad(MB^-1)'+SigB+SigXhypoth)*SE3_Ad(X)';

SigAtest2=SE3_Ad(MX)*(SE3_Ad(MB^-1)*SigMX*SE3_Ad(MB^-1)'+SigB+SigMX)*SE3_Ad(MX)';

SigX=SigXcalc(SigA, MB, SigB, X_solved);
SigAtest3=SE3_Ad(X_solved)*(SE3_Ad(MB^-1)*SigX*SE3_Ad(MB^-1)'+SigB+SigX)*SE3_Ad(X_solved)';


