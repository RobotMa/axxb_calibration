%AXXB - Batch Method Noise

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num=100;	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

noise=0.05;%(0:0.02:0.1);	%Gaussian Noise standard deviation Range

shift=0; %step shift

model=1;        %noise model

ElipseParam=[10, 10, 10];

trials=1;

meanB=0.05*randn(6,1);

sdevB=0.1;

%------------------------------------------------------










%Computation Loops
%---------------------------------------------------------------------------------------------------------

X_error=[];
X_meanerror=[];

h = waitbar(0,'Computing...');
for k=1:trials
    
    x=randn(6,1); X=expm(se3_vec(x));   %Generate a Random X
    
    A=[];
    MA=[];
    SigA=[];
    B=[];
    MB=[];
    SigB=[];
    C=[];
    SigX=[];
    
    %     trajParam=[.5, .5, .5, 0, 0];
    %     [A1, B1]=AB_genTraj(X, ElipseParam, trajParam, num/3);
    %
    %     trajParam=[.5, .5, .5, 0, 0.5*pi];
    %     [A2, B2]=AB_genTraj(X, ElipseParam, trajParam, num/3);
    %
    %     trajParam=[.5, .5, .5, 0, pi];
    %     [A3, B3]=AB_genTraj(X, ElipseParam, trajParam, num/3);
    %
    %     A=cat(3, A1, A2, A3);
    %     B=cat(3, B1, B2, B3);
    
    [A, B, X_new]=AB_genRandcov(X, noise, meanB, sdevB, num);
    
    for i=1:size(A,3)
        Ainv(:,:,i)=A(:,:,i)^-1;
        Binv(:,:,i)=B(:,:,i)^-1;
    end
    
    A=cat(3,A,Ainv);
    B=cat(3,B,Binv);
    
    [MX, SigMX]=distibutionProps(X_new);
    
    
%     A=sensorNoise(A,[0;0;0;0;0;0],noise(k),1);
    
    
    [X_solved(:,:,1), MA, MB, SigA, SigB]=batchEDSolve(MX,A,B);
    
    SigX(:,:,1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,1));
    
    C(1)=L2calc(SigA, MB, SigB, X_solved(:,:,1), SigX(:,:,1));
    %C(1)=abs(L2calc(SigA, MB, SigB, X_solved(:,:,1), SigX(:,:,1)));
    
    diff=0.0000000001; eps=0.01;
    E(:,:,1)=[0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0]; E(:,:,2)=[0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0]; E(:,:,3)=[0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
    E(:,:,4)=[0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0]; E(:,:,5)=[0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]; E(:,:,6)=[0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
    E(:,:,7:12) = -E(:,:,1:6);
    
    
    while(C(end)>1e-10)
        
        X_error(k,end)=norm(X_solved(:,:,end)-MX)^2/norm(MX)^2;

        
        Cset=zeros(12,1);
        for j=1:12
            
            X_set(:,:,j)=X_solved(:,:,end)*expm(eps*E(:,:,j));
            
            %Cset(j)=abs(L2calc(SigA, MB, SigB, X_set(:,:,j), SigX(:,:,ind-1)));
            Cset(j)=L2calc(SigA, MB, SigB, X_set(:,:,j), SigX(:,:,end));
        end
        
        [C(end+1), indx]=min(Cset);
        
        if C(end)<C(end-1)
            X_solved(:,:,end+1)=X_set(:,:,end);
            SigX(:,:,end+1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,end));
        else
            break;
        end
        a=0;
    end
    
    X_meanerror=mean(X_error,1);
    
    waitbar(k / trials)
    
end
close(h);

% roterror(X_solved(:,:,1),X)
% roterror(X_solved(:,:,ind-1),X)
% tranerror(X_solved(:,:,1),X)
% tranerror(X_solved(:,:,ind-1),X)

% figure(1);
% plot(X_meanroterror)
% figure(2);
% plot(X_meantranerror)

figure(3);
hold on
plot(X_roterror(1,:),'k')
% plot(X_roterror(2,:), 'b')
% plot(X_roterror(3,:), 'r')
% plot(X_roterror(4,:), 'g')
% plot(X_roterror(5,:), 'y')
hold off
figure(4);
hold on
plot(X_tranerror(1,:))
% plot(X_tranerror(2,:))
% plot(X_tranerror(3,:))
% plot(X_tranerror(4,:))
% plot(X_tranerror(5,:))

figure(5);
plot(C)




%---------------------------------------------------------------------------------------------------------


