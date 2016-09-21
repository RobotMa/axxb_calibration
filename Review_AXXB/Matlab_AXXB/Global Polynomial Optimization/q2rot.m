function R = q2rot(q)

w = q(1);
x = q(2);
y = q(3);
z = q(4);

Nq = w^2 + x^2 + y^2 + z^2;

if Nq > 0.0 
    s = 2/Nq; 
else
    s = 0.0;
end

X = x*s; Y = y*s; Z = z*s;
wX = w*X; wY = w*Y; wZ = w*Z;
xX = x*X; xY = x*Y; xZ = x*Z;
yY = y*Y; yZ = y*Z; zZ = z*Z;

R=zeros(3);
R(1,1:3) = [ 1.0-(yY+zZ)       xY-wZ        xZ+wY  ];
R(2,1:3) = [      xY+wZ   1.0-(xX+zZ)       yZ-wX  ];
R(3,1:3) = [      xZ-wY        yZ+wX   1.0-(xX+yY) ];
   
