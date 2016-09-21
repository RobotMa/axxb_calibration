function [X] = sym_skew(x)
%[X] = sym_skew(x)

l = x;
l1 = l(1);
l2 = l(2);
l3 = l(3);

X = [0 -l3 l2; l3 0 -l1;-l2 l1 0];
