% Robot Sensor Calibration: Solving AX = XB on the Euclidean Group

function W = hat(w)
        
        % rearrange the vector as column vector
        w = w(:);
        
        if size(w,1) < 3
            display('dimension of w is less than 3')
            return;
        elseif size(w,1) == 3
            W = [  0     -w(3)   w(2);
                  w(3)    0     -w(1);
                 -w(2)    w(1)    0];
        else 
            display('dimension of input vector is beyond the scope of computation')
        end
end