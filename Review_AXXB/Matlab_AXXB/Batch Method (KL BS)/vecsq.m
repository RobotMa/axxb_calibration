function X=vecsq(x)

a = size(x,1);

X = reshape(x,sqrt(a),sqrt(a));

end