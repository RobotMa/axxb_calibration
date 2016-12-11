% Hand-Eye Calibration Using Uual Quaternions
% paramter computation 
clc

if norm(ans2(1:3,1:3)-X_known(1:3,1:3)) > norm(ans1(1:3,1:3)-X_known(1:3,1:3))
    display('x_cal_1 ')
    vpa(x_cal_1,4)
    
    display('dq1')
    vpa(dq1.s,4)
    vpa(dq1.v,4)
    vpa(dq1.s_d,4)
    vpa(dq1.v_d,4)

else
    ans2
    
    display('x_cal_2')
    vpa(x_cal_2,4)
    
    display('dq2')
    dq2 = Dual_Quaternion(a)
%     vpa(dq2.s,8)
%     vpa(dq2.v,8)
%     vpa(dq2.s_d,8)
%     vpa(dq2.v_d,8)

    q_p = Quaternion([dq2.s_d dq2.v_d]);
    q_bar = Quaternion([dq2.s dq2.v]);
    t = 2*q_p.mtimes(q_bar)

end

% vpa(lam1(1),4)
% vpa(lam1(3),4)