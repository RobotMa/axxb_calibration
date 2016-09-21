function [x] = vee(X)

% x = zeros(1,length(X));

if length(X) == 3 %SE(2)
x(1) = X(1,3);
x(2) = X(2,3);
x(3) = X(2,1);
    
elseif length(X) == 4 %SE(3)
x(4) = X(1,4);
x(5) = X(2,4);
x(6) = X(3,4);
x(1) = X(3,2);
x(2) = X(1,3);
x(3) = X(2,1);

end

x = stack(x); %Forces x to be a nx1 vector