function [C10, C11]=trace1(na, M, q, Rx)

C10=trace(so3_vec(Rx'*q)*M);
C11=trace(so3_vec(Rx'*na)*M);


end