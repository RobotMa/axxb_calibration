%Function to vectorize or hat an element of se(3)

%files needed:
%none

function g = se3_vec(X)

if (size(X,2)==4) %If input is skew-sym change to vector
    
    g = [-X(2,3); X(1,3); -X(1,2); X(1,4); X(2,4); X(3,4)];
    
else %If input is vector change to skew-sym 
    
    g = [0      -X(3)	X(2)	X(4)
        X(3)    0       -X(1)   X(5)
        -X(2)   X(1)    0       X(6)
        0       0       0       0];

end
