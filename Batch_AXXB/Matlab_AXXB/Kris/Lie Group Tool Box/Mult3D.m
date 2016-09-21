function [C] = Mult3D(A,B,n)
%[C] = Mult3D(A,B,n)
%A n x n
%B n x n x m
%Applies matrix multiplication to all m "sheets" of B 


if n == 4
C(1,1,:) = A(1,1).*squeeze(B(1,1,:)) + A(1,2).*squeeze(B(2,1,:)) + A(1,3).*squeeze(B(3,1,:)) + A(1,4).*squeeze(B(4,1,:));
C(1,2,:) = A(1,1).*squeeze(B(1,2,:)) + A(1,2).*squeeze(B(2,2,:)) + A(1,3).*squeeze(B(3,2,:)) + A(1,4).*squeeze(B(4,2,:));
C(1,3,:) = A(1,1).*squeeze(B(1,3,:)) + A(1,2).*squeeze(B(2,3,:)) + A(1,3).*squeeze(B(3,3,:)) + A(1,4).*squeeze(B(4,3,:));
C(1,4,:) = A(1,1).*squeeze(B(1,4,:)) + A(1,2).*squeeze(B(2,4,:)) + A(1,3).*squeeze(B(3,4,:)) + A(1,4).*squeeze(B(4,4,:));

C(2,1,:) = A(2,1).*squeeze(B(1,1,:)) + A(2,2).*squeeze(B(2,1,:)) + A(2,3).*squeeze(B(3,1,:)) + A(2,4).*squeeze(B(4,1,:));
C(2,2,:) = A(2,1).*squeeze(B(1,2,:)) + A(2,2).*squeeze(B(2,2,:)) + A(2,3).*squeeze(B(3,2,:)) + A(2,4).*squeeze(B(4,2,:));
C(2,3,:) = A(2,1).*squeeze(B(1,3,:)) + A(2,2).*squeeze(B(2,3,:)) + A(2,3).*squeeze(B(3,3,:)) + A(2,4).*squeeze(B(4,3,:));
C(2,4,:) = A(2,1).*squeeze(B(1,4,:)) + A(2,2).*squeeze(B(2,4,:)) + A(2,3).*squeeze(B(3,4,:)) + A(2,4).*squeeze(B(4,4,:));

C(3,1,:) = A(3,1).*squeeze(B(1,1,:)) + A(3,2).*squeeze(B(2,1,:)) + A(3,3).*squeeze(B(3,1,:)) + A(3,4).*squeeze(B(4,1,:));
C(3,2,:) = A(3,1).*squeeze(B(1,2,:)) + A(3,2).*squeeze(B(2,2,:)) + A(3,3).*squeeze(B(3,2,:)) + A(3,4).*squeeze(B(4,2,:));
C(3,3,:) = A(3,1).*squeeze(B(1,3,:)) + A(3,2).*squeeze(B(2,3,:)) + A(3,3).*squeeze(B(3,3,:)) + A(3,4).*squeeze(B(4,3,:));
C(3,4,:) = A(3,1).*squeeze(B(1,4,:)) + A(3,2).*squeeze(B(2,4,:)) + A(3,3).*squeeze(B(3,4,:)) + A(3,4).*squeeze(B(4,4,:));

C(4,1,:) = A(4,1).*squeeze(B(1,1,:)) + A(4,2).*squeeze(B(2,1,:)) + A(4,3).*squeeze(B(3,1,:)) + A(4,4).*squeeze(B(4,1,:));
C(4,2,:) = A(4,1).*squeeze(B(1,2,:)) + A(4,2).*squeeze(B(2,2,:)) + A(4,3).*squeeze(B(3,2,:)) + A(4,4).*squeeze(B(4,2,:));
C(4,3,:) = A(4,1).*squeeze(B(1,3,:)) + A(4,2).*squeeze(B(2,3,:)) + A(4,3).*squeeze(B(3,3,:)) + A(4,4).*squeeze(B(4,3,:));
C(4,4,:) = A(4,1).*squeeze(B(1,4,:)) + A(4,2).*squeeze(B(2,3,:)) + A(4,3).*squeeze(B(3,4,:)) + A(4,4).*squeeze(B(4,4,:));

elseif n == 3
C(1,1,:) = A(1,1).*squeeze(B(1,1,:)) + A(1,2).*squeeze(B(2,1,:)) + A(1,3).*squeeze(B(3,1,:)); 
C(1,2,:) = A(1,1).*squeeze(B(1,2,:)) + A(1,2).*squeeze(B(2,2,:)) + A(1,3).*squeeze(B(3,2,:)); 
C(1,3,:) = A(1,1).*squeeze(B(1,3,:)) + A(1,2).*squeeze(B(2,3,:)) + A(1,3).*squeeze(B(3,3,:)); 

C(2,1,:) = A(2,1).*squeeze(B(1,1,:)) + A(2,2).*squeeze(B(2,1,:)) + A(2,3).*squeeze(B(3,1,:)); 
C(2,2,:) = A(2,1).*squeeze(B(1,2,:)) + A(2,2).*squeeze(B(2,2,:)) + A(2,3).*squeeze(B(3,2,:));
C(2,3,:) = A(2,1).*squeeze(B(1,3,:)) + A(2,2).*squeeze(B(2,3,:)) + A(2,3).*squeeze(B(3,3,:)); 

C(3,1,:) = A(3,1).*squeeze(B(1,1,:)) + A(3,2).*squeeze(B(2,1,:)) + A(3,3).*squeeze(B(3,1,:)); 
C(3,2,:) = A(3,1).*squeeze(B(1,2,:)) + A(3,2).*squeeze(B(2,2,:)) + A(3,3).*squeeze(B(3,2,:));
C(3,3,:) = A(3,1).*squeeze(B(1,3,:)) + A(3,2).*squeeze(B(2,3,:)) + A(3,3).*squeeze(B(3,3,:));

end