function [G] = R6toSE3(V)

num = size(V,2);
omega = V(1:3,:);
v = V(4:6,:);


G = zeros(4,4,num);
norm1 = sqrt(omega(1,:).^2 + omega(2,:).^2 + omega(3,:).^2); %norm of omega
norm2 = norm1.^2;
norm3 = norm1.^3;

Omega = skew(omega');

%Define Omega^2
Omega2(1,1,:) = -Omega(3,1,:).^2 -Omega(2,1,:).^2;
Omega2(2,2,:) = -Omega(3,2,:).^2 -Omega(2,1,:).^2;
Omega2(3,3,:) = -Omega(3,2,:).^2 -Omega(3,1,:).^2;
Omega2(1,3,:) = Omega(3,2,:).*Omega(2,1,:);
Omega2(3,1,:) = Omega2(1,3,:);
Omega2(1,2,:) = Omega(3,2,:).*Omega(1,3,:);
Omega2(2,1,:) = Omega2(1,2,:);
Omega2(3,2,:) = Omega(1,3,:).*Omega(2,1,:);
Omega2(2,3,:) = Omega2(3,2,:);


I = eye(3,3);
%apply sin(norm(x))/norm(x) to Omega, 
%and (1-cos(norm(x)))/(norm(x)^2) to Omega2
scale1 = sin(norm1)./(norm1);
scale2 = ((1-cos(norm1))./(norm2));


Omega1a = reshape(Omega,num,9);
Omega2a = reshape(Omega2,num,9);

scale1b = repmat(scale1',[1 9]);
scale2b = repmat(scale2',[1 9]);

Omega1b = scale1b.*Omega1a;
Omega2b = scale2b.*Omega2a;

Omega1c = reshape(Omega1b,3,3,num);
Omega2c = reshape(Omega2b,3,3,num);

R = [repmat(eye(3,3),[1 1 num])] + Omega1c + Omega2c;
G(1:3,1:3,:) = R;
G(4,4,:) = ones(1,num);

%Jacobian of SO(3)
scalej1= (1-cos(norm1))./(norm1);
scalej1b = repmat(scalej1',[1 9]);

scalej2= (norm1 - sin(norm1))./(norm3);
scalej2b = repmat(scalej2',[1 9]);

Omega1jb = scalej1b.*Omega1a;
Omega2jb = scalej2b.*Omega2a;

Omega1jc = reshape(Omega1jb,3,3,num);
Omega2jc = reshape(Omega2jb,3,3,num);

Jl = [repmat(eye(3,3),[1 1 num])] + Omega1jc + Omega2jc;

t(1,:) = squeeze(Jl(1,1,:))'.*v(1,:) + squeeze(Jl(1,2,:))'.*v(2,:) + squeeze(Jl(1,3,:))'.*v(3,:);
t(2,:) = squeeze(Jl(2,1,:))'.*v(1,:) + squeeze(Jl(2,2,:))'.*v(2,:) + squeeze(Jl(2,3,:))'.*v(3,:);
t(3,:) = squeeze(Jl(3,1,:))'.*v(1,:) + squeeze(Jl(3,2,:))'.*v(2,:) + squeeze(Jl(3,3,:))'.*v(3,:);


G(1:3,4,:) = t;

