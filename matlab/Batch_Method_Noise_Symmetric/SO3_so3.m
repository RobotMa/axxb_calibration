%Function to transform between elements in SO(3) and so(3)

%files needed:
%none

function g=SO3_so3(X)

if (X(3,3)~=0) %If input is SO3, log
    g=logm(X);
else %If input is so3, exponentiate
    g=expm(X);    
end