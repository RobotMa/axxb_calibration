function herwc_demo
% 2013 Jan Heller, hellej1@cmp.felk.cvut.cz

xz_flag = 1;
exp.verbose = 1;

path = fileparts(mfilename('fullpath'));
sedumi_path = [path filesep 'SeDuMi_1_3'];
gloptipoly_path = [path filesep 'gloptipoly3'];

addpath(sedumi_path);
addpath(gloptipoly_path);

% Example data ------------------------------------------------------------

X_orig = [ ...
    0.9995   -0.0100    0.0297   -0.1229
    0.0116    0.9986   -0.0523    0.1575
   -0.0291    0.0526    0.9982    0.0088
         0         0         0    1.0000       
];

Z_orig = [ ...
    0.2790   -0.0981   -0.9553   -0.2593
   -0.5439    0.8037   -0.2414   -0.2469
    0.7914    0.5869    0.1709   -0.0367
         0         0         0    1.0000
];

% Camera matrices -- transforming points from the camera coordinate 
% frame to the world coordinate frame

A = cell(4,1);

A{1} = [ ...
    0.1752   -0.6574    0.7329   -0.5536
    0.6325   -0.4954   -0.5954   -0.5304
    0.7545    0.5679    0.3290    0.4851
         0         0         0    1.0000
];         

A{2} = [ ...
   -0.0745    0.9661    0.2471   -0.4123
    0.8573   -0.0645    0.5108   -0.8904
    0.5094    0.2499   -0.8234    0.8685
         0         0         0    1.0000
];

A{3} = [ ...
   -0.1456   -0.6867    0.7122   -0.5519
    0.8252   -0.4814   -0.2955   -0.6491
    0.5458    0.5447    0.6367    0.4312
         0         0         0    1.0000
];

A{4} = [ ...
   -0.1434   -0.5250    0.8389   -0.5892
    0.8158   -0.5427   -0.2001   -0.6730
    0.5603    0.6557    0.5061    0.4641
         0         0         0    1.0000
];

% Robot matrices -- transforming points from the gripper coordinate 
% frame to the robot (base) coordinate frame

B = cell(4,1);

B{1} = [ ...
    0.2846    0.5730    0.7685    0.5391
    0.9440   -0.0281   -0.3287   -0.0108
   -0.1667    0.8191   -0.5489    0.5908
         0         0         0    1.0000
];

B{2} = [ ...
   -0.0533    0.4572   -0.8877    1.1056
    0.9976   -0.0151   -0.0677   -0.0940
   -0.0443   -0.8892   -0.4553    0.3216
         0         0         0    1.0000
];

B{3} = [ ...
   -0.0767    0.5464    0.8340    0.6009
    0.9954   -0.0065    0.0958   -0.1420
    0.0578    0.8375   -0.5434    0.5844
         0         0         0    1.0000
];

B{4} = [ ...
   -0.0543    0.7062    0.7059    0.6527
    0.9965   -0.0071    0.0839   -0.1386
    0.0643    0.7080   -0.7033    0.6106
         0         0         0    1.0000
];


% Experiment --------------------------------------------------------------

no_poses = numel(B);
for i = 1:no_poses
    [exp.Rb_abs{i}, exp.tb_abs{i}] = hom2rt(B{i});
    % Notice that we expect inverse transformation in Ra_abs/ta_abs
    [exp.Ra_abs{i}, exp.ta_abs{i}] = ihom2rt(A{i});
end

% We need to construct relative movements for hand-eye calibration
c = 1;
for m = 1:no_poses
    for n = (m+1):no_poses
        [exp.Rb{c}, exp.tb{c}] = hom2rt(irt2hom(exp.Rb_abs{n}, exp.tb_abs{n}) * rt2hom(exp.Rb_abs{m}, exp.tb_abs{m}));
        [exp.Ra{c}, exp.ta{c}] = hom2rt(rt2hom(exp.Ra_abs{n}, exp.ta_abs{n}) * irt2hom(exp.Ra_abs{m}, exp.ta_abs{m}));        
        c = c + 1;
    end
