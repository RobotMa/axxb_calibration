clc 
close all
clear all

%%
addpath('H:/Dropbox/Conference/ASME IDETC 2015/export_fig')
addpath('H:/Dropbox/2014Summer/Robotics Research/rvctools/robot')
addpath('H:/Dropbox/2014Summer/Robotics Research/rvctools/common')

%% Overlapping two images of UR5 for AXXB illustration
A = imread('IMG_6905.JPG');
B = imread('IMG_6906.JPG');

Aim = image(A);
for i = 1:1
    Aim.AlphaData = i*0.1;
    A1 = Aim.CData;
    C = imfuse(A1,B,'blend');
    figure
    imshow(C)
end

C_sub = C(:, 500:5184,:);
figure
imshow(C_sub)

%%
OverlayedUR5 = imread('Overlayed UR5.jpg');
figure
imshow(OverlayedUR5);

hold on
% Base Frame
x0 = 500; y0 = 800; angle0 = 0;
posePlot(x0, y0, angle0, 'k')

% Pose 1
x1 = 1070; y1 = 490; angle1 = pi/3 + pi/12;
posePlot(x1, y1, angle1, 'y')

% Pose 2
x2 = 1290; y2 = 490; angle2 = 2*pi/3 - pi/12;
posePlot(x2, y2, angle2, 'y')

% Object Frame
x3 = 1120; y3 = 880; angle3 = 0;
posePlot(x3, y3, angle3, 'b')

% Sensor 1
x4 = 1110; y4 = 660; angle4 = pi/3 + pi/12;
posePlot(x4, y4, angle4, 'y')

% Sensor 2
x5 = 1250; y5 = 660; angle5 = 2*pi/3 - pi/12;
posePlot(x5, y5, angle5, 'y')

%%
fig = gcf;

print(fig,'-dpng')

%% Attach Calibration Pattern to Atalas Robot Image 
close all
figure
M1 = imread('Atalas_Door.png');
M2 = imread('checkerboard.png');

img = imread('checkerboard.png');
if size(img,3) == 3
   img = rgb2gray(img);
end

x = size(img, 1);
y = size(img, 2);

movingPoints = [  1  1;  x  1;  
                  x  y;  1  y]; %(x,y) coordinate
fixedPoints  = [125 210;  240 215;  240 370;  125 400];

TFORM = fitgeotrans(movingPoints, fixedPoints, 'projective');

R = imref2d(size(img),[1 size(img,2)],[1 size(img,1)]);

imgTransformed = imwarp(imread('checkerboard.png'), R, TFORM, 'OutputView', R, 'FillValues', 255);

imshow(M2)

figure
imshow(imgTransformed,[]);
if size(imgTransformed,3) == 3
   imgTransformed = rgb2gray(imgTransformed);
end

A = ones(size(imgTransformed,1), size(imgTransformed,2));
for i = 1:size(imgTransformed, 1)
    for j = 1:size(imgTransformed, 2)
        if imgTransformed(i,j) == 255
            A(i,j) = 0;
        end
    end
end
            
imwrite(imgTransformed,'pattern.png','Alpha', A)
