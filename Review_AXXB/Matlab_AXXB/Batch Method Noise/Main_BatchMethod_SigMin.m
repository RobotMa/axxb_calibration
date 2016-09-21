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
for k=1:trials
    
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
    
    
    [X_solved(:,:,1), MA, MB, SigA, SigB]=batchEDSolve(X,A,B);
    X_kron=axb_KronSolve2(A,B);
    
    X_roterror_start(k)=roterror(X_solved(:,:,1),X);
    X_tranerror_start(k)=tranerror(X_solved(:,:,1),X);
    
    
    [MeanA, SigA]=distibutionProps(A);
    [MeanB, SigB]=distibutionProps(B);
    SigAinv=SigA^-1;
    SigBinv=SigB^-1;
    
    
    meanA=se3_vec(logm(MeanA));
    thetaa=norm(meanA(1:3,1));
    na=meanA(1:3,1)/thetaa;
    va=meanA(4:6,1);
    
    meanB=se3_vec(logm(MeanB));
    thetab=norm(meanB(1:3,1));
    nb=meanB(1:3,1)/thetab;
    vb=meanB(4:6,1);
    
    R_nanb=eye(3)+so3_vec(cross(nb, na))+(1-dot(nb,na))/norm(cross(nb,na))^2*so3_vec(cross(nb, na))^2;
    
    z=(MX(1:3,1:3)*vb-va)/thetab;
    
    ma=1/sqrt(na(1,1)^2+na(2,1)^2)*[-na(2,1); na(1,1); 0];
    
    b=dot(z, ma);
    a=-dot(z, cross(ma, na));
    
    q=a*ma+b*cross(ma,na);
    
    phiTRUE=acos((trace(R_nanb'*MX(1:3,1:3))-1)/2);
    sTRUE=norm(MX(1:3,4)-q)/norm(na);
    
    
    z=(X_solved(1:3,1:3,1)*vb-va)/thetab;
    
    b=dot(z, ma);
    a=-dot(z, cross(ma, na));
    
    q=a*ma+b*cross(ma,na);
    
    
    phiCALC1=-acos((trace(R_nanb'*X_solved(1:3,1:3,1))-1)/2);
    phiCALC2=acos((trace(R_nanb'*X_solved(1:3,1:3,1))-1)/2);
    sCALC1=norm(X_solved(1:3,4,1)-q)/norm(na);
    sCALC2=-norm(X_solved(1:3,4,1)-q)/norm(na);
    
    R_nbphi1=eye(3)+sin(phiCALC1)*so3_vec(nb)+(1-cos(phiCALC1))*so3_vec(nb)^2;
    R_nbphi2=eye(3)+sin(phiCALC2)*so3_vec(nb)+(1-cos(phiCALC2))*so3_vec(nb)^2;
    
    
    if (roterror(R_nanb'*MX(1:3,1:3),R_nbphi1)<roterror(R_nanb'*MX(1:3,1:3),R_nbphi2))
        phi_initial=phiCALC1;
        R_nbphi=R_nbphi1;
    else
        phi_initial=phiCALC2;
        R_nbphi=R_nbphi2;
    end
    
    Rx=R_nanb*R_nbphi;
    
    z=(Rx*vb-va)/thetab;
    
    b=dot(z, ma);
    a=-dot(z, cross(ma, na));
    
    q=a*ma+b*cross(ma,na);
    
    tx1=sCALC1*na+q;
    tx2=sCALC2*na+q;
    
    Xtest1=[Rx tx1; [0 0 0] 1];
    Xtest2=[Rx tx2; [0 0 0] 1];
    
    if (tranerror(MX,Xtest1)<tranerror(MX,Xtest2))
        s_initial=sCALC1;
        X_initial=Xtest1;
    else
        s_initial=sCALC2;
        X_initial=Xtest2;
    end
    
    
    
    
    
    
    
    R_nbphicost=eye(3)+sin(phi_initial)*so3_vec(nb)+(1-cos(phi_initial))*so3_vec(nb)^2;
    
    Rxcost=R_nanb*R_nbphicost;
    
    z=(Rxcost*vb-va)/thetab;
    
    b=dot(z, ma);
    a=-dot(z, cross(ma, na));
    
    q=a*ma+b*cross(ma,na);
    
    txcost=s_initial*na+q;
    
    Xcost1=[Rxcost txcost; [0 0 0] 1];
    
    SigX(:,:,1)=sigCalc(MeanB, Xcost1, SigA, SigB);
    
    C=norm(SigX(:,:,1))^2;
    C_old=inf;
    ind=1;
    
    diff=0.000000001; eps=0.001;
    %     E(:,:,1)=[0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0]; E(:,:,2)=[0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0]; E(:,:,3)=[0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
    %     E(:,:,4)=[0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0]; E(:,:,5)=[0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]; E(:,:,6)=[0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
    %     E(:,:,7:12) = -E(:,:,1:6);    

    while(abs(C(ind)-C_old)>diff)
        C_old=C(ind);
        ind=ind+1;
        
        phi(1:2)=phi_initial(ind-1)+eps;
        phi(3:4)=phi_initial(ind-1)-eps;
        s([1,3])=s_initial(ind-1)+eps;
        s([2,4])=s_initial(ind-1)-eps;
        
        for i=1:4
            R_nbphicost=eye(3)+sin(phi(i))*so3_vec(nb)+(1-cos(phi(i)))*so3_vec(nb)^2;
            
            Rxcost=R_nanb*R_nbphicost;
            
            z=(Rxcost*vb-va)/thetab;
            
            b=dot(z, ma);
            a=-dot(z, cross(ma, na));
            
            q=a*ma+b*cross(ma,na);
            
            txcost=s(i)*na+q;
            
            Xcost(:,:,i)=[Rxcost txcost; [0 0 0] 1];
            
            SigX_set(:,:,i)=sigCalc(MeanB, Xcost(:,:,i), SigA, SigB);

            Cset(i)=norm(SigX_set(:,:,i))^2;
        end
        
        
        [C_temp, indx]=min(Cset);
        C(ind)=C_temp;
        
        if C(ind)<C_old
            X_solved(:,:,ind)=Xcost(:,:,indx);
            SigX(:,:,ind)=SigX_set(:,:,indx);
            phi_initial(ind)=phi(indx);
            s_initial(ind)=phi(indx);
        else
            break;
        end
        
        X_roterror(k,ind-1)=roterror(X_solved(:,:,ind),X);
        X_tranerror(k,ind-1)=tranerror(X_solved(:,:,ind),X);
        
    end
    
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


