function [M] = ComputeMMatrix(epsilon,Sigma_n)
%[M] = ComputeMMatrix(epsilon,Sigma_n)


e1 = [1 0 0 0 0 0]';
e2 = [0 1 0 0 0 0]';
e3 = [0 0 1 0 0 0]';
e4 = [0 0 0 1 0 0]';
e5 = [0 0 0 0 1 0]';
e6 = [0 0 0 0 0 1]';

E1 = hat2(e1');
E2 = hat2(e2');
E3 = hat2(e3');
E4 = hat2(e4');
E5 = hat2(e5');
E6 = hat2(e6');

adE1 = little_adjoint(E1,2);
adE2 = little_adjoint(E2,2);
adE3 = little_adjoint(E3,2);
adE4 = little_adjoint(E4,2);
adE5 = little_adjoint(E5,2);
adE6 = little_adjoint(E6,2);

I = eye(6,6);

ade = little_adjoint(hat2(epsilon'),2);

% %??????????????????
% Sn = [I - (1/2)*ade + (1/12)*ade*ade]*inv2(Sigma_n)*[I - (1/2)*ade + (1/12)*ade*ade];
% %????????????????????
Sn = inv2(Sigma_n);
M = zeros(6,6);

ev = epsilon;

%Row 1
M(1,1) = (1/12)*ev'*[adE1'*adE1'*Sn' + Sn*adE1*adE1]*ev;
M(1,2) = (1/12)*ev'*[adE2'*adE1'*Sn' + Sn*adE1*adE2]*ev;
M(1,3) = (1/12)*ev'*[adE3'*adE1'*Sn' + Sn*adE1*adE3]*ev;
M(1,4) = (1/12)*ev'*[adE4'*adE1'*Sn' + Sn*adE1*adE4]*ev;
M(1,5) = (1/12)*ev'*[adE5'*adE1'*Sn' + Sn*adE1*adE5]*ev;
M(1,6) = (1/12)*ev'*[adE6'*adE1'*Sn' + Sn*adE1*adE6]*ev;

%Row 2
M(2,1) = (1/12)*ev'*[adE1'*adE2'*Sn' + Sn*adE2*adE1]*ev;
M(2,2) = (1/12)*ev'*[adE2'*adE2'*Sn' + Sn*adE2*adE2]*ev;
M(2,3) = (1/12)*ev'*[adE3'*adE2'*Sn' + Sn*adE2*adE3]*ev;
M(2,4) = (1/12)*ev'*[adE4'*adE2'*Sn' + Sn*adE2*adE4]*ev;
M(2,5) = (1/12)*ev'*[adE5'*adE2'*Sn' + Sn*adE2*adE5]*ev;
M(2,6) = (1/12)*ev'*[adE6'*adE2'*Sn' + Sn*adE2*adE6]*ev;




%Row 3
M(3,1) = (1/12)*ev'*[adE1'*adE3'*Sn' + Sn*adE3*adE1]*ev;
M(3,2) = (1/12)*ev'*[adE2'*adE3'*Sn' + Sn*adE3*adE2]*ev;
M(3,3) = (1/12)*ev'*[adE3'*adE3'*Sn' + Sn*adE3*adE3]*ev;
M(3,4) = (1/12)*ev'*[adE4'*adE3'*Sn' + Sn*adE3*adE4]*ev;
M(3,5) = (1/12)*ev'*[adE5'*adE3'*Sn' + Sn*adE3*adE5]*ev;
M(3,6) = (1/12)*ev'*[adE6'*adE3'*Sn' + Sn*adE3*adE6]*ev;

%Row 4
M(4,1) = (1/12)*ev'*[adE1'*adE4'*Sn' + Sn*adE4*adE1]*ev;
M(4,2) = (1/12)*ev'*[adE2'*adE4'*Sn' + Sn*adE4*adE2]*ev;
M(4,3) = (1/12)*ev'*[adE3'*adE4'*Sn' + Sn*adE4*adE3]*ev;
M(4,4) = (1/12)*ev'*[adE4'*adE4'*Sn' + Sn*adE4*adE4]*ev;
M(4,5) = (1/12)*ev'*[adE5'*adE4'*Sn' + Sn*adE4*adE5]*ev;
M(4,6) = (1/12)*ev'*[adE6'*adE4'*Sn' + Sn*adE4*adE6]*ev;

%Row 5
M(5,1) = (1/12)*ev'*[adE1'*adE5'*Sn' + Sn*adE5*adE1]*ev;
M(5,2) = (1/12)*ev'*[adE2'*adE5'*Sn' + Sn*adE5*adE2]*ev;
M(5,3) = (1/12)*ev'*[adE3'*adE5'*Sn' + Sn*adE5*adE3]*ev;
M(5,4) = (1/12)*ev'*[adE4'*adE5'*Sn' + Sn*adE5*adE4]*ev;
M(5,5) = (1/12)*ev'*[adE5'*adE5'*Sn' + Sn*adE5*adE5]*ev;
M(5,6) = (1/12)*ev'*[adE6'*adE5'*Sn' + Sn*adE5*adE6]*ev;

%Row 6
M(6,1) = (1/12)*ev'*[adE1'*adE6'*Sn' + Sn*adE6*adE1]*ev;
M(6,2) = (1/12)*ev'*[adE2'*adE6'*Sn' + Sn*adE6*adE2]*ev;
M(6,3) = (1/12)*ev'*[adE3'*adE6'*Sn' + Sn*adE6*adE3]*ev;
M(6,4) = (1/12)*ev'*[adE4'*adE6'*Sn' + Sn*adE6*adE4]*ev;
M(6,5) = (1/12)*ev'*[adE5'*adE6'*Sn' + Sn*adE6*adE5]*ev;
M(6,6) = (1/12)*ev'*[adE6'*adE6'*Sn' + Sn*adE6*adE6]*ev;


