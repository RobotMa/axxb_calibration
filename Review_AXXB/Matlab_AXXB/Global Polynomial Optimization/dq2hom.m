function H  = dq2hom(dq)

if (size(dq, 1) == 1)
    dq = dq';
end

R = q2rot(dq(1:4));
t = 2 * mulq(dq(5:8), [1; -1; -1; -1] .* dq(1:4));

H = rt2hom(R,t(2:4));