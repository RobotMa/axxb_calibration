function [v] = SymMat2Vec(S)
%[v] = SymMat2Vec(S)


S1 = size(S,1);
S2 = size(S,2);

n = S1*(S1+1)/2; %number of degrees of freedom

v = zeros(n,1);
  
for ii = 1 : S1
    for jj = 1 : S2
        if ii >= jj
            T(ii,jj) = 1;
        else 
            T(ii,jj) = 0;
        end
    end
end

Snew = S.*T;

count = 0;
for ii = 1 : S1
    for jj = 1 : S2
        if Snew(ii,jj) ~= 0
            count = count + 1;
            v(count) = Snew(ii,jj);
        else
        end
    end
end


