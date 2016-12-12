% Robot Sensor Calibration: Solving AX = XB on the Euclidean Group
clc 
clear all
close all
global X_result

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

% digits(6)
% THETA_X = vpa(A/B);
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

[Sbx1, Sbx2] = solve(M_L(1:2,1:3)*bx == M_R(1:2,1));
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

ita(1:2,10) = 0;
ita_bar(1:2,1) = 0;
ai_n = 3*ones(3,100);

% disturbance
% angle = pi/100;
% dist = 5;
angle = pi/20;
dist = 10;

n = 100;

for j = 1:10
    
    M = zeros(3,3);
    ai_n = 3*ones(3,100);

    for i = 1:n
        
        x = 3;
        y = 3;
        z = 3;

        % construct random translation part of Ai
        range = 400*sqrt(3);
        p_ai_r = [-range + 2*range*rand; -range + 2*range*rand; -range + 2*range*rand];

        % construct random Ai in canonical coordinates
            while sqrt(x^2 + y^2 + z^2) > pi || sqrt(x^2 + y^2 + z^2) == pi...
                    || x^2 + y^2 + z^2 == 0 || norm(ai_n(1:3,i)) > pi|| ...
                    norm(ai_n(1:3,i)) == pi || norm(ai_n(1:3,i)) == 0

                x = -pi + 2*pi*rand;
                y = -pi + 2*pi*rand;
                z = -pi + 2*pi*rand;
                ai_r = [x; y; z];
                ai_n(1:3,i) = ai_r + [ -angle + 2*angle*rand; -angle + 2*angle*rand; -angle + 2*angle*rand];    
            end

        ai_r = [x; y; z];
        bi_r = transpose(THETA_X)*ai_r;


        % calculation of the exponential of matrix
        % note that here we don't use the built-in function expm because it's
        % based on another algorithm to calculate the matrix of exponential.
        % for the details please refer to the function in Matlab

        Ai_r = exp_ma(ai_r);
        A = [Ai_r p_ai_r;0 0 0 1];
%         B = X_hat\A*X_hat;
        B = X\A*X;

        Bi_r = B(1:3,1:3);
        p_bi_r = B(1:3,4);

        % add noise to each component of a1 a2 b1 b2
%         ai_n(1:3,i) = ai_r + [ -pi/100 + pi/50*rand; -pi/100 + pi/50*rand; -pi/100 + pi/50*rand];
        bi_n(1:3,i) = bi_r + [ -angle + 2*angle*rand; -angle + 2*angle*rand; -angle + 2*angle*rand];    

        % add noise to each component of p_a1 p_b1
        p_ai_n(1:3,i) = p_ai_r + [ -dist + 2*dist*rand; -dist + 2*dist*rand; -dist + 2*dist*rand ];
        p_bi_n(1:3,i) = p_bi_r + [ -dist + 2*dist*rand; -dist + 2*dist*rand; -dist + 2*dist*rand ];

    end
        % least square estimation
    for k = 1:n
        
        num1 = 3*k - 2;
        num2 = 3*k;
        
        ai_bar = sum(ai_n,2)/k;
        bi_bar = sum(bi_n,2)/k;
        
        P = ai_n(:,1:k) - ai_bar*ones(1,k);
        Q = bi_n(:,1:k) - bi_bar*ones(1,k);
        
        M = P*Q';

%          M = M + bi_n*transpose(ai_n);

%         THETA_hat = (transpose(M)*M)^(-1/2)*transpose(M);
        

            if k > 2
                
                if k == 3
                    
                   Ai_n1 = exp_ma(ai_n(1:3,1));
                   Ai_n2 = exp_ma(ai_n(1:3,2));
                   Ai_n3 = exp_ma(ai_n(1:3,3));
                   THETA_hat = M*(transpose(M)*M)^(-1/2);
                   C(1:9,1:3) = [eye(3) - Ai_n1; eye(3) - Ai_n2; eye(3) - Ai_n3];
                   d(1:9,1) = [p_ai_n(1:3,1) - THETA_hat*p_bi_n(1:3,1);
                               p_ai_n(1:3,2) - THETA_hat*p_bi_n(1:3,2);
                               p_ai_n(1:3,3) - THETA_hat*p_bi_n(1:3,3)];
                    
                else
                
                    THETA_hat = M*(transpose(M)*M)^(-1/2);

                    Ai_n = exp_ma(ai_n(1:3,k));

                    C(num1:num2,1:3) = eye(3) - Ai_n;
                    d(num1:num2,1) = p_ai_n(1:3,k) - THETA_hat*p_bi_n(1:3,k);
                end
                
                b_hat(1:3,k) = (transpose(C)*C)\transpose(C)*d;
                X_hat_LS = [THETA_hat b_hat(1:3,k); 0 0 0 1];

%                 ita(k,j) = norm(X_hat_LS - X_hat);
                ita(k,j) = norm(X_hat_LS - X);

                % average of ten indepedent simulations


                if k == n
                    X_result = X_hat_LS;
                end

            end
    end
    
    clear C d % not clearing these two will affect new C and d when j > 1

    if j == 10
                
       ita_bar = sum(ita,2)/10;
    end

end

%%
plot(ita_bar(3:n),'o')
if dist ==5 
   axis([0 100 0 10])
elseif dist == 10
    axis([0 100 0 20])
else
    display('new disturbance')
    axis([0 100 0 50])
end
title('error \gamma as a function of k')
xlabel('k times')
ylabel('error \gamma')
X_result


   


