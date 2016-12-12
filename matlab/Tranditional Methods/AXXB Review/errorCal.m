% Calculate the error in Rotation, Translation and Transformation

function Error = errorCal(X,X_e,N)

%     % Error on Rotation
%     errorRot = zeros(1,N);
%     for i = 2:N
%         errorRot(1,i) = norm(X(1:3,1:3) - X_e(1:3,1:3,i));
%     end
% 
%     % Error on Translation
%     errorTranslation = zeros(1,N);
%     for j = 2:N
%         errorTranslation(1,j) = norm(X(1:3,4) - X_e(1:3,4,j));
%     end

    errorRotation = zeros(N,1);
    errorTranslation = zeros(N,1);
    errorTransformation = zeros(N,1);
    for k = 2:N
        errorRotation(k,1) = norm(X(1:3,1:3) - X_e(1:3,1:3,k));
        errorTranslation(k,1) = norm(X(1:3,4) - X_e(1:3,4,k));
        errorTransformation(k,1) = norm(X(:,:) - X_e(:,:,k));
    end
    
    Error = [errorRotation errorTranslation errorTransformation];
    
end