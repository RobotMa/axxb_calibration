%Function to add Gaussian noise to a g \in SE(3)

%files needed:
%se3_vec().m

function [g_noise, MeanNoise, SigNoise]=sensorNoise2(g, gmean, std, model)


switch model
    case 1
        
        %-----------Independently from Normal Distribution------------
        for i=1:size(g,3)
            
            temp=randn(3,1);
            
            noise_old1=[0*randn(3,1); std*randn(3,1)]+gmean;
            noise_old2=[std*(temp/norm(temp)); 0*randn(3,1)]+gmean;
            
            g_noise(:,:,i)=g(:,:,i)*expm(se3_vec(noise_old1))*expm(se3_vec(noise_old2));
            
            Noise(:,:,i)=expm(se3_vec(noise_old1))*expm(se3_vec(noise_old2));
            
        end
        
        [MeanNoise, SigNoise]=distibutionProps(Noise);
        %--------------------------------------------------------------
            
            
    otherwise
        disp('error');
end




end