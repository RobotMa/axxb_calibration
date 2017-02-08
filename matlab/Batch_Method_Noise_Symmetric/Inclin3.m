function [J1,J2,J,c1,c2,c]=Inclin3(E1,E2,MA,MB,MX0,SigX0,SigA,SigB)


sk1=[0 0 0; 0 0 -1; 0 1 0];
sk2=[0 0 1; 0 0 0; -1 0 0];
sk3=[0 -1 0; 1 0 0; 0 0 0];


adE1(:,:,1)=[sk1, zeros(3,3); zeros(3,3), sk1]; 
adE1(:,:,2)=[sk2, zeros(3,3); zeros(3,3), sk2];
adE1(:,:,3)=[sk3, zeros(3,3); zeros(3,3), sk3];
adE1(:,:,4)=[zeros(3,3), zeros(3,3); sk1, zeros(3,3)];
adE1(:,:,5)=[zeros(3,3), zeros(3,3); sk2, zeros(3,3)];
adE1(:,:,6)=[zeros(3,3), zeros(3,3); sk3, zeros(3,3)];

for j=1:6
    M1=MA*MX0*E1(:,:,j)-MX0*E1(:,:,j)*MB;
    m1=vec(M1(1:3,1:4));
    J1(:,j)=m1;
end

M1=MX0*MB-MA*MX0;
c1=vec(M1(1:3,1:4));

for j=1:6

    M2=-adE1(:,:,j)*SE3_Ad(MX0^-1)*SigA*SE3_Ad(MX0^-1)'-SE3_Ad(MX0^-1)*SigA*SE3_Ad(MX0^-1)*adE1(:,:,j);
    m2=vec(M2);
    J2(:,j)=m2;

end

M2=SE3_Ad(MX0^-1)*SigA*SE3_Ad(MX0^-1)'-SE3_Ad(MB^-1)*SigX0*SE3_Ad(MB^-1)'-SigX0-SigB;
c2=vec(M2);


J=[J1; J2];
c=cat(1,c1,c2);



end