% First written by M. Kendal Ackerman
% Edited by Qianli Ma

function [Bi]= createTraj(a, b, c, num, twist)

% function [Bi]= e_trajComplex2(a, b, c, num, twist)

% twist will be used to give perturbations around the normal axis


% TRAJECTORY
t = ( 0: 2*pi/(num - 1) : 2*pi );

opt_visual = 0;

method  = 'S';

switch method
    
    % u and v specify the x and y coordinates of the trajectory
    % du and dv are used for ploting the coodinate frame at each waypoint
    
    case 'Line'
        
        % ---Line------------
        u  = (t-pi)/4;
        v  = (t-pi)/4;
        du = ones( length(t) );
        dv = ones( length(t) );
        % -------------------
        
    case 'Ellipse'
        
        % ---Ellipse---------
        u  = sin(t);
        v  = cos(t);
        du = cos(t);
        dv = -sin(t);
        % -------------------
        
    case 'Figure 8'
        
        % ----Figure 8------------
        u  = cos(t);
        v  = sin(t).*cos(t);
        du = -sin(t);
        dv = cos(t).*cos(t)-sin(t).*sin(t);
        % -------------------------
        
    case 'S'
        
        % ----S----------
        c1 = 0.4;
        c2 = 0.5;
        c3 = 0.5;
        
        u  = cos(c1*t);
        v  = sin(c2*t).*cos(c3*t);
        du = -c1*sin(c1*t);
        dv = c2*cos(c2*t).*cos(c3*t)-c3*sin(c2*t).*sin(c3*t);
        % ---------------
end

traj = [ -a*cos(u).*cos(v); -b*cos(u).*sin(v); c*sin(u)];

if opt_visual == 1
    
    figure
    plot3(traj(1,:), traj(2,:), traj(3,:))
    hold on
    
end


% Construct Bi's

Bi = zeros(4,4,num);

for i = 1:size(traj,2)
    
    d1(1:3,i) = [ a*sin(u(i))*cos(v(i));  b*sin(u(i))*sin(v(i));   c*cos(u(i))];
    d2(1:3,i) = [ a*cos(u(i))*sin(v(i));  -b*cos(u(i))*cos(v(i));  0];
    
    
    %     t_traj(1:3,i)=(d1(1:3,i)+d2(1:3,i))/norm(d1(1:3,i)+d2(1:3,i));
    t_traj(1:3,i) = ( d1(1:3,i).*du(i)+d2(1:3,i).*dv(i))/norm(d1(1:3,i).*du(i)+d2(1:3,i).*dv(i));
    
    n(1:3,i) = cross( d2(1:3,i),d1(1:3,i)) / norm(cross(d2(1:3,i),d1(1:3,i)) );
    
    z(1:3,i) = cross( t_traj(1:3,i),n(1:3,i)) / norm(cross(t_traj(1:3,i),n(1:3,i)) );
    
    
    Rb = [t_traj(1:3,i) n(1:3,i) z(1:3,i)]*[cos(twist(i))    0   sin(twist(i));
        0    1               0;
        -sin(twist(i))   0   cos(twist(i))];
    
    if opt_visual == 1
        
        plot3([t_traj(1,i),traj(1,i)], [t_traj(2,i),traj(2,i)],[t_traj(3,i),traj(3,i)], 'r')
        hold on
        
        plot3([n(1,i),traj(1,i)], [n(2,i),traj(2,i)], [n(3,i),traj(3,i)], 'b')
        hold on
        
        plot3([z(1,i),traj(1,i)], [z(2,i),traj(2,i)], [z(3,i),traj(3,i)], 'g')
        hold on
    end
    
    Bi(:,:,i) = [Rb traj(1:3,i); zeros(1,3) 1];
    
    
end

end


% a=1;
% b=2;
% c=3;

% u1=-pi/3;
% u2=pi/4;
% v1=-pi;
% v2=-pi+1;


%d1=dy/dphi|(phi,theta)   d2=dy/dtheta|(phi,theta)  n=d1 cross d2/norm d1 cross d2