function error = tranerror(X, Xtrue)
% Calculate the relative translation between two SE3 matrices
% The order of matrices matters

error = norm(X(1:3,4)-Xtrue(1:3,4))/norm(Xtrue(1:3,4));

end