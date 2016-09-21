function F = myfun1(x,e1,e2,Sigma1,Sigma2)


ad1 = little_adjoint(logm(e1),2);
ad2 = little_adjoint(logm(e2),2);

e12 = expm(hat2(x(22:27)));

ad12 = little_adjoint(logm(e12),2);

Sigma12 = Vec2SymMat(x(1:21));



M1 = inv(Sigma1) - inv(Sigma1)*ad1;
M2 = inv(Sigma2) - inv(Sigma2)*ad2;
M12 = inv(Sigma12) - inv(Sigma12)*ad12;

%vectorize M1,M2, and M12 as n*(n+1)/2 dimensional vectors
m1a = SymMat2Vec(M1);
m1b = SymMat2Vec(M1');

m2a = SymMat2Vec(M2);
m2b = SymMat2Vec(M2');

m12a = SymMat2Vec(M12);
m12b = SymMat2Vec(M12');




F1 = inv(Sigma12)*vee(logm(e12))' - inv(Sigma1)*vee(logm(e1))' - inv(Sigma2)*vee(logm(e2))';

F2 = m12a + m12b - m1a - m1b - m2a - m2b;


F = [F1;F2];



