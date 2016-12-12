% Robot Sensor Calibration: Solving AX = XB on the Euclidean Group
clc 
clear all
close all

A1 = [-0.989992 -0.141120  0         0;
       0.141120 -0.989992  0         0;
       0         0         1         0;
       0         0         0         1];
B1 = [-0.989992 -0.138307  0.028036 -26.9559; 
       0.138307 -0.911449  0.387470 -96.1332;
      -0.028036  0.387470  0.921456  19.4872;
       0         0         0         1];
A2 = [ 0.070737  0         0.997495 -400.000;
       0         1         0         0;
      -0.997495  0         0.070737  400.000;
       0         0         0         1];
B2 = [ 0.070737  0.198172  0.977612 -309.543;
      -0.198172  0.963323 -0.180936  59.0244;
      -0.977612 -0.180936  0.107415  291.177;
       0         0         0         1];
   
%%
% extraction of rotation matrix
A1_R = A1(1:3,1:3);
A2_R = A2(1:3,1:3);
B1_R = B1(1:3,1:3);
B2_R = B2(1:3,1:3);

% extraction of translation vector
p_a1 = A1(1:3,4);
p_a2 = A2(1:3,4);
p_b1 = B1(1:3,4);
p_b2 = B2(1:3,4);

% calculation of point in the visualized solid ball
a1 = LOGARITHM(A1_R);
b1 = LOGARITHM(B1_R);
a2 = LOGARITHM(A2_R);
b2 = LOGARITHM(B2_R);

A = [a1 a2 cross(a1,a2)];
B = [b1 b2 cross(b1,b2)];

THETA_X = A/B;


%%
syms bx1 bx2 bx3

bx = [bx1; bx2; bx3];

% according to Equ(6)
M_L = [A1_R - eye(3);
       A2_R - eye(3)];
M_R = [THETA_X*p_b1 - p_a1;
       THETA_X*p_b2 - p_a2];
   
format short
% determine the zero rows in M_L
% we can see (accordingi to the positions of zero elements in M_L) that the 3rd and 5th row of M_L are all zeros, thus these
% shall be eliminated. Then we use the 1st and 2nd row to calculate bx1
% and bx2, and use 4th row and 6th row to calculate bx1 and bx3. Finally,
% we again use 1st row and 6th row to test the result. 

[Sbx1, Sbx2] = solve(M_L([1,2],1:3)*bx == M_R(1:2,1));
bx1_1 = double(Sbx1);
bx2 = double(Sbx2);

[Sbx1, Sbx3] = solve(M_L([4,6],1:3)*bx == M_R([4,6],1));
bx1_2 = double(Sbx1);
bx3 = double(Sbx3);

b = [(bx1_1+bx1_2)/2; bx2; bx3];

% for consistency, we set the translation vector of X as given in the paper
% which is as follows, vector "temp"
temp = [10; 50; 100];
X = [THETA_X temp; 0 0 0 1];
X_hat = [THETA_X b;0 0 0 1];

%%
% construction of random Ai without noise
% initialization of vector

N = 100;
n = 100;

gmean = zeros(6,1);
std = 0.01;
model = 2;
error = zeros(100,3,n);

for j = 1:n
    
    M = zeros(3,3);
    ai_n = zeros(3,N);
    bi_n = zeros(3,N);
    p_ai_n = zeros(3,N);
    p_bi_n = zeros(3,N);
    X_e = zeros(4,4,N);
    A(1:4,1:4,1:N) = zeros(4,4,N);
    B(1:4,1:4,1:N) = zeros(4,4,N);
    
    for i = 1:N 
        [A(:,:,i), B(:,:,i)] = g_noise_ABPair(X,gmean,std,model);
        ai_n(:,i) = LOGARITHM(A(1:3,1:3,i));
        bi_n(:,i) = LOGARITHM(B(1:3,1:3,i));
        p_ai_n(:,i) = A(1:3,4,i);
        p_bi_n(:,i) = B(1:3,4,i);
    end
    
        % least square estimation
    for k = 1:N
        
        num1 = 3*k - 2;
        num2 = 3*k;
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % added on 12/10/2013
%         ai_k = ai_n(:,1:k);
%         bi_k = bi_n(:,1:k);
        
        ai_bar = sum(ai_n,2)/k;
        bi_bar = sum(bi_n,2)/k;
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        
        P = ai_n(:,1:k) - ai_bar*ones(1,k);
        Q = bi_n(:,1:k) - bi_bar*ones(1,k);
        
        M = P*Q';
        
            if k > 2
                
                if k == 3
                    
                   Ai_n1 = expm(skew(ai_n(1:3,1)));
                   Ai_n2 = expm(skew(ai_n(1:3,2)));
                   Ai_n3 = expm(skew(ai_n(1:3,3)));
                   THETA_hat = M*(transpose(M)*M)^(-1/2);
                   C(1:9,1:3) = [eye(3) - Ai_n1; eye(3) - Ai_n2; eye(3) - Ai_n3];
                   d(1:9,1) = [p_ai_n(1:3,1) - THETA_hat*p_bi_n(1:3,1);
                               p_ai_n(1:3,2) - THETA_hat*p_bi_n(1:3,2);
                               p_ai_n(1:3,3) - THETA_hat*p_bi_n(1:3,3)];
                    
                else
                
                    THETA_hat = M*(transpose(M)*M)^(-1/2);

                    Ai_n = expm(skew(ai_n(1:3,k)));

                    C(num1:num2,1:3) = eye(3) - Ai_n;
                    d(num1:num2,1) = p_ai_n(1:3,k) - THETA_hat*p_bi_n(1:3,k);
                end
                
                b_hat(1:3,k) = (transpose(C)*C)\transpose(C)*d;
                X_e(:,:,k) = [THETA_hat b_hat(1:3,k); 0 0 0 1];

            end
    end
    
    error(:,:,j) = errorCal(X,X_e,N);
    
    clear C d % not clearing these two will affect new C and d when j > 1

end


%%
errorTotal = zeros(N,3);
for i = 1:n
    errorTotal = errorTotal + error(:,:,i);
end

errorMean = errorTotal/n;

figure
plot(3:100,errorMean(3:100,1),'o')
xlabel('k times')
ylabel('error \gamma')
title('error \gamma as a function of k')
grid on

figure
plot(3:100,errorMean(3:100,2),'o')
xlabel('k times')
ylabel('error \gamma')
title('error \gamma as a function of k')
grid on

figure
plot(3:100,errorMean(3:100,3),'o')
xlabel('k times')
ylabel('error \gamma')
title('error \gamma as a function of k')
grid on
% tr((H1 - H2)W(H1 - H2)')


   


