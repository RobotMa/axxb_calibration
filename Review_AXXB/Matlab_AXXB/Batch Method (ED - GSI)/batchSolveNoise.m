function [X_batchNoise,SigX]=batchSolveNoise(MeanA,MeanB,X_batch,SigA,SigB)

X_batchNoise=X_batch;

for i=1:1

M=kron(SE3inv_Ad(MeanB),SE3inv_Ad(MeanB)) - kron(eye(6),eye(6)); 
%C=kron(SE3inv_Ad(X_batch), SE3inv_Ad(X_batch))*reshape(SigA, 36,1)-kron(eye(6),eye(6))*reshape(SigB,36,1)
C=reshape(SE3inv_Ad(X_batchNoise)*SigA*SE3inv_Ad(X_batchNoise)'-SigB, 36,1);

sigX=pinv(M)*C;

SigX=reshape(sigX,6,6);


SigRight(1:3,1:3)=MeanB(1:3,1:3)'*SigX(1:3,1:3)*MeanB(1:3,1:3)+SigB(1:3,1:3)-SigX(1:3,1:3);

[VA,DA]=eig(SigA(1:3,1:3));
[DA order] = sort(diag(DA),'ascend');
DA=diag(DA);
VA = VA(:,order);
[VB,DB]=eig(SigRight(1:3,1:3));
[DB order] = sort(diag(DB),'ascend');
DB=diag(DB);
VB = VB(:,order);

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

[~,Na,~, ~]=param_extract(MeanA);
[~,Nb,~, ~]=param_extract(MeanB);
na=so3_vec(Na);
nb=so3_vec(Nb);

min=inf;
for i=1:8
    if (abs(det(Rx_solved(:,:,i))-1)<0.001) && (norm(na-Rx_solved(1:3,1:3,i)*nb)<min)
        min=norm(na-Rx_solved(1:3,1:3,i)*nb);
        Rx=Rx_solved(:,:,i);
   end
end

tx_temp=so3_vec(((Rx'*SigA(1:3,1:3)*Rx)^-1*(SigB(1:3,4:6)-Rx'*SigA(1:3,4:6)*Rx))');
tx=-Rx*tx_temp;

X_batchNoise=[Rx tx; [0 0 0] 1];

a=0;

end
