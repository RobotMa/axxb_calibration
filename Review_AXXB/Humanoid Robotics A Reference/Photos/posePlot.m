function posePlot(x, y, angle, color)

% This function is far from optimal and needs to be shortened in the future
x0 = 500; y0 = 800;
x1 = 500; y1 = 700;
x2 = 600; y2 = 800;
x3 = 450; y3 = 850;

% Pose 1
x11 = x1 - x0; y11 = y1 - y0;
x22 = x2 - x0; y22 = y2 - y0;
x33 = x3 - x0; y33 = y3 - y0;

a1 = rot2(angle)*[x11; y11];
a2 = rot2(angle)*[x22; y22];
a3 = rot2(angle)*[x33; y33];

x11 = a1(1) + x; y11 = a1(2) + y;
x22 = a2(1) + x; y22 = a2(2) + y;
x33 = a3(1) + x; y33 = a3(2) + y;

arrow([x, y],[x11, y11],'EdgeColor',color,'FaceColor',color);
arrow([x, y],[x22, y22],'EdgeColor',color,'FaceColor',color);
arrow([x, y],[x33, y33],'EdgeColor',color,'FaceColor',color);

end