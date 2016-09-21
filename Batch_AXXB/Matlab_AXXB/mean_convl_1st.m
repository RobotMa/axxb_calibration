% This fucntion calculate the 1st order approximation of the mean of the 
% convolution of two probability density functions on SE(3). 

% Input: M1_hat and M2_hat denotes the mean before orthogonalization

% Future Work: To be determined which is the better M12

function M12 = mean_convl_1st(M1_hat, M2_hat)

opt = 1;

if opt == 1
    
    M12_hat = M1_hat * M2_hat;
    M12 = orthog(M12_hat);
    
elseif opt == 2
    
    M12 = orthog(M1_hat)*orthog(M2_hat);
    
end

end