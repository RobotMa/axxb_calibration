function [E] = Perm6b6(val)
%[E] = Perm6b6(val)
% Generates a 6x6 permuation matrix that maps vee(x) to vee(x') where x is
% a 36x1 vector

E = eye(36,36);

%Define Vectors for Swapping
for cfl = 1 : 1
E2 = E(:,2);
E7 = E(:,7);

E3 = E(:,3);
E13 = E(:,13);

E4 = E(:,4);
E19 = E(:,19);

E5 = E(:,5);
E25 = E(:,25);

E6 = E(:,6);
E31 = E(:,31);

E9 = E(:,9);
E14 = E(:,14);

E10 = E(:,10);
E20 = E(:,20);

E11 = E(:,11);
E26 = E(:,26);

E12 = E(:,12);
E32 = E(:,32);

E16 = E(:,16);
E21 = E(:,21);

E17 = E(:,17);
E27 = E(:,27);

E18 = E(:,18);
E33 = E(:,33);

E23 = E(:,23);
E28 = E(:,28);

E24 = E(:,24);
E34 = E(:,34);

E30 = E(:,30);
E35 = E(:,35);


end %Collapsable For Loop

%Exchange Columns
for cfl = 1 : 1
E(:,2) = E7;
E(:,7) = E2;

E(:,3) = E13;
E(:,13) = E3;

E(:,4) = E19;
E(:,19) = E4;

E(:,5) = E25;
E(:,25) = E5;

E(:,6) = E31;
E(:,31) = E6;

E(:,9) = E14;
E(:,14) = E9;

E(:,10) = E20;
E(:,20) = E10;

E(:,11) = E26;
E(:,26) = E11;

E(:,12) = E32;
E(:,32) = E12;

E(:,16) = E21;
E(:,21) = E16;

E(:,17) = E27;
E(:,27) = E17;

E(:,18) = E33;
E(:,33) = E18;

E(:,23) = E28;
E(:,28) = E23;

E(:,24) = E34;
E(:,34) = E24;

E(:,30) = E35;
E(:,35) = E30;


end %Collapsable For Loop


% Q = kron(A',eye(size(A)))*E + kron(eye(size(A)),A);
