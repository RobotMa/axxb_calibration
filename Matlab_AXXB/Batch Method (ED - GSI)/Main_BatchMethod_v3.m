%AXXB - Fixing Temporal Misalignment

%Required function list:
%AB_gen().m
%noise_Gauss().m
%param_extract().m
%se3_vec().m
%so3_vec().m

clear; clc; close all;


%Editable Variables
%------------------------------------------------------

num = 50;	% Number of steps

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

nstd = 0;	% Gaussian Noise standard deviation Range

shift = 0;  % Step shift

n = 1;      % VP(n)

window = 0; % Target correlation area

model = 5;  % Noise model


t2 = (0:(2*pi)/((num+shift)):2*pi);
twist = 0.0*sin(16*t2);

ElipseParam = [10, 20, 30];

%------------------------------------------------------


x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x)); % Generate a Random X

Roterror_batch = [];
Roterror_kron  = [];
Tranerror_batch = [];
Tranerror_kron  = [];



%% Computation Loops
%---------------------------------------------------------------------------------------------------------

B = [];

Mean = [0;0;0;0;0;0];
Cov = 0.9*eye(6,6);
[A, B] = AB_genRand(X, Mean, Cov, num);

skip = 5;
for j = 1:skip:100
% PA=randperm(size(A,3));
% PB=randperm(size(B,3));

waitbar(j/100)

PA = (1:size(A,3));
PB = (1:size(B,3));

for i = 1:length(PA)

    if rand <= 0.01*j
        index = randi(num,1);
        PA([i index]) = PA([index i]);       
    end
    
end

for i = 1:length(PB)

    if rand <= 0.01*j
        index = randi(num,1);
        PB([i index]) = PB([index i]);       
    end
    
end

A_perm = A(:,:,PA);
B_perm = B(:,:,PB);



[X_batch] = batchSolve(A_perm, B_perm);
[X_kron]  = axb_KronSolve(A_perm, B_perm);


Roterror_batch  = [Roterror_batch  roterror(X_batch,X)];
Roterror_kron   = [Roterror_kron   roterror(X_kron,X)];
Tranerror_batch = [Tranerror_batch tranerror(X_batch,X)];
Tranerror_kron  = [Tranerror_kron  tranerror(X_kron,X)];


end
%----------------------------------------------------------------------------------------------------------------




figure(1)
scatter(0.01*(1:skip:100), Roterror_batch);
hold on
scatter(0.01*(1:skip:100), Roterror_kron);
hold off

figure(2)
scatter(0.01*(1:skip:100), Tranerror_batch);
hold on
scatter(0.01*(1:skip:100), Tranerror_kron);
hold off



