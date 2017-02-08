function exp = uvhec(exp)

mset clear
mpsettings(exp);

no_poses = numel(exp.Rb);

% Scaling
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
mpol('rx1', 'rx2', 'rx4', 'rx5', 'rx7', 'rx8', 'tx1', 'tx2', 'tx3'); 

uvhec_monvect;
coeffs = zeros(size(monvect, 1), 1);

for i = 1:no_poses          
  % A
  A = rt2hom(exp.Ra{i}, exp.ta{i} / nn_max);  
  As = [A(1, :), A(2, :), A(3, :)]; 
  % B
  B = rt2hom(exp.Rb{i}, exp.tb{i} / nn_max);  
  Bs = [B(1, :), B(2, :), B(3, :)]; 
    
  % coeffs
  cfs = uvhec_poly([As, Bs]);
  coeffs = coeffs + cfs;    
end  
 
% Objective function
F = coeffs' * monvect;

% Constraints 
u = [rx1, rx4, rx7]';
v = [rx2, rx5, rx8]';

K_norm = [v'*v == 1, u'*u == 1, u'*v == 0];
K_ball = [tx1^2 + tx2^2 + tx3^2 <= 2];

tic;
if (isfield(exp, 'verbose'))
    [problem] = msdp(min(F), K_ball, K_norm, 2);
    [stat, obj] = msol(problem); %#ok<NASGU>
else
    [T, problem] = evalc('msdp(min(F), K_ball, K_norm, 2)'); %#ok<NASGU>
    [T, stat, obj] = evalc('msol(problem)'); %#ok<NASGU>
end
exp.timer_uvhec = toc;

u = double([rx1, rx4, rx7]');
v = double([rx2, rx5, rx8]');
w = cross(u,v);

exp.Rx_uvhec = [u, v, w];
exp.tx_uvhec = double([tx1, tx2, tx3]') * nn_max;
end
