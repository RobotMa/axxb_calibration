%Function to add Gaussian noise to a g \in SE(3)

%files needed:
%se3_vec().m

function g_noise=sensorNoise(g, gmean, std, model)


switch model
    case 1
        
        %-----------Independently from Normal Distribution------------
        for i=1:size(g,3)
            
            temp=randn(3,1);
            
            noise_old1=[0*randn(3,1); std*randn(3,1)]+gmean;
            noise_old2=[std*randn(3,1); 0*randn(3,1)]+gmean;
            
            Delta(:,:,i)=expm(se3_vec(noise_old1))*expm(se3_vec(noise_old2));
            
            g_noise(:,:,i)=g(:,:,i)*Delta(:,:,i);
            
        end
        %--------------------------------------------------------------
        
    case 2
        
        %-----------Coupling Matrix------------------------------------
        
        
        C=zeros(size(g,3)*6);
        
        for i=1:size(g,3)
            if((i-3)>=0)
                C((i-1)*6+1:(i)*6,(i-3)*6+1:(i-2)*6)=eye(6).*0.25;
            end
            if((i-2)>=0)
                C((i-1)*6+1:(i)*6,(i-2)*6+1:(i-1)*6)=eye(6).*0.5;
            end
            C((i-1)*6+1:(i)*6,(i-1)*6+1:(i)*6)=eye(6);
            if((i+1)<=size(g,3))
                C((i-1)*6+1:(i)*6,(i)*6+1:(i+1)*6)=eye(6).*0.5;
            end
            if((i+2)<=size(g,3))
                C((i-1)*6+1:(i)*6,(i+1)*6+1:(i+2)*6)=eye(6).*0.25;
            end
        end
        
        noise_old=std*randn(6*size(g,3),1)+gmean;
        
        noise_new=C*noise_old;
        
        for i=1:size(g,3)
            
            g_noise(:,:,i)=g(:,:,i)*expm(se3_vec(noise_new((i-1)*6+1:i*6,1)));
            
        end
        %--------------------------------------------------------------
        
    case 3
        
        %-----------Wiener Process------------------------------------
        
        noise_old=std*randn(6,size(g,3))+gmean;
        
        
        for i=1:size(g,3)
            
            noise_new(1:6,i)=sum(noise_old(1:6,1:i),2).*(1/sqrt(i));
            
            g_noise(:,:,i)=g(:,:,i)*expm(se3_vec(noise_new(1:6,i)));
            
        end
        %---------------------------------------------------------------
        
    case 4
        
        %-----------plucker nudge------------------------------------
        
        for i=1:size(g,3)
            
            [thetag(i), Ng(:,:,i), dg(i), pg(1:3,i)]=param_extract(g(:,:,i));
            
            thetag2(i)=thetag(i)+std*randn;
            Ng2(:,:,i)=so3_vec(so3_vec(Ng(:,:,i))+[std*randn; std*randn; std*randn]/norm(so3_vec(Ng(:,:,i))+[std*randn; std*randn; std*randn]));
            Rg2(:,:,i)=expm(thetag2(i).*Ng2(:,:,i));
            tg2(:,i)=g(1:3,4,i)+[std*randn;std*randn;std*randn];
            dg2(i)=dot(tg2(:,i),so3_vec(Ng2(:,:,i)));
            
            n=so3_vec(Ng2(:,:,i));
            u=1/sqrt(n(1)^2+n(2)^2)*[-n(2); n(1); 0];
            c=linsolve([1-cos(thetag2(i)) sin(thetag2(i)); -sin(thetag2(i)) 1-cos(thetag2(i))], [dot(tg2(:,i),u); dot(tg2(:,i),(cross(n,u)))]);
            
            pg2(1:3,i)=c(1)*u+c(2)*cross(n,u);
            
            
            
            g_noise(:,:,i)=[expm(thetag2(i)*Ng2(:,:,i)) (eye(3)-expm(thetag2(i)*Ng2(:,:,i)))*pg2(1:3,i)+dg2(i).*so3_vec(Ng2(:,:,i)); zeros(1,3) 1];
            
            %             dot(pg2(1:3,i),so3_vec(Ng2(:,:,i)))
            %             dg2(i)==dot(g_noise(1:3,4,i),so3_vec(Ng2(:,:,i)))
        end
        %---------------------------------------------------------------
        
    case 5
        
        %-----------outlier noise-----------------------------------
        
        for i=1:size(g,3)
            
            if mod(i,10)==1
                
                temp=randn(3,1);
                
                noise_old1=[0*randn(3,1); 0.1*randn(3,1)]+gmean;
                noise_old2=[0.01*(temp/norm(temp)); 0*randn(3,1)]+gmean;
                
                g_noise(:,:,i)=g(:,:,i)*expm(se3_vec(noise_old1))*expm(se3_vec(noise_old2));
                
                
                %             elseif ((i==12) || (i==13))
                %                 g_noise(:,:,i)=g(:,:,i);
                
            else
                noise_old1=[std*randn(3,1); 0*std*randn(3,1)]+gmean;
                noise_old2=[0*std*randn(3,1); std*randn(3,1)]+gmean;
                
                g_noise(:,:,i)=g(:,:,i)*expm(se3_vec(noise_old1))*expm(se3_vec(noise_old2));
            end
            
        end
        %---------------------------------------------------------------
        
            
            
    otherwise
        disp('error');
end




end