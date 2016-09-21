%Function to add Gaussian noise to a g \in SE(3)

%files needed:
%se3_vec().m

function g_noise=sensorNoiseDist(g, gmean, x, SigX)


for i=1:size(g,3)    
    
    X_1(:,:,i)=
    
    X_2(:,:,i)=
    
    g_noise(:,:,i)=X_1(:,:,i)*B(:,:,i)*X_2(:,:,i)^-1;
    
end

X_dist=cat(3, X_1, X_2);







end