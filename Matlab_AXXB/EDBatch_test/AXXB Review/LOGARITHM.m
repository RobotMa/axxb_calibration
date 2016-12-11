% Robot Sensor Calibration: Solving AX = XB on the Euclidean Group

function uniball = LOGARITHM(R)

% uniball : visualize SO(3) as a 3-dimentional solid ball of radius pi and
% "uniball", a point in the ball represents a rotation by an angle
% ||uniball|| about the ray directed from the origin through uniball

        % find the largest element in the deduction of two matrices
        test = R*R' - eye(3);
        a = max(test);
        b = max(a);
        if b > 0.001
            
            display('R does not lie in SO(3)')
            R
            return;
        else

            if trace(R) == -1
                display('rotated angle equals to +/- pi')
            elseif trace(R) == 3
                display('phi = 0')
            else
                phi = acos((trace(R) - 1)/2);
                uniball_hat = phi/(2*sin(phi))*(R - R');
                uniball(1,1) = uniball_hat(3,2);
                uniball(2,1) = uniball_hat(1,3);
                uniball(3,1) = uniball_hat(2,1);
            end
        end
end