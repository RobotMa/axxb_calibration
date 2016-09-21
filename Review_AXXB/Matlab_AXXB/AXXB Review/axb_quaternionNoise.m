% Quaternion method
% Solve for rotation and translation seperately
% Faugeras & Hebert

function X = axb_quaternionNoise(A, B)

n = size(A,3);
AAi = zeros(4,4,n);

% Generating noisy pairs of As and Bs given the true X
for i = 1:n
    
    AAi(:,:,i) = AB2AA_i( A(:,:,i), B(:,:,i) );
    
end

%% Calculate the sum of matrix AA
AA = zeros(4,4);
for i = 1:n
    
    AA = AA + AAi(:,:,i);
    
end

%%
[V, ~] = eig(AA);

%     % pick the eigenvector of AA associated with its smallest eigenvalue
%     eigSmall = D(1,1);
%     bound = 0.1; % filter the eigenvalues that are non-positive
%                  % due to the numerical accuracy of Matlab
%                  % a positive bound close to 0 is selected
%     counter = 1;
%
%     for i = 1:3
%
%
%         if  D(i,i) < bound
%
%             eigSmall = D(i+1,i+1);
%             counter = i+1;
%
%         elseif eigSmall > D(i+1,i+1)
%
%             eigSmall = D(i+1,i+1);
%             counter = i+1;
%
%         end
%
%         if eigSmall < bound
%             display('AA value not correct')
%         end
%
%     end

% Due to the order that the eigenvalues and eigenvectors of V are
% arranged, the first column of V is the eigenvector corresponding to
% the smallest eigenvalue of AA
v = V(:,1);
q = Quaternion(v);
R_x = R(q);

%% solve for p_x for X
% Using traditional least square method

C = zeros(3*n,3);

for i = 1:n
    C(3*i-2:3*i,:) = eye(3) - A(1:3,1:3,i);
end

d = zeros(3*n,1);
for i = 1:n
    d(3*i-2:3*i,1) = A(1:3,4,i) - R_x*B(1:3,4,i);
end

t_x = (transpose(C)*C)\transpose(C)*d;

X = [R_x t_x;0 0 0 1];
end
