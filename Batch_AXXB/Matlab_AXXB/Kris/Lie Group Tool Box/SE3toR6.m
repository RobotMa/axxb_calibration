function [v] = SE3toR6(G)
%[v] = SE3toR6(G)

num = size(G,3);
v = zeros(6,num);
t = squeeze(G(1:3,4,:));

R = G(1:3,1:3,:);
R2 = R;
R2(1,2,:) = R(2,1,:);
R2(2,1,:) = R(1,2,:);
R2(1,3,:) = R(3,1,:);
R2(3,1,:) = R(1,3,:);
R2(2,3,:) = R(3,2,:);
R2(3,2,:) = R(2,3,:);



TR = @(R) squeeze(acos((R(1,1,:) + R(2,2,:) + R(3,3,:) - 1)/2));
scale1 = (1/2)*(TR(R)./sin(TR(R)));

R3 = R - R2;
omega0 = [squeeze(R3(3,2,:)),squeeze(R3(1,3,:)),squeeze(R3(2,1,:))]';

omega = repmat(scale1',[3 1]).*omega0;
Omega = skew(omega');
Omega2(1,1,:) = -Omega(3,1,:).^2 -Omega(2,1,:).^2;
Omega2(2,2,:) = -Omega(3,2,:).^2 -Omega(2,1,:).^2;
Omega2(3,3,:) = -Omega(3,2,:).^2 -Omega(3,1,:).^2;
Omega2(1,3,:) = Omega(3,2,:).*Omega(2,1,:);
Omega2(3,1,:) = Omega2(1,3,:);
Omega2(1,2,:) = Omega(3,2,:).*Omega(1,3,:);
Omega2(2,1,:) = Omega2(1,2,:);
Omega2(3,2,:) = Omega(1,3,:).*Omega(2,1,:);
Omega2(2,3,:) = Omega2(3,2,:);

norm1 = sqrt(omega(1,:).^2 + omega(2,:).^2 + omega(3,:).^2);
scale2 = (1./(norm1).^2) - ((1 + cos(norm1))./(2*norm1.*sin(norm1)));

Omega3 = reshape(Omega2,num,9);
scale3 = repmat(scale2',[1 9]);
Omega4 = scale3.*Omega3;
Omega5 = reshape(Omega4,3,3,num);


Jl = [repmat(eye(3,3),[1 1 num])] - 0.5.*Omega + Omega5;

v(4,:) = squeeze(Jl(1,1,:))'.*t(1,:) + squeeze(Jl(1,2,:))'.*t(2,:) + squeeze(Jl(1,3,:))'.*t(3,:);
v(5,:) = squeeze(Jl(2,1,:))'.*t(1,:) + squeeze(Jl(2,2,:))'.*t(2,:) + squeeze(Jl(2,3,:))'.*t(3,:);
v(6,:) = squeeze(Jl(3,1,:))'.*t(1,:) + squeeze(Jl(3,2,:))'.*t(2,:) + squeeze(Jl(3,3,:))'.*t(3,:);

v(1:3,:) = omega;

