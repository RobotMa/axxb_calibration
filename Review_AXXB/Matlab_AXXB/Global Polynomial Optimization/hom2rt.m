function [R, t] = hom2rt(H)
    R = H(1:3, 1:3);
    t = H(1:3, 4);
end