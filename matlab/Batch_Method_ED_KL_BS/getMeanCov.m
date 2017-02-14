function [Mean, Covariance] = getMeanCov(M)

[m1,m2,m3]  = size(M);
M_mex = reshape(M, m1, m2*m3);

[ Mean, Covariance ] = distibutionPropsMex_mex(M_mex); %_mex

end
