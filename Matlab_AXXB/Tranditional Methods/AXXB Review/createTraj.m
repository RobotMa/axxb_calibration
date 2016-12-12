function [Bi] = createTraj(a, b, c, c1, c2, c3, t1, t2, num, twist)

%twist will be used to give perturbations around the normal axis


%TRAJECTORY
t = (0:2*pi/(num-1):2*pi);

%---Line-----------
% u=(t-pi)/4;
% v=(t-pi)/4;
% du=ones(length(t));
% dv=ones(length(t));
%-------------------

%---Ellipse-----------
% u=sin(t);
% v=cos(t);
% du=cos(t);
% dv=-sin(t);
%-------------------

% ----Figure 8------------
u=cos(t);
v=sin(t).*cos(t);
du=-sin(t);
dv=cos(t).*cos(t)-sin(t).*sin(t);
% -------------------------

% % ----S----------
% u  = cos(c1*t)+t1;
% v  = sin(c2*t).*cos(c3*t)+t2;
% du = -c1*sin(c1*t);
% dv = c2*cos(c2*t).*cos(c3*t)-c3*sin(c2*t).*sin(c3*t);
% % --------------------


traj = [-a*cos(u).*cos(v); -b*cos(u).*sin(v); c*sin(u)];




%construct Bis

Bi = zeros(4,4,num);

for i = 1:size(traj,2)
    
    d1(1:3,i) = [a*sin(u(i))*cos(v(i));  b*sin(u(i))*sin(v(i)); c*cos(u(i))];
    d2(1:3,i) = [a*cos(u(i))*sin(v(i)); -b*cos(u(i))*cos(v(i));           0];
    
    
%     t_traj(1:3,i)=(d1(1:3,i)+d2(1:3,i))/norm(d1(1:3,i)+d2(1:3,i));
    t_traj(1:3,i) = (d1(1:3,i).*du(i)+d2(1:3,i).*dv(i))/norm(d1(1:3,i).*du(i)+d2(1:3,i).*dv(i));
    
    n(1:3,i) = cross(d2(1:3,i),d1(1:3,i))/norm(cross(d2(1:3,i),d1(1:3,i)));
    
    z(1:3,i) = cross(t_traj(1:3,i),n(1:3,i))/norm(cross(t_traj(1:3,i),n(1:3,i)));
    
    
    Rb = [t_traj(1:3,i) n(1:3,i) z(1:3,i)]*[cos(twist(i)) 0 sin(twist(i)); 0 1 0; -sin(twist(i)) 0 cos(twist(i))];
    
    Bi(:,:,i) = [Rb traj(1:3,i); 
                  zeros(1,3) 1];
    
    
end

end
