function [delta_v1 delta_v2 phi_v1 phi_v2]=deltaPhiCalc(A1,A2)

i=1;
j=2;

[~, N(:,:,i), ~, p(1:3,i)]=param_extract(A1);
[~, N(:,:,j), ~, p(1:3,j)]=param_extract(A2);
n(:,i)=so3_vec(N(:,:,i));
n(:,j)=so3_vec(N(:,:,j));





delta_v1=abs(dot(n(:,i),cross(n(:,j),(p(:,j)-p(:,i)))))/norm(cross(n(:,i),n(:,j)));

delta_v2=norm((eye(3)+((n(:,j)*n(:,j)'-n(:,i)*n(:,i)')/(1-dot(n(:,i),n(:,j))^2)))*(p(:,j)-p(:,i)));


phi_v1=atan2(dot(n(:,i),n(:,j)), delta_v1^-1*dot(n(:,i),cross(n(:,j),(p(:,j)-p(:,i)))));


temp1=(n(:,i)*n(:,i)'+dot(n(:,i),n(:,j))*n(:,i)*n(:,j)')/(1-dot(n(:,i), n(:,j))^2);
q(:,i)=p(:,i)+temp1*(p(:,j)-p(:,i));

temp2=(n(:,j)*n(:,j)'+dot(n(:,i),n(:,j))*n(:,i)*n(:,j)')/(1-dot(n(:,i), n(:,j))^2);
q(:,j)=p(:,j)+temp2*(p(:,j)-p(:,i));

n3=(q(:,j)-q(:,i))/norm(q(:,j)-q(:,i));

phi_v2=atan2((cross(n3,n(:,i))'*n(:,j)), (n(:,i)'*n(:,j)));



end