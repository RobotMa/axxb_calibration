%Test Vectorized Code

% T = 0.5;
% x01 = [0;0;0;0;0;0];
% Parachute3;
clc
tic
for ii = 1 : length(G)    
V1(:,ii) = vee(logm(G(:,:,ii)))';    
end
time1 = toc;
tic
V2 = SE3toR6(G);
time2 = toc;

time1
time2


tic
for ii = 1 : length(G)
Gnew(:,:,ii) = inv(mu)*G(:,:,ii);
end
time1b = toc;
tic
Gnew2 = Mult3D(inv(mu),G);
time2b = toc;

time1b
time2b

sum(sum(sum(Gnew - Gnew2)))

