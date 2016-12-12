function error = roterror(X1, Xtrue)


error = norm( so3_vec( logm( ( X1(1:3,1:3)'*Xtrue(1:3,1:3) ) ) ) );


end