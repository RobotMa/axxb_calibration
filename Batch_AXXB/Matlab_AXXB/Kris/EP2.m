function [mu12,sigma12] = EP2(mu1,mu2,sigma1,sigma2)
%[mu12,sigma12] = EP1(mu1,mu2,sigma1,sigma2)
%This code is from Xiao's Thesis
mu12 = mu1*mu2;
sigma12 = zeros(6,6);

invmu2 = inv(mu2);
Ad2 = BigAdjoint(invmu2,2);
A = Ad2*sigma1*Ad2';
B = sigma2;

count = 0;
F0 = zeros(6,6,36);
for ii = 1 : 6
    for jj = 1 : 6
        count = count + 1;
        ei = zeros(6,1);
        ej = zeros(6,1);
        ei(ii) = 1;
        ej(jj) = 1;
        Ei = hat2(ei');
        Ej = hat2(ej');
        F0(:,:,count) = little_adjoint(Ei,2)*B*little_adjoint(Ej,2)'*A(ii,jj);
    end
end
f0 = (1/4)*sum(F0,3); 

%A'' and B'' computation
count = 0;
App = zeros(6,6,36);
Bpp = zeros(6,6,36);
for ii = 1 : 6
    for jj = 1 : 6
        count = count + 1;       
        ei = zeros(6,1);
        ej = zeros(6,1);
        ei(ii) = 1;
        ej(jj) = 1;
        Ei = hat2(ei');
        Ej = hat2(ej');
        App(:,:,count) = little_adjoint(Ei,2)*little_adjoint(Ej,2)*A(ii,jj);
        Bpp(:,:,count) = little_adjoint(Ei,2)*little_adjoint(Ej,2)*B(ii,jj);
        
    end
end
App = sum(App,3);
Bpp = sum(Bpp,3);

f1 = App*B;
f2 = (App*B)';
f3 = Bpp*A;
f4 = (Bpp*A)';

F = f0 + (1/12)*(f1 + f2 + f3 + f4);
sigma12 = A + B + F;





