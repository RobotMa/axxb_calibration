%Gradient Descent to find the Mean (Using backtracking for step size)
function [M, Sig]=distibutionPropsGrad(X)

h = waitbar(0,'computing initial estimate','Name','Calculating Distribution Properties...',...
    'CreateCancelBtn',...
    'setappdata(gcbf,''canceling'',1)');
setappdata(h,'canceling',0)


%initial values-----------------
C=[];
delta=1e-8;
b=0.5;
eps=1;

E(:,:,1)=[0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0]; E(:,:,2)=[0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0]; E(:,:,3)=[0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
E(:,:,4)=[0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0]; E(:,:,5)=[0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]; E(:,:,6)=[0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
%-------------------------------


%Minitial-----------------------
Xsum=zeros(4);
for j=1:size(X,3)
    Xsum=Xsum+logm(X(:,:,j));
end
M=expm((1/size(X,3))*Xsum);
%-------------------------------

%Initial Cost-------------------
Mnewsum=zeros(4);
for k=1:size(X,3)
    Mnewsum=Mnewsum+logm(M^-1*X(:,:,k));
end
C(1)=norm(Mnewsum)^2;
%-------------------------------

%Gradient Descent until cost is practically zero (<e-15)
while C(end)>1e-15
    
    %For a gradient stepsize "eps"
    while(1==1)
        
        %Calculate the numerical gradient
        for j=1:6
            Mnew(:,:,j)=M(:,:,end)*expm(delta*E(:,:,j));
            Mnewsum=zeros(4);
            for k=1:size(X,3)
                Mnewsum=Mnewsum+logm(Mnew(:,:,j)^-1*X(:,:,k));
            end
            C_coord(j)=norm(Mnewsum)^2;
            grad(j)=(C_coord(j)-C(end))/delta;
        end
        
        %step along the gradient by stepsize "eps"
        Mstep=M(:,:,end)*expm(-eps*se3_vec(grad));
        Mstepsum=zeros(4);
        for k=1:size(X,3)
            Mstepsum=Mstepsum+logm(Mstep^-1*X(:,:,k));
        end
        
        %calculate the cost of the step
        C(end+1)=norm(Mstepsum)^2;
        
        %If the new cost is less than the previous cost, step is successful
        %- save the new value of mean. Otherwise, go back a step and reduce
        %the step size.
        if C(end)<C(end-1)
            M(:,:,end+1)=Mstep;
            C(end)
        else
            if size(M,3)>1
                M(:,:,end)=[];
                C(end-1:end)=[];
                break;
            else
                C(end)=[];
                break;
            end
        end
        
        % Report current estimate in the waitbar's message field
        waitbar(0,h,sprintf('C=%12.5e and eps=%12.5e',C(end),eps))
        
    end
    
    %reduce stepsize
    eps=b*eps
    
    % Check for Cancel button press
    if getappdata(h,'canceling')
        break
    end
    
end
delete(h);

M=M(:,:,end);

Sig=zeros(6,6);

for i=1:size(X,3)
    
    Sig=Sig+se3_vec(logm(M^(-1)*X(:,:,i)))*se3_vec(logm(M^(-1)*X(:,:,i)))';
    
end

Sig=Sig*(1/(size(X,3)-1));

end