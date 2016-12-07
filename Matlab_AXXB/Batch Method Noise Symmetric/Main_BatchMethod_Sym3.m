%AXXB - Batch Method Noise

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num=400;%[30,100,400,1000];	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

noise=0.05;%(0.01:0.02:0.09);	%Gaussian Noise standard deviation Range

sdevB=0.1;

shift=0; %step shift

model=1;        %noise model

ElipseParam=[10, 10, 10];

trials=1;

meanB=randn(6,1);

H=eye(4);
T=eye(6);
W01=1e-15*eye(4);
W02=1e-15*eye(6);
W1=1e-15*eye(4);
W2=1e1*eye(6);

diff=1e-8;
eps=1;
delta=1e-5;
b=0.75;
stopThresh=1e-15;

%nh=1e-8;

%------------------------------------------------------







% x=randn(6,1); X=expm(se3_vec(x));   %Generate a Random X
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
X=[];

for m=1:length(noise)
    
    X_roterror_start=[];
    X_tranerror_start=[];
    SigX_error_start=[];
    X_roterror=[];
    X_tranerror=[];
    SigX_error=[];
    
    
    for k=1:trials
        
        h = waitbar(0,'initializing','Name','Improving X with Gradient Descent...');%,...
        %             'CreateCancelBtn',...
        %             'setappdata(gcbf,''canceling'',1)');
        %         setappdata(h,'canceling',0)
        
        x=[randn(3,1); 10*randn(3,1)]; X(:,:,end+1)=expm(se3_vec(x));
        A=[];
        B=[];
        X_new=[];
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
        %         X_new=cat(3, X_new1, X_new2, X_new3);
        
        [A, B, X_new]=AB_genRandcov(X(:,:,end), noise(m), meanB, sdevB, num);
        
        
        [MX, SigMX]=distibutionProps(X_new);
        
        
        [X_solved(:,:,1), MA, MB, SigA, SigB]=batchKLSolve(A,B,X);
        
        %                         load('dataset_396-005-888')
        %                         load('dataset_402-005-007')
        %         load('dataset_402-005-007-nonsym')
        X_kron=axb_KronSolve2(A,B);
        SigMX=real(SigMX);
        MX=real(MX);
        
        
        SigX(:,:,1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,1));
        
        X_roterror_start(k)=roterror(X_solved(:,:,1),X);
        X_tranerror_start(k)=tranerror(X_solved(:,:,1),X);
        SigX_error_start(k)=norm(SigMX-SigX)/norm(SigMX);
        
        
        %         X_solved(:,:,1)=MX*expm(se3_vec(0.2*randn(6,1)));
        %         SigX(:,:,1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,1));
        C=LGcost(MA,MB,X_solved(:,:,1),SigA,SigB,SigX(:,:,1),H,T,W01,W02,W1,W2);
        
        
        E1(:,:,7:12)=-E1(:,:,1:6);
        %set the initial eps value
        eps=1;
        
        %Coordinate Descent until cost is practically zero
        while C(end)>stopThresh && eps>1e-30
            
            %For a stepize of "eps"
            while(1==1)
                
                %Calculate cost along each coordinate direction
                Cset=zeros(12,1);
                for j=1:12
                    H(:,:,j)=expm(eps*E1(:,:,j));
                    T(:,:,j)=eye(6);
                    
                    SigXset(:,:,j)=SigXcalc(SigA, MB, SigB, X_solved(:,:,end)*H(:,:,j));
                    
                    Cset(j)=LGcost(MA,MB,X_solved(:,:,end),SigA,SigB,SigXset(:,:,j),H(:,:,j),T(:,:,j),W01,W02,W1,W2);
                end
                
                %choose the coordinate direction with minimum cost
                [C(end+1), indx]=min(Cset);
                C;
                
                %If the new cost is less than the previous cost, step is successful
                %- save the new value of mean. Otherwise, go back a step and reduce
                %the step size.
                if C(end)<C(end-1)
                    X_solved(:,:,end+1)=X_solved(:,:,end)*H(:,:,indx);
                    SigX(:,:,end+1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,end));
                    X_roterror(k,end+1)=roterror(X_solved(:,:,end),MX);
                    X_tranerror(k,end+1)=tranerror(X_solved(:,:,end),MX);
                    SigX_error(end+1)=norm(SigX(:,:,end)-SigMX)/norm(SigMX);
                    C(end);
                else
                    C(end)=[];
                    break;
                end
                
                % Report current estimate in the waitbar's message field
                waitbar((20+log(stopThresh/C(end)))/20,h,sprintf('C=%12.5e and eps=%12.5e',C(end),eps))
                
            end
            
            %reduce stepsize
            eps=b*eps
            
            % Check for Cancel button press
            if getappdata(h,'canceling')
                break
            end
            
        end
        delete(h);
        
        
        
        
        
        
        
        
        
        %         E1(:,:,7:12)=-E1(:,:,1:6);
        %         E2(:,:,37:72)=-E2(:,:,1:36);
        %         %set the initial eps value
        %         eps=1;
        %
        %         %Coordinate Descent until cost is practically zero
        %         while C(end)>stopThresh %&& eps>1e-15
        %
        %             %For a stepize of "eps"
        %             while(1==1)
        %
        %                 %Calculate cost along each coordinate direction
        %                 Cset=zeros(84,1);
        %                 for j=1:84
        %                     if j<13
        %                         H(:,:,j)=expm(eps*E1(:,:,j));
        %                         T(:,:,j)=eye(6);
        %
        %                         Cset(j)=LGcost(MA,MB,X_solved(:,:,end),SigA,SigB,SigX(:,:,end),H(:,:,j),T(:,:,j),W01,W02,W1,W2);
        %                     else
        %                         H(:,:,j)=eye(4);
        %                         T(:,:,j)=expm(eps*E2(:,:,j-12));
        %
        %                         Cset(j)=LGcost(MA,MB,X_solved(:,:,end),SigA,SigB,SigX(:,:,end),H(:,:,j),T(:,:,j),W01,W02,W1,W2);
        %                     end
        %                 end
        %
        %                 %choose the coordinate direction with minimum cost
        %                 [C(end+1), indx]=min(Cset);
        %                 C;
        %
        %                 %If the new cost is less than the previous cost, step is successful
        %                 %- save the new value of mean. Otherwise, go back a step and reduce
        %                 %the step size.
        %                 if C(end)<C(end-1)
        %                     X_solved(:,:,end+1)=X_solved(:,:,end)*H(:,:,indx);
        %                     SigX(:,:,end+1)=T(:,:,indx)*SigX(:,:,end)*T(:,:,indx)';
        %                     %             C(end)
        %                 else
        %                     C(end)=[];
        %                     break;
        %                 end
        %
        %                 % Report current estimate in the waitbar's message field
        %                 waitbar((20+log(stopThresh/C(end)))/20,h,sprintf('C=%12.5e and eps=%12.5e',C(end),eps))
        %
        %             end
        %
        %             %reduce stepsize
        %             eps=b*eps
        %
        % %             % Check for Cancel button press
        % %             if getappdata(h,'canceling')
        % %                 break
        % %             end
        %
        %         end
        % %         delete(h);
        
        
        
        %         %Gradient Descent until cost is practically zero (<e-15)
        %         while C(end)>stopThresh
        %
        %             %For a gradient stepsize "eps"
        %             while(1==1)
        %
        %                 %Calculate the new values of H and T along the gradient
        %                 [H,T]=LGgrad(E1,E2,MA,MB,X_solved(:,:,end),SigA,SigB,SigX(:,:,end),H,T,W01,W02,W1,W2,eps,delta);
        %
        %                 %calculate the cost of the step
        %                 C(end+1)=LGcost(MA,MB,X_solved(:,:,end),SigA,SigB,SigX(:,:,end),H,T,W01,W02,W1,W2);
        %                 C(end);
        %
        %                 %If the new cost is less than the previous cost, step is successful
        %                 %- save the new value of mean. Otherwise, go back a step and reduce
        %                 %the step size.
        %                 if C(end)<C(end-1)
        %                     X_solved(:,:,end+1)=X_solved(:,:,end)*H;
        %                     SigX(:,:,end+1)=T*SigX(:,:,end)*T';
        %                     %                     C(end)
        %                     X_roterror(k,end+1)=roterror(X_solved(:,:,end),X);
        %                     X_tranerror(k,end+1)=tranerror(X_solved(:,:,end),X);
        %                     SigX_error(end+1)=norm(SigX(:,:,end)-SigMX)/norm(SigMX);
        %                 else
        %                     C(end)=[];
        %                     break;
        %                 end
        %
        %                 % Report current estimate in the waitbar's message field
        %                 waitbar(0,h,sprintf('C=%12.5e and eps=%12.5e',C(end),eps))
        %
        %             end
        %
        %             %reduce stepsize
        %             eps=b*eps
        %
        %             %             % Check for Cancel button press
        %             %             if getappdata(h,'canceling')
        %             %                 break
        %             %             end
        %
        %         end
        %         delete(h);
        %
        
        
        %         H=eye(4);
        %         T=eye(6);
        %
        %         X_solved2(:,:,1)=MX*expm(se3_vec(0.2*randn(6,1)));
        %         SigX2(:,:,1)=SigXcalc(SigA, MB, SigB, X_solved2(:,:,1));
        %         C2=LGcost(MA,MB,X_solved2(:,:,1),SigA,SigB,SigX2(:,:,1),H,T,W01,W02,W1,W2);
        %
        %
        %         E1(:,:,7:12)=-E1(:,:,1:6);
        %         E2(:,:,37:72)=-E2(:,:,1:36);
        %         %set the initial eps value
        %         eps=1;
        %
        %         %Coordinate Descent until cost is practically zero
        %         while C2(end)>stopThresh && eps>1e-15
        %
        %             %For a stepize of "eps"
        %             while(1==1)
        %
        %                 %Calculate cost along each coordinate direction
        %                 Cset=zeros(84,1);
        %                 for j=1:84
        %                     if j<13
        %                         H(:,:,j)=expm(eps*E1(:,:,j));
        %                         T(:,:,j)=eye(6);
        %
        %                         Cset(j)=LGcost(MA,MB,X_solved2(:,:,end),SigA,SigB,SigX2(:,:,end),H(:,:,j),T(:,:,j),W01,W02,W1,W2);
        %                     else
        %                         H(:,:,j)=eye(4);
        %                         T(:,:,j)=expm(eps*E2(:,:,j-12));
        %
        %                         Cset(j)=LGcost(MA,MB,X_solved2(:,:,end),SigA,SigB,SigX2(:,:,end),H(:,:,j),T(:,:,j),W01,W02,W1,W2);
        %                     end
        %                 end
        %
        %                 %choose the coordinate direction with minimum cost
        %                 [C2(end+1), indx]=min(Cset);
        %                 C;
        %
        %                 %If the new cost is less than the previous cost, step is successful
        %                 %- save the new value of mean. Otherwise, go back a step and reduce
        %                 %the step size.
        %                 if C2(end)+nh<C2(end-1)
        %                     X_solved2(:,:,end+1)=X_solved2(:,:,end)*H(:,:,indx);
        %                     SigX2(:,:,end+1)=T(:,:,indx)*SigX2(:,:,end)*T(:,:,indx)';
        %                     %             C(end)
        %                 else
        %                     C2(end)=[];
        %                     break;
        %                 end
        %
        %                 % Report current estimate in the waitbar's message field
        %                 waitbar((20+log(stopThresh/C2(end)))/20,h,sprintf('C=%12.5e and eps=%12.5e',C2(end),eps))
        %
        %             end
        %
        %             %reduce stepsize
        %             eps=b*eps
        %
        % %             % Check for Cancel button press
        % %             if getappdata(h,'canceling')
        % %                 break
        % %             end
        %
        %         end
        %         delete(h);
        
        
        
        
        
        
        
        
        
        
        
        
        
        figure;
        plot(C);
        figure;
        plot(X_roterror);
        figure;
        plot(X_tranerror);
        figure;
        plot(SigX_error)
        
        X_roterror_end(k)=roterror(X_solved(:,:,end),X);
        X_tranerror_end(k)=tranerror(X_solved(:,:,end),X);
        
        Kron_roterror(k)=roterror(X_kron,X);
        Kron_tranerror(k)=tranerror(X_kron,X);
        
        waitbar(((m-1)*trials+k)/ (trials*length(noise)))
        
    end
    
    Xinitial_meanroterror(m)=mean(X_roterror_start);
    Xinitial_meantranerror(m)=mean(X_tranerror_start);
    
    X_meanroterror(m)=mean(X_roterror_end);
    X_meantranerror(m)=mean(X_tranerror_end);
    
    Kron_meanroterror(m)=mean(Kron_roterror);
    Kron_meantranerror(m)=mean(Kron_tranerror);
    
    X_errordiff(:,:,m)=[X_roterror_start-X_roterror_end;X_tranerror_start-X_tranerror_end];
    
end

% roterror(X_solved(:,:,1),X)
% roterror(X_solved(:,:,ind-1),X)
% tranerror(X_solved(:,:,1),X)
% tranerror(X_solved(:,:,ind-1),X)

% figure(1);
% hold on
% plot(noise, Xinitial_meanroterror, 'r')
% plot(noise, X_meanroterror, 'g')
% title('Rotation Error for Initial Solution of X and the Improved Solution Using Covariance Minimization')
% xlabel('Noise Level (standard deviation on the X distribution generation)')
% ylabel('Rotation Error (rad)')
% hold off
% figure(2);
% hold on
% plot(noise, Xinitial_meantranerror, 'r')
% plot(noise, X_meantranerror, 'g')
% title('Translation Error for Initial Solution of X and the Improved Solution Using Covariance Minimization')
% xlabel('Noise Level (standard deviation on the X distribution generation)')
% ylabel('Translation Error (mm)')
% hold off
% 
% figure(3);
% plot(C)




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


