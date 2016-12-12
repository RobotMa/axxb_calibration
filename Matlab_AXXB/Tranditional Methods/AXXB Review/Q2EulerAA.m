% Find the Position and Orientaion of a Sensor on a Robot Manipulator Using
% Quaternions 
% express unit quaternion in Euler Axis - Angle form
function [ theta u ] = Q2EulerAA(q)
        
        qv = q.v(:);
        q = [q.s; qv];
        if size(q,1) ~= 4
            display('dimension of quaternion is NOT 4')
            return
        elseif q(1) == 1 || q(1) == 0
            display('singularity encountered')
            return
        else
            theta = 2*acos(q(1));
            u = q(2:4)/sin(theta/2);
        end
end
            