function exp = dqhec(exp)

mset clear
mpsettings(exp);
no_poses = numel(exp.Rb);

% Scaling - may be helpful ...
nn_max = 1;
if (isfield(exp, 'normalize'))
    if (exp.normalize == 1)
        nn_max = 0;

        for i=1:no_poses
            nn = norm(exp.ta{i});
            if (nn > nn_max)
                nn_max = nn;
            end
            nn = norm(exp.tb{i});
            if (nn > nn_max)
                nn_max = nn;
            end
        end
    end
end

% X
mpol('qx1', 'qx2', 'qx3', 'qx4', 'qx5', 'qx6', 'qx7', 'qx8');

dqhec_monvect;
coeffs = zeros(size(monvect, 1), 1);

for i = 1:no_poses          
  % A
  qa = hom2dq(rt2hom(exp.Ra{i}, exp.ta{i} / nn_max));
  qb = hom2dq(rt2hom(exp.Rb{i}, exp.tb{i} / nn_max));  

  % coeffs
  cfs = dqhec_poly([qa, qb]);
  coeffs = coeffs + cfs;    
end  
  
F = coeffs' * monvect;

K_norm = [qx1^2 + qx2^2 + qx3^2 + qx4^2 == 1]; %#ok<NASGU>
K_norm = [qx1^2 + qx2^2 + qx3^2 + qx4^2 == 1, ...
          qx1*qx5 + qx2*qx6 + qx3*qx7+ qx4*qx8 == 0, ...
          qx1 >= 0]; %#ok<NASGU>
      
tic;
if (isfield(exp, 'verbose'))
    [problem] = msdp(min(F),K_norm, 2);
    [stat, obj] = msol(problem); %#ok<NASGU>
else
    [T, problem] = evalc('msdp(min(F), K_norm, 2)'); %#ok<NASGU>
    [T, stat, obj] = evalc('msol(problem)'); %#ok<NASGU>
end
exp.timer_mpaqhec = toc;

rqx = double([qx1 qx2 qx3 qx4 qx5 qx6 qx7 qx8]');
[exp.Rx_dqhec, exp.tx_dqhec] = hom2rt(dq2hom(rqx));
exp.tx_dqhec = exp.tx_dqhec * nn_max;
end
