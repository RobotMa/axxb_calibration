function [mceq,mcge] = momcon(P)
% @MSDP/MOMCON - Moment constraints of a moment SDP problem
%
% Given a moment SDP problem P (class MSDP) previously defined by MDEF,
% the instruction
%
%  [MCEQ,MCGE] = MOMCON(P)
%
% returns column vectors MCEQ, MCGE of class MOMCON corresponding
% to moment equality constraints MCEQ==0 and moment inequality
% constraints MCGE>=0, in an order consistent with the vector of
% dual multipliers returned by function MSOL.

% D. Henrion, 27 November 2006

mceq = (P.mmomceq==0);
mcge = (P.mmomcge>=0);
