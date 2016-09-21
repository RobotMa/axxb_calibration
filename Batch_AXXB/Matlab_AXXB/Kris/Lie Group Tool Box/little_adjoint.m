function [ad] = little_adjoint(X,type)
%[ad] = little_adjoint(X,type)
% Inputs:
% X - Lie Algebra of Either SE(2) or SE(3)
% type - 1 for SE(2) and 2 for SE(3)
%
% Output - little adjoint matrix [ad]

if type == 1 %SE(2)
E1  = hat([1 0 0]);
E2 = hat([0 1 0]);
E3 = hat([0 0 1]);

ad = zeros(3,3);
ad(:,1) = vee(LieBracket(X,E1))';
ad(:,2) = vee(LieBracket(X,E2))';
ad(:,3) = vee(LieBracket(X,E3))';

elseif type == 2 %SE(3)
E1 = hat2([1 0 0 0 0 0]);
E2 = hat2([0 1 0 0 0 0]);
E3 = hat2([0 0 1 0 0 0]);
E4 = hat2([0 0 0 1 0 0]);
E5 = hat2([0 0 0 0 1 0]);
E6 = hat2([0 0 0 0 0 1]);

ad = zeros(6,6);
ad(:,1) = vee(LieBracket(X,E1))';
ad(:,2) = vee(LieBracket(X,E2))';
ad(:,3) = vee(LieBracket(X,E3))';
ad(:,4) = vee(LieBracket(X,E4))';
ad(:,5) = vee(LieBracket(X,E5))';
ad(:,6) = vee(LieBracket(X,E6))';

end