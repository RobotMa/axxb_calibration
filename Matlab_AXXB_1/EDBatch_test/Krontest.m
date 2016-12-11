clear;
clc;

%Editable Variables
%------------------------------------------------------

num = 100;	%Number of steps

gmean = [0;0;0;0;0;0];	%Gaussian Noise Mean

nstd = 0;	%Gaussian Noise standard deviation Range

shift = 0; %step shift

model = 1;        %noise model

ElipseParam = [10, 10, 10];

trials = 1;


t2 = (0:(2*pi)/((num+shift)):2*pi);
twist = 0.0*sin(16*t2);
%------------------------------------------------------

x = randn(6,1); X = expm(se3_vec(x));


A = [];
B = [];

trajParam = [.5, .5, .5, 0, 0];
[A1, B1]=AB_genTraj(X, ElipseParam, trajParam, num/2);

trajParam = [.5, .5, .5, 0, 0.5*pi];
[A2, B2]=AB_genTraj(X, ElipseParam, trajParam, num/2);

A = cat(3, A1, A2);
B = cat(3, B1, B2);
A = sensorNoise(A, [0;0;0;0;0;0], 0.0, 1);

X_kron = axb_KronSolve2(A,B);


roterror(X, X_kron)

tranerror(X, X_kron)
