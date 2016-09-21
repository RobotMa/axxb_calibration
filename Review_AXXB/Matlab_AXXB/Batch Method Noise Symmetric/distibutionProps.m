%Coordinate Descent to find the Mean (Using backtracking for step size)
function [M, Sig]=distibutionProps(X)

h = waitbar(0,'computing initial estimate','Name','Calculating Distribution Properties...');%,...
%             'CreateCancelBtn',...
%             'setappdata(gcbf,''canceling'',1)');
% setappdata(h,'canceling',0)



%initial values-----------------
C=[];
b=0.5;
stopThresh=1e-10;

E(:,:,1)=[0 0 0 0; 0 0 -1 0; 0 1 0 0; 0 0 0 0]; E(:,:,2)=[0 0 1 0; 0 0 0 0; -1 0 0 0; 0 0 0 0]; E(:,:,3)=[0 -1 0 0; 1 0 0 0; 0 0 0 0; 0 0 0 0];
E(:,:,4)=[0 0 0 1; 0 0 0 0; 0 0 0 0; 0 0 0 0]; E(:,:,5)=[0 0 0 0; 0 0 0 1; 0 0 0 0; 0 0 0 0]; E(:,:,6)=[0 0 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
E(:,:,7:12) = -E(:,:,1:6);
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

%set the initial eps value at the initial cost
eps=C(1);

%Coordinate Descent until cost is practically zero (<e-10)
while C(end)>stopThresh
    
    count=0;
    %For a stepize of "eps"
    while(count<100)
        count=count+1;
        %Calculate cost along each coordinate direction
        Cset=zeros(12,1);
        for j=1:12
            Mnew(:,:,j)=M(:,:,end)*expm(eps*E(:,:,j));
            Mnewsum=zeros(4);
            for k=1:size(X,3)
                Mnewsum=Mnewsum+logm(Mnew(:,:,j)^-1*X(:,:,k));
            end
            Cset(j)=norm(Mnewsum)^2;
        end
        
        %choose the coordinate direction with minimum cost
        [C(end+1), indx]=min(Cset);
        
        %If the new cost is less than the previous cost, step is successful
        %- save the new value of mean. Otherwise, go back a step and reduce
        %the step size.
        if C(end)<C(end-1)
            M(:,:,end+1)=Mnew(:,:,indx);
%             C(end)
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
        waitbar((20+log(stopThresh/C(end)))/20,h,sprintf('C=%12.5e and eps=%12.5e',C(end),eps))
        
    end
    
    %reduce stepsize
    eps=b*eps;
    
%     % Check for Cancel button press
%     if getappdata(h,'canceling')
%         break
%     end
    
end
delete(h);

M=M(:,:,end);

Sig=zeros(6,6);

for i=1:size(X,3)
    
    Sig=Sig+se3_vec(logm(M^(-1)*X(:,:,i)))*se3_vec(logm(M^(-1)*X(:,:,i)))';
    
end

Sig=Sig*(1/(size(X,3)-1));

end