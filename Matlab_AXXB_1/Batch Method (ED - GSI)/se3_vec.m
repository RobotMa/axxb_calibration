%Function to vectorize or hat an element of se(3)

%files needed:
%none

function g = se3_vec(X)

n = 0;
n = size(X,2);

if ( n == 4 ) %If input is skew-sym change to vector
    
    X_init = zeros(4, 4);
    
    X_init = X;
    
    g = [-X_init(2,3); X_init(1,3); -X_init(1,2); X_init(1,4); X_init(2,4); X_init(3,4)];
    
else %If input is vector change to skew-sym 
    
    X_init = zeros(6, 1);
    
    X_init = X;
    
    g = [0          -X_init(3)	X_init(2)	X_init(4);
         X_init(3)   0         -X_init(1)   X_init(5);
        -X_init(2)   X_init(1)  0           X_init(6);
          0          0          0           0       ];

end
