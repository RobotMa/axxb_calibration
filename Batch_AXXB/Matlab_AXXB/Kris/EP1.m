function [mu12,sigma12] = EP1(mu1,mu2,sigma1,sigma2)
%[mu12,sigma12] = EP1(mu1,mu2,sigma1,sigma2)
%This Method is Dr C's EP Paper (Corrected)

sigma12 = zeros(6,6);
%Convolved Mean mu12
mu12 = mu1*mu2;

invmu2 = inv(mu2);

Ad2 = BigAdjoint(invmu2,2);
A = Ad2*sigma1*Ad2';
B = sigma2;

A11 = A(1:3,1:3);
A12 = A(1:3,4:6);
A22 = A(4:6,4:6);
B11 = B(1:3,1:3);
B12 = B(1:3,4:6);
B22 = B(4:6,4:6);

App = zeros(6,6);
App(1:3,1:3) = A11 - trace(A11)*eye(3,3);
App(4:6,1:3) = A12 + A12' - 2*trace(A12)*eye(3,3);
App(4:6,4:6) = A11 - trace(A11)*eye(3,3);

Bpp = zeros(6,6);
Bpp(1:3,1:3) = B11 - trace(B11)*eye(3,3);
Bpp(4:6,1:3) = B12 + B12' - 2*trace(B12)*eye(3,3);
Bpp(4:6,4:6) = B11 - trace(B11)*eye(3,3);

f1 = App*B;
f2 = (App*B)';
f3 = Bpp*A;
f4 = (Bpp*A)';

[D_1111] = Dfunction(A11,B11);
[D_1211] = Dfunction(A12,B11);
[D_2211] = Dfunction(A22,B11);
[D_1112] = Dfunction(A11,B12);
[D_1122] = Dfunction(A11,B22);
[D_1212] = Dfunction(A12,B12);

C11 = -D_1111;
C12 = -(D_1211)' - D_1112;
C21 = C12';
C22 = -(D_2211) - (D_1212) - (D_1212)' - (D_1122);

C = [C11 C12;C21 C22];
f0 = C;

sigma12 = A + B + f0/4 + (1/12)*(f1+f2+f3+f4);

