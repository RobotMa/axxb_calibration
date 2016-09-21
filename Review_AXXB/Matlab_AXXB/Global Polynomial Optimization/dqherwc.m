function exp = dqherwc(exp)

if (~isfield(exp, 'qmul'))
    error('qmul field is not set in exp');
end

mset clear
mpsettings(exp);
no_poses = numel(exp.Rb_abs);

% Scaling - may be helpful ...
nn_max = 1;
if (isfield(exp, 'normalize'))
    if (exp.normalize == 1)
        nn_max = 0;

        for i=1:no_poses
            nn = norm(exp.ta_abs{i});
            if (nn > nn_max)
                nn_max = nn;
            end
            nn = norm(exp.tb_abs{i});
            if (nn > nn_max)
                nn_max = nn;
            end
        end
    end
end

% X Z
mpol('qx1', 'qx2', 'qx3', 'qx4', 'qx5', 'qx6', 'qx7', 'qx8');
mpol('qz1', 'qz2', 'qz3', 'qz4', 'qz5', 'qz6', 'qz7', 'qz8');

dqherwc_monvect;

err_min = realmax;
exp.counter_dqherwc = 0;

for j = 1:size(exp.qmul, 1)

    coeffs = zeros(size(monvect, 1), 1);

    for i = 1:no_poses
        A{i} = irt2hom(exp.Ra_abs{i}, exp.ta_abs{i} / nn_max); %#ok<AGROW>
        B{i} = rt2hom(exp.Rb_abs{i}, exp.tb_abs{i} / nn_max); %#ok<AGROW>
    end

    for i = 1:no_poses          
      qa = hom2dq(A{i});

      if (isfield(exp, 'qmul'))
        qb = hom2dq(B{i}, exp.qmul(j,i)); 
      else
        qb = hom2dq(B{i}); 
      end
      
      % coeffs
      cfs = dqherwc_poly([qa', qb']);
      coeffs = coeffs + cfs;    
    end  

    F = coeffs' * monvect; %#ok<NASGU>

    K_norm = [qx1^2 + qx2^2 + qx3^2 + qx4^2 == 1, ...
              qz1^2 + qz2^2 + qz3^2 + qz4^2 == 1, ...
              qx1*qx5 + qx2*qx6 + qx3*qx7+ qx4*qx8 == 0, ...
              qz1*qz5 + qz2*qz6 + qz3*qz7+ qz4*qz8 == 0, ...
              qx1 >= 0, ...
              qz1 >= 0]; %#ok<NASGU>

    tic;
    if (isfield(exp, 'verbose'))
        [problem] = msdp(min(F), K_norm, 2);
        [stat, obj] = msol(problem); %#ok<NASGU>
    else
        [T, problem] = evalc('msdp(min(F), K_norm, 2)'); %#ok<NASGU>
        [T, stat, obj] = evalc('msol(problem)'); %#ok<NASGU>
    end
    
    exp.counter_dqherwc = exp.counter_dqherwc + 1;
    exp.timer_dqherwc = toc;

    
    rqx = double([qx1 qx2 qx3 qx4 qx5 qx6 qx7 qx8])';
    rqz = double([qz1 qz2 qz3 qz4 qz5 qz6 qz7 qz8])';
    
    X = dq2hom(rqx);
    Z = dq2hom(rqz);

    err = 0;
    for i = 1:no_poses
       err = err + norm(A{i} * X - Z * B{i});
    end
        
    if (err < err_min)
        err_min = err;
        [exp.Rx_dqherwc, exp.tx_dqherwc] = hom2rt(dq2hom(rqx));
        exp.tx_dqherwc = exp.tx_dqherwc * nn_max;

        [exp.Rz_dqherwc, exp.tz_dqherwc] = ihom2rt(dq2hom(rqz));
        exp.tz_dqherwc = exp.tz_dqherwc * nn_max;
    end
    
end
