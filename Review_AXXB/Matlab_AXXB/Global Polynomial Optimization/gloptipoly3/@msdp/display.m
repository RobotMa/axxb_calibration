function display(P)
% @MSDP/DISPLAY - Display a moment SDP problem

% D. Henrion, 27 March 2006
% Last modified on 31 March 2006
  
% Spacing
if isequal(get(0,'FormatSpacing'),'compact')
 cr = '';
else
 cr = '\n';
end

% Display variable name
% xname = inputname(1);
% if ~isempty(xname)
%  fprintf([cr xname ' = \n' cr]);
% end
fprintf(cr);

[nr,nc] = size(P);

if max(nr,nc) > 1
  
 % Vector or matrix
 
 fprintf([int2str(nr) '-by-' int2str(nc)]);
 if min(nr,nc) == 1
  fprintf(' vector');
 else
  fprintf(' matrix');
 end
 fprintf([' of moment SDP problems\n']);
 
end

% Display information on the problems
 
for r = 1:nr
 for c = 1:nc
   
  fprintf('Moment SDP problem ');

  if max(nr,nc) > 1

   if nr == 1
    fprintf(int2str(c));
   elseif nc == 1
    fprintf(int2str(r));
   else
    fprintf(['(' int2str(r) ',' int2str(c) ')']);
   end
  end
 
  fprintf('\n');
  
  if length(P(r,c).indmeas) > 1
   disp(['  Measure labels            = ' int2str(P(r,c).indmeas)]);
   disp(['  Relaxation orders         = ' int2str(P(r,c).order)]);
  else
   disp(['  Measure label             = ' int2str(P(r,c).indmeas)]);
   disp(['  Relaxation order          = ' int2str(P(r,c).order)]);
  end
  disp(['  Decision variables        = ' int2str(length(P(r,c).b))]);
  if P(r,c).K.f > 0
   disp(['  Linear equalities         = ' int2str(P(r,c).K.f)]); 
  end
  if P(r,c).K.l > 0
   disp(['  Linear inequalities       = ' int2str(P(r,c).K.l)]); 
  end
  if P(r,c).K.q > 0
   disp(['  Quadratic inequalities    = ' int2str(P(r,c).K.q)]);
  end;   
  fprintf('  Semidefinite inequalities = ');
  if ~isempty(P(r,c).K.s)
   nr = P(r,c).K.s(1); oldnr = nr;
   rep = 1; first = true;
   if length(P(r,c).K.s) == 1
    fprintf('%dx%d',nr,nr);
   else
    for k = 2:length(P(r,c).K.s)+1
     if k == length(P(r,c).K.s)+1;
      nr = 0;
     else
      nr = P(r,c).K.s(k);
     end
     if nr ~= oldnr
      if ~first
       fprintf('+');
      else
       first = false;
      end
      if rep == 1
       fprintf('%dx%d',oldnr,oldnr);
      else
       fprintf('%dx(%dx%d)',rep,oldnr,oldnr);
       rep = 1;
      end
      oldnr = nr;
     else
      rep = rep+1;
     end
    end
   end
   fprintf('\n');
  else
   fprintf('0\n');
  end

 end
end

fprintf(cr)
