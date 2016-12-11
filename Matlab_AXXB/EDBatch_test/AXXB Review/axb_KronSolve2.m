function [ X ] = axb_KronSolve2( A,B )
%AXB_KRONSOLVECORRECT Summary of this function goes here
%   Detailed explanation goes here

n = size(A,3);

C1 = [];
C2 = [];
for i=1:n
    Ra = A(1:3,1:3,i);
    Rb = B(1:3,1:3,i);
    
    C1 = [C1;eye(9)-kron(Rb,Ra)];
    C2 = [C2;eye(3)-Ra];
end

[~, ~, v] = svd(C1);
vecRx = v(:,end);


Rx = [[vecRx(1); vecRx(2); vecRx(3)] [vecRx(4); vecRx(5); vecRx(6)] ...
      [vecRx(7); vecRx(8); vecRx(9)]];

% Ensure rotation is rotation
Rx = Rx*(Rx'*Rx)^(-1/2);

Rx = sign(det(Rx))/abs(det(Rx))^(1/3)*Rx;

d = [];
for i=1:n
    ub = B(1:3,4,i);
    ua = A(1:3,4,i);
    d = [d;-Rx*ub+ua];
end

% Least Squares Inverse C2*t = d
t = C2\d;

X = eye(4);
X(1:3,1:3) = Rx;
X(1:3,4) = t;

end

