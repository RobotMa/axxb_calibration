function [E] = Perm3b3(val)
%[E] = Perm6b6(val)
% Generates a 6x6 permuation matrix that maps vee(x) to vee(x') where x is
% a 36x1 vector

E = eye(9,9);

%Define Vectors for Swapping
for cfl = 1 : 1
E2 = E(:,2);
E4 = E(:,4);

E7 = E(:,7);
E3 = E(:,3);

E8 = E(:,8);
E6 = E(:,6);

end %Collapsable For Loop

%Exchange Columns
for cfl = 1 : 1
E(:,2) = E4;
E(:,4) = E2;

E(:,3) = E7;
E(:,7) = E3;

E(:,8) = E6;
E(:,6) = E8;

end %Collapsable For Loop

