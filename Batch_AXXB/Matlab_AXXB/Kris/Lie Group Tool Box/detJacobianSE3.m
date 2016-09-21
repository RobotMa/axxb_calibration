function [dJr] = detJacobianSE3(X)
%[dJr] = detJacobianSE3(X)

x = vee(X)';
omega = x(1:3);

dJr1 = 2*(1-cos(norm(omega)))/(norm(omega)^2);
dJr = dJr1^2;