function [H,T]=LGgrad(E1,E2,MA,MB,MX0,SigA,SigB,SigX,H,T,W01,W02,W1,W2,eps, delta)

grad1=[];
Grad1=zeros(4,4);
grad2=[];
Grad2=zeros(6,6);


for i=1:6
    
    Hnew=H*expm(delta*E1(:,:,i));
    
    grad1(i,1)=(LGcost(MA,MB,MX0,SigA,SigB,SigX,Hnew,T,W01,W02,W1,W2)-LGcost(MA,MB,MX0,SigA,SigB,SigX,H,T,W01,W02,W1,W2))/delta;
    
    Grad1=Grad1-eps*(grad1(i,1)*E1(:,:,i));
    
    
end

for i=1:36
    
    Tnew=T*expm(delta*E2(:,:,i));
    
    grad2(i+6,1)=(LGcost(MA,MB,MX0,SigA,SigB,SigX,H,Tnew,W01,W02,W1,W2)-LGcost(MA,MB,MX0,SigA,SigB,SigX,H,T,W01,W02,W1,W2))/delta;
    
    Grad2=Grad2-eps*(grad2(i,1)*E2(:,:,i));
    
end


H=H*expm(Grad1);
T=T*expm(Grad2);





end