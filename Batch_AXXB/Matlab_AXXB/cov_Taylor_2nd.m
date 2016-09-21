% This function calculates the 2nd order approximation of the covariance of
% a bunch of matrices based on the Taylor expansion of the matrix logarithm
% and the definition of mean of a probability density function.

% Input: X is a 4 by 4*n cumulation of n rigid body transformations

function Sigma = cov_Taylor_2nd(X) %#codegen

n_search = int16(10^2);

M_X = mean_Taylor_2nd_mex( X, 1, n_search );

n = size(X,2)/4;
Sigma = zeros(6,6);

for i = 1:n

    X_i = X(:,4*(i-1)+1:4*i);
    P = ( M_X\X_i - eye(4) ) - 1/2*( M_X\X_i - eye(4) )^2;
    Sigma = Sigma + se3_vec( P )*se3_vec( P )';
end

Sigma = 1/n*Sigma;

end