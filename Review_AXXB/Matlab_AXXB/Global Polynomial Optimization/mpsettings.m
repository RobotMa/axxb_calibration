function mpsettings(exp)

pars.eps = 1e-20;
mset(pars);

%{
if (isfield(exp, 'solver'))
    if (strcmp(exp.solver, 'mosek'))
        mset('yalmip',true);
        warning('off','YALMIP:strict')
        mset(sdpsettings('solver','mosek', 'mosek.MSK_DPAR_INTPNT_CO_TOL_PFEAS ', 1e-20, 'mosek.MSK_DPAR_INTPNT_CO_TOL_DFEAS ', 1e-20));
    elseif (strcmp(exp.solver, 'csdp'))
        mset('yalmip',true);
        warning('off','YALMIP:strict')
        mset(sdpsettings('solver','csdp', 'csdp.axtol', 1.0e-8, 'csdp.atytol', 1.0e-8));
    else
        mset('yalmip',true);
        warning('off','YALMIP:strict')
        mset(sdpsettings('solver','sedumi', 'sedumi.eps', 1e-20));        
    end
end
%}

end