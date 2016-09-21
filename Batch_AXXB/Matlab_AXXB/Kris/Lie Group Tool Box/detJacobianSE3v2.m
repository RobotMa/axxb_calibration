function [dJr] = detJacobianSE3v2(V)
%[dJr] = detJacobianSE3(X)

omega = V(1:3,:);
norm1 = sqrt(omega(1,:).^2 + omega(2,:).^2 + omega(3,:).^2); %norm of omega
norm2 = norm1.^2;

dJr1 = 2.*(1-cos(norm1))./(norm2);
dJr = dJr1.^2;