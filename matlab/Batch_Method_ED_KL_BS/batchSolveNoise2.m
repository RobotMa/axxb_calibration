function [X, MeanA, MeanB, MeanA_deconv, MeanB_deconv, SigA, SigB, ...
    SigA_deconv,SigB_deconv] = batchSolveNoise2(A,B,SigErrorA,SigErrorB, MeanErrorA, MeanErrorB)

[MeanA, SigA] = distibutionProps(A);
[MeanB, SigB] = distibutionProps(B);


MeanA_deconv = MeanA*MeanErrorA^-1;
MeanB_deconv = MeanB*MeanErrorB^-1;

SigA_deconv = SE3_Ad(MeanErrorA)*(SigA-SigErrorA)*SE3_Ad(MeanErrorA)';
SigB_deconv = SE3_Ad(MeanErrorB)*(SigB-SigErrorB)*SE3_Ad(MeanErrorB)';


[VA,DA] = eig(SigA_deconv(1:3,1:3));
da = diag(DA);
[daS,indA] = sort(da,'ascend');
DA = diag(daS);
VA = VA(:,indA);

[VB,DB] = eig(SigB_deconv(1:3,1:3));
db = diag(DB);
[dbS,indB] = sort(db,'ascend');
DB = diag(dbS);
VB = VB(:,indB);



Q1=eye(3);
Q2=[-1 0 0; 0 -1 0; 0 0 1];
Q3=[-1 0 0; 0 1 0; 0 0 -1];
Q4=[1 0 0; 0 -1 0; 0 0 -1];

Rx_solved(:,:,1) = VA*Q1*VB';
Rx_solved(:,:,2) = VA*Q2*VB';
Rx_solved(:,:,3) = VA*Q3*VB';
Rx_solved(:,:,4) = VA*Q4*VB';
Rx_solved(:,:,5) = VA*-Q1*VB';
Rx_solved(:,:,6) = VA*-Q2*VB';
Rx_solved(:,:,7) = VA*-Q3*VB';
Rx_solved(:,:,8) = VA*-Q4*VB';

[~,Na,~, ~]=param_extract(MeanA_deconv);
[~,Nb,~, ~]=param_extract(MeanB_deconv);
na=so3_vec(Na);
nb=so3_vec(Nb);

min=inf;
for i=1:8
    if (abs(det(Rx_solved(:,:,i))-1)<0.001) && (norm(na-Rx_solved(1:3,1:3,i)*nb)<min)
        min=norm(na-Rx_solved(1:3,1:3,i)*nb);
        Rx=Rx_solved(:,:,i);
   end
end

%tx=Rx*so3_vec((SigB(1:3,1:3))^-1*(SigB(1:3,4:6)-Rx'*SigA(1:3,4:6)*Rx));
tx = Rx*so3_vec((SigB_deconv(1:3,1:3))^-1*(SigB_deconv(1:3,4:6)-Rx'*SigA_deconv(1:3,4:6)*Rx));

X = [Rx tx; [0 0 0] 1];

end

