function [X_calc, MA, MB, SigA, SigB, skip]=batchEDSolve(X,A,B)

tx_temp=[];
cost=0;
skip=0;

[MA, SigA]=distibutionProps(A);
[MB, SigB]=distibutionProps(B);

meanA=se3_vec(MA);
meanB=se3_vec(MB);

va=meanA([4:6]);
vb=meanB([4:6]);

[VA, ~]=eig(SigA(1:3,1:3));
[VB, ~]=eig(SigB(1:3,1:3));

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
        cost(ind)=norm(thetaa*na-Rx_temp(:,:,ind)*thetab*nb);
        cost1(ind)=norm(va-thetab*so3_vec(tx_temp(:,ind))*Rx_temp(:,:,ind)*nb+Rx_temp(:,:,ind)*vb);
        cost2(ind)=norm(pa-(Rx_solved(:,:,ind)*pb+(eye(3)-na*na')*tx_temp(:,ind)));
        cost3(ind)=norm(SigB(4:6,4:6)-so3_vec(-Rx_temp(:,:,ind)'*tx_temp(:,ind))*Rx_temp(:,:,ind)'*SigA(1:3,1:3)*Rx_temp(:,:,ind)*so3_vec(-Rx_temp(:,:,ind)'*tx_temp(:,ind))'+Rx_temp(:,:,ind)'*SigA(4:6,1:3)*Rx_temp(:,:,ind)*so3_vec(-Rx_temp(:,:,ind)'*tx_temp(:,ind))'+so3_vec(-Rx_temp(:,:,ind)'*tx_temp(:,ind))*Rx_temp(:,:,ind)'*SigA(1:3,4:6)*Rx_temp(:,:,ind)+Rx_temp(:,:,ind)'*SigA(4:6,4:6)*Rx_temp(:,:,ind));
        cost4(ind)=norm(SigXcalc(SigA, MB, SigB, [Rx_temp(:,:,ind) tx_temp(:,ind); 0 0 0 1]));
        cost5(ind)=norm(SigA-SE3_Ad([Rx_temp(:,:,ind) tx_temp(:,ind); 0 0 0 1])*SigB*SE3_Ad([Rx_temp(:,:,ind) tx_temp(:,ind); 0 0 0 1])');
    end
end

[~, indx]=min(cost5);
% cost=cost4;
% cost4(indx)=[];
% [mincost2,~]=min(cost4);

Rx = Rx_temp(:,:,indx);
tx = tx_temp(:,indx);

X_calc = [Rx tx; [0 0 0] 1];

% if norm(mincost-mincost2)/norm(mincost)<0.1
%    skip=1
% end


a=0;

