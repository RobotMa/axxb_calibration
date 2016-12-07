%AXXB - Batch Method Noise

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num=500;%[50 100 250 500 1000];	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

nstd=0;	%Gaussian Noise standard deviation Range

shift=0; %step shift

model=1;        %noise model

ElipseParam=[10, 10, 10];

trials=1;

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



for i=1:1

    

for k=1:trials
    
A=[];
B=[];

trajParam=[.5, .5, .5, 0, 0];
[A1, B1, X_new1]=AB_genTrajcov(x, SigX, ElipseParam, trajParam, num(i)/2);

trajParam=[.5, .5, .5, 0, 0.5*pi];
[A2, B2, X_new2]=AB_genTrajcov(x, SigX, ElipseParam, trajParam, num(i)/2);

% trajParam=[.5, .5, .5, 0, pi];
% [A3, B3, X_new3]=AB_genTrajcov(X, ElipseParam, trajParam, num/3);

A=cat(3, A1, A2);
B=cat(3, B1, B2);
X_new=cat(3, X_new1, X_new2);
% A=sensorNoise(A,[0;0;0;0;0;0],0.0,1);


[MX, SigX]=distibutionProps(X_new);
SigX(:,:,k)=real(SigX);
[MA, SigA]=distibutionProps(A);
[MB, SigB]=distibutionProps(B);

% C1=kron(SE3_Ad(MX)*SE3_Ad(MB^-1),SE3_Ad(MX)*SE3_Ad(MB^-1))+kron(SE3_Ad(MX^-1),SE3_Ad(MX^-1));
% c2=vec(SigA)-kron(SE3_Ad(MX),SE3_Ad(MX))*vec(SigB);

C1=kron(SE3_Ad(MB^-1),SE3_Ad(MB^-1))+eye(36);
c2=vec(SE3_Ad(MX^-1)*SigA*SE3_Ad(MX^-1)'-SigB);


sigx=pinv(C1)*c2;

SigXBatch(:,:,k)=real(vecsq(sigx));

error(i,k)=norm(SigX(:,:,k)-SigXBatch(:,:,k));

end

errormean(i)=mean(error(i,:))

waitbar(i / 5)

end



plot(num, errormean)
title('Accuracy of finding the X distribution')

close(h);





