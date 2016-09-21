function [ M, Sig ] = distibutionProps( X, aug )


Xsum = zeros(4);

% 1. Use X to calculate the mean of se(3) Lie algebra
% 2. Exponentiate the mean of se(3) into Lie group SE(3) 
for j = 1:size(X,3)
    Xsum = Xsum + twistlog(X(:,:,j));
end

M = expm( (1/size(X,3))*Xsum );

m = 1;

%% Augmented Using 2nd Taylor Approximation 
if aug == 1
n_search = int16(10^2);
[a1,a2,a3]  = size(X);
X_mex = reshape(X, a1, a2*a3);

Mean = mean_Taylor_2nd_mex( X_mex, 0, n_search );
M(1:3,1:3) = Mean(1:3,1:3);

m = 4; % Only optimize on translation
end

%%
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
    
    for j = m:6
        
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
        for k = 1:size(X,3)
            M1sum = M1sum + logm( M1^-1*X(:,:,k) );
            M2sum = M2sum + logm( M2^-1*X(:,:,k) );
            
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

for i = 1:size(X,3)
    
    Sig = Sig+se3_vec(logm(M^(-1)*X(:,:,i)))*se3_vec(logm(M^(-1)*X(:,:,i)))';
    
end

Sig = Sig*(1/size(X,3));

end