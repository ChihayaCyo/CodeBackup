% demo_D_ADMM_MRI

% Demo of MRI image reconstruction, with total variation. 
% 128*128 SHepp-Logan phantom, 22 radial lines.

% close all;
% clear;

% addpath ./../../src
% addpath ./../../utils

addpath(genpath('.'));



load im08_flit08.mat;%Ä£ºıºË

%kernel=f{1};
%x=im2double(imread('x{1}'));
%kernel=fspecial('motion',31,10);
%y=y{1};
%y=imfilter(x,kernel,'conv','replicate')+1e-3*randn(size(x)); %¼ÓÄ£ºı
%y=imfilter(x,kernel,'replicate','conv')+ sigma*randn(m,n);

mask=rand(size(x))>0.3;
y=y.*mask;%ÏñËØÈ±Ê§

%%%% algorithm parameters
par.kernel=f;
par.mu = 0.001;
par.mask=mask;
par.maxIter=400;
par.tol=1e-4;
par.L=3;
window=size(x);


[x_r,x_full]=APG_TV(y,par);
psnr=psnr(x_r,x);
ssim=ssim(x_r,x);
figure,
subplot(2,2,1);imshow(x);title('original image')
subplot(2,2,2);imshow(y);title('degraded image')
subplot(2,2,3);imshow(x_r);title('recovered image')



