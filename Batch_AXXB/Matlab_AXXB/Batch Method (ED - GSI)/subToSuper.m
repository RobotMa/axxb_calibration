function [ superPoses ] = subToSuper( subPoses )
%SUBTOSUPER Goes from subscripts to superscripts
%   Detailed explanation goes here

n = size(subPoses,3);
superPoses = zeros(4,4,n-1);

for i = 1:1:n-1
    superPoses(:,:,i) = subPoses(:,:,i)^-1*subPoses(:,:,i+1);
end

end

