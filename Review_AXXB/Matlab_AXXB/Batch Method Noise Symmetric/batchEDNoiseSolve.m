function [X_calc]=batchEDNoiseSolve(X,MA,MB,SigA,SigB,SigXCalc)

Sig_XB=SigXCalc(1:3,1:3)+MB(1:3,1:3)'*SigXCalc(1:3,1:3)*MB(1:3,1:3)+SigB(1:3,1:3);

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


for i=1:size(Rx_solved,3)
    tx_temp(:,i)=-Rx_solved(:,:,i)*so3_vec(((Rx_solved(:,:,i)'*SigA(1:3,1:3)*Rx_solved(:,:,i))^-1*(SigB(1:3,4:6)-Rx_solved(:,:,i)'*SigA(1:3,4:6)*Rx_solved(:,:,i)))');
    
    cost(i)=norm(na-Rx_solved(1:3,1:3,i)*nb)+norm(mA(4:6)-thetab*so3_vec(tx_temp(:,i))*Rx_solved(:,:,i)*nb+Rx_solved(:,:,i)*mB(4:6));
    %cost(i)=norm(na-Rx_solved(1:3,1:3,i)*nb)+norm(pa-(Rx_solved(1:3,1:3,i)*pb+(eye(3)-na*na')*tx_temp(:,i)));
end

[~,indx]=min(cost);

Rx=Rx_solved(:,:,indx);
tx=tx_temp(:,indx);

X_calc=[Rx tx; [0 0 0] 1];

end

