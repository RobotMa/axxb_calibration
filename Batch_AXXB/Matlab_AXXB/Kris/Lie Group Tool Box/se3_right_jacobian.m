%SE(3) Right-Jacobian
clear
clc

syms a b g x y z real

R = Rzxz(a,b,g);
q = [a;b;g;x;y;z];

g = [R [x;y;z]; 0 0 0 1];
ginv = [R' -R'*[x;y;z]; 0 0 0 1];

Jr(:,1) = vee(ginv*diff(g,q(1)));
Jr(:,2) = vee(ginv*diff(g,q(2)));
Jr(:,3) = vee(ginv*diff(g,q(3)));
Jr(:,4) = vee(ginv*diff(g,q(4)));
Jr(:,5) = vee(ginv*diff(g,q(5)));
Jr(:,6) = vee(ginv*diff(g,q(6)));
Jr = simplify(Jr);
Jrt = Jr';
Jrti = inv2(Jrt);