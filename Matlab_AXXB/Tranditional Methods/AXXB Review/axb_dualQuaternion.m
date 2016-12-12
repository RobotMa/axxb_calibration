% Dual Quaternion Method

function X = axb_dualQuaternion(A,B)

X = [eye(3) zeros(3,1); 0 0 0 1];

n = size(A,3);
T = zeros(6*n,8);

bound = 0.15; % filter the pairs of dual quaternions that don't have the
             % same scalar part
counter = 0;

if n ~= size(B,3)
    
    disp('Numbers of As and Bs not equal');
    
else
    
    for i = 1:n
        a = Dual_Quaternion(A(:,:,i));
        b = Dual_Quaternion(B(:,:,i));
        if ((a.s + a.s_d) - (b.s + b.s_d)) > bound
            diff = (a.s + a.s_d) - (b.s + b.s_d);
            disp(['Diference of scalar part of dual-quat a and b are greater than ', num2str(diff)])
        else
            counter = counter +1;
            T(1+6*(i - 1):6*i, 1:8) = DQ2S(a, b);
        end
    end
    
    [~, ~, V] = svd(T);
    
    v7 = V(:,7);        v8 = V(:,8);
    
    u1 = v7(1:4);       v1 = v7(5:8);
    u2 = v8(1:4);       v2 = v8(5:8);
    s11 = u1.'*u1;      s12 = 2*u1.'*u2;          s13 = u2.'*u2;
    s21 = u1.'*v1;      s22 = u1.'*v2 + u2.'*v1;  s23 = u2.'*v2;
    
    syms lamda1 lamda2
    [lam1, lam2] = solve( s11*lamda1^2 + s12*lamda1*lamda2 + s13*lamda2^2 == 1,...
        s21*lamda1^2 + s22*lamda1*lamda2 + s23*lamda2^2 == 0, ...
        lamda1, lamda2);
    
    lam1 = double(lam1);
    lam2 = double(lam2);
    lam_abs = abs(lam1 + lam2);
    [~,I] = min(lam_abs);
    
    x_cal = lam1(I)*v7 + lam2(I)*v8;
    dq = Dual_Quaternion(x_cal);
    X = DQ2T(dq);
    
end

end