% Hand-Eye Calibration Using Dual Quaternions
% this function generate pairs of A and B given known transformation matrix
% X;

function [ A, B ] = ABPair1(X)
        
        % initialization for the construction of matrix A
        x = 3;
        y = 3;
        z = 3;
        ai_n = 3*ones(3,1);
        
        angle = pi/100;
        % dist = 5;
        
        % construct translation part of matrix A
        % range of each element of translation vector
        range = 4*sqrt(3);
        p_ai_r = [-range + 2*range*rand; 
                  -range + 2*range*rand; 
                  -range + 2*range*rand];
        
        % construct rotation part of matrix A in the form of a uniball
        % "Robot Sensor Calibration Solving AX = XB on the Euclidean Group"
           while abs(sqrt(x^2 + y^2 + z^2) - pi) < 0.1 || sqrt(x^2 + y^2 + z^2) > pi...
                    || abs(x^2 + y^2 + z^2) < 0.1 || norm(ai_n) > pi|| ...
                    norm(ai_n) == pi || norm(ai_n) == 0

                x = -pi + 2*pi*rand;
                y = -pi + 2*pi*rand;
                z = -pi + 2*pi*rand;
                ai_r = [x; y; z];
                ai_n = ai_r + [ -angle + 2*angle*rand; 
                                -angle + 2*angle*rand; 
                                -angle + 2*angle*rand];    
            end

        ai_r = [x; y; z];
        
        R_Ai = expm(hat(ai_r));
        A = [R_Ai p_ai_r;0 0 0 1];
        B = X\A*X; 
        
end