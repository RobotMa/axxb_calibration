function F = myfun2sym(x,a,b,K)

%Force K to be symmetric
K = (K+K')/2;


e = hat2(x(1:6)');
ev = vee(e)';

s = x(7:end);
Sigma_n = Vec2SymMat(s);
S = inv2(Sigma_n);

ad = little_adjoint(e,2);


F = zeros(6+21,1);

F(1:6) = (-ev'*S*(eye(size(ad)) -0.5*ad + (1/12)*ad*ad) - b')';

%Define M
for ii = 1 : 6
    for jj = 1 : 6
        ei = zeros(6,1);
        ei(ii) = 1;
        Ei = hat2(ei');
        ej = zeros(6,1);
        ej(jj) = 1;
        Ej = hat2(ej');
        adEi = little_adjoint(Ei,2);
        adEj = little_adjoint(Ej,2);
        
        
        M(ii,jj) = (1/12)*ev'*(adEj'*adEi'*S + S*adEi*adEj)*ev;
        
    end
end

Msym = (M+M')/2; %symmetric version of M

F3 = (eye(size(ad)) -0.5*ad + (1/12)*ad*ad)'*S*(eye(size(ad)) -0.5*ad + (1/12)*ad*ad) + Msym - K;

f3  = SymMat2Vec(F3);

F(7:end) = f3;
%F = norm(F);