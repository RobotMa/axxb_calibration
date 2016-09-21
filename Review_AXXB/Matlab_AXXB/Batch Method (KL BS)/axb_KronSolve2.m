function [ X ] = axb_KronSolve2( A,B )
%AXB_KRONSOLVECORRECT Summary of this function goes here
%   Detailed explanation goes here

n = size(A,3);

C1 = [];
C2 = [];
for i=1:n
    ua = A(1:3,4,i);
    Ra = A(1:3,1:3,i);
    Rb = B(1:3,1:3,i);
    
    C1 = [C1;eye(9)-kron(Ra,Rb)];
    C2 = [C2;eye(3)-Ra -ua];
end

[u, s, v] = svd(C1);
vecRx = v(:,end);

% vecRx=null(C1);

Rx = [vecRx(1) vecRx(2) vecRx(3); vecRx(4) vecRx(5) vecRx(6); vecRx(7) vecRx(8) vecRx(9)];

Rx=Rx*(Rx'*Rx)^(-1/2);
% [U, ~, V] = svd(Rx);
% Rx = U*([1 0 0;0 1 0;0 0 det(U*V')])*V';


Rx = sign(det(Rx))/abs(det(Rx))^(1/3)*Rx;



d = [];
for i=1:n
    ub = B(1:3,4,i);
    d = [d;-Rx*ub];
end

vecT = C2\d;
t = vecT(1:3);

X = eye(4);
X(1:3,1:3) = Rx;
X(1:3,4) = t;

end

