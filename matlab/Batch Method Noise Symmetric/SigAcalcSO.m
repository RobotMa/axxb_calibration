function [SigA]=SigAcalcSO(MB, SigB, MX, SigX)

%--------------fx*fb------------
A=SE3_Ad(MB^-1)*SigX*SE3_Ad(MB^-1)';
B=SigB;




App=[A(1:3,1:3)-trace(A(1:3,1:3))*eye(3), zeros(3,3); A(1:3,4:6)+A(1:3,4:6)'-2*trace(A(1:3,4:6))*eye(3), A(1:3,1:3)-trace(A(1:3,1:3))*eye(3)];
Bpp=[B(1:3,1:3)-trace(B(1:3,1:3))*eye(3), zeros(3,3); B(1:3,4:6)+B(1:3,4:6)'-2*trace(B(1:3,4:6))*eye(3), B(1:3,1:3)-trace(B(1:3,1:3))*eye(3)];


D1111=Dcalc(App(1:3,1:3),Bpp(1:3,1:3));

D2111=Dcalc(App(4:6,1:3),Bpp(1:3,1:3));

D1112=Dcalc(App(1:3,1:3),Bpp(1:3,4:6));

D2211=Dcalc(App(4:6,4:6),Bpp(1:3,1:3));

D2121=Dcalc(App(4:6,1:3),Bpp(4:6,1:3));

D2112=Dcalc(App(4:6,1:3),Bpp(1:3,4:6));

D1122=Dcalc(App(1:3,1:3),Bpp(4:6,4:6));



C=zeros(6,6);

C(1:3,1:3)=-D1111;
C(1:3,4:6)=-(D2111)'-D1112;
C(4:6,1:3)=-(D2111)'-D1112;
C(4:6,4:6)=-D2211-D2121-(D2112)'-D1122;


F=(1/4)*C+(1/12)*(App*B+(App*B)'+Bpp*A+(Bpp*A)');

SigXB=A+B+F;






%---------------()*fx^-1--------------------
A=SE3_Ad(MX)*SigXB*SE3_Ad(MX)';
B=SE3_Ad(MX)*SigX*SE3_Ad(MX)';




App=[A(1:3,1:3)-trace(A(1:3,1:3))*eye(3), zeros(3,3); A(1:3,4:6)+A(1:3,4:6)'-2*trace(A(1:3,4:6))*eye(3), A(1:3,1:3)-trace(A(1:3,1:3))*eye(3)];
Bpp=[B(1:3,1:3)-trace(B(1:3,1:3))*eye(3), zeros(3,3); B(1:3,4:6)+B(1:3,4:6)'-2*trace(B(1:3,4:6))*eye(3), B(1:3,1:3)-trace(B(1:3,1:3))*eye(3)];


D1111=Dcalc(App(1:3,1:3),Bpp(1:3,1:3));

D2111=Dcalc(App(4:6,1:3),Bpp(1:3,1:3));

D1112=Dcalc(App(1:3,1:3),Bpp(1:3,4:6));

D2211=Dcalc(App(4:6,4:6),Bpp(1:3,1:3));

D2121=Dcalc(App(4:6,1:3),Bpp(4:6,1:3));

D2112=Dcalc(App(4:6,1:3),Bpp(1:3,4:6));

D1122=Dcalc(App(1:3,1:3),Bpp(4:6,4:6));



C=zeros(6,6);

C(1:3,1:3)=-D1111;
C(1:3,4:6)=-(D2111)'-D1112;
C(4:6,1:3)=-(D2111)'-D1112;
C(4:6,4:6)=-D2211-D2121-(D2112)'-D1122;


F=(1/4)*C+(1/12)*(App*B+(App*B)'+Bpp*A+(Bpp*A)');

SigA=A+B+F;







end