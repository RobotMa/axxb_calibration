function q = rot2q(R)
r = rot2r(R);
alpha = norm(r) / 2;
axis = r / norm(r);
q = [cos(alpha); sin(alpha) * axis];
