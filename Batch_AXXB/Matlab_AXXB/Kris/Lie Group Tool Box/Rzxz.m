function [R] = Rzxz(a,b,g)
%[R] = Rzxz(a,b,g)

Rza = [cos(a) -sin(a) 0; sin(a) cos(a) 0; 0 0 1];
Rxb = [1 0 0; 0 cos(b) -sin(b); 0 sin(b) cos(b)];
Rzg = [cos(g) -sin(g) 0; sin(g) cos(g) 0; 0 0 1];

R = Rza*Rxb*Rzg;

