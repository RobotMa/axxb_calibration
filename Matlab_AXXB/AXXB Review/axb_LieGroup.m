% Robot Sensor Calibration: Solving AX = XB on the Euclidean Group

function X = axb_LieGroup( A, B )


n = size(A,3);
M = zeros(3,3);
counter = 0;
index = 0;
if n < 3
    display(' At least three pairs of As and Bs are needed ')
else
    ai_n = zeros(3,n);
    bi_n = zeros(3,n);
    p_ai_n = zeros(3,n);
    p_bi_n = zeros(3,n);
    
    for i = 1:n
        trA = trace(A(1:3,1:3,i));
        trB = trace(B(1:3,1:3,i));
        if trA < - 0.9999 && trA > - 1.0001
            display('ill conditioned A for Lie Group, and the trace of A is ', num2str(trA))
            counter = counter + 1;
        elseif trB < - 0.9999 && trB > - 1.0001
            display('ill conditioned B for Lie Group, and trace of B is ', num2str(trB))
            counter = counter + 1;
%         else
%             index = index + 1;
%             
%             ai_n(:,index) = LOGARITHM(A(1:3,1:3,i));
%             bi_n(:,index) = LOGARITHM(B(1:3,1:3,i));
%             p_ai_n(:,index) = A(1:3,4,i);
%             p_bi_n(:,index) = B(1:3,4,i);
            
        end
                ai_n(:,i) = LOGARITHM(A(1:3,1:3,i));
                bi_n(:,i) = LOGARITHM(B(1:3,1:3,i));
                p_ai_n(:,i) = A(1:3,4,i);
                p_bi_n(:,i) = B(1:3,4,i);
    end
    
    % least square estimation
    
%     n = index;
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % added on 12/10/2013
    %         ai_k = ai_n(:,1:k);
    %         bi_k = bi_n(:,1:k);
    
    ai_bar = sum(ai_n,2)/n;
    bi_bar = sum(bi_n,2)/n;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %     for j = 1:n
    %         ai_n(:,j) = ai_n(:,j) - ai_bar;
    %         bi_n(:,j) = bi_n(:,j) - bi_bar;
    %         M = M + bi_n*ai_n.';
    %     end
    
    P = ai_n(:,1:n) - ai_bar*ones(1,n);
    Q = bi_n(:,1:n) - bi_bar*ones(1,n);
    
    M = P*Q';
    
    if n == 3
        
        Ai_n1 = expm(ai_n(1:3,1));
        Ai_n2 = expm(ai_n(1:3,2));
        Ai_n3 = expm(ai_n(1:3,3));
        THETA_hat = M*(transpose(M)*M)^(-1/2);
        C(1:9,1:3) = [eye(3) - Ai_n1; eye(3) - Ai_n2; eye(3) - Ai_n3];
        d(1:9,1) = [p_ai_n(1:3,1) - THETA_hat*p_bi_n(1:3,1);
            p_ai_n(1:3,2) - THETA_hat*p_bi_n(1:3,2);
            p_ai_n(1:3,3) - THETA_hat*p_bi_n(1:3,3)];
        
    else
        
        THETA_hat = M*(transpose(M)*M)^(-1/2);
        
        if 0.99 < det(THETA_hat) && det(THETA_hat) < 1.01
            display('Rotation part valid')
        elseif -0.99 > det(THETA_hat) && det(THETA_hat) > - 1.01
            display('Det of Rotation is negative')
            det(THETA_hat)
        end
        
        for k = 1:n
            
            Ai_n = expm(ai_n(1:3,k));
            
            num1 = 3*k - 2;
            num2 = 3*k;
            
            C(num1:num2,1:3) = eye(3) - Ai_n;
            d(num1:num2,1) = p_ai_n(1:3,k) - THETA_hat*p_bi_n(1:3,k);
        end
        
    end
    
    b_hat = (transpose(C)*C)\transpose(C)*d;
    X = [THETA_hat b_hat; 0 0 0 1];
    
end






