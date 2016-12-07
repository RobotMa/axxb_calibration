% Find the Position and Orientaion of a Sensor on a Robot Manipulator Using
% Quaternions 

% one of the two compact notations
% "+" hat

function a_plus = plushat(a)
        
        a = a(:);
        
        if size(a,1) ~= 4
            display('dimension of the input not equal to 4')
        else
            a_plus = [a(1)    -transpose(a(2:4));
                      a(2:4)   a(1)*eye(3) + hat(a(2:4))];
        end
end
