% Hand-Eye Calibration Using Dual Quaternions
% Experiments part : "SEPA" solution based on Quaternion

function Q = q2Q(q)
        
        Q = [q(1)     -transpose(q(2:4)); 
             q(2:4)  hat(q(2:4)) + eye(3)*q(1) ];
        if Q ~= -transpose(Q)
            display('Error :Q is not skew symmetric matrix ')
        end
        
end
        