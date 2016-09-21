function [F,h,y,s] = myalmip(P)
% @MSDP/MYALMIP - Convert moment SDP problem into YALMIP input format
%
% [F,H,Y,S] = MYALMIP(P) translates a moment SDP problem P built with MDEF
% into the YALMIP input format. In particular the SDP problem can then
% be solved with the YALMIP command SOLVESDP(F,H). YALMIP SDPVAR object Y
% is the vector of moments. The objective last output argument S is the
% expected sign of the objective function: if S=+1, the optimization problem
% to be solved is MAX(H) s.t. F(Y)>(=)0; if S=-1, it is MIN(H) s.t. F(Y)>(=)0

% D. Henrion, 5 August 2004
% Last modified on 30 September 2008
% The script is based on J. Löfberg's LOADSEDUMIDATA in YALMIP/EXTRAS

if exist('sdpvar') ~= 2
 error('YALMIP is not properly installed')
end

At = P.A; b = P.b; c = P.c; K = P.K; b0 = P.objshift; s = P.objsign;

nvars = length(b);
x = sdpvar(nvars,1);

if size(At,2)~=length(b)
    At = At';
end

F = set([]);
top = 1;

if isvalidfield(K,'f')
 AT = At(top:top+K.f-1,:);
 if nnz(AT) > 0
   X = c(top:top+K.f-1)-AT*x;
   F = F + set(X(:) == 0);
 end
 top = top + K.f;
end

if isvalidfield(K,'l')
 AT = At(top:top+K.l-1,:);
 if nnz(AT) > 0
   X = c(top:top+K.l-1)-AT*x;
   F = F + set(X(:));
 end
 top = top + K.l;
end

if isvalidfield(K,'q')
 for i = 1:length(K.q)
  AT = At(top:top+K.q(i)-1,:);
  if nnz(AT) > 0
    X = c(top:top+K.q(i)-1)-AT*x;
    F = F + set(cone(X(2:end),X(1)));
  end
  top = top + K.q(i);
 end
end

if isvalidfield(K,'r')
 for i = 1:length(K.r)
  AT = At(top:top+K.r(i)-1,:);
  if nnz(AT) > 0 
    X = c(top:top+K.r(i)-1)-AT*x;
    F = F + set(rcone(X(3:end),X(2),X(1)));
  end
  top = top + K.r(i);
 end
end

if isvalidfield(K,'s')
 for i = 1:length(K.s)
  [ix,iy,iv] = find([c(top:top+K.s(i)^2-1) At(top:top+K.s(i)^2-1,:)]);
  off = (ix-1)/(K.s(i)+1);
  if all(off == round(off))
   AT = At(top:top+K.s(i)^2-1,:);
   if nnz(AT) > 0
    X = c(top:top+K.s(i)^2-1)-AT*x;
    F = F + set(diag(reshape(X,K.s(i),K.s(i))) > 0);
   end
   top = top + K.s(i)^2;
  else
   AT = At(top:top+K.s(i)^2-1,:);
   if nnz(AT) > 0 
    X = c(top:top+K.s(i)^2-1)-AT*x;
    F = F + set(reshape(X,K.s(i),K.s(i)) > 0);
   end
   top = top + K.s(i)^2;
  end
 end
end

y = x;
h = s*(b0+b*y);

function ok = isvalidfield(K,fld)
ok = 0;
if isfield(K,fld)
    s = getfield(K,fld);
    if prod(size(s))>0
        if s(1)>0
            ok = 1;
        end
    end
end
