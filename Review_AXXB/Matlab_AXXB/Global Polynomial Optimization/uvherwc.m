function exp = uvherwc(exp)

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
mpol('rx1', 'rx2', 'rx4', 'rx5', 'rx7', 'rx8', 'tx1', 'tx2', 'tx3'); 
mpol('rz1', 'rz2', 'rz4', 'rz5', 'rz7', 'rz8', 'tz1', 'tz2', 'tz3'); 

uvherwc_monvect;
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
  cfs = uvherwc_poly([As, Bs]);
  coeffs = coeffs + cfs;    
end  
  
F = coeffs' * monvect; %#ok<NASGU>


u = [rx1, rx4, rx7]';
v = [rx2, rx5, rx8]';

K_norm = [v'*v == 1, u'*u == 1, u'*v == 0];

u = [rz1, rz4, rz7]';
v = [rz2, rz5, rz8]';

K_norm = [K_norm, v'*v == 1, u'*u == 1, u'*v == 0]; %#ok<NASGU>

K_ball = [tx1^2 + tx2^2 + tx3^2 <= 2, ...
          tz1^2 + tz2^2 + tz3^2 <= 100]; %#ok<NASGU>

tic;
if (isfield(exp, 'verbose'))
    [problem] = msdp(min(F), K_ball, K_norm, 2);
    [stat, obj] = msol(problem); %#ok<NASGU>
else
    [T, problem] = evalc('msdp(min(F), K_ball, K_norm, 2)'); %#ok<NASGU>
    [T, stat, obj] = evalc('msol(problem)'); %#ok<NASGU>
end
exp.timer_uvherwc = toc;

u = double([rx1, rx4, rx7]');
v = double([rx2, rx5, rx8]');
w = cross(u,v);

exp.Rx_uvherwc = [u, v, w];
exp.tx_uvherwc = double([tx1, tx2, tx3]') * nn_max;

u = double([rz1, rz4, rz7]');
v = double([rz2, rz5, rz8]');
w = cross(u,v);

Rz = [u, v, w];
tz = double([tz1, tz2, tz3]') * nn_max;

[exp.Rz_uvherwc, exp.tz_uvherwc] =  hom2rt(irt2hom(Rz, tz));
end
