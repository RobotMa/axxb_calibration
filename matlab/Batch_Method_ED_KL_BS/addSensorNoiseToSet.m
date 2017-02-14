function M_noise = addSensorNoiseToSet(M, gmean, coeff2, noiseModel)

n_M = size(M, 3);
n_sets = size(M, 4);

M_noise = zeros(4, 4, n_M, n_sets);

for i = 1: n_sets
    M_noise(:,:,:,i) = sensorNoise(M(:,:,:,i), gmean, coeff2, noiseModel);
end

fprintf('Added noise to sensor measurements \n')

end