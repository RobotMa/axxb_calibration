function sc = supcon(P,M)
% @MSDP/SUPCON - Measure support constraints of a moment SDP problem
%
% Given a moment SDP problem P (class MSDP) and a measure M (class MEAS)
% previously defined by MDEF, the instruction
%
%  SC = SUPCON(P,M)
%
% returns a column vector SC of class SUPCON corresponding
% to localization constraints of measure M in P. Equality constraints
% SC(K)==0 can be found at the top, and inequality constraints SC(K)>=0
% at the bottom, in an order consistent with the cell array of dual
% multipliers returned by function MSOL.

% D. Henrion, 27 November 2006

if nargin < 2
 error('Unspecified measure')
end
if ~isa(P,'msdp')
 old = P; P = M; M = P;
end
if ~isa(P,'msdp')
 error('Unspecified moment SDP problem')
end
if length(P) > 1
 error('First input argument must be a scalar')
end
if ~isa(M,'meas')
 error('Unspecified measure')
end
if length(M) > 1
 error('Second input argument must be a scalar')
end

im = indmeas(M);
sc = [];
for k = 1:length(P.supceq)
 if indmeas(P.supceq(k)) == im
  sc = [sc; P.supceq(k)];
 end
end
for k = 1:length(P.supcge)
 if indmeas(P.supcge(k)) == im
  sc = [sc; P.supcge(k)];
 end
end

