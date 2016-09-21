function [M] = ComputeMMatrixSE2(epsilon,Sigma_n)
%[M] = ComputeMMatrixSE2(epsilon,Sigma_n)


e1 = [1 0 0]';
e2 = [0 1 0]';
e3 = [0 0 1]';

E1 = hat(e1');
E2 = hat(e2');
E3 = hat(e3');

adE1 = little_adjoint(E1,1);
adE2 = little_adjoint(E2,1);
adE3 = little_adjoint(E3,1);

I = eye(3,3);

ade = little_adjoint(hat(epsilon'),1);

%Sn = [I - (1/2)*ade + (1/12)*ade*ade]*inv2(Sigma_n)*[I - (1/2)*ade + (1/12)*ade*ade];
Sn = inv2(Sigma_n);

M = zeros(3,3);

ev = epsilon;

%Row 1
M(1,1) = (1/12)*ev'*[2*Sn*adE1*adE1]*ev;
M(1,2) = (1/12)*ev'*[2*Sn*adE1*adE2]*ev;
M(1,3) = (1/12)*ev'*[2*Sn*adE1*adE3]*ev;

%Row 2
M(2,1) = (1/12)*ev'*[2*Sn*adE2*adE1]*ev;
M(2,2) = (1/12)*ev'*[2*Sn*adE2*adE2]*ev;
M(2,3) = (1/12)*ev'*[2*Sn*adE2*adE3]*ev;


%Row 3
M(3,1) = (1/12)*ev'*[2*Sn*adE3*adE1]*ev;
M(3,2) = (1/12)*ev'*[2*Sn*adE3*adE2]*ev;
M(3,3) = (1/12)*ev'*[2*Sn*adE3*adE3]*ev;



