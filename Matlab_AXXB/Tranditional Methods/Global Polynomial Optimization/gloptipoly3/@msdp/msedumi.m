function [A,b,c,K,b0,s] = msedumi(P)
% @MSDP/MSEDUMI - Convert moment SDP problem to SeDuMi input format
%
% [A,b,c,K,b0,s] = MSEDUMI(P) translates a moment SDP problem P built with MDEF
% into the SeDuMi input format A,b,c,K
%
% The SDP problem is in SeDuMi dual format
% b0 + max(b'*y) s.t. z = c-A'*y \in K, if s = +1, and
% -(b0 + max(b'*y)) = -b0 + min(-b'*y) s.t. z = c-A'*y \in K, if s = -1
% where b0 is a constant shift

% D. Henrion, 5 August 2004
% Last modified on 30 September 2008

A = P.A'; b = P.b'; c = P.c; K = P.K; b0 = P.objshift; s = P.objsign;
