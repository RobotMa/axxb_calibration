function x=vec(X)

[a,b] = size(X);

x = reshape(X,a*b,1);

end