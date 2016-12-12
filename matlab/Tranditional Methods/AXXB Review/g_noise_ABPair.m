% Hand-Eye Calibration Using Dual Quaternions
% this function generate pairs of As and Bs given known transformation
% matrix using g_noise 

function [ A, B ] = g_noise_ABPair(X, gmean, std, model)
          
        angle = 0;
%         dist = 1; % for Dual Quaternion Testimation 
        dist = 4;
        ai_n = 3*ones(3,1);

        x = 3;
        y = 3;
        z = 3;

        % construct random translation part of Ai
        range = 400*sqrt(3);
%         range = 100; % for Dual Quaternion Testimation
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

        Ai_r = expm(skew(ai_r));

        A = [Ai_r p_ai_r;0 0 0 1];
        B = X\A*X; % without noise
        
        % add g_noise to the matrices
        % g_noise=sensorNoise(g, gmean, std, model)
        % gmean is 6 by 1
        % model 1 2 3 4 
%         A_g_noise = sensorNoise(A, gmean, std, model);
%         B_g_noise = sensorNoise(B, gmean, std, model);

end