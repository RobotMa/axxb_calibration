function [J,c]=Inclin1(E1,MA,MB,MX0)



for j=1:6
    M=MA*MX0*E1(:,:,j)-MX0*E1(:,:,j)*MB;
    m=vec(M(1:3,1:4));
    J(:,j)=m;
end

M=MX0*MB-MA*MX0;
c=vec(M(1:3,1:4));

end