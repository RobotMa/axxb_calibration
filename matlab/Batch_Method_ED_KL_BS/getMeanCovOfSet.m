function [Mean, Sig] = getMeanCovOfSet(M)
% Compute the mean and covariance given a cloud of SE3 matrices

n_sets = size(M, 4);

Mean = zeros(4, 4, n_sets);
Sig  = zeros(6, 6, n_sets);

for i  = 1: n_sets
    [Mean(:,:,i), Sig(:,:,i)] = getMeanCov(M(:,:,:,i));
end

end