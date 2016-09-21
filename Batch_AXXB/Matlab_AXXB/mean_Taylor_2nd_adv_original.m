% This function calculates the 2nd order approximation of the mean of a
% bunch of matrices based on the Taylor expansion of the matrix logarithm
% and the definition of mean of a probability density function.

% Input: X is a cell of 4 by 4*n rigid transformation matrices
% Output: M_T1 is the mean of the 1st order approximation of Taylor
% expansion

% Output: MX is the 2nd order approximation of the Taylor expansion

function MX = mean_Taylor_2nd_adv_original( X, noise, num ) %#codegen

% coder.extrinsic('mean_Taylor_1st_mex');

M_t1 = zeros(4);
M_hat = zeros(4);

n = size(X,2)/4;

for i = 1:n
    M_hat = M_hat + X(:,(i-1)*4+1:i*4);
end

M_t1 = mean_Taylor_1st( X );

% Potential further refinement
% M_t1 = mean_Taylor_1st( M_t1 );

n = size(X,2)/4;

% Perturb M_t1 along each direction defined by the Lie algebra element of
% SE(3)
CA = inf;

CA1 = inf;
CA2 = inf;

%%added later
last_CA = CA;
n_step_change = 0;
precison = 0.000005;

costfun_min = 10^-15;%10^-12;
eps  =  0.001;

E = zeros(4,4,6);
E(:,:,1) = [0  0 0 0; 0 0 -1 0;  0 1 0 0; 0 0 0 0];
E(:,:,2) = [0  0 1 0; 0 0  0 0; -1 0 0 0; 0 0 0 0];
E(:,:,3) = [0 -1 0 0; 1 0  0 0;  0 0 0 0; 0 0 0 0];
E(:,:,4) = [0  0 0 1; 0 0  0 0;  0 0 0 0; 0 0 0 0];
E(:,:,5) = [0  0 0 0; 0 0  0 1;  0 0 0 0; 0 0 0 0];
E(:,:,6) = [0  0 0 0; 0 0  0 0;  0 0 0 1; 0 0 0 0];

MX = M_t1;

count = 0;

if noise == 0
    m = 4;
elseif noise == 1
    m = 1;
else
    m = 0;
end

step = 1; % Change the step lengths if descent direction is not found

% fprintf('---------------------------------------------- \n')
% fprintf('Search gradient descent direction from %f to 6 \n', m)
% fprintf('---------------------------------------------- \n')

    %% added by haiyuan
%      figure;
%      v = VideoWriter('display.avi');
%      open(v);
     
     max_num = 20;
%      array_plot = zeros(1,max_num);
     array_num = 1;
%      lHandle = plot(array_plot,'r*');

    %%

while( abs(CA) > costfun_min )

     count = count + 1;
     n_step = 0;
    % Approximation of rotation is good so far so we only further optimize
    % on translation
    for j = m:6
                
        MX1 = MX*expm( step*eps*E(:,:,j));
        MX2 = MX*expm(-step*eps*E(:,:,j));
        
        MX1sum = zeros(4);
        MX2sum = zeros(4);
        
        for k = 1:n
            X_k = X(:,(k-1)*4+1:k*4);
            MX1sum = MX1sum + X_k/MX1*X_k;
            MX2sum = MX2sum + X_k/MX2*X_k;
        end
        
        MX1cost = 2/n*M_hat - 1/2/n*MX1sum - 3/2*MX1;
        MX2cost = 2/n*M_hat - 1/2/n*MX2sum - 3/2*MX2;
        
        if noise == 0
            CA1 = norm(MX1cost(1:3,4))^2;
            CA2 = norm(MX2cost(1:3,4))^2;
        elseif noise == 1
            CA1 = norm(MX1cost)^2;
            CA2 = norm(MX2cost)^2;
        else
            CA1 = -1;
            CA2 = -1;
        end
        
        
        if CA1 <= CA2 && CA1 < CA
            CA = CA1;
            MX = MX1;
            step = 1;
            % fprintf('Found a descent direction along %d \n', j)
            % disp(MX1cost)
            % disp(CA)
        elseif CA2 < CA1 && CA2 < CA
            CA = CA2;
            MX = MX2;
            step = 1;
            % fprintf('Found a descent direction along -%d \n', j)
            % disp(MX2cost)
            % disp(CA)
        else
            % fprintf('Not a descent direction along +/-%d \n', j)
            n_step = n_step + 1;
            if n_step == 6
               step = step + 1;
               fprintf('test\n');
            end
        end
        
        %% added by haiyuan
        
        
%         if(array_num <= max_num)        
%             
%             array_plot(array_num) = CA;
%             array_num = array_num + 1;
%         else
%             array_plot(1:(max_num - 1)) = array_plot(2:max_num);
%             array_plot(max_num) = CA;
%         end
% 
%        b = sum(abs(array_plot(2:max_num) - array_plot(1:(max_num - 1)))); % differeniating
%        fprintf('%d Error CA is %2.18f with differeniate %2.18f, \n',count, CA,b );
%        if b < 1e-25 
%             step = step/2;
%             fprintf('step is changed into %2.18f, \n',step );
%         end 
       
%        a = get(0,'PointerLocation');
%         if a(1)<100 
%             step = step/2;
%             input('step will be divided by 2. press any key');
%         end 
       % X = get(lHandle, 'XData');
       % Y = get(lHandle, 'YData');
%         set(lHandle, 'YData', array_plot);
%         axis auto
%         drawnow  %updates the display
%         
%         writeVideo(v,getframe);
    
        
        
%         if abs((last_CA - CA)/last_CA) < precison
% 
%         last_CA = CA;
%%
    end
    
        
    if count == num
%         fprintf('Error CA1 is %2.18f \n', CA1 )
%         fprintf('Error CA2 is %2.18f \n', CA2 )
        break;
    end
end
% close(v)
% pause();
% fprintf('Number of iterations is %f \n', count)
% fprintf('Final Error CA1 for this loop is %2.18f \n', CA1 )
% fprintf('Final Error CA2 for this loop is %2.18f \n', CA2 )


end


