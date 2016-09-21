function [c]=LGcost(MA,MB,X_solved,SigA,SigB,SigX,H,T,W01,W02,W1,W2)



K1=MA-(X_solved*H)*MB*((X_solved*H)^(-1));
K2=SigA-SE3_Ad(X_solved*H)*((T*SigX*T')+SigB+SE3_Ad(MB^-1)*(T*SigX*T')*(SE3_Ad(MB^-1)'))*(SE3_Ad(X_solved*H)');
K3=X_solved*H;
K4=T*SigX*(T');



c=trace(K1*W01*(K1'))+trace(K2*W02*(K2'))+trace(K3*W1*(K3'))+trace(K4*W2*(K4'));
% c=trace(K1*W01*K1')+trace(K2*W02*K2')+trace(K3*W1*K3');
% c=1e20*trace(K1*W01*(K1'))*trace(K2*W02*(K2'));




end