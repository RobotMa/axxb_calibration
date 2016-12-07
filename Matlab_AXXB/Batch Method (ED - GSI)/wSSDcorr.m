function [lags, corr]=wSSDcorr(sigA,sigB, window)

n=length(sigA);


for i = 0:2*n-2
    

    lags(i+1)=-(n-1)+(i-1);
    
    if i<n
    corr(i+1) = sum((sigA(n-i:n)-sigB(1:i+1)).^2)/length(sigA(n-i:n));
    end
    
    if i>=n  
    corr(i+1) = sum((sigA(1:2*n-i)-sigB(i-(n-1):n)).^2)/length(sigA(1:2*n-i));    
    end
    
end


corr(1:floor(length(corr)*(0.5-window/2))) = max(corr).*ones(1,length(corr(1:floor(length(corr)*(0.5-window/2)))));
corr(floor(length(corr)*(0.5+window/2)):end) = max(corr).*ones(1,length(corr(floor(length(corr)*(0.5+window/2)):end)));


end