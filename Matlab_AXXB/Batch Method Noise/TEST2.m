h = waitbar(0,'Computing...');

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




s=(s_initial-s_initial:(2*s_initial)/100:s_initial+s_initial);
phi=(phi_initial-phi_initial:(2*phi_initial)/100:phi_initial+phi_initial);


cost1=[];
cost2=[];
cost3=[];
% s=(-3:0.05:3);
% phi=(-pi:0.05:pi);

for i=1:length(s)
    for j=1:length(phi)
        
        waitbar(((i-1)*length(phi)+j) / (length(s)*length(phi)))
        
        R_nbphicost=eye(3)+sin(phi(j))*so3_vec(nb)+(1-cos(phi(j)))*so3_vec(nb)^2;
        
        Rxcost=R_nanb*R_nbphicost;
        
        z=(Rxcost*vb-va)/thetab;
        
        b=dot(z, ma);
        a=-dot(z, cross(ma, na));
        
        q=a*ma+b*cross(ma,na);
        
        txcost=s(i)*na+q;
        
        Xcost(:,:,i,j)=[Rxcost txcost; [0 0 0] 1];
        
        cost1(i,j)=roterror(MX,Xcost(:,:,i,j));
        cost2(i,j)=tranerror(MX,Xcost(:,:,i,j));
        cost3(i,j)=norm(sigCalc(MeanB, Xcost(:,:,i,j), SigA, SigB))^2;
        
    end
end

figure;surf(cost1)
figure;surf(cost2)
figure;surf(cost3)