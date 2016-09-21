function [Jrti] = load_Jrti_se3(state)
a = state(1);
b = state(2);
g = state(3);
x = state(4);
y = state(5);
z = state(6);

Jrti(1,:) = [ sin(g)/(sin(b)*(cos(g)^2 + sin(g)^2)), cos(g)/(cos(g)^2 + sin(g)^2), -(cos(b)*sin(g))/(sin(b)*(cos(g)^2 + sin(g)^2)), 0, 0, 0];
Jrti(2,:) = [ cos(g)/(sin(b)*(cos(g)^2 + sin(g)^2)), -sin(g)/(cos(g)^2 + sin(g)^2), -(cos(b)*cos(g))/(sin(b)*(cos(g)^2 + sin(g)^2)), 0, 0, 0];
Jrti(3,:) = [ 0, 0, 1, 0, 0, 0];
Jrti(4,:) = [ 0, 0, 0, (cos(a)*cos(b)^2*cos(g) + cos(a)*cos(g)*sin(b)^2 - cos(b)*sin(a)*sin(g))/((cos(a)^2 + sin(a)^2)*(cos(b)^2 + sin(b)^2)*(cos(g)^2 + sin(g)^2)), (cos(g)*sin(a)*cos(b)^2 + cos(a)*sin(g)*cos(b) + cos(g)*sin(a)*sin(b)^2)/((cos(b)^2 + sin(b)^2)*(cos(a)^2*cos(g)^2 + cos(a)^2*sin(g)^2 + cos(g)^2*sin(a)^2 + sin(a)^2*sin(g)^2)), (sin(b)*sin(g))/((cos(b)^2 + sin(b)^2)*(cos(g)^2 + sin(g)^2))];
Jrti(5,:) = [ 0, 0, 0, -(cos(a)*sin(g)*cos(b)^2 + cos(g)*sin(a)*cos(b) + cos(a)*sin(g)*sin(b)^2)/((cos(a)^2 + sin(a)^2)*(cos(b)^2 + sin(b)^2)*(cos(g)^2 + sin(g)^2)), -(cos(b)^2*sin(a)*sin(g) + sin(a)*sin(b)^2*sin(g) - cos(a)*cos(b)*cos(g))/((cos(b)^2 + sin(b)^2)*(cos(a)^2*cos(g)^2 + cos(a)^2*sin(g)^2 + cos(g)^2*sin(a)^2 + sin(a)^2*sin(g)^2)), (cos(g)*sin(b))/((cos(b)^2 + sin(b)^2)*(cos(g)^2 + sin(g)^2))];
Jrti(6,:) = [ 0, 0, 0, (sin(a)*sin(b))/((cos(a)^2 + sin(a)^2)*(cos(b)^2 + sin(b)^2)), -(cos(a)*sin(b))/((cos(a)^2 + sin(a)^2)*(cos(b)^2 + sin(b)^2)), cos(b)/(cos(b)^2 + sin(b)^2)];
