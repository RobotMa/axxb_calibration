%Function to vectorize or hat an element in so(3)

%files needed:
%none


function g = so3_vec(X)

if ( size(X,2) == 3 ) %If input is skew-sym change to vector
    
    g = [-X(2,3); X(1,3); -X(1,2)];
    
else %If input is vector change to skew-sym 
    
    g = [   0   -X(3)	 X(2);
         X(3)       0   -X(1);
        -X(2)    X(1)      0];
end

end
