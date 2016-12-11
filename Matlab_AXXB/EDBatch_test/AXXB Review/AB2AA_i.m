% Hand-Eye Calibration Using Dual Quaternions
% Experiments part : "SEPA" solution based on Quaternion

function AA_i = AB2AA_i( A,B )

        a = Quaternion(A);
        b = Quaternion(B);
        
        % Convert quaternion to 4*1 vector form
        va = double(a);
        vb = double(b);
        
        va = va(:);
        vb = vb(:);
        
%         [theta_a n_a] = Q2EulerAA(a);
%         [theta_b n_b] = Q2EulerAA(b);
        
%         if norm(A(1:3,1:3)-R(a)) > 1
%             display('Error: Problems with transformation between Quaternion and SE(3)')
%         end
        
        % extract the vector part of the computed quaternion
        % to generate the quaternion form of screw axis
        
        % put the axis vector into R^4 vector space
%         n_a = n_a(:);
%         n_b = n_b(:);
%         
%         q_a = [0; n_a];
%         q_b = [0; n_b];
        
        Q = q2Q(va);
        W = q2W(vb);
        
        AA_i = transpose(Q - W)*(Q - W);
        
end