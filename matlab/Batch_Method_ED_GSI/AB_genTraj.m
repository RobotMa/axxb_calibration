%Function to generate B^is from a trajectory along an ellipsoid surface and corresponding A^is from a given X

function [A, B] = AB_genTraj(X, ElipseParam, num, twist)

A = zeros(4, 4, num-1);
B = zeros(4, 4, num-1);

Bi = createTraj(ElipseParam(1), ElipseParam(2), ElipseParam(3), num, twist);


for i = 1:size(Bi,3) - 1
    
    B(:,:,i) = Bi(:,:,i)^-1*Bi(:,:,i+1);
    
end


for i = 1:size(B,3)
    
    A(:,:,i) = X*B(:,:,i)*X^-1;
    
end


end