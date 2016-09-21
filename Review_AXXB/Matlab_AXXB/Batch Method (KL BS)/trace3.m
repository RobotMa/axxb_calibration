function [C10, C11, C12]=trace3(na, M1, M2, q, Rx)

C10=trace(so3_vec(Rx'*q)*M1*so3_vec(Rx'*q)*M2);
C11=trace(so3_vec(Rx'*q)*M1*so3_vec(Rx'*na)*M2)+trace(so3_vec(Rx'*na)*M1*so3_vec(Rx'*q)*M2);
C12=trace(so3_vec(Rx'*na)*M1*so3_vec(Rx'*na)*M2);


end