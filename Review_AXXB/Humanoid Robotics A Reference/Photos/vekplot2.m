function [arrowx,arrowy]=vekplot2(x,y,u,v,scale,linetype,mark,fillcolour)
%VEKPLOT2 Create quiver plot
% [arrowx,arrowy]=vekplot2(x,y,u,v,scale) plots 2 dimensional 
% arrows with components (u,v), with length scale*(sqrt(u.^2+u.^2)),
% at points (x,y).
% Returns [arrowx,arrowy] which can be used to make the same
% vector plot using plot(arrowx,arrowy).
%
% vekplot2(x,y,u,v,scale,linetype,mark,fillcolour) plots with linetype 
% 'linetype', markers at the arrows basepoints 'mark' and with
% fillcolour 'fillcolour'.
%
% Example:
%
% x=[1:2]; x=x(ones(1,2),:);
% y=x';
% u=10*rand(2,2);
% v=10*rand(2,2);
%
% vekplot2(x,y,u,v,1);
%
% figure
% vekplot2(x,y,u,v,2,'red-')
%
% figure
% vekplot2(x,y,u,v,2,'green-','d','r')

n=size(x,1)*size(x,2);

x=reshape(x,1,n);
y=reshape(y,1,n);
u=reshape(u,1,n);
v=reshape(v,1,n);

rel_head=0.25; % length of arrow head relative to total length
% *****
min_head=0.0; % minimum length of arrow head

alfa=pi/6; % half opening angle of arrow head

ih=ishold;

x1=x;
x2=x+u*scale;
y1=y;
y2=y+v*scale;
r=sqrt((x2-x1).^2 + (y2-y1).^2);

retcos=[cos(alfa), -sin(alfa) ; sin(alfa), cos(alfa)];

% arrow heads
rel_headlength=max(min_head./(r*scale),rel_head*ones(size(r))); 
lvek1=retcos *[(x1-x2) ; (y1-y2)] .* rel_headlength([1;1],:);
lvek2=retcos'*[(x1-x2) ; (y1-y2)] .* rel_headlength([1;1],:);

% arrows
arrowx=[x1; x2; x2+lvek1(1,:); x2; x2+lvek2(1,:)];
arrowy=[y1; y2; y2+lvek1(2,:); y2; y2+lvek2(2,:)];

if nargin<6 | isempty(linetype)
   plot(arrowx,arrowy,'blue-')
else
   plot(arrowx,arrowy,linetype)
end

if nargin==7 & ~isempty(mark)
   hold on
   plot(x,y,mark)
end

if nargin==8 & ~isempty(fillcolour)
   hold on
   ha=plot(x,y,mark);
   set(ha,'markerFaceColor',fillcolour)
end

if ih
   hold on
else
   hold off
end