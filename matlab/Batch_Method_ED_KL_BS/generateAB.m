function [A, B] = generateAB(length, optPDF, X, M, Sig)
%% Data generation for AX = XB problem


%% Initialization
A = zeros(4, 4, length);
B = zeros(4, 4, length);

if optPDF == 1
    
    for i = 1:length      
        B(:,:,i) = expm(se3_vec(mvg(M, Sig, 1)));
        A(:,:,i) = X*B(:,:,i)*X^-1;
        
    end
    
end

end