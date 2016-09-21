% Function to generate Bi's from a trajectory along an ellipsoid surface and corresponding Ai's from a given X

% First written by M. Kendal Ackerman
% Edited by Qianli Ma


function [ A, B ]= AB_genTraj_gap( X, ElipseParam, num, twist, gap_size )

A = zeros( 4,4,(num-1)/gap_size );
B = zeros( 4,4, num-1 );

Bi = createTraj( ElipseParam(1), ElipseParam(2), ElipseParam(3), num, twist );


for i = 1 : size(Bi,3)-1
    
    B(:,:,i) = Bi(:,:,i)^-1*Bi(:,:,i+1);
    
end


for i = 1 : (size(B,3)/gap_size)
    
    A(:,:,i) = X*B(:,:,gap_size*i)*X^-1;
    
end

% a = 0;


end