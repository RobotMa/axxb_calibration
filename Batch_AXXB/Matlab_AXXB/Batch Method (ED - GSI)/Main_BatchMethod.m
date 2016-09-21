% AXXB - Fixing Temporal Misalignment

% Required function list:
% AB_gen().m
% noise_Gauss().m
% param_extract().m
% se3_vec().m
% so3_vec().m

clear; clc; close all;


% Editable Variables
%------------------------------------------------------

num = 50;	% Number of steps

gmean = [0; 0; 0; 0; 0; 0];	% Gaussian Noise Mean

nstd  = 0;	% Gaussian Noise standard deviation Range

shift = 0;  % Step shift

n = 1;      % VP(n)

window = 0; % Target correlation area ??

model = 5;  % Noise model


t2 = (0:(2*pi)/((num+shift)):2*pi);
twist = 0.0*sin(16*t2);

ElipseParam = [10, 20, 30];

%------------------------------------------------------


x = randn(6,1); x = x./norm(x); X = expm(se3_vec(x));    %Generate a Random X



%% Computation Loops
%---------------------------------------------------------------------------------------------------------

A_noise = [];
B = [];

[A, B] = AB_genTraj(X, ElipseParam, num+shift+1, twist);

PA = randperm(size(A,3));
PB = randperm(size(B,3));

A_perm = A(:,:,PA);
B_perm = B(:,:,PB);

Asum = zeros(4);
Bsum = zeros(4);
for j = 1:size(A,3)
    Asum = Asum + logm(A(:,:,j));
    Bsum = Bsum + logm(B(:,:,j));
end

%MA = expm((1/size(A,3))*Asum);
%MB = expm((1/size(B,3))*Bsum);

MA = expm(Asum);
MB = expm(Bsum); 


CAmin = inf;
CBmin = inf;
CA = 0;
CB = 0;

diff = 0.0001;
eps  =  0.001;
E(:,:,1) = [0  0 0 0; 0 0 -1 0;  0 1 0 0; 0 0 0 0]; 
E(:,:,2) = [0  0 1 0; 0 0  0 0; -1 0 0 0; 0 0 0 0]; 
E(:,:,3) = [0 -1 0 0; 1 0  0 0;  0 0 0 0; 0 0 0 0];
E(:,:,4) = [0  0 0 1; 0 0  0 0;  0 0 0 0; 0 0 0 0]; 
E(:,:,5) = [0  0 0 0; 0 0  0 1;  0 0 0 0; 0 0 0 0]; 
E(:,:,6) = [0  0 0 0; 0 0  0 0;  0 0 0 1; 0 0 0 0];

while( abs(CA-CAmin) > diff )
    
    for j = 1:6    
        MA1 = MA*expm( eps*E(:,:,j));
        MA2 = MA*expm(-eps*E(:,:,j));
        
        MA1sum = zeros(4);
        MA2sum = zeros(4);
        for k = 1:size(A,3)
            MA1sum = MA1sum + logm(MA1^-1*A(:,:,k));
            MA2sum = MA2sum + logm(MA2^-1*A(:,:,k));
            
        end
        
        
        CA1 = norm(MA1sum)^2;
        CA2 = norm(MA2sum)^2;
        
        if (CA1 <= CA2)
            CA = CA1;
            MA = MA1;
        else
            CA = CA2;
            MA = MA2;
        end
        
        
        if CA < CAmin
            CAmin = CA;
        end
        
    end
end

while( abs(CB-CBmin) > diff )
    
    for j = 1:6
        MB1 = MB*expm( eps*E(:,:,j));
        MB2 = MB*expm(-eps*E(:,:,j));
        
        MB1sum = zeros(4);
        MB2sum = zeros(4);
        
        for k = 1:size(B,3)
            
            MB1sum = MB1sum + logm(MB1^(-1)*B(:,:,k));
            MB2sum = MB2sum + logm(MB2^(-1)*B(:,:,k));
        end
        
        CB1 = norm(MB1sum)^2;
        CB2 = norm(MB2sum)^2;
        
        if (CB1 <= CB2)
            CB = CB1;
            MB = MB1;
        else
            CB = CB2;
            MB = MB2;
        end
        
        if CB < CBmin
            CBmin = CB;
        end
        
    end
    
end

%%
MA1*X - X*MB1

% ---- 1st order Taylor expansion ---- %
[MA1,~] = mean_Taylor_1st( A );
[MB1,~] = mean_Taylor_1st( B );

% ---- 2nd order Taylor expansion ---- %
MA2 = mean_Taylor_2nd( A, 0 );
MB2 = mean_Taylor_2nd( B, 0 );

MA1*X - X*MB1

MA2*X - X*MB2


SigA = zeros(6,6);
SigB = zeros(6,6);

