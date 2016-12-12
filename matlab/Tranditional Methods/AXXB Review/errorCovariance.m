% AXXB Error Covariance matrix
function S = errorCovariance(A,B,X)

N = size(A,3);
S = zeros(6,6);

for i = 1:N
    a_se3 = logm(A(:,:,i));
    b_se3 = logm(B(:,:,i));
    
    a_twist = se3_vec(a_se3);
    b_twist = se3_vec(b_se3);
    
    X_ad = SE3_Ad(X);
    S = S + (a_twist - X_ad*b_twist)*(a_twist - X_ad*b_twist).';
end
    S = 1/(N - 1)*S;
end