%Function to generate B^is from a trajectory along an ellipsoid surface and corresponding A^is from a given X

function [A, B]=AB_genTraj(X, ElipseParam, trajParam, num)

A=zeros(4,4,num-1);
B=zeros(4,4,num-1);

Bi=createTraj(ElipseParam(1), ElipseParam(2), ElipseParam(3), trajParam(1), trajParam(2), trajParam(3), trajParam(4), trajParam(5), num);


B=subToSuper(Bi);


for i=1:size(B,3)
    
    A(:,:,i)=X*B(:,:,i)*X^-1;
    
end




end