for i = 1:size(A,3)
    
    SigA = SigA + se3_vec(logm(MA^(-1)*A(:,:,i)))*se3_vec(logm(MA^(-1)*A(:,:,i)))';
    SigB = SigB + se3_vec(logm(MB^(-1)*B(:,:,i)))*se3_vec(logm(MB^(-1)*B(:,:,i)))';
    
end

SigA = SigA*(1/size(A,3));
SigB = SigB*(1/size(B,3));


SigA(1:3,1:3)*X(1:3,1:3);
X(1:3,1:3)*SigB(1:3,1:3);



%     [X_solve]=axb_KronSolve(A_noise,B_noise);
%     [X_perm]=axb_KronSolve(A_perm,B_perm);
%
%     Roterror_noise=roterror(X, X_solve);
%     Roterror_filt=roterror(X, X_perm);
%
%     Tranerror_noise=tranerror(X, X_solve);
%     Tranerror_filt=tranerror(X, X_perm);



%-------------------------------------------------------------------------------------------------------------



%Plotting Loops
%---------------------------------------------------------------------------------------------------------

% colors=['k' 'b' 'r' 'g' 'c' 'm' 'y' 'k' 'b' 'r'];   %create a list of colors for the plots
%
% var=1;
% res=1;
%
% scrsz = get(0,'ScreenSize');
% topshift=0;%125;
%
% figure(1);%('Position',[1 1-topshift*(3/2) scrsz(3)/2 scrsz(4)/2]); hold on
%
% scatter((1:1:length(delta1A)), delta1A, 'b.')
% hold on
% scatter((1:1:length(delta1B)), delta1B, 'r')
% xlabel('Index')
% ylabel('Delta1 Value')
% title('Delta1_A and Delta1_B')
% axis([0 length(delta1A) min(min(delta1A), min(delta1B)) max(max(delta1A), max(delta1B))+max(max(delta1B), max(delta1B))*0.1])
%
% hold off
%
%
%
% figure(2);%('Position',[1 1-topshift*(3/2) scrsz(3)/2 scrsz(4)/2]); hold on
%
% scatter((1:1:length(delta2A)), delta2A, 'b.')
% hold on
% scatter((1:1:length(delta2B)), delta2B, 'r')
% xlabel('Index')
% ylabel('Delta2 Value')
% title('Delta2_A and Delta2_B')
% axis([0 length(delta2A) min(min(delta2A), min(delta2B)) max(max(delta2A), max(delta2B))+max(max(delta2B), max(delta2B))*0.1])
%
% hold off
%
%
% figure(3);%('Position',[1 1-topshift*(3/2) scrsz(3)/2 scrsz(4)/2]); hold on
%
% scatter((1:1:length(phi1A)), phi1A, 'b.')
% hold on
% scatter((1:1:length(phi1B)), phi1B, 'r')
% xlabel('Index')
% ylabel('Phi1 Value')
% title('Phi1_A and Phi1_B')
% axis([0 length(phi1A) min(min(phi1A), min(phi1B)) max(max(phi1A), max(phi1B))+max(max(phi1B), max(phi1B))*0.1])
%
% hold off
%
%
% figure(4);%('Position',[1 1-topshift*(3/2) scrsz(3)/2 scrsz(4)/2]); hold on
%
% scatter((1:1:length(phi2A)), phi2A, 'b.')
% hold on
% scatter((1:1:length(phi2B)), phi2B, 'r')
% xlabel('Index')
% ylabel('Phi2 Value')
% title('Phi2_A and Phi2_B')
% axis([0 length(phi2A) min(min(phi2A), min(phi2B)) max(max(phi2A), max(phi2B))+max(max(phi2B), max(phi2B))*0.1])
%
% hold off
%
%
% figure(5);%('Position',[1 1-topshift*(3/2) scrsz(3)/2 scrsz(4)/2]); hold on
%
% scatter((1:1:length(thetaa)), thetaa, 'b.')
% hold on
% scatter((1:1:length(thetab)), thetab, 'r')
% xlabel('Index')
% ylabel('Theta Value')
% title('Theta_A and Theta_B')
% axis([0 length(thetaa) min(min(thetaa), min(thetab)) max(max(thetaa), max(thetab))+max(max(thetaa), max(thetab))*0.1])
%
% hold off
%
%
% figure(6);%('Position',[scrsz(3)/2 1-topshift*(3/2) scrsz(3)/2 scrsz(4)/2]); hold on
%
% scatter((1:1:length(da)), da, 'b.')
% hold on
% scatter((1:1:length(db)), db, 'r')
% xlabel('Index')
% ylabel('d Value')
% title('d_A and d_B')
% axis([0 length(da) min(min(da), min(db)) max(max(da), max(db))+max(max(da), max(db))*0.1])
%
% hold off
%---------------------------------------------------------------------------------------------------------


