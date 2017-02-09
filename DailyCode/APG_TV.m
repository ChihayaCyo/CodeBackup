function [x,x_full]=APG_TV(y,opts)


mu=opts.mu;
k=opts.kernel;
mask=opts.mask;
L=opts.L;
maxIter=opts.maxIter;

x=y;

[mk,nk]=size(k);
mk=floor(mk/2);nk=floor(nk/2);
x=padarray(x,[mk,nk],'replicate');

K_FFT=psf2otf(k,size(x));
KT_FFT=conj(K_FFT);

UBCM=@(x) x(mk+1:end-mk,nk+1:end-nk).*mask;
UBCMT=@(x) padarray(x.*mask,[mk,nk],0);


w=x;


t0=1;t1=1;

% lambda2=0.0008;

for iter=1:maxIter
    
    Kw=real(ifft2(fft2(w).*K_FFT));
    tmp1=UBCM(Kw)-y;
    grad_w=real(ifft2(fft2(UBCMT(tmp1)).*KT_FFT));
    z=w-grad_w/L;
    
    
    x_pre=x;
    x=tvdenoise(z,L/mu,5);%求解TV子问题
    
    x(x<0)=0;
    x(x>1)=1;
    
%     u_pre=u;
%     u= soft_threshold(gu, lambda2/L);
    
    t0=t1;
    t1=(1+sqrt(1+4*t0^2))/2;
    w=x+(t0-1)/t1*(x-x_pre);
    
%         du=u+(t0-1)/t1*(u-u_pre);
    
end

x_full=x;
x=x_full(mk+1:end-mk,nk+1:end-nk);


end