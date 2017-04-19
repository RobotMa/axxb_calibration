function [A_set, B_set] = generateSetsOfAB( n_sets, num, optPDF, ...
                                            gmean, cov, X, Y)

A_set = zeros(4, 4, num, n_sets);
B_set = zeros(4, 4, num, n_sets);

for i = 1 : n_sets
    [A_set(:,:,:,i), B_set(:,:,:,i)] = generateAB(num, optPDF, gmean, cov, X, Y);
end

end