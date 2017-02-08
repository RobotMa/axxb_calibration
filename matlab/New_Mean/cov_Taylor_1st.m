% This function calculates the 1st order approximation of the covariance of
% a bunch of matrices based on the Taylor expansion of the matrix logarithm
% and the definition of mean of a probability density function.

% Input: X is a 4 by 4*n cumulation of n rigid body transformations

function Sigma = cov_Taylor_1st(X)


[M_t1,~] = mean_Taylor_1st_mex(X);

n = size(X,2)/4;
Sigma = zeros(6,6);

for i = 1:n
    
    Q = M_t1\X(:,4*(i-1)+1:4*i);
    Sigma = Sigma + se3_vec( Q - eye(4) )*se3_vec( Q - eye(4) )';
end

Sigma = 1/n*Sigma;

end