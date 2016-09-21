%Function to transform between elements in SE(3) and se(3)

%files needed:
%none

function g=SE3_se3(X)

if (X(4,4)==1) %If input is SE3, log
    g=logm(X);
else %If input is se3, exponentiate
    g=expm(X);    
end