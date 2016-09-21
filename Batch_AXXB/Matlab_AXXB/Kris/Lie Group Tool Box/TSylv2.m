function F = TSylv2(w,R,E)




e = reshape(E,36,1);

W = reshape(w,6,6);

F0 = R*W + W'*R' - E';

F = reshape(F0,36,1);