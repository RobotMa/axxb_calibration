function [A_filt, A_bad, B_filt, B_bad, best, Thresh_v]=allFilter(A, B, thresh_t, thresh_d, thresh_v)

A_filt=[];
A_bad=[];
B_filt=[];
B_bad=[];
best=0;

maxThresh=0;
for k=1:size(A,3)
    
    [thetaa(k), Na(:,:,k), da(k), pa(1:3,k)]=param_extract(A(:,:,k));
    [thetab(k), Nb(:,:,k), db(k), pb(1:3,k)]=param_extract(B(:,:,k));
    
%     if (abs(thetaa(k)-thetab(k))<0.0000001)
%         k
% 
%     end
    
    
    Thresh_t(k)=exp(-abs(thetaa(k)-thetab(k)));
    
    if (Thresh_t(k)>thresh_t)
        Check(1,k)=1;
        
        if (Thresh_t(k)>maxThresh)
            best=k;
            maxThresh=Thresh_t;
        end
    else
        Check(1,k)=0;
    end
    
%     Thresh_d(k)=exp(-abs(da(k)-db(k)));
    
%     if (Thresh_d(k)>thresh_d)
%         Check(2,k)=1;
%     else
%         Check(2,k)=0;
%     end
%     
%     Thresh_td(k)=exp(-abs(thetaa(k)-thetab(k)))*exp(-0.05*abs(da(k)-db(k)));
%     
%     if (Thresh_td(k)>maxThresh)
%         best=k;
%         maxThresh=Thresh_td;
%     end
    
end


for i = 1:1:size(A,3)
    
    [deltaA(i), ~, ~, ~]=deltaPhiCalc(A(:,:,best),A(:,:,i));
    [deltaB(i), ~, ~, ~]=deltaPhiCalc(B(:,:,best),B(:,:,i));
    
    Thresh_v(i)=abs(deltaA(i)-deltaB(i));
    
    if (Thresh_v(i)<thresh_v)
        Check(2,i)=0;
    else
        Check(2,i)=0;
    end
end


count=0;
count2=0;
for j=1:size(A,3)
   
    if sum(Check(:,j))>=1
        count=count+1;
        A_filt(:,:,count)=A(:,:,j);
        B_filt(:,:,count)=B(:,:,j);
    else
        count2=count2+1;
        A_bad(:,:,count2)=A(:,:,j);
        B_bad(:,:,count2)=B(:,:,j);
    end
    
    
end
% ts=sum(Check(1,:))
% vs=sum(Check(2,:))
% all=sum(ismember(Check',[1 1], 'rows'))




