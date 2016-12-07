function error = roterror(X1, X2)


error = norm( so3_vec( logm( ( X1(1:3,1:3)'*X2(1:3,1:3) ) ) ) );


end