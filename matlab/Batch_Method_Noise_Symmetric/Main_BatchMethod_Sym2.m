%AXXB - Batch Method Noise

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num=401;	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

noise=0.05;%(0.01:0.02:0.09);	%Gaussian Noise standard deviation Range

spread=1;

shift=0; %step shift

model=1;        %noise model

ElipseParam=[8, 8, 8];

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
    
    X_roterror_start=[];
    X_tranerror_start=[];
    SigX_error_start=[];
    X_roterror=[];
    X_tranerror=[];
    SigX_error=[];
    
    
    for k=1:trials
        
%         h=1e-2*randn(6,1); H=expm(se3_vec(h));
%         T=1e-4*randn(6,6);
        H=eye(4);
        T=eye(6);
        W01=eye(4);
        W02=eye(6);
        W1=1e-15*eye(4);
        W2=1e-15*eye(6);
        
        
        A=[];
        B=[];

        X_solved=[];
        SigX=[];
        C2=[];
        
%         trajParam=[.5, .5, .5, 0, 0];
%         [A1, B1, X_new1]=AB_genTrajcov(X, noise(m), ElipseParam, trajParam, num/3);
%         
%         trajParam=[.5, .5, .5, 0, 0.5*pi];
%         [A2, B2, X_new2]=AB_genTrajcov(X, noise(m), ElipseParam, trajParam, num/3);
%         
%         trajParam=[.5, .5, .5, 0, pi];
%         [A3, B3, X_new3]=AB_genTrajcov(X, noise(m), ElipseParam, trajParam, num/3);
%         
%         A=cat(3, A1, A2, A3);
%         B=cat(3, B1, B2, B3);
%         
% %         for i=1:size(A,3)
% %             Ainv(:,:,i)=A(:,:,i)^-1;
% %             Binv(:,:,i)=B(:,:,i)^-1;
% %         end
% %         
% %         A=cat(3,A,Ainv);
% %         B=cat(3,B,Binv);
%         
%         X_new=cat(3, X_new1, X_new2, X_new3);
%         
%         %         [A, B, X_new]=AB_genRandcov(X, noise(m), spread, num);
%         
%         [MX, SigMX]=distibutionProps(X_new);
%         
%         
%         [X_solved(:,:,1), MA, MB, SigA, SigB]=batchEDSolve(X,A,B);



        load('dataset_396-005-888')
        X_kron=axb_KronSolve2(A,B);
        %         X_solved(:,:,1)=X_kron;
        %
        %     X_solved(:,:,1)=X_kron;
        
        SigX(:,:,1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,1));
        
        X_roterror_start(k)=roterror(X_solved(:,:,1),X);
        X_tranerror_start(k)=tranerror(X_solved(:,:,1),X);
        SigX_error_start(k)=norm(SigMX-SigX)/norm(SigMX);
        
        
        E1(:,:,1)=[0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0]; E1(:,:,2)=[0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0]; E1(:,:,3)=[0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
        E1(:,:,4)=[0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0]; E1(:,:,5)=[0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]; E1(:,:,6)=[0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
        
        indx=0;
        for i=1:6
            for j=1:6
                if (i<=j)
                    indx=indx+1;
                    E2(:,:,indx)=zeros(6,6);
                    E2(i,j,indx)=1;
                    E2(:,:,indx)=E2(:,:,indx)+triu(E2(:,:,indx),1)';
                end
            end
        end
        
        
        [J1,J2,J,c1,c2,c]=Inclin2(E1,E2,MA,MB,X_solved(:,:,1),SigX(:,:,end),SigA,SigB);
        
        z=pinv(J)*c;
        
        Z=zeros(4,4);
        for i=1:6
            Z=Z+z(i)*E1(:,:,i);
        end
        X_solved(:,:,2)=X_solved(:,:,1)*(eye(4)+Z);
        SigX(:,:,end+1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,end));
        
        
        C(1)=inf;
        C(2)=LGcost(MA,MB,X_solved(:,:,1),SigA,SigB,SigX(:,:,1),H,T,W01,W02,W1,W2);
        while(C(end)<C(end-1))
            [J1,J2,J,c1,c2,c]=Inclin2(E1,E2,MA,MB,X_solved(:,:,end),SigX(:,:,end),SigA,SigB);
            
            z=pinv(J)*c;
            
            Z=zeros(4,4);
            for i=1:6
                Z=Z+z(i)*E1(:,:,i);
            end
            X_solved(:,:,end+1)=X_solved(:,:,end)*(eye(4)+Z);
%             SigX(:,:,end+1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,end));
            S=zeros(6,6);
            for i=7:27
                S=S+z(i)*E2(:,:,i-6);
            end
            SigX(:,:,end+1)=SigX(:,:,end)+S;
            C(end+1)=Inccost(MA,MB,X_solved(:,:,end),SigA,SigB,SigX(:,:,end),W01,W02,W1,W2);
            a=0;
        end
        
        
        
