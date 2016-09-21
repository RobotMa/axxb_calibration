function exp = qherwc(exp)

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
mpol('qx1', 'qx2', 'qx3', 'qx4', 'tx1', 'tx2', 'tx3');
mpol('qz1', 'qz2', 'qz3', 'qz4', 'tz1', 'tz2', 'tz3');

qherwc_monvect;
coeffs = zeros(size(monvect, 1), 1);

for i=1:no_poses
    [Ra_abs{i}, ta_abs{i}] = hom2rt(irt2hom(exp.Ra_abs{i}, exp.ta_abs{i} / nn_max)); %#ok<AGROW>
end

for i = 1:no_poses          
  % A
  A = rt2hom(Ra_abs{i}, ta_abs{i});  
  As = [A(1, :), A(2, :), A(3, :)]; 
  % B
  B = rt2hom(exp.Rb_abs{i}, exp.tb_abs{i} / nn_max);  
  Bs = [B(1, :), B(2, :), B(3, :)]; 
    
  % coeffs
  cfs = qherwc_poly([As, Bs]);
  coeffs = coeffs + cfs;    
end  
  
F = coeffs' * monvect;

K_norm = [qx1^2 + qx2^2 + qx3^2 + qx4^2 == 1, ...
          qz1^2 + qz2^2 + qz3^2 + qz4^2 == 1];
K_ball = [tx1^2 + tx2^2 + tx3^2 <= 2, ...
          tz1^2 + tz2^2 + tz3^2 <= 100, ...
          qx1 >= 0, ...
          qz1 >= 0]; 

tic;

if (isfield(exp, 'verbose'))
    [problem] = msdp(min(F), K_ball, K_norm, 2);
    [stat, obj] = msol(problem); %#ok<NASGU>
else
    [T, problem] = evalc('msdp(min(F), K_ball, K_norm, 2)'); %#ok<NASGU>
    [T, stat, obj] = evalc('msol(problem)'); %#ok<NASGU>
end

exp.timer_qherwc = toc;

qx = double([qx1 qx2 qx3 qx4])';
tx = double([tx1 tx2 tx3])';

exp.Rx_qherwc = q2rot(qx);
exp.tx_qherwc = tx * nn_max;

qz = double([qz1 qz2 qz3 qz4])';
tz = double([tz1 tz2 tz3])';

Rz = q2rot(qz);
tz = tz * nn_max;
[exp.Rz_qherwc, exp.tz_qherwc] = hom2rt(irt2hom(Rz, tz));
end
