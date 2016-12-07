function [X, MeanA, MeanB, SigA, SigB] = batchEDSolve(A,B)

[MeanA, SigA] = distibutionProps(A);
[MeanB, SigB] = distibutionProps(B);

[VA, ~] = eig(SigA(1:3,1:3));
[VB, ~] = eig(SigB(1:3,1:3));

Q1 = eye(3);
Q2 = [-1 0 0; 0 -1 0; 0 0 1];
Q3 = [-1 0 0; 0 1 0; 0 0 -1];
Q4 = [1 0 0; 0 -1 0; 0 0 -1];

Rx_solved(:,:,1) = VA*Q1*VB';
Rx_solved(:,:,2) = VA*Q2*VB';
Rx_solved(:,:,3) = VA*Q3*VB';
Rx_solved(:,:,4) = VA*Q4*VB';
Rx_solved(:,:,5) = VA*-Q1*VB';
Rx_solved(:,:,6) = VA*-Q2*VB';
Rx_solved(:,:,7) = VA*-Q3*VB';
Rx_solved(:,:,8) = VA*-Q4*VB';

[~, Na, ~, pa] = param_extract(MeanA);
[~, Nb, ~, pb] = param_extract(MeanB);
na = so3_vec(Na);
nb = so3_vec(Nb);

%min=inf;
min2 = inf;
for i = 1:size(Rx_solved,3)
    tx_temp = so3_vec(((Rx_solved(:,:,i)'*SigA(1:3,1:3)*Rx_solved(:,:,i))^-1*(SigB(1:3,4:6)-Rx_solved(:,:,i)'*SigA(1:3,4:6)*Rx_solved(:,:,i)))');
    
    if (abs(det(Rx_solved(:,:,i))-1)<0.001) && (norm(na-Rx_solved(1:3,1:3,i)*nb)<1.5) && (norm(pa-(Rx_solved(1:3,1:3,i)*pb+(eye(3)-na*na')*tx_temp))<min2)
        %min=norm(na-Rx_solved(1:3,1:3,i)*nb);
        min2 = norm(pa-(Rx_solved(1:3,1:3,i)*pb+(eye(3)-na*na')*tx_temp));
        Rx = Rx_solved(:,:,i);
   end
end

tx_temp = so3_vec(((Rx'*SigA(1:3,1:3)*Rx)^-1*(SigB(1:3,4:6)-Rx'*SigA(1:3,4:6)*Rx))');
tx = -Rx*tx_temp;

X = [Rx tx; [0 0 0] 1];
end
