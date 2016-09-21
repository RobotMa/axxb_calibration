%AXXB - Batch Method Noise

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num=102;	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

noise=0.3;%(0:0.02:0.1);	%Gaussian Noise standard deviation Range

spread=1;

shift=0; %step shift

model=1;        %noise model

ElipseParam=[10, 10, 10];

trials=1;

%------------------------------------------------------







x=randn(6,1); X=expm(se3_vec(x));   %Generate a Random X
SigX=zeros(6,6);

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

for m=1:length(noise)
    for k=1:trials
        
        A=[];
        B=[];
        
        trajParam=[.5, .5, .5, 0, 0];
        [A1, B1, X_new1]=AB_genTrajcov(X, noise(m), ElipseParam, trajParam, num/3);
        
        trajParam=[.5, .5, .5, 0, 0.5*pi];
        [A2, B2, X_new2]=AB_genTrajcov(X, noise(m), ElipseParam, trajParam, num/3);
        
        trajParam=[.5, .5, .5, 0, pi];
        [A3, B3, X_new3]=AB_genTrajcov(X, noise(m), ElipseParam, trajParam, num/3);
        
        A=cat(3, A1, A2, A3);
        B=cat(3, B1, B2, B3);
        X_new=cat(3, X_new1, X_new2, X_new3);
        
        for i=1:size(A,3)
            A_inv(:,:,i)=A(:,:,i)^-1;
            B_inv(:,:,i)=B(:,:,i)^-1;
        end
        
        A=cat(3,A,A_inv);
        B=cat(3,B,B_inv);

%         [A, B, X_new]=AB_genRandcov(X, noise(m), spread, num);
        
        [MX, SigMX]=distibutionProps(X_new);
        
        
        [X_solved(:,:,1), MA, MB, SigA, SigB]=batchEDSolve(X,A,B);
        X_kron=axb_KronSolve2(A,B);
%         X_solved(:,:,1)=X_kron;
        %
        %     X_solved(:,:,1)=X_kron;
        
        SigX(:,:,1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,1));
        
        X_roterror_start(k)=roterror(X_solved(:,:,1),X);
        X_tranerror_start(k)=tranerror(X_solved(:,:,1),X);
        
        
        C=norm(SigX(:,:,1))^2+0.0001*norm(MA-X_solved(:,:,1)*MB*X_solved(:,:,1)^-1)^2;
        C_old=inf;
        ind=1;
        
        diff=0.000000000001; eps=0.01; step=0.01;
        E(:,:,1)=[0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0]; E(:,:,2)=[0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0]; E(:,:,3)=[0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
        E(:,:,4)=[0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0]; E(:,:,5)=[0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]; E(:,:,6)=[0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];        
        
        while(abs(C(ind)-C_old)>diff)
            C_old=C(ind);
            ind=ind+1;
            grad=zeros(6,1);
            
            for j=1:6
                
                Xnew_set(:,:,j)=X_solved(:,:,ind-1)*expm(eps*E(:,:,j));
                
                SigX_set(:,:,j)=SigXcalc(SigA, MB, SigB, Xnew_set(:,:,j));
                
                grad(j,1)=((norm(SigX_set(:,:,j))^2+0.0001*norm(MA-Xnew_set(:,:,j)*MB*Xnew_set(:,:,j)^-1)^2)-(norm(SigX(:,:,1))^2+0.0001*norm(MA-X_solved(:,:,ind-1)*MB*X_solved(:,:,ind-1)^-1)^2))/eps;
                
            end
            
            X_new(:,:,ind-1)=X_solved(:,:,ind-1)*expm(-step*se3_vec(grad));
            SigX_new(:,:,ind-1)=SigXcalc(SigA, MB, SigB, X_new(:,:,ind-1));
            
            C(ind)=norm(SigX_new(:,:,ind-1))^2;
            
            if C(ind)<C_old
                X_solved(:,:,ind)=X_new(:,:,ind-1);
                SigX(:,:,ind)=SigX_new(:,:,ind-1);
            else
                break;
            end
            
            if ind>10000
                break;
            end
            
            
            X_roterror(k,ind-1)=roterror(X_solved(:,:,ind),X);
            X_tranerror(k,ind-1)=tranerror(X_solved(:,:,ind),X);
            
        end
        
        X_roterror_end(k)=roterror(X_solved(:,:,end),X);
        X_tranerror_end(k)=tranerror(X_solved(:,:,end),X);
        
        Kron_roterror(k)=roterror(X_kron,X);
        Kron_tranerror(k)=tranerror(X_kron,X);
        
        waitbar(k / trials)
        
    end
    
    X_meanroterror(m)=mean(X_roterror_end);
    X_meantranerror(m)=mean(X_tranerror_end);
    
    Kron_meanroterror(m)=mean(Kron_roterror);
    Kron_meantranerror(m)=mean(Kron_tranerror);
    
    X_errordiff(:,:,m)=[X_roterror_start-X_roterror_end;X_tranerror_start-X_tranerror_end];
    
end

close(h);

% roterror(X_solved(:,:,1),X)
% roterror(X_solved(:,:,ind-1),X)
% tranerror(X_solved(:,:,1),X)
% tranerror(X_solved(:,:,ind-1),X)

% figure(1);
% plot(X_meanroterror)
% plot(Kron_meanroterror)
% figure(2);
% plot(X_meantranerror)
% plot(Kron_meantranerror)

figure;%(3);
hold on
plot(X_roterror(1,:),'k')
% plot(X_roterror(2,:), 'b')
% plot(X_roterror(3,:), 'r')
% plot(X_roterror(4,:), 'g')
% plot(X_roterror(5,:), 'y')
hold off
figure;%(4);
hold on
plot(X_tranerror(1,:),'k')
% plot(X_tranerror(2,:), 'b')
% plot(X_tranerror(3,:), 'r')
% plot(X_tranerror(4,:), 'g')
% plot(X_tranerror(5,:), 'y')

figure;%(5);
plot(C)




%---------------------------------------------------------------------------------------------------------


