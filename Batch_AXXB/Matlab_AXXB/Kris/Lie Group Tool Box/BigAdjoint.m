function [Ad] = BigAdjoint(g,type)
%[Ad] = BigAdjoint(g,type)
% Inputs: g - a group element of either SE(2) or SE(3)
%         type - a value 1 for SE(2) and 2 for SE(3)
%
% Output: The Adjoint matrix [Ad]

if type == 1 %SE(2)
E1  = hat([1 0 0]);
E2 = hat([0 1 0]);
E3 = hat([0 0 1]);
    
Ad = zeros(3,3);
Ad(:,1) = vee(g*E1*inv(g));
Ad(:,2) = vee(g*E2*inv(g));
Ad(:,3) = vee(g*E3*inv(g));

elseif type == 2 %SE(3)
E1 = hat2([1 0 0 0 0 0]);
E2 = hat2([0 1 0 0 0 0]);
E3 = hat2([0 0 1 0 0 0]);
E4 = hat2([0 0 0 1 0 0]);
E5 = hat2([0 0 0 0 1 0]);
E6 = hat2([0 0 0 0 0 1]);

Ad = zeros(6,6);
Ad(:,1) = vee(g*E1*inv(g))';
Ad(:,2) = vee(g*E2*inv(g))';
Ad(:,3) = vee(g*E3*inv(g))';
Ad(:,4) = vee(g*E4*inv(g))';
Ad(:,5) = vee(g*E5*inv(g))';
Ad(:,6) = vee(g*E6*inv(g))';


    
end

