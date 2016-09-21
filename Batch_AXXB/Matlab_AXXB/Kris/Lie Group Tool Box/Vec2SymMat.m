function [S] = Vec2SymMat(v)
%[S] = Vec2SymMat(v)


n = length(v);

r = roots([1 1 -2*n]);
m = max(r);
S = zeros(m,m);

count = 0;
for ii = 1 : m
    for jj = 1 : m
        if ii >= jj
            count = count + 1;
            S(ii,jj) = v(count);
        else
        end
    end
end

%fill in zeros
for ii = 1 : m
    for jj = 1 : m
        if S(ii,jj) == 0;
            S(ii,jj) = S(jj,ii);
        else
        end
    end
end

