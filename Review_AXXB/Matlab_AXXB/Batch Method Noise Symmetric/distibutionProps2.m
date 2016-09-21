function [Minitial, M, Sig]=distibutionProps2(X, Xtrue)


Xsum=zeros(4);
for j=1:size(X,3)
    Xsum=Xsum+logm(X(:,:,j));
end

M=expm((1/size(X,3))*Xsum);
Minitial=M;

C_old=0; C=inf;

diff=0.01; eps=1e-4;
E(:,:,1)=[0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0]; E(:,:,2)=[0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0]; E(:,:,3)=[0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
E(:,:,4)=[0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0]; E(:,:,5)=[0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]; E(:,:,6)=[0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
E(:,:,7:12) = -E(:,:,1:6);

for i=1:1000
% while(abs(C-C_old)>diff)
    C_old=C;
    Cset=zeros(12,1);
    
    for j=1:12

        Mnew(:,:,j)=M*expm(eps*E(:,:,j));
        
        
        
        Mnewsum=zeros(4);
        for k=1:size(X,3)
            Mnewsum=Mnewsum+logm(Mnew(:,:,j)^-1*X(:,:,k));      
        end
        
        Cset(j)=norm(Mnewsum)^2;
        
    end
    
    [C, indx]=min(Cset);
    
    Xtrue
    Minitial
    M=Mnew(:,:,indx)
    
end

Sig=zeros(6,6);

for i=1:size(X,3)
    
    Sig=Sig+se3_vec(logm(M^(-1)*X(:,:,i)))*se3_vec(logm(M^(-1)*X(:,:,i)))';
    
end

Sig=Sig*(1/(size(X,3)-1));

end