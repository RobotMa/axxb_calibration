function [X_calc]=batchEDNoiseSolve(X,MA,MB,SigA,SigB,SigX)

Sig_XB=SE3_Ad(MX)*(SigX(1:3,1:3)+MB(1:3,1:3)'*SigX(1:3,1:3)*MB(1:3,1:3)+SigB(1:3,1:3))*SE3_Ad(MX)';

[VA,DA]=eig(SigA(1:3,1:3));
[VXB,DM]=eig(Sig_XB);

Q1=eye(3);
Q2=[-1 0 0; 0 -1 0; 0 0 1];
Q3=[-1 0 0; 0 1 0; 0 0 -1];
Q4=[1 0 0; 0 -1 0; 0 0 -1];

Rx_solved(:,:,1)=VA*Q1*VXB';
Rx_solved(:,:,2)=VA*Q2*VXB';
Rx_solved(:,:,3)=VA*Q3*VXB';
Rx_solved(:,:,4)=VA*Q4*VXB';
Rx_solved(:,:,5)=VA*-Q1*VXB';
Rx_solved(:,:,6)=VA*-Q2*VXB';
Rx_solved(:,:,7)=VA*-Q3*VXB';
Rx_solved(:,:,8)=VA*-Q4*VXB';

[thetaa,Na,~, pa]=param_extract(MA);
[thetab,Nb,~, pb]=param_extract(MB);
mA=se3_vec(logm(MA));
mB=se3_vec(logm(MB));
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
    end
end

[~,indx]=min(cost);

Rx=Rx_solved(:,:,indx);
tx=tx_temp(:,indx);

X_calc=[Rx tx; [0 0 0] 1];

end

