function [v] = SE2toR3(G)
n = size(G,3);
v = zeros(3,n);


R = G(1:2,1:2,:);

st = squeeze(G(2,1,:));
ct = squeeze(G(1,1,:));
v(3,:) = atan2(st,ct);

a = v(3,:);
t1 = squeeze(G(1,3,:))';
t2 = squeeze(G(2,3,:))';


v(1,:) = (a.*t2)./2 - (a.*t1.*sin(a))./(2.*(cos(a) - 1));
v(2,:) = - (a.*t1)./2 - (a.*t2.*sin(a))./(2.*(cos(a) - 1));