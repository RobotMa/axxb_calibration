

x=randn(6,1); X=expm(se3_vec(x));


noise=0.05;


for i=1:10
    
    
%     SigX=eye(6);
%     T=0.1*randn(6,6);
%     SigX=T*SigX*T';
%     x_1=SigX^.5*randn(6,1);    
%     x_2=SigX^.5*randn(6,1);

    x_1=noise*randn(6,1);
    
    
    X_new(:,:,i)=X*expm(se3_vec(x_1));
    
end

% for i=1:size(X_new,3)
%     
%     Xinv_new(:,:,i)=X_new(:,:,i)^-1;
%     
% end
% 
% X_set=cat(3, X_new, Xinv_new);

X_set=X_new;

% [Minitial, MX, SigX]=distibutionProps2(X_set, X);

SigXhypoth=diag(noise^2*ones(6,1));


Sig=zeros(6,6);

for i=1:size(X_new,3)
    
    Sig=Sig+se3_vec(logm(X^(-1)*X_new(:,:,i)))*se3_vec(logm(X^(-1)*X_new(:,:,i)))';
    
end

SigXtrue=Sig*(1/(size(X_new,3)-1));

norm(SigXtrue-SigXhypoth)/norm(SigXhypoth)


