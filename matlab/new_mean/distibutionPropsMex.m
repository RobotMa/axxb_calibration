function [ M, Sig ] = distibutionPropsMex( X ) %#codegen

% Note: the Matlab bulit-in function logm() is not convertable
% into a standalone for c/c++ code generation. Another SE3 to twist matrix
% logarithm is used instead.

% File Dependency
% addpath ../../../kinematics/kinematics/screws

%%
Xsum = zeros(4);

coder.extrinsic('logm');

n = size(X,2)/4; % Number of matrices

X_logm = zeros(4);

% 1. Use X to calculate the mean of se(3) Lie algebra
% 2. Exponentiate the mean of se(3) into Lie group SE(3)
for j = 1:n
    j1 = (j-1)*4+1;
    j2 = j*4;
    
    X_logm = twistlog(X(:,j1:j2));
    Xsum = Xsum + X_logm;
end

M = expm( (1/n)*Xsum );

C_old = inf; C = 0;

diff = 0.05; eps = 0.001;

E = zeros(4,4,6);
% The six Lie algebra elements for SE(3)
E(:,:,1) = [0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0];
E(:,:,2) = [0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0];
E(:,:,3) = [0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
E(:,:,4) = [0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0];
E(:,:,5) = [0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0];
E(:,:,6) = [0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];

count = 0;
while( abs(C-C_old) > diff && count < 10 )
    
    C_old = C;
    
    for j = 1:6
        
        if C_old > 20
            M1 = M*expm(eps*20*E(:,:,j));
            M2 = M*expm(-eps*20*E(:,:,j));
        elseif C_old > 1
            M1 = M*expm(eps*C_old*E(:,:,j));
            M2 = M*expm(-eps*C_old*E(:,:,j));
            
        else
            M1 = M*expm(eps*E(:,:,j));
            M2 = M*expm(-eps*E(:,:,j));
            
        end
        
        
        M1sum = zeros(4);
        M2sum = zeros(4);
        
        M1X_logm = zeros(4);
        M2X_logm = zeros(4);
        
        for k = 1:size(X,2)/4
            k1 = (k-1)*4+1;
            k2 = k*4;
            
            M1X_logm = twistlog( M1^-1*X(:,k1:k2) );
            M2X_logm = twistlog( M2^-1*X(:,k1:k2) );
            
            M1sum = M1sum + M1X_logm;
            M2sum = M2sum + M2X_logm;
            
        end
        
        
        C1 = norm(M1sum)^2;
        C2 = norm(M2sum)^2;
        
        if (C1 <= C2)
            C = C1;
            M = M1;
        else
            C = C2;
            M = M2;
        end
        
    end
    
    count = count+1;
    
end

Sig = zeros(6,6);

for i = 1:size(X,2)/4
    
    i1 = (i-1)*4+1;
    i2 = i*4;
    Sig = Sig+se3_vec(twistlog(M^(-1)*X(:,i1:i2)))*se3_vec(twistlog(M^(-1)*X(:,i1:i2)))';
    
end

Sig = Sig*(1/size(X,2)/4);

end