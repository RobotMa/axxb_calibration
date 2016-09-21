function [R] = RotationMult3D(R1,R2)
%[R] = RotationMult3D(R1,R2)

R(1,1,:) = squeeze(R1(1,1,:)).*squeeze(R2(1,1,:)) + squeeze(R1(1,2,:)).*squeeze(R2(2,1,:)) + squeeze(R1(1,3,:)).*squeeze(R2(3,1,:)); 
R(1,2,:) = squeeze(R1(1,1,:)).*squeeze(R2(1,2,:)) + squeeze(R1(1,2,:)).*squeeze(R2(2,2,:)) + squeeze(R1(1,3,:)).*squeeze(R2(3,2,:)); 
R(1,3,:) = squeeze(R1(1,1,:)).*squeeze(R2(1,3,:)) + squeeze(R1(1,2,:)).*squeeze(R2(2,3,:)) + squeeze(R1(1,3,:)).*squeeze(R2(3,3,:)); 

R(2,1,:) = squeeze(R1(2,1,:)).*squeeze(R2(1,1,:)) + squeeze(R1(2,2,:)).*squeeze(R2(2,1,:)) + squeeze(R1(2,3,:)).*squeeze(R2(3,1,:)); 
R(2,2,:) = squeeze(R1(2,1,:)).*squeeze(R2(1,2,:)) + squeeze(R1(2,2,:)).*squeeze(R2(2,2,:)) + squeeze(R1(2,3,:)).*squeeze(R2(3,2,:));
R(2,3,:) = squeeze(R1(2,1,:)).*squeeze(R2(1,3,:)) + squeeze(R1(2,2,:)).*squeeze(R2(2,3,:)) + squeeze(R1(2,3,:)).*squeeze(R2(3,3,:)); 

R(3,1,:) = squeeze(R1(3,1,:)).*squeeze(R2(1,1,:)) + squeeze(R1(3,2,:)).*squeeze(R2(2,1,:)) + squeeze(R1(3,3,:)).*squeeze(R2(3,1,:)); 
R(3,2,:) = squeeze(R1(3,1,:)).*squeeze(R2(1,2,:)) + squeeze(R1(3,2,:)).*squeeze(R2(2,2,:)) + squeeze(R1(3,3,:)).*squeeze(R2(3,2,:));
R(3,3,:) = squeeze(R1(3,1,:)).*squeeze(R2(1,3,:)) + squeeze(R1(3,2,:)).*squeeze(R2(2,3,:)) + squeeze(R1(3,3,:)).*squeeze(R2(3,3,:));