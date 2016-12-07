function sc = supcon(M)
% @MEAS/SUPCON - Measure support constraint
%
% The instruction
%
%  [SCEQ,SCGE] = SUPCON(M)
%
% returns column vectors SCEQ,SCGE of class SUPCON corresponding
% respectively to localization equality and inequality constraints
% on measure M. The constraints are arranged consistently with the
% cell array of dual multipliers returned by function MSOL.

% D. Henrion, 27 November 2006

if length(M) > 1
 error('Please specify only one measure')
end

im = indmeas(M);
sceq = []; 
for k = 1:length(P.supceq)
 if indmeas(P.supceq(k)) == im
  sceq = [sceq; P.supceq(k)];
 end
end
scge = [];
for k = 1:length(P.supcge)
 if indmeas(P.supcge(k)) == im
  scge = [scge; P.supcge(k)];
 end
end

