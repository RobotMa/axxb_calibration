function exp = qhec(exp)

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
mpol('qx1', 'qx2', 'qx3', 'qx4', 'tx1', 'tx2', 'tx3');

qhec_monvect;
coeffs = zeros(size(monvect, 1), 1);

for i = 1:no_poses          
  % A
  A = rt2hom(exp.Ra{i}, exp.ta{i} / nn_max);  
  As = [A(1, :), A(2, :), A(3, :)]; 
  % B
  B = rt2hom(exp.Rb{i}, exp.tb{i} / nn_max);  
  Bs = [B(1, :), B(2, :), B(3, :)]; 
    
  % coeffs
  cfs = qhec_poly([As, Bs]);
  coeffs = coeffs + cfs;    
end  
  
% Objective function
F = coeffs' * monvect;

% Constraints 
K_norm = [qx1^2 + qx2^2 + qx3^2 + qx4^2 == 1];
K_ball = [tx1^2 + tx2^2 + tx3^2 <= 2, ...
          qx1 >= 0];

tic;
if (isfield(exp, 'verbose'))
    [problem] = msdp(min(F), K_ball, K_norm, 2);
    [stat, obj] = msol(problem); %#ok<NASGU>
else
    [T, problem] = evalc('msdp(min(F), K_ball, K_norm, 2)'); %#ok<NASGU>
    [T, stat, obj] = evalc('msol(problem)'); %#ok<NASGU>
end
exp.timer_qhec = toc;

qx = double([qx1 qx2 qx3 qx4']);
exp.Rx_qhec = q2rot(qx);
exp.tx_qhec = double([tx1, tx2, tx3]')  * nn_max;
end
