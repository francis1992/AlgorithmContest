struct Z
{
    double re,im;
    Z(): re(0),im(0) {}
    Z(double a,double b): re(a),im(b) {}
    Z operator + (const Z &b) const
    {
        return Z(re+b.re,im+b.im);
    }
    Z operator - (const Z &b) const
    {
        return Z(re-b.re,im-b.im);
    }
    Z operator * (const Z &b) const
    {
        return Z(re*b.re-im*b.im,re*b.im+im*b.re);
    }
    Z inv()
    {
        return Z(re,-im);
    }
};

int gao(int x,int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans<<=1;
        if(x&1)ans++;
        x>>=1;
    }
    return ans;
}
void FFT(Z *ff,int n,int m,Z *ans)
{
    for(int i=0;i<n;i++)ans[i]=ff[gao(i,m)];
    for(int len=1;len<n;len<<=1)
    {
        Z wo=Z(cos(-pi/len),sin(-pi/len)),w,t1,t2;
        for(int k=0;k*len<n;k+=2)
        {
            w=Z(1,0);
            for(int i=0;i<len;i++)
            {
                t1=ans[i+k*len],t2=w*ans[i+(k+1)*len],w=w*wo;
                ans[i+k*len]=t1+t2;
                ans[i+(k+1)*len]=t1-t2;
            }
        }
    }
}

Z ff[4*maxn],A[4*maxn];
void FFT(int a[],int n,int b[],int m,double ans[])
{
    int N=1,M=0;
    while(N<n+m)N*=2,M++;
    for(int i=0;i<n;i++)ff[i].re=a[i];
    for(int i=n;i<N;i++)ff[i].re=0;
    for(int i=0;i<m;i++)ff[i].im=b[i];
    for(int i=m;i<N;i++)ff[i].im=0;
    FFT(ff,N,M,A);
    A[N]=A[0];
    Z w1,w2,w3;
    for(int i=0;i<N;i++)
    {
        w3=A[N-i].inv();
        w1=A[i]+w3;
        w2=A[i]-w3;
        w1=w1*w2;
        w1=w1.inv();
        ff[i]=Z(-w1.im/4,w1.re/4);
    }
    FFT(ff,N,M,A);
    for(int i=0;i<N;i++)ans[i]=A[i].re/N;
}
