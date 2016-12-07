function [ superPoses ] = subToSuper2( subPoses )
%SUBTOSUPER Goes from subscripts to superscripts
%   Detailed explanation goes here

n = size(subPoses,3);
%superPoses = zeros(4,4,(n*n-1)/2);
count = 0;

for i = 1:1:n
    for j =i:1:n
        if (i ~= j)
            count = count + 1;
            superPoses(:,:,count) = subPoses(:,:,i)^-1*subPoses(:,:,j);
        end
    end
end

end

