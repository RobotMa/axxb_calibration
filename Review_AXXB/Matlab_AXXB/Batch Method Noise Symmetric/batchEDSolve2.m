function [X_calc, MAnoise, MA, MB, SigAnoise, SigA, SigB]=batchEDSolve2(X,Anoise,MDA,SigDA,B)

tx_temp=[];
cost=0;

[MAnoise, SigAnoise]=distibutionProps(Anoise);
[MB, SigB]=distibutionProps(B);

MA=MAnoise*MDA^-1;
SigA=SE3_Ad(MDA)*(SigAnoise-SigDA)*SE3_Ad(MDA)';

meanA=se3_vec(MA);
meanB=se3_vec(MB);

va=meanA([4:6]);
vb=meanB([4:6]);

[VA,DA]=eig(SigA(1:3,1:3));
[VB,DB]=eig(SigB(1:3,1:3));

Q1=eye(3);
Q2=[-1 0 0; 0 -1 0; 0 0 1];
Q3=[-1 0 0; 0 1 0; 0 0 -1];
Q4=[1 0 0; 0 -1 0; 0 0 -1];

Rx_solved(:,:,1)=VA*Q1*VB';
Rx_solved(:,:,2)=VA*Q2*VB';
Rx_solved(:,:,3)=VA*Q3*VB';
Rx_solved(:,:,4)=VA*Q4*VB';
Rx_solved(:,:,5)=VA*-Q1*VB';
Rx_solved(:,:,6)=VA*-Q2*VB';
Rx_solved(:,:,7)=VA*-Q3*VB';
Rx_solved(:,:,8)=VA*-Q4*VB';

[thetab,Na,~, pa]=param_extract(MA);
[thetaa,Nb,~, pb]=param_extract(MB);
na=so3_vec(Na);
nb=so3_vec(Nb);

ind=0;
for i=1:size(Rx_solved,3)
    if det(Rx_solved(:,:,i))>0
        ind=ind+1;
        Rx_temp(:,:,ind)=Rx_solved(:,:,i);
        tx_temp(:,ind)=-Rx_solved(:,:,i)*so3_vec(((Rx_solved(:,:,i)'*SigA(1:3,1:3)*Rx_solved(:,:,i))^-1*(SigB(1:3,4:6)-Rx_solved(:,:,i)'*SigA(1:3,4:6)*Rx_solved(:,:,i)))');
        %         cost(i)=norm(na-Rx_solved(1:3,1:3,i)*nb)+norm(pa-(Rx_solved(1:3,1:3,i)*pb+(eye(3)-na*na')*tx_temp(:,i)));
        %         cost(i)=norm(thetaa*na-Rx_solved(1:3,1:3,i)*thetab*nb);%+norm(va-thetab*so3_vec(tx_temp(:,i))*Rx_solved(1:3,1:3,i)*nb+Rx_solved(1:3,1:3,i)*vb);
        cost(ind)=norm(thetaa*na-Rx_solved(1:3,1:3,i)*thetab*nb)+0.01*norm(pa-(Rx_solved(1:3,1:3,i)*pb+(eye(3)-na*na')*tx_temp(:,ind)));
    end
end

[~,indx]=min(cost);

Rx=Rx_temp(:,:,indx);
tx=tx_temp(:,indx);

X_calc=[Rx tx; [0 0 0] 1];

a=0;

