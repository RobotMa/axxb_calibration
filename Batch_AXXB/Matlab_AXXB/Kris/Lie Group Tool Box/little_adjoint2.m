function [ad] = little_adjoint2(X,type)
%[ad] = little_adjoint(X,type)

if type == 1 %SE(2)
E1  = hat([1 0 0]);
E2 = hat([0 1 0]);
E3 = hat([0 0 1]);

ad = zeros(3,3);
elseif type == 2 %SE(3)

twist = vee(X);

omega = twist(1:3);
v = twist(4:6);

ad = [skew(omega) skew([0 0 0]); skew(v) skew(omega)];
    
end