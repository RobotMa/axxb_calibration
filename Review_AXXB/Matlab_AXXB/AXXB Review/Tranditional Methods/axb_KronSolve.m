%Function to solve AX=XB for inputs of A and B which are 3D matrices where
%each AB pair is stacked in the third dimension (ie. Ai=A(:,:,i)). 'num' is
%the amount of pairs

%files needed:
%none

function [X] = axb_KronSolve(A,B)

A_k = [];
b_k = [];

for i = 1:size(A,3)
    Ra(:,:,i) = A(1:3,1:3,i);
    Rb(:,:,i) = B(1:3,1:3,i);
    
    Ta(:,:,i) = A(1:3,4,i);
    Tb(:,:,i) = B(1:3,4,i);
    
    D = diag(Ta(:,:,i));
    
    A_k = [A_k;[eye(9)-kron(Rb(:,:,i),Ra(:,:,i)), zeros(9,3); kron(Tb(:,:,i)',eye(3)), eye(3)-Ra(:,:,i)]];
    
    b_k = [b_k;[zeros(9,1); Ta(:,:,i)]];
end


X_k = pinv(A_k)*b_k;
% X_k=A_k\b_k;


X = [[X_k(1:3), X_k(4:6), X_k(7:9)] X_k(10:12); zeros(1,3) 1];

X(1:3,1:3) = sign(det(X(1:3,1:3)))/abs(det(X(1:3,1:3)))^(1/3)*X(1:3,1:3);

end