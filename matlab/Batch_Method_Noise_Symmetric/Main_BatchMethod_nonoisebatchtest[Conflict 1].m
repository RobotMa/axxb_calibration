%AXXB - Nonoise batch test

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num=500;	%Number of steps

gmean=[0;0;0;0;0;0];	%Gaussian Noise Mean

noise=0.05;%[0.01 0.05 0.1];	%Gaussian Noise standard deviation Range

sdevB=0.1;

model=1;        %noise model

trials=1;

meanB=0.05*randn(6,1);

H=eye(4);
T=eye(6);
W01=1e1*eye(4);
W02=1e1*eye(6);
W1=1e-15*eye(4);
W2=1e-15*eye(6);

%------------------------------------------------------


SigX=zeros(6,6);

%Computation Loops
%---------------------------------------------------------------------------------------------------------

h = waitbar(0,'initializing','Name','Calculating Batch Solutions...');%,...
%             'CreateCancelBtn',...
%             'setappdata(gcbf,''canceling'',1)');
%         setappdata(h,'canceling',0)

X_normerror=[];
SigX_normerror=[];
Xkron_normerror=[];

for n=1:length(num)
    
    for m=1:length(noise)
        
        k=1;
        while k<=trials
            
            x=randn(6,1); X=expm(se3_vec(x));   %Generate a Random X
            
            waitbar(((m-1)*trials+k)/ (trials*length(noise)),h,sprintf('noise level=%6.3f and trial=%6.3f',m,k))
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
            
            [A, B, X_new]=AB_genRandcov(X, noise(m), meanB, sdevB, num(n));
            
%             for i=1:size(A,3)
%                 Ainv(:,:,i)=A(:,:,i)^-1;
%                 Binv(:,:,i)=B(:,:,i)^-1;
%             end
%             
%             A=cat(3,A,Ainv);
%             B=cat(3,B,Binv);
            
            [MX, SigMX]=distibutionProps(X_new);
            
            
            [X_solved, MA, MB, SigA, SigB, skip]=batchEDSolve(X,A,B);
            
            if skip==0
                
                %                         load('dataset_396-005-888')
                %                         load('dataset_402-005-007')
                %         load('dataset_402-005-007-nonsym')
                X_kron=axb_KronSolve2(A,B);
                SigMX=real(SigMX);
                MX=real(MX);
                
                
                SigX(:,:,1)=SigXcalc(SigA, MB, SigB, X_solved(:,:,1));
                
                X_normerror(k,m,n)=norm(X_solved-MX)/norm(MX)
                SigX_normerror(k,m,n)=norm(SigMX-SigX)/norm(SigMX)
                Xkron_normerror(k,m,n)=norm(X_kron-MX)/norm(MX)
                
                k=k+1;
                
            end
            
            
        end
        
    end
end


save(results-symdata1)