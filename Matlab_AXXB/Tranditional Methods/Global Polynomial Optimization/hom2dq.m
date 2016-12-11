function dq = hom2dq(t, m)
% convert homogeneous transformation t to dual quaternion
[R, t] = hom2rt(t);

dq = zeros(8, 1);
dq(1:4) = rot2q(R);
if (nargin > 1)
  dq(1:4) = m * dq(1:4);
end

dq(5:8) = 0.5 * mulq([0;t], dq(1:4));

end
