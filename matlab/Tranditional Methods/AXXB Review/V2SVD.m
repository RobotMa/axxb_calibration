% Find the Position and Orientaion of a Sensor on a Robot Manipulator Using
% Quaternions 
% Generate the closed form of V2, where V2 is a part of the right singular
% vectors of matrix B.
% B is a 4 by 4 skew symmetric matrix defined in page 244, where B*px = 0

function V2 = V2SVD( u_a, u_b )
        
        if norm(u_a - u_b) > 0.1^4 % which means u_a ~= u_b 
            u_a_hat = hat(u_a);
            m2 = sqrt( 2 + 2*u_b'*u_a);
            V2 = [-1/2*m2 0; u_a_hat*u_b/m2 ( u_a + u_b)/m2];
        else % which means u_a = u_b
            x = u_a(1);
            y = u_a(2);
            z = u_a(3);
            m3 = sqrt(2 - (y - z)^2);
            V2 = 1/m3*[       0              0 ;
                        -(y + z)      x*(y - z);  
                              x   y*(y - z) - 1;
                              x   z*(y - z) + 1];
        end
                              
end
        