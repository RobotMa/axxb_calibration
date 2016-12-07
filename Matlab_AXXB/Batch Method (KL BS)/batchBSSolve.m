function [X_new, MeanA, MeanB, SigA, SigB]=batchBSSolve(A,B,X)

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

ang=norm(so3_vec(logm(R_nanb'*X(1:3,1:3))));
so3_vec(logm(R_nanb'*X(1:3,1:3)))/norm(so3_vec(logm(R_nanb'*X(1:3,1:3))));
nb;

R_nbphi=eye(3)+sin(ang)*so3_vec(nb)+(1-cos(ang))*so3_vec(nb)*so3_vec(nb);
Rx=R_nanb*R_nbphi;
X(1:3,1:3);



phimin=0;
phimax=2*pi;
phistep=(phimax-phimin)/3600;
C2_min=inf;
ind=0;


for phi=phimin:phistep:phimax
    
    ind=ind+1;
    
    R_nbphi=eye(3)+sin(phi)*so3_vec(nb)+(1-cos(phi))*so3_vec(nb)*so3_vec(nb);
    
    %Rx_solved(:,:,ind)=X(1:3,1:3);
   
    Rx_solved(1:3,1:3,ind)=R_nanb*R_nbphi;
    
    z=(Rx_solved(:,:,ind)*vb-va)/thetab;
    
    ma=1/sqrt(na(1,1)^2+na(2,1)^2)*[-na(2,1); na(1,1); 0];
    
    b=dot(z, ma);
    a=-dot(z, cross(ma, na));
    
    sa1=SigA(1:3,1:3);
    sa2=SigA(1:3,4:6);
    sa3=SigA(4:6,1:3);
    sa4=SigA(4:6,4:6);
    sb1=SigB(1:3,1:3);
    sb2=SigB(1:3,4:6);
    sb3=SigB(4:6,1:3);
    sb4=SigB(4:6,4:6);
    rx=Rx_solved(:,:,ind);
    
    
    M1=rx'*sa1*sa1'*rx;
    M2=eye(3);
    M3=rx'*sa3*sa1'*rx;
    M4=-sb3*rx'*sa1'*rx;
    M5=rx'*sa1*sa3'*rx;
    M6=rx'*sa1*-rx*sb3';
    M7=sa2'*rx*sb1*rx';
    M8=rx*sb1'*rx'*sa2;
    M9=rx*sb1'*sb1*rx';
    M10=eye(3);
    M11=rx*sb1'*-sb2*rx';
    M12=-rx*sb2'*sb1*rx';
    M13=rx'*sa2*sa2'*rx;
    M14=eye(3,3);
    M15=rx'*sa4*sa2'*rx;
    M16=sa2'*rx;
    M17=sb3*rx';
    M18=-sb4*rx'*sa2'*rx;
    M19=rx'*sa2*sa4'*rx;
    M20=sa4'*rx*sb3*rx';
    M21=rx*sb3';
    M22=rx'*sa2;
    M23=rx*sb3'*rx'*sa4;
    M24=rx*sb3'*sb3*rx';
    M25=eye(3,3);
    M26=rx*sb3'*-sb4*rx';
    M27=rx'*sa2*-rx*sb4';
    M28=-rx*sb4'*sb3*rx';
    
    q=a*ma+b*cross(ma,na);
    
    
    C10=zeros(22,1);
    C11=zeros(22,1);
    C12=zeros(22,1);
    
    [C10(1),C11(1),C12(1)]=trace3(na, -M1, M2, q, rx);
    [C10(2),C11(2)]=trace1(na, M3, q, rx);
    [C10(3),C11(3)]=trace1(na, M4, q, rx);
    [C10(4),C11(4)]=trace1(na, -M5, q, rx);
    [C10(5),C11(5)]=trace1(na, -M6, q, rx);
    [C10(6),C11(6)]=trace1(na, M7, q, eye(3));
    [C10(7),C11(7)]=trace1(na, -M8, q, eye(3));
    [C10(8),C11(8), C12(8)]=trace2(na, -M9, M10, q, eye(3));
    [C10(9),C11(9)]=trace1(na, -M11, q, eye(3));
    [C10(10),C11(10)]=trace1(na, M12, q, eye(3));
    [C10(11),C11(11),C12(11)]=trace3(na, -M13, M14, q, rx);
    [C10(12),C11(12)]=trace1(na, M15, q,rx);
    [C10(13),C11(13),C12(13)]=trace2(na, M16, M17, q, rx);
    [C10(14),C11(14)]=trace1(na, M18, q, rx);
    [C10(15),C11(15)]=trace1(na, -M19, q, rx);
    [C10(16),C11(16)]=trace1(na, M20, q, eye(3));
    [C10(17),C11(17),C12(17)]=trace2(na, -M21, -M22, q, rx);
    [C10(18),C11(18)]=trace1(na, -M23, q, eye(3));
    [C10(19),C11(19),C12(19)]=trace2(na, -M24, M25, q, eye(3));
    [C10(20),C11(20)]=trace1(na, -M26, q, eye(3));
    [C10(21),C11(21)]=trace1(na, -M27, q, rx);
    [C10(22),C11(22)]=trace1(na, M28, q, eye(3));
    
    
       
    s(ind)=-sum(C11)/(2*sum(C12));
    
    s_real(ind)=mean((X(1:3,4)-q)./na);
    
    tx_solved(:,ind)=s(ind)*na+q;
    
    
    
    X_solved(1:4,1:4,ind)=[Rx_solved(:,:,ind) tx_solved(:,ind); [0 0 0] 1];
    
    
    C1(ind)=sum(C10)+sum(C11)*s(ind)+sum(C12)*s(ind)*s(ind);
    C2(ind)=norm(SE3inv_Ad(X_solved(:,:,ind))*SigA-SigB*SE3_Ad(X_solved(:,:,ind))')^2;
    
end

% figure(3);
% plot(C2)
% hold on; plot(C1, 'k')
% 
% 
% figure(4);
% plot(s)
% hold on; plot(s_real, 'k')


[~,ind]=min(C2);
X_new=X_solved(:,:,ind);

