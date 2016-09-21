function [A_VPN, B_VPN]=VPN(A_noise, B_noise, n)


for  i=1:size(B_noise,3)-(n-1)
    
    B_VPN(:,:,i)=eye(4,4);
    
    for j=0:(n-1)
    B_VPN(:,:,i)=B_VPN(:,:,i)*B_noise(:,:,i+j);
    end

end

for  i=1:size(A_noise,3)-(n-1)
    
    A_VPN(:,:,i)=eye(4,4);
    
    for j=0:(n-1)
    A_VPN(:,:,i)=A_VPN(:,:,i)*A_noise(:,:,i+j);
    end
    
end


end