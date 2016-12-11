function error = tranerror(X1, Xtrue)


error = norm(X1(1:3,4)-Xtrue(1:3,4))/norm(Xtrue(1:3,4));

end