% This fucntion calculate the 2nd order approximation of the mean of the
% convolution of two probability density functions on SE(3).

% Input: X1 and X2 denote the data streams

function M12_f = mean_convl_2nd(X1, X2, s1, s2, n_search)

n1 = size(X1,2)/4;
n2 = size(X2,2)/4;

if n1 ~= n2
    fprintf('Sizes of X1 and X2 do not match.')
else
end

n = n1;

M1 = mean_Taylor_2nd( X1, s1, n_search );

M2 = mean_Taylor_2nd( X2, s2, n_search );

M12 = M1*M2; % Initial guess of M12

M12_f = M12; % Final M12
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


diff = 10^-12;
eps  = 0.001;
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

while( abs(CA) > diff )
    
    count = count + 1;
    
    % Adjust the step length
    if abs(CA) > 0.001
        eps = 0.05;
    elseif abs(CA) < 10^-6
        eps = 0.0001;
    elseif abs(CA) < 10^-8
        eps = 0.00001;
    elseif abs(CA) < 10^-9
        eps = 0.000001;
    else
        eps = 0.001;
    end
    
    % Approximation of rotation is good so far so we only further optimize
    % on translation
    for j = m:6
        
        % disp(step)
        
        M12_r = M12_f*expm( step*eps*E(:,:,j));
        M12_l = M12_f*expm(-step*eps*E(:,:,j));
        
        M12_r_sum = zeros(4);
        M12_l_sum = zeros(4);
        
        for i = 1:n1
            for k = 1:n2
                X1_i = X1(:,(i-1)*4 + 1:i*4);
                X2_k = X2(:,(k-1)*4 + 1:k*4);
                M12_r_sum = M12_r_sum + X1_i*X2_k/M12_r*X1_i*X2_k;
                M12_l_sum = M12_l_sum + X1_i*X2_k/M12_l*X1_i*X2_k;
            end
        end
        
        M12_r_cost = M12 - 1/4/n^2*M12_r_sum - 3/4*M12_r;
        M12_l_cost = M12 - 1/4/n^2*M12_l_sum - 3/4*M12_l;
        
        if m == 4
            CA1 = norm(M12_r_cost(1:3,4))^2;
            CA2 = norm(M12_l_cost(1:3,4))^2;
        elseif m == 1
            CA1 = norm(M12_r_cost)^2;
            CA2 = norm(M12_l_cost)^2;
        else
            CA1 = -1;
            CA2 = -1;
        end
        
        if CA1 <= CA2 && CA1 < CA
            CA = CA1;
            M12_f = M12_r;
            step = 1;
            % fprintf('Found a descent direction along %d \n', j)
            % disp(MX1cost)
            % disp(CA)
        elseif CA2 < CA1 && CA2 < CA
            CA = CA2;
            M12_f = M12_l;
            step = 1;
            % fprintf('Found a descent direction along -%d \n', j)
            % disp(MX2cost)
            % disp(CA)
        else
            % fprintf('Not a descent direction along +/-%d \n', j)
            n_step = n_step + 1;
            if n_step == (6 - m +1 )
                n_step = 0;
                step = step + 1;
            end
        end
        
        fprintf('Value of cost function is %f \n',  CA)
        
    end
    
    if step == n_search
    fprintf('Value of cost function is %f \n',  CA)
        break;
    end
    
    
end



end
