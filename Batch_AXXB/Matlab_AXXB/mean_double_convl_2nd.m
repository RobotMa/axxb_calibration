% This fucntion calculate the 2nd order approximation of the mean of the
% convolution of two probability density functions on SE(3).

% Input: X, B and X_inv
% Future Work: To be determined which is the better M12

function M123_f = mean_double_convl_2nd(X1, X2, X3, s1, s2, s3, n_search, diff)

n1 = size(X1,2)/4;
n2 = size(X2,2)/4;
n3 = size(X2,2)/4;

if n1 ~= n2 || n1 ~= n2
    fprintf('Sizes of X1, X2 and X3 do not match.')
else
end

n = n1;

M1 = mean_Taylor_2nd( X1, s1, n_search );

M2 = mean_Taylor_2nd( X2, s2, n_search );

M3 = mean_Taylor_2nd( X3, s3, n_search );

% This initial guess is not good
% M123 = M1*M2*M3; % Initial guess of M12

% Another possible way to calculate M123
M123 = M1*M2/M1;

M123_f = M123; % Final M12
% Perturb M_t1 along each direction defined by the Lie algebra element of
% SE(3)
CA = inf;

E = zeros(4,4,6);
E(:,:,1) = [0  0 0 0; 0 0 -1 0;  0 1 0 0; 0 0 0 0];
E(:,:,2) = [0  0 1 0; 0 0  0 0; -1 0 0 0; 0 0 0 0];
E(:,:,3) = [0 -1 0 0; 1 0  0 0;  0 0 0 0; 0 0 0 0];
E(:,:,4) = [0  0 0 1; 0 0  0 0;  0 0 0 0; 0 0 0 0];
E(:,:,5) = [0  0 0 0; 0 0  0 1;  0 0 0 0; 0 0 0 0];
E(:,:,6) = [0  0 0 0; 0 0  0 0;  0 0 0 1; 0 0 0 0];


% diff = 10^-12;
eps  =  0.001;
step = 1;
count = 0;
n_step = 0;

if s1 == 0
    m = 4;
elseif s1 == 1
    m = 1;
else
    m = 0;
end

CA1 = 0;
CA2 = 0;

while( abs(CA) > diff )
    
    count = count + 1;
    
    % Adjust the step length
    if abs(CA) > 100
        eps = 1;
    elseif abs(CA) > 1 && abs(CA) < 100
        eps = 0.1;
    elseif abs(CA) > 0.01 && abs(CA) < 1
        eps = 0.001;
    elseif abs(CA) < 0.01
        eps = 0.0001;
    elseif abs(CA) < 10^-8
        eps = 0.00001;
    else
        eps = 0.001;
    end
    
    
    for j = m:6
        
        % disp(step)
        
        M123_r = M123_f*expm( step*eps*E(:,:,j));
        M123_l = M123_f*expm(-step*eps*E(:,:,j));
        
        M123_r_sum = zeros(4);
        M123_l_sum = zeros(4);
        
        for i = 1:n1
            for k = 1:n2
                for l = 1:n3
                    X1_i = X1(:,(i-1)*4 + 1:i*4);
                    X2_k = X2(:,(k-1)*4 + 1:k*4);
                    X3_j = X2(:,(l-1)*4 + 1:l*4);
                    M123_r_sum = M123_r_sum + X1_i*X2_k*X3_j/M123_r*X1_i*X2_k*X3_j;
                    M123_l_sum = M123_l_sum + X1_i*X2_k*X3_j/M123_l*X1_i*X2_k*X3_j;
                end
            end
        end
        
        M123_r_cost = M123 - 1/4/n^2*M123_r_sum - 3/4*M123_r;
        M123_l_cost = M123 - 1/4/n^2*M123_l_sum - 3/4*M123_l;
        
        if m == 4
            CA1 = norm(M123_r_cost(1:3,4))^2;
            CA2 = norm(M123_l_cost(1:3,4))^2;
        elseif m == 1
            CA1 = norm(M123_r_cost)^2;
            CA2 = norm(M123_l_cost)^2;
        else
            CA1 = -1;
            CA2 = -1;
        end
        
        if CA1 <= CA2 && CA1 < CA
            CA = CA1;
            M123_f = M123_r;
            step = 1;
            % fprintf('Found a descent direction along %d \n', j)
            % disp(MX1cost)
            % disp(CA)
        elseif CA2 < CA1 && CA2 < CA
            CA = CA2;
            M123_f = M123_l;
            step = 1;
            % fprintf('Found a descent direction along -%d \n', j)
            % disp(MX2cost)
            % disp(CA)
        else
            % fprintf('Not a descent direction along +/-%d \n', j)
            if CA > 10
                step = 1;
            else
                n_step = n_step + 1;
                if n_step == (6 - m +1 )
                    n_step = 0;
                    step = step + 1;
                end
            end
        end
        
    end
    
    fprintf('Value of the cost function is %f, %f and %f \n', CA1, CA2, CA);
    % fprintf('Value of the cost function is %f \n', CA2);
    % fprintf('Value of the cost function is %f \n', CA);
    
    if step == 20
        break;
    end
    
end



end