end                  


% Hand-eye calibration ----------------------------------------------------


fprintf(1, 'Running uvhec ...\n');
exp = uvhec(exp);
X_uvhec = rt2hom(exp.Rx_uvhec, exp.tx_uvhec);

fprintf(1, 'Running qhec ...\n');
exp = qhec(exp);
X_qhec = rt2hom(exp.Rx_qhec, exp.tx_qhec);

fprintf(1, 'Running dqhec ...\n');
exp = dqhec(exp);
X_dqhec = rt2hom(exp.Rx_dqhec, exp.tx_dqhec);

% Run simultaneous hand-eye and robot-world calibration -------------------

if (xz_flag)
    disp('Running uvherwc ...');
    exp = uvherwc(exp);
    X_uvherwc = rt2hom(exp.Rx_uvherwc, exp.tx_uvherwc);
    % Notice that we receive an inverse transformation in Rz/tz
    Z_uvherwc = irt2hom(exp.Rz_uvherwc, exp.tz_uvherwc);

    disp('Running qherwc ...');
    exp = qherwc(exp);
    X_qherwc = rt2hom(exp.Rx_qherwc, exp.tx_qherwc);
    % Notice that we receive an inverse transformation in Rz/tz
    Z_qherwc = irt2hom(exp.Rz_qherwc, exp.tz_qherwc);

    disp('Running dqherwc ...');
    exp.qmul = [-1, -1, -1, -1; 1 1 1 1];
    exp = dqherwc(exp);
    X_dqherwc = rt2hom(exp.Rx_dqherwc, exp.tx_dqherwc);
    % Notice that we receive an inverse transformation in Rz/tz
    Z_dqherwc = irt2hom(exp.Rz_dqherwc, exp.tz_dqherwc);
end

% Results -----------------------------------------------------------------

fprintf(1, '\n\n\n');
fprintf(1, 'Results of uvhec \n');
fprintf(1, '  [X_orig, X_uvhec]\n\n');
disp([X_orig, X_uvhec]);
fprintf(1, '\n\n');

fprintf(1, 'Results of qhec \n');
fprintf(1, '  [X_orig, X_qhec]\n\n');
disp([X_orig, X_qhec]);
fprintf(1, '\n\n');

fprintf(1, 'Results of dqhec \n');
fprintf(1, '  [X_orig, X_dqhec]\n\n');
disp([X_orig, X_dqhec]);
fprintf(1, '\n\n');

if (xz_flag)
    fprintf(1, 'Results of uvherwc \n');
    fprintf(1, '  [X_orig, X_uvherwc]\n\n');
    disp([X_orig, X_uvherwc]);
    fprintf(1, '  [Z_orig, X_uvherwc]\n\n');
    disp([Z_orig, Z_uvherwc]);
    fprintf(1, '\n\n');

    fprintf(1, 'Results of qherwc \n');
    fprintf(1, '  [X_orig, X_qherwc]\n\n');
    disp([X_orig, X_qherwc]);
    fprintf(1, '  [Z_orig, X_qherwc]\n\n');
    disp([Z_orig, Z_qherwc]);
    fprintf(1, '\n\n');

    fprintf(1, 'Results of dqherwc \n');
    fprintf(1, '  [X_orig, X_dqherwc]\n\n');
    disp([X_orig, X_dqherwc]);
    fprintf(1, '  [Z_orig, X_dqherwc]\n\n');
    disp([Z_orig, Z_dqherwc]);
    fprintf(1, '\n\n');
else
    fprintf(1, 'Simultaneous hand-eye and robot-world calibration not run.\n');
    fprintf(1, 'In order to run it, set xz_flag to 1. It may, however, consume\n');
    fprintf(1, 'a sizable amount of CPU and memory resources. \n');
end

end