%         C1(1)=Inccost(MA,MB,X_solved(:,:,1),SigA,SigB,SigX(:,:,1),W01,W02,W1,W2);
%         error_rot1(1)=roterror(X_solved(:,:,1),X);
%         error_tran1(1)=tranerror(X_solved(:,:,1),X);
%         error_sig1(1)=norm(SigX(:,:,1)-SigMX);
%         for j=1:10
%             [J,c]=Inclin1(E1,MA,MB,X_solved(:,:,j));
%             
%             z=pinv(J)*c;
%             
%             Z=zeros(4,4);
%             for i=1:6
%                 Z=Z+z(i)*E1(:,:,i);
%             end
%             X_solved(:,:,j+1)=X_solved(:,:,j)*(eye(4)+Z);
%             SigX(:,:,j+1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,j+1));
%             C1(j+1)=Inccost(MA,MB,X_solved(:,:,j+1),SigA,SigB,SigX(:,:,j+1),W01,W02,W1,W2);
%             
%             error_rot1(j+1)=roterror(X_solved(:,:,j+1),X);
%             error_tran1(j+1)=tranerror(X_solved(:,:,j+1),X);
%             error_sig1(j+1)=norm(SigX(:,:,j+1)-SigMX);
%         end
%         
%         
%         
%         
%         C3(1)=Inccost(MA,MB,X_solved(:,:,1)*H,SigA,SigB,T*SigX(:,:,1)*T',W01,W02,W1,W2);
%         error_rot3(1)=roterror(X_solved(:,:,1),X);
%         error_tran3(1)=tranerror(X_solved(:,:,1),X);
%         error_sig3(1)=norm(SigX(:,:,1)-SigMX);
%         for j=1:10
%             [J1,J2,J,c1,c2,c]=Inclin2(E1,E2,MA,MB,X_solved(:,:,j)*H,T*SigX(:,:,j)*T',SigA,SigB);
%             
%             SYS1=[J1 c1];
%             SYS1rref=rref(SYS1);
%             
%             SYS2=[J2 c2];
%             SYS2rref=rref(SYS2);
%             
%             SYS=[J c];
%             SYSrref=rref(SYS);
%             
%             y=(SYS2rref(1:21,1:27)'*(SYS2rref(1:21,1:27)*SYS2rref(1:21,1:27)')^-1)*(-SYS2rref(1:21,28));
%             
%             Z=zeros(4,4);
%             for i=1:6
%                 Z=Z+y(i)*E1(:,:,i);
%             end
%             X_solved(:,:,j+1)=X_solved(:,:,j)*(eye(4)+Z);
%             
%             S=zeros(6,6);
%             for i=7:27
%                 S=S+y(i)*E2(:,:,i-6);
%             end
%             
%             SigX(:,:,j+1)=SigX(:,:,j)+S;
%             C3(j+1)=Inccost(MA,MB,X_solved(:,:,j+1),SigA,SigB,SigX(:,:,j+1),W01,W02,W1,W2);
%             
%             error_rot3(j+1)=roterror(X_solved(:,:,j+1),X);
%             error_tran3(j+1)=tranerror(X_solved(:,:,j+1),X);
%             error_sig3(j+1)=norm(SigX(:,:,j+1)-SigMX);
%         end
%         
        
        
%         C2(1)=Inccost(MA,MB,X_solved(:,:,1),SigA,SigB,SigX(:,:,1),W01,W02,W1,W2);
%         error_rot2(1)=roterror(X_solved(:,:,1),X);
%         error_tran2(1)=tranerror(X_solved(:,:,1),X);
%         error_sig2(1)=norm(SigX(:,:,1)-SigMX);
%         indx=1;
%         while 1==1
%             [J1,J2,J,c1,c2,c]=Inclin3(E1,E2,MA,MB,X_solved(:,:,indx),SigX(:,:,indx),SigA,SigB);
%             
%             z=pinv(J)*c;
%             
%             Z=zeros(4,4);
%             for i=1:6
%                 Z=Z+z(i)*E1(:,:,i);
%             end
%             X_solved(:,:,indx+1)=X_solved(:,:,indx)*(eye(4)+Z);
%             SigX(:,:,indx+1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,indx+1));
%             C2(indx+1)=Inccost(MA,MB,X_solved(:,:,indx+1),SigA,SigB,SigX(:,:,indx+1),W01,W02,W1,W2);
%             
%             error_rot2(indx+1)=roterror(X_solved(:,:,indx+1),X);
%             error_tran2(indx+1)=tranerror(X_solved(:,:,indx+1),X);
%             error_sig2(indx+1)=norm(SigX(:,:,indx+1)-SigMX);
%             
%             if C2(indx+1)>C2(indx) || indx>1000
%                 X_solved(:,:,indx+1)=[];
%                 SigX(:,:,indx+1)=[];
%                 
%                 break
%             end
%             indx=indx+1;
%         end
        
