% This function takes in a 4 by 4 matrix which has the form of
% [3 by 4; 0 0 0 n] and return a rigig transformation matrix by
% orthogonalizing the upper left 3 by 3 matrix into a rotation matrix

function T = orthog(M_hat)

opt = 2;   % opt = 1: Orthogonalize only the rotation part of M_hat 
           % opt = 2: SVD the whole M_hat to obtain a transformation matrix
if opt == 1
    
    R_hat = M_hat(1:3,1:3); % Note that R_hat doesn't belong to SO(3)
    
    % Project onto SO(3)
    Rx = R_hat*(R_hat'*R_hat)^(-1/2);
    Rx = sign(det(Rx))/abs(det(Rx))^(1/3)*Rx;
    
    T = [Rx M_hat(1:3,4); 0 0 0 1];
    
elseif opt == 2
    
    [U, ~, V] = svd(M_hat(1:3,1:3));
    
    % Note that the order of U and V matters
    Rx = U*V';
    
    if det(Rx) < 0
        Rx(:,3) = - Rx(:,3);  
    end
    
    if abs( det(Rx) - 1) > 10^-8
        fprintf('A non rotation matrix is returned');
    end
    
    T = [Rx M_hat(1:3,4); 0 0 0 1];
end

end