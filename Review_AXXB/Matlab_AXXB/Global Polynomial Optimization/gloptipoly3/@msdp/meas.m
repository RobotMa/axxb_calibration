function m = meas(p)
% @MSDP/MEAS - Measures of a moment SDP problem
%
% The instruction
%
%  M = MEAS(P)
%
% returns a vector of measures (class MEAS) associated
% with problem P. The measures are arranged by increasing
% index.

% D. Henrion, 27 November 2006

m = meas(p.indmeas);
