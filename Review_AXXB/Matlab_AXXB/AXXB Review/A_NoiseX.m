%Function to add Gaussian noise to a g \in SE(3)

%files needed:
%se3_vec().m

function [A, X_dist] = A_NoiseX(B, X, gmean, std, model)

n = size(B,3);
X_1 = zeros(4,4,n);
X_2 = zeros(4,4,n);
A = zeros(4,4,n);

for i = 1:size(B,3)
    
    
    X_1(:,:,i) = sensorNoise(X, gmean, std, model);
        
    X_2(:,:,i) = sensorNoise(X, gmean, std, model);
    
    A(:,:,i) = X_1(:,:,i)*B(:,:,i)*X_2(:,:,i)^-1;
    
end

    X_dist = cat(3, X_1, X_2);


end