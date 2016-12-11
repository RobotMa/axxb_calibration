% Hand-Eye Calibration Using Dual Quaternions
% Experiments part : "SEPA" solution based on Quaternion

function W = q2W(q)
        
        W = [q(1)      -transpose(q(2:4));
             q(2:4)   eye(3)*q(1) - hat(q(2:4)) ];
        if W ~= -transpose(W)
            disp('Error :W is not skew symmetric matrix ')
        end
     
end
        