% Hand-Eye Calibration Using Dual Quaternions
% this function use non-dual and dual vector parts of a and b to generate
% the S matrix, which can be accumulated to compose T matrix 

function S = DQ2S( dq_a, dq_b )
        
        if nargin == 2
            if isa(dq_a, 'Dual_Quaternion') && isa(dq_b, 'Dual_Quaternion')
                a = dq_a.v(:);
                b = dq_b.v(:);
                a_p = dq_a.v_d(:);
                b_p = dq_b.v_d(:);
                S = [ a - b      hat(a + b)      zeros(3,1) zeros(3,3);
                      a_p - b_p  hat(a_p + b_p)  a - b      hat( a+ b)];
            else
                display('Not dual quaternion')
            end
        else
            display('number of input arguments not equal to 2')
        end
end