clc
echo on
% Short demo of Gloptipoly 3
%
% Consider the classical problem of minimizing globally the
% two-dimensional six-hump camel back function 
%
% min g0(x) = 4x1^2+x1x2-4x2^2-2.1x1^4+4x2^4+x1^6/3 
%
% The function has six local minima, two of them being global minima.
%
% This optimization problem can be modeled as a moment
% problem as follows.
%
% First we define the variables
% and the polynomial to be minimized

mpol x1 x2
g0 = 4*x1^2+x1*x2-4*x2^2-2.1*x1^4+4*x2^4+x1^6/3
pause % Strike any key to continue.

% Then we define the optimization problem

P = msdp(min(g0))
pause % Strike any key to continue.

% Once the moment problem is modeled, a semidefinite solver can be used to
% solve it numerically with the command [status,obj] = msol(P)

pause % Strike any key to continue.

[status,obj] = msol(P)                       
pause % Strike any key to continue.

status

% This means that the moment problem is solved successfully
% that GloptiPoly can extract two globally optimal
% solutions reaching the objective function: 

obj
x = double([x1 x2]);
