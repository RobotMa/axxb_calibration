% Find the Position and Orientaion of a Sensor on a Robot Manipulator Using
% Quaternions 

% one of the two compact notations
% "-" hat

function b_minus = minushat(b)
        
        b = b(:);
        
        if size(b,1) ~= 4
            display('dimension of the input not equal to 4')
        else
            b_minus = [b(1)    -transpose(b(2:4));
                      b(2:4)   b(1)*eye(3) - hat(b(2:4))];
        end
end
