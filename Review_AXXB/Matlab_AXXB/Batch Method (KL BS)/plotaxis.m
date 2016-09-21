function []=plotaxis(X, scale, c)

o=X*[0;0;0;1];
a1=X*[scale;0;0;1];
a2=X*[0;scale;0;1];
a3=X*[0;0;scale;1];




plot3([o(1) a1(1)], [o(2) a1(2)], [o(3) a1(3)], c);
hold on
plot3([o(1) a2(1)], [o(2) a2(2)], [o(3) a2(3)], c);
plot3([o(1) a3(1)], [o(2) a3(2)], [o(3) a3(3)], c);

hold off

end