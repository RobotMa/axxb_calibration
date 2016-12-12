clear;clc;close all;


std=0.01;
gmean=0;


%-----------Independently from Normal Distribution------------
for i=1:100
    
    noise_old(i)=std*randn(1,1)+gmean;
    
end

figure
plot((1:length(noise_old)), noise_old)
%--------------------------------------------------------------


%-----------Coupling Matrix------------------------------------


C=zeros(100*6);

for i=1:100
    if((i-3)>=0)
        C((i-1)*6+1:(i)*6,(i-3)*6+1:(i-2)*6)=eye(6).*0.5;
    end
    if((i-2)>=0)
        C((i-1)*6+1:(i)*6,(i-2)*6+1:(i-1)*6)=eye(6).*0.75;
    end
    C((i-1)*6+1:(i)*6,(i-1)*6+1:(i)*6)=eye(6);
    if((i+1)<=100)
        C((i-1)*6+1:(i)*6,(i)*6+1:(i+1)*6)=eye(6).*0.75;
    end
    if((i+2)<=100)
        C((i-1)*6+1:(i)*6,(i+1)*6+1:(i+2)*6)=eye(6).*0.5;
    end
end

noise_old=std*randn(6*100,1)+gmean;

noise_new=C*noise_old;
count=0;

for i=1:size(noise_old, 1)
    
    if mod(i,6)==1
        count=count+1;
    noise1(count)=noise_old(i,1);
    end
end

figure
plot((1:length(noise1)), noise1)

%--------------------------------------------------------------





%-----------Wiener Process------------------------------------

noise_old=std*randn(6,100)+gmean;


for i=1:100
    
    noise_new(1:6,i)=sum(noise_old(1:6,1:i),2).*(1/sqrt(i));
    
    
end

figure
plot((1:length(noise_new(1,:))), noise_new(1,:))
%---------------------------------------------------------------

    
