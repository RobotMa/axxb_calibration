%Function to extract Plucker parameters from a g \in SE(3)

%files needed:
%so3_vec().m

function [theta, N, d, p]=param_extract(X)

%extract theta---------------------------------
theta=acos((trace(X(1:3,1:3))-1)/2);
%----------------------------------------------

%extract N---------------------------------
N=(X(1:3,1:3)-X(1:3,1:3)')/(2*sin(theta));
%----------------------------------------------

%extract d---------------------------------
d=dot(X(1:3,4),so3_vec(N));
%----------------------------------------------

%extract p---------------------------------
n=so3_vec(N);
u=1/sqrt(n(1)^2+n(2)^2)*[-n(2); n(1); 0];
c=linsolve([1-cos(theta) sin(theta); -sin(theta) 1-cos(theta)], [dot(X(1:3,4),u); dot(X(1:3,4),(cross(n,u)))]);

p=c(1)*u+c(2)*cross(n,u);
%----------------------------------------------

end