% ********************************************************************
% Software License Agreement (BSD License)
%
% Copyright (c) 2016, Johns Hopkins University
% All rights reserved.
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
% * Redistributions of source code must retain the above copyright
% notice, this list of conditions and the following disclaimer.
% * Redistributions in binary form must reproduce the above
% copyright notice, this list of conditions and the following
% disclaimer in the documentation and/or other materials provided
% with the distribution.
% * Neither the name of the Johns Hopkins University nor the names of its
% contributors may be used to endorse or promote products derived
% from this software without specific prior written permission.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
% FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
% COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
% INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
% LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
% CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
% LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
% ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
% *********************************************************************/

%
% Author: Qianli Ma, qianli.ma622@gmail.com, Johns Hopkins University
%

% Function to solve AX=XB for inputs of A and B which are 3D matrices where
% each AB pair is stacked in the third dimension (ie. Ai=A(:,:,i)).

function [X] = kronecker(A,B)

A_k = [];
b_k = [];
s_A = size(A, 3);

Ra = zeros(3, 3, s_A);
Rb = zeros(3, 3, s_A);

Ta = zeros(3, 1, s_A);
Tb = zeros(3, 1, s_A);

for i = 1:s_A
    Ra(:,:,i) = A(1:3,1:3,i);
    Rb(:,:,i) = B(1:3,1:3,i);
    
    Ta(:,:,i) = A(1:3,4,i);
    Tb(:,:,i) = B(1:3,4,i);
    
    D = diag(Ta(:,:,i));
    
    A_k = [A_k;[eye(9)-kron(Rb(:,:,i),Ra(:,:,i)), zeros(9,3); ...
           kron(Tb(:,:,i)',eye(3)), eye(3)-Ra(:,:,i)]];
    
    b_k = [b_k;[zeros(9,1); Ta(:,:,i)]];
end


X_k = pinv(A_k)*b_k;
% X_k=A_k\b_k;


X = [[X_k(1:3), X_k(4:6), X_k(7:9)] X_k(10:12); zeros(1,3) 1];

X(1:3,1:3) = sign(det(X(1:3,1:3)))/abs(det(X(1:3,1:3)))^(1/3)*X(1:3,1:3);

end