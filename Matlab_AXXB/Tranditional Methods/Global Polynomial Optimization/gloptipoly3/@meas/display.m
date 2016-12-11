function display(x)
% @MEAS/DISPLAY - Display information on a measure

% D. Henrion, 28 March 2006
% Last modified on 26 March 2010
  
global MMM

% Spacing
if isequal(get(0,'FormatSpacing'),'compact')
 cr = '';
else
 cr = '\n';
end

% Display variable name
% xname = inputname(1);
% if ~isempty(xname)
% fprintf([cr xname ' = \n' cr]);
% end
fprintf(cr);

[nr,nc] = size(x);

if max(nr,nc) > 1
  
 % Vector or matrix
 
 fprintf([int2str(nr) '-by-' int2str(nc)]);
 if min(nr,nc) == 1
  fprintf(' vector');
 else
  fprintf(' matrix');
 end
 fprintf([' of measures\n' cr]);
 
end

% Display information on the measures
 
for r = 1:nr
 for c = 1:nc
 
  if max(nr,nc) > 1
   if nr == 1
    fprintf([int2str(c) ':']);
   elseif nc == 1
    fprintf([int2str(r) ':']);
   else
    fprintf(['(' int2str(r) ',' int2str(c) '):']);
   end
  end

  measx = x(r,c).meas;
  ind = find(MMM.indmeas == measx);
  
  if isempty(ind)
    
   fprintf(['Measure ' int2str(measx) ' not defined\n']);

  else
  
   vars = MMM.var(ind);
   nvar = length(vars);
  
   fprintf(['Measure ' int2str(measx) ' on ' int2str(nvar)]);
   if nvar == 1
    fprintf(' variable: ');
   else
    fprintf(' variables: ');
   end
   fprintf(vars{1});
   for k = 2:length(vars)
    fprintf([',' vars{k}]);
   end
   fprintf('\n');
   if isfield(MMM,'M')
    if length(MMM.M) >= measx
     comma = false;
     if isfield(MMM.M{measx},'ord')
      fprintf(['  with moments of degree up to ' ...
 	    int2str(MMM.M{measx}.ord*2)]);
      comma = true;
     end
     if isfield(MMM.M{measx},'sol')
      if ~isempty(MMM.M{measx}.sol)
       [nr,nc] = size(MMM.M{measx}.sol);
       if nr == nvar
        nsol = nc;
       else
        nsol = nr;
       end
       if comma
	fprintf(',');
       end
       fprintf(['  supported on ' int2str(nsol)]);
       if nsol == 1
        fprintf(' point');
       else
        fprintf(' points');
       end
       comma = true;
      end
     end
     if isfield(MMM.M{measx},'scale')
      if any(MMM.M{measx}.scale ~= 1)
       if comma
	fprintf(',');
       end
       fprintf('  scaled');
       comma = true;
      end
     end
     if comma
      fprintf('\n');
     end
    end
   end
  end
 end
end

fprintf(cr);
