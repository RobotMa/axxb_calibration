function H = irt2hom(R, t)
    H = [R', -R'*t; 0, 0, 0 1];
end