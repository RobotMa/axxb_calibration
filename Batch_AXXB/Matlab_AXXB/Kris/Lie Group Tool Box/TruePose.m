function [g1] = TruePose(a1,v,T,S)

[Twist]=GenerateTwist2(1,[0;0;0;0;0;0],v,T,S);
for ii = 1 : 1
g1 = expm(hat2(Twist(:,ii)));
end
g1(1,4) = g1(1,4) + a1(1,4);
g1(2,4) = g1(2,4) + a1(2,4);
g1(3,4) = g1(3,4) + a1(3,4);