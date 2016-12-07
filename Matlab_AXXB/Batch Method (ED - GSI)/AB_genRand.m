function [A, B] = AB_genRand(X, M, Sig, num)


for i = 1:num
    
    B(:,:,i) = expm(se3_vec(mvg(M, Sig, 1)));
    A(:,:,i) = X*B(:,:,i)*X^-1;
    
end