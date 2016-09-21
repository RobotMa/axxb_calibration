function [J,c]=Inclin1(E1,MA,MB,MX0)



for j=1:6
    M=MA*MX0*E1(:,:,j)-MX0*E1(:,:,j)*MB;
    m=vec(M);
    for i=1:16
       J(i,j)=m(i);
    end 
end

M=MX0*MB-MA*MX0;
c=vec(M);

end