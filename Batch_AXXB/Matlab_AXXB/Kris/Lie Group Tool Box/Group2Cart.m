function [CC] = Group2Cart(g)
CC = zeros(6,1);
CC(1) = g(1,4);
CC(2) = g(2,4);
CC(3) = g(3,4);

R1 = g(1:3,1:3);
%decompose R1 via roll pitch and yaw

yaw = atan2(R1(2,1),R1(1,1));
pitch = atan2(-R1(3,1),sqrt(R1(3,2)^2+R1(3,3)^2));
roll = atan2(R1(3,2),R1(3,3));
CC(4) = roll;
CC(5) = pitch;
CC(6) = yaw;
