%AXXB - Batch Method Noise

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num=210;	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

nstd=0;	%Gaussian Noise standard deviation Range

shift=0; %step shift

model=1;        %noise model

ElipseParam=[10, 10, 10];

trials=1;

%------------------------------------------------------







x=randn(6,1); X=expm(se3_vec(x));   %Generate a Random X


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
    
    trajParam=[.5, .5, .5, 0, 0];
    [A1, B1]=AB_genTraj(X, ElipseParam, trajParam, num/3);
    
    trajParam=[.5, .5, .5, 0, 0.5*pi];
    [A2, B2]=AB_genTraj(X, ElipseParam, trajParam, num/3);
    
    trajParam=[.5, .5, .5, 0, pi];
    [A3, B3]=AB_genTraj(X, ElipseParam, trajParam, num/3);
    
    A=cat(3, A1, A2, A3);
    B=cat(3, B1, B2, B3);


% for i=1:num
%    
%     b=randn(6,1); B(:,:,i)=expm(se3_vec(b));
%     
%     A(:,:,i)=X*B(:,:,i)*X^-1;
% 
%     
% end

    A=sensorNoise(A,[0;0;0;0;0;0],0.05,1);
    
    
    [X_solved(:,:,1), MA, MB, SigA, SigB]=batchEDSolve(A,B);
%     X_kron=axb_KronSolve2(A,B);
%     
%     X_solved(:,:,1)=X_kron;
    
    SigX(:,:,1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,1));
    
    X_roterror_start(k)=roterror(X_solved(:,:,1),X);
    X_tranerror_start(k)=tranerror(X_solved(:,:,1),X);
    
    
    SigX(4:6,4:6,1)=0;    
    C=norm(SigX(:,:,1))^2;
    C_old=inf;
    ind=1;
    
    diff=0.0000001; eps=0.01;
    E1(:,:,1)=[0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0]; E1(:,:,2)=[0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0]; E1(:,:,3)=[0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
    E1(:,:,4:6) = -E1(:,:,1:3);
    
    
    while(abs(C(ind)-C_old)>diff)
        C_old=C(ind);
        ind=ind+1;
        Cset=zeros(6,1);
        
        for j=1:6
            
            Xnew(:,:,j)=X_solved(:,:,ind-1)*expm(eps*E1(:,:,j));
            
            SigX_set(:,:,j)=SigXcalc(SigA, MB, SigB, Xnew(:,:,j));            
            
            SigX(4:6,4:6,j)=0;            
            Cset(j)=norm(SigX_set(:,:,j))^2;
            
        end
        
        [C_temp, indx]=min(Cset);
        C(ind)=C_temp;
        
        if C(ind)<C_old
            X_solved(:,:,ind)=Xnew(:,:,indx);
            SigX(:,:,ind)=SigX_set(:,:,indx);
        else
            break;
        end
        
        X_roterror(k,ind-1)=roterror(X_solved(:,:,ind),X);
        X_tranerror(k,ind-1)=tranerror(X_solved(:,:,ind),X);
        
    end
    
    
%     SigX(1:3,1:3,1)=0;
%     ind2=ind+1;
%     C(ind2)=norm(SigX(:,:,1))^2;
%     C_old=inf;
%     
%     diff=0.0000001; eps=0.01;
%     E2(:,:,1)=[0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0]; E2(:,:,2)=[0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]; E2(:,:,3)=[0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
%     E2(:,:,4:6) = -E2(:,:,1:3);
%     
%     
%     while(abs(C(ind2)-C_old)>diff)
%         C_old=C(ind2);
%         ind2=ind;
%         Cset=zeros(6,1);
%         
%         for j=1:6
%             
%             Xnew(:,:,j)=X_solved(:,:,ind2-1)*expm(eps*E2(:,:,j));
%             
%             SigX_set(:,:,j)=SigXcalc(SigA, MB, SigB, Xnew(:,:,j));    
%             
%             SigX(1:3,1:3,j)=0;             
%             Cset(j)=norm(SigX_set(:,:,j))^2;
%             
%         end
%         
%         [C_temp, indx]=min(Cset);
%         C(ind2)=C_temp;
%         
%         if C(ind)<C_old
%             X_solved(:,:,ind2)=Xnew(:,:,indx);
%             SigX(:,:,ind2)=SigX_set(:,:,indx);
%         else
%             break;
%         end
%         
%         X_roterror(k,ind2-1)=roterror(X_solved(:,:,ind2),X);
%         X_tranerror(k,ind2-1)=tranerror(X_solved(:,:,ind2),X);
%         
%     end
    
    X_roterror_end(k)=roterror(X_solved(:,:,end),X);
    X_tranerror_end(k)=tranerror(X_solved(:,:,end),X);
    
    
    X_meanroterror=mean(X_roterror,1);
    X_meantranerror=mean(X_tranerror,1);
    
    waitbar(k / trials)
    
end

X_errordiff=[X_roterror_start-X_roterror_end;X_tranerror_start-X_tranerror_end];

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
plot(X_tranerror(1,:),'k')
% plot(X_tranerror(2,:), 'b')
% plot(X_tranerror(3,:), 'r')
% plot(X_tranerror(4,:), 'g')
% plot(X_tranerror(5,:), 'y')

figure(5);
plot(C)




%---------------------------------------------------------------------------------------------------------


