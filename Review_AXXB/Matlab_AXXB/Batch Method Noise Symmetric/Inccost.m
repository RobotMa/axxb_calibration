function [c]=Inccost(MA,MB,X_solved,SigA,SigB,SigX,W01,W02,W1,W2)



K1=MA-(X_solved)*MB*(X_solved)^-1;
K2=SigA-SE3_Ad(X_solved)*((SigX)+SigB+SE3_Ad(MB^-1)*(SigX)*SE3_Ad(MB^-1)')*SE3_Ad(X_solved)';
K3=X_solved;
K4=SigX;



c=trace(K1*W01*K1')+trace(K2*W02*K2')+trace(K3*W1*K3')+trace(K4*W2*K4');
% c=trace(K1*W01*K1')+trace(K2*W02*K2')+trace(K4*W2*K4');



end