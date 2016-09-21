function [Ad]=SE3inv_Ad(X)

Ad=[X(1:3,1:3)' zeros(3,3); so3_vec(-X(1:3,1:3)'*X(1:3,4))*X(1:3,1:3)' X(1:3,1:3)];