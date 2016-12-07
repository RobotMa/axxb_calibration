% Find the Position and Orientaion of a Sensor on a Robot Manipulator Using
% Quaternions 

function [y21_2 y22_2]  = y2(alpha,beta,gamma)
        
        if abs(alpha) > abs(beta) || abs(alpha) == abs(beta)
            y21_2 = gamma/sqrt( alpha^2 + gamma^2);
            y22_2 = -alpha/sqrt( alpha^2 + gamma^2);
        else
            y21_2 = beta/sqrt( beta^2 + gamma^2);
            y22_2 = -gamma/sqrt( beta^2 + gamma^2);
        end
end
            
