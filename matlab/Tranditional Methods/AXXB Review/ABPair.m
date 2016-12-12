% Hand-Eye Calibration Using Uual Quaternions
% this function generate pairs of A and B given known transformation matrix
% X;
% 
function [ A,  B ] = ABPair(X)
          
        angle = pi/100;
        dist = 5;
        ai_n = 3*ones(3,1);

        x = 3;
        y = 3;
        z = 3;

        % construct random translation part of Ai
        range = 400*sqrt(3);
        p_ai_r = [-range + 2*range*rand; -range + 2*range*rand; -range + 2*range*rand];

        % construct random Ai in canonical coordinates
            while sqrt(x^2 + y^2 + z^2) > pi || sqrt(x^2 + y^2 + z^2) == pi...
                    || x^2 + y^2 + z^2 == 0 || norm(ai_n) > pi|| ...
                    norm(ai_n) == pi || norm(ai_n) == 0

                x = -pi + 2*pi*rand;
                y = -pi + 2*pi*rand;
                z = -pi + 2*pi*rand;
                ai_r = [x; y; z];
                ai_n = ai_r + [ -angle + 2*angle*rand; -angle + 2*angle*rand; -angle + 2*angle*rand];    
            end

        ai_r = [x; y; z];
        THETA_X = X(1:3,1:3);
        bi_r = transpose(THETA_X)*ai_r;


        % calculation of the exponential of matrix
        % note that here we don't use the built-in function expm because it's
        % based on another algorithm to calculate the matrix of exponential.
        % for the details please refer to the function in Matlab

        Ai_r = exp_ma(ai_r);
        A = [Ai_r p_ai_r; 0 0 0 1];
        B = X\A*X; % without noise

        p_bi_r = B(1:3,4);

        % add noise to each component of ai and bi
        ai_n = ai_r + [ -angle + 2*angle*rand; -angle + 2*angle*rand; -angle + 2*angle*rand];    
        bi_n = bi_r + [ -angle + 2*angle*rand; -angle + 2*angle*rand; -angle + 2*angle*rand];    

        % add noise to each component of p_ai and p_bi
        p_ai_n = p_ai_r + [ -dist + 2*dist*rand; -dist + 2*dist*rand; -dist + 2*dist*rand ];
        p_bi_n = p_bi_r + [ -dist + 2*dist*rand; -dist + 2*dist*rand; -dist + 2*dist*rand ];
        
        Ai_n = exp_ma(ai_n);
        Bi_n = exp_ma(bi_n);
        
        A = [Ai_n p_ai_n;0 0 0 1];
        B = [Bi_n p_bi_n;0 0 0 1];
        
        
end