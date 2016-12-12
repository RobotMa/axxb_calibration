% Hand-Eye Calibration Using Uual Quaternions

function lam = lamOpti(lam1,lam2,s11,s12,s13)
    
     a = s11*lam1^2 + s12*lam1 + s13;
     b = s11*lam2^2 + s12*lam2 + s13;
     if a > b
         lam = lam1;
     else
         lam = lam1;
     end
end