%Test R6 to SE3

V = rand(6,10);

G1 = R6toSE3(V);

for ii = 1 : length(V)
    twist = V(:,ii)';
    G2(:,:,ii) = expm(hat2(twist));
end

for ii = 1 : length(V)
    
    V2(:,ii) =vee(logm(G2(:,:,ii)));
end
V1 = SE3toR6(G1);