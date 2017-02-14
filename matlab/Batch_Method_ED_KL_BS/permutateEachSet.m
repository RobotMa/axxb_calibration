function M_perm = permutateEachSet(M, rate)

n_M = size(M, 3);
n_sets = size(M, 4);
M_perm = zeros(4, 4, n_M, n_sets);

for i = 1 : n_sets
    
    PM = (1:size(M,3));

    for j = 1:length(PM)
        if rand <= 0.01*rate
            index = randi(n_M,1);
            PM([j index]) = PM([index j]);
        end
    end
    
    M_perm(:,:,:,i) = M(:, :, PM, i);
    
end

fprintf('Permuated sensor measurements by %d percent \n', rate)

end