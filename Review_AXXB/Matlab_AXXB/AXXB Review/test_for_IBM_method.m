% Test for IBM method of estimation
clc 
clear all
close all

w = [1;2;3]/(14);
x = hat(w);
theta_x = expm(x);
theta_x*theta_x';
M = zeros(3,3);
n = 50;

for i = 1:n
        
    x = 3;
    y = 3;
    z = 3;
            while sqrt(x^2 + y^2 + z^2) > pi || sqrt(x^2 + y^2 + z^2) == pi...
                    || x^2 + y^2 + z^2 == 0 || abs(x) > 49/50*pi || ...
                    abs(y) > 49/50*pi || abs(z) > 49/50*pi

                x = -pi + 2*pi*rand;
                y = -pi + 2*pi*rand;
                z = -pi + 2*pi*rand;
            end

        ai(1:3,i) = [x; y; z];    
        bi(1:3,i) = theta_x'*ai(1:3,i);
end

ai_bar = sum(ai,2)/n;
bi_bar = sum(bi,2)/n;
P = ai - ai_bar*ones(1,n);
Q = bi - bi_bar*ones(1,n);


% for i = 1:50
%     M = M + (bi(1:3,i) - bi_bar)*(ai(1:3,i) - ai_bar)';
% end


M = P*Q';

M1= zeros(1:3,1:3);
for j = 1:n
    M1 = M1 + bi(1:3,j)*ai(1:3,j)';
end
theta_x


theta_est = M*(transpose(M)*M)^(-1/2) 


theta_est = (transpose(M1)*M1)^(-1/2)*M1' 
