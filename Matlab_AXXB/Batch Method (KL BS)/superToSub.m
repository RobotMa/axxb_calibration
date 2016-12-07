function [ subPoses ] = superToSub( initialPose, supPoses )
%SUPERTOSUB Regenerates subscript poses from initial pose and relative
%superscript poses
%   Detailed explanation goes here

n = size(supPoses,3);
subPoses = zeros(4,4,n+1);
subPoses(:,:,1) = initialPose;

for i = 1:1:n
    subPoses(:,:,i+1) = subPoses(:,:,i)*supPoses(:,:,i);
end

end

