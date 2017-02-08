function r = rot2r(R)
    %logR = logm(R);
    %r = [logR(3,2), logR(1,3), logR(2,1)]'; 
    
    alpha = acos((trace(R) - 1)/2);
    r = alpha / (2 * sin(alpha)) * [R(3,2) - R(2,3); R(1,3) - R(3,1); R(2,1) - R(1,2)];
end