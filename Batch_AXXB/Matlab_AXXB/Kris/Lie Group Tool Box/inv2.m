function [Ainv] = inv2(A)
%[Ainv] = inv2(A)
%Encodes inverse in a more efficient way as
%
%Ainv = eye(size(A))/A;

Ainv = eye(size(A))/A; 