%         figure(1);
%         hold on
% %         plot(C1,'r');
% %         plot(C2,'g');
%         plot(C3,'k');
%         figure(2);
%         hold on
% %         plot(error_rot1,'r');
% %         plot(error_rot2,'g');
%         plot(error_rot3,'k');
%         figure(3);
%         hold on
% %         plot(error_tran1,'r');
% %         plot(error_tran2,'g');
%         plot(error_tran3,'k');
%         figure(4);
%         hold on
% %         plot(error_sig1,'r');
% %         plot(error_sig2,'g');
%         plot(error_sig3,'k');
        
        
        
        %                 [J1,J2,J,c1,c2,c]=Inclin3(E1,E2,MA,MB,X_solved(:,:,1),SigX(:,:,1),SigA,SigB);
        %
        %                 z=pinv(J)*c;
        %
        %                 Z=zeros(4,4);
        %                 for i=1:6
        %                     Z=Z+z(i)*E1(:,:,i);
        %                 end
        %                 X_solved(:,:,2)=X_solved(:,:,1)*(eye(4)+Z);
        
        
        
        
        
        %         J1=kron(eye(4),MA*X_solved(:,:,1))-kron(MB',X_solved(:,:,1));
        %         c1=vec(X_solved(:,:,1)*MB)-vec(MA*X_solved(:,:,1));
        %
        %         z=pinv(J1)*c1;

        X_roterror_end(k)=roterror(X_solved(:,:,end),X);
        X_tranerror_end(k)=tranerror(X_solved(:,:,end),X);
        
        Kron_roterror(k)=roterror(X_kron,X);
        Kron_tranerror(k)=tranerror(X_kron,X);
        
        waitbar(k / trials)
        
    end
    
    Xinitial_meanroterror(m)=mean(X_roterror_start);
    Xinitial_meantranerror(m)=mean(X_tranerror_start);
    
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

figure(1);
hold on
plot(noise, Xinitial_meanroterror, 'r')
plot(noise, X_meanroterror, 'g')
title('Rotation Error for Initial Solution of X and the Improved Solution Using Covariance Minimization')
xlabel('Noise Level (standard deviation on the X distribution generation)')
ylabel('Rotation Error (rad)')
hold off
figure(2);
hold on
plot(noise, Xinitial_meantranerror, 'r')
plot(noise, X_meanroterror, 'g')
title('Translation Error for Initial Solution of X and the Improved Solution Using Covariance Minimization')
xlabel('Noise Level (standard deviation on the X distribution generation)')
ylabel('Translation Error (mm)')
hold off


% figure;%(3);
% hold on
% plot(X_roterror(1,:),'k')
% title('Reduction in Rotation Error as the Covariance of the Solved X is minimized')
% xlabel('step')
% ylabel('Rotation Error (rad)')
% % plot(X_roterror(2,:), 'b')
% % plot(X_roterror(3,:), 'r')
% % plot(X_roterror(4,:), 'g')
% % plot(X_roterror(5,:), 'y')
% hold off
% figure;%(4);
% hold on
% plot(X_tranerror(1,:),'k')
% title('Reduction in Translation Error as the Covariance of the Solved X is minimized')
% xlabel('step')
% ylabel('Translation Error (mm)')
% % plot(X_tranerror(2,:), 'b')
% % plot(X_tranerror(3,:), 'r')
% % plot(X_tranerror(4,:), 'g')
% % plot(X_tranerror(5,:), 'y')
% 
% figure;%(5);
% plot(C)
% title('Solved X Covariance')




%---------------------------------------------------------------------------------------------------------


