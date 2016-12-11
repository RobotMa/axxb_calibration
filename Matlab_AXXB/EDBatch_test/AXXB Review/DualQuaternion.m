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

% DUAL QUATERNIONs dual quaternion class
classdef DualQuaternion
    
    properties 
        s    % scalar part of nondual part
        v    % vector part of nondual part
        s_d  % scalar part of dual part
        v_d  % vector part of dual part
%         eps  % parameter of dual quaternion
        
    end
    
    methods 
        function q_dual = DualQuaternion(theta,d,l,m)
        %DualQuaternion.DualQuaternion Constructor for quaternion objects
          
            if nargin == 4
               % from screw parameters to dual quaternion 
               theta = theta(:);
               d = d(:);
               l = l(:);
               m = m(:);  
                if  size(l,1) == 3
                    if size(l,1) == 3 && size(m,1) == 3
                        q_dual.s = cos(theta/2);
                        q_dual.v = l*sin(theta/2);
                        q_dual.v = q_dual.v.';
                        q_dual.s_d = -d/2*sin(theta/2);
                        q_dual.v_d = m*sin(theta/2) + d/2*l*cos(theta/2);
                        q_dual.v_d = q_dual.v_d.';
                    else
                        disp('dimension error of screw')
                    end
                elseif  size(d,1) == 3
                        q_dual.s = theta;
                        q_dual.v = d.';
                        q_dual.s_d = l;
                        q_dual.v_d = m.';                       
                end
            elseif nargin == 1
                % from SE(3) to dual quaternion
                if size(theta,1) == 4 && size(theta,2) == 4
                    
                    t = Quaternion(theta(1:3,4));
                    q = tr2q(theta);
%                     q = Quaternion(theta(1:3,1:3));
                    q_prime = 1/2*mtimes(t,q);
                    q_dual = DualQuaternion(q, q_prime);
                    
                elseif size(theta,1) == 8
                        
%                         theta = vpa(theta,4);
                        theta = transpose(theta);
                        q_dual.s = theta(1);
                        q_dual.v = theta(2:4);
                        q_dual.s_d = theta(5);
                        q_dual.v_d = theta(6:8);                     
                elseif isa(theta,'DualQuaternion')
                    
                        q_dual.s = theta.s;
                        q_dual.v = theta.v;
                        q_dual.s_d = theta.s_d;
                        q_dual.v_d = theta.v_d;                     
                        
                else
                    disp('dimension of transformation matrix not correct')
                end
                
            elseif nargin == 0
                    q_dual.s = 1;
                    q_dual.v = [0, 0, 0];
                    q_dual.s_d = 0;
                    q_dual.v_d = [0, 0, 0];
                    
            elseif nargin == 2
                if isa(theta,'Quaternion') && isa(d,'Quaternion')
                    q_dual.s = theta.s;
                    q_dual.v = theta.v;
                    q_dual.s_d = d.s;
                    q_dual.v_d = d.v;
                else
                    disp('Input not in quaternion form')
                end
                
            else
                disp('Input in neither SE(3) nor screw form')
            end
        end
        
        % Dual quaternion concatenated multiplication
        function a = DQRigidMotion(q,b)
            
            q1 = DQTimes2(q,b);
            q_bar = QBar(q);
            a = DQTimes2(q1,q_bar);
            
        end
        
        % Dual quaternion multiplication
        function c = DQTimes2(a,b)
            
            % decompose dual quaternion multiplication into two quaternion
            % multiplication
            
            a1 = Quaternion([a.s,a.v]);
            b1 = Quaternion([b.s,b.v]);
            a2 = Quaternion([a.s_d,a.v_d]);
            b2 = Quaternion([b.s_d,b.v_d]);
            
            c1 = mtimes(a1,b1);
            c2 = mtimes(a1,b2) + mtimes(a2,b1);
            c = DualQuaternion(c1,c2);
        end
        
        function a = DQTimes3(dual_q,dual_b)
            % AX = XB in dual quaternion form dual_a =
            % dual_q*dual_b*dual_q_bar
            q = Quaternion([dual_q.s dual_q.v]);
            q_p = Quaternion([dual_q.s_d dual_q.v_d]);
            b = Quaternion([dual_b.s dual_b.v]);
            b_p = Quaternion([dual_b.s_d dual_b.v_d]);
            
            q_v = inv(q);
            m1 = mtimes(q,b);
            a = mtimes(m1,q_v);
            
            q_p_v = inv(q_p);
            m2 = mtimes(q,b);
            m3 = mtimes(q,b_p);
            m4 = mtimes(q_p,b);
            
            a_p = mtimes(m2,q_p_v) + mtimes(m3,q_v) + mtimes(m4,q_v);
            a = DualQuaternion(a, a_p);
            
        end
        
        function q_bar = QBar(q)
        % calculate the conjugate of a dual quaternion
            q_bar.s = q.s;
            q_bar.v = - q.v;
            q_bar.s_d = q.s_d;
            q_bar.v_d = - q.v_d;
            
        end
        
        function T = DQ2T(q_dual)
            
            q = Quaternion([q_dual.s q_dual.v]);
            q_p = Quaternion([q_dual.s_d q_dual.v_d]);
            R = q2tr(q); % Return a 4 by 4 transformation matrix
            R = R(1:3,1:3);
            t = 2*mtimes(q_p,inv(q));
            if abs(t.s) > 1
                disp('t.s ~= 0')
                abs(t.s)
            else
                t.s;
            end
            t = t.v(:);
            T = [R t; zeros(1,3) 1];
            
        end
            
            
    end
end
            
                    
                    
                    
        