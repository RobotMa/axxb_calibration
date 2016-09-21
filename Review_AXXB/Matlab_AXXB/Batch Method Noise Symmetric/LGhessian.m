function [He, grad]=LGhessian(E1,E2,MA,MB,MX0,SigA,SigB,SigX,H,T,W01,W02,W1,W2)

He=zeros(42,42);

delta=5e-10;
e1=[1,1,1,1,1,1]*1e-8;
e2=1e-8;



cost=LGcost(MA,MB,MX0,SigA,SigB,SigX,H,T,W01,W02,W1,W2);



for i=1:6
    
    Hnew=H*expm(delta*E1(:,:,i));
    
    grad(i,1)=(LGcost(MA,MB,MX0,SigA,SigB,SigX,Hnew,T,W01,W02,W1,W2)-LGcost(MA,MB,MX0,SigA,SigB,SigX,H,T,W01,W02,W1,W2))/delta;
    
    
    
end

for i=1:36
    
    Tnew=T*expm(delta*E2(:,:,i));
    
    grad(i+6,1)=(LGcost(MA,MB,MX0,SigA,SigB,SigX,H,Tnew,W01,W02,W1,W2)-LGcost(MA,MB,MX0,SigA,SigB,SigX,H,T,W01,W02,W1,W2))/delta;
    
    
    
end





for i=1:42
    for j=1:42
        if(i<=j)
            if(i<7 && j<7)
                H1=H*expm(delta*E1(:,:,i))*expm(delta*E1(:,:,j));
                H2=H*expm(delta*E1(:,:,i))*expm(-delta*E1(:,:,j));
                H3=H*expm(-delta*E1(:,:,i))*expm(delta*E1(:,:,j));
                H4=H*expm(-delta*E1(:,:,i))*expm(-delta*E1(:,:,j));
                T1=T;
                T2=T;
                T3=T;
                T4=T;
            elseif (i<7 && j>=7)
                H1=H*expm(delta*E1(:,:,i));
                H2=H*expm(delta*E1(:,:,i));
                H3=H*expm(-delta*E1(:,:,i));
                H4=H*expm(-delta*E1(:,:,i));
                T1=T*expm(delta*E2(:,:,j-6));
                T2=T*expm(-delta*E2(:,:,j-6));
                T3=T*expm(delta*E2(:,:,j-6));
                T4=T*expm(-delta*E2(:,:,j-6));
            elseif (i>=7 && j<7)
                H1=H*expm(delta*E1(:,:,j));
                H2=H*expm(-delta*E1(:,:,j));
                H3=H*expm(delta*E1(:,:,j));
                H4=H*expm(-delta*E1(:,:,j));
                T1=T*expm(delta*E2(:,:,i-6));
                T2=T*expm(delta*E2(:,:,i-6));
                T3=T*expm(-delta*E2(:,:,i-6));
                T4=T*expm(-delta*E2(:,:,i-6));
            elseif (i>=7 && j>=7)
                H1=H;
                H2=H;
                H3=H;
                H4=H;
                T1=T*expm(delta*E2(:,:,i-6))*expm(delta*E2(:,:,j-6));
                T2=T*expm(delta*E2(:,:,i-6))*expm(-delta*E2(:,:,j-6));
                T3=T*expm(-delta*E2(:,:,i-6))*expm(delta*E2(:,:,j-6));
                T4=T*expm(-delta*E2(:,:,i-6))*expm(-delta*E2(:,:,j-6));
            end
            
            He(i,j)=He(i,j)+0.5*(LGcost(MA,MB,MX0,SigA,SigB,SigX,H1,T1,W01,W02,W1,W2)-LGcost(MA,MB,MX0,SigA,SigB,SigX,H2,T2,W01,W02,W1,W2)-LGcost(MA,MB,MX0,SigA,SigB,SigX,H3,T3,W01,W02,W1,W2)+LGcost(MA,MB,MX0,SigA,SigB,SigX,H4,T4,W01,W02,W1,W2))/(4*delta^2);
            
            
            if(i<7 && j<7)
                H1=H*expm(delta*E1(:,:,j))*expm(delta*E1(:,:,i));
                H2=H*expm(delta*E1(:,:,j))*expm(-delta*E1(:,:,i));
                H3=H*expm(-delta*E1(:,:,j))*expm(delta*E1(:,:,i));
                H4=H*expm(-delta*E1(:,:,j))*expm(-delta*E1(:,:,i));
                T1=T;
                T2=T;
                T3=T;
                T4=T;
            elseif (i<7 && j>=7)
                H1=H*expm(delta*E1(:,:,i));
                H2=H*expm(-delta*E1(:,:,i));
                H3=H*expm(delta*E1(:,:,i));
                H4=H*expm(-delta*E1(:,:,i));
                T1=T*expm(delta*E2(:,:,j-6));
                T2=T*expm(delta*E2(:,:,j-6));
                T3=T*expm(-delta*E2(:,:,j-6));
                T4=T*expm(-delta*E2(:,:,j-6));
            elseif (i>=7 && j<7)
                H1=H*expm(delta*E1(:,:,j));
                H2=H*expm(delta*E1(:,:,j));
                H3=H*expm(-delta*E1(:,:,j));
                H4=H*expm(-delta*E1(:,:,j));
                T1=T*expm(delta*E2(:,:,i-6));
                T2=T*expm(-delta*E2(:,:,i-6));
                T3=T*expm(delta*E2(:,:,i-6));
                T4=T*expm(-delta*E2(:,:,i-6));
            elseif (i>=7 && j>=7)
                H1=H;
                H2=H;
                H3=H;
                H4=H;
                T1=T*expm(delta*E2(:,:,j-6))*expm(delta*E2(:,:,i-6));
                T2=T*expm(delta*E2(:,:,j-6))*expm(-delta*E2(:,:,i-6));
                T3=T*expm(-delta*E2(:,:,j-6))*expm(delta*E2(:,:,i-6));
                T4=T*expm(-delta*E2(:,:,j-6))*expm(-delta*E2(:,:,i-6));
            end
            
            He(i,j)=He(i,j)+0.5*(LGcost(MA,MB,MX0,SigA,SigB,SigX,H1,T1,W01,W02,W1,W2)-LGcost(MA,MB,MX0,SigA,SigB,SigX,H2,T2,W01,W02,W1,W2)-LGcost(MA,MB,MX0,SigA,SigB,SigX,H3,T3,W01,W02,W1,W2)+LGcost(MA,MB,MX0,SigA,SigB,SigX,H4,T4,W01,W02,W1,W2))/(4*delta^2);
            
        end
    end
end

He=He+triu(He,1)';

end