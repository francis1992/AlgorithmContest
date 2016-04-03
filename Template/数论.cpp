#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
using namespace std;
bool wintess(long long a,int q,long long m,long long n)
{
    long long x=exp_mod(a,m,n),y;
    for(int j=1;j<=q;j++)
    {
        y=mult_mod(x,x,n);
        if(y==1&&x!=1&&x!=(n-1))return 1;
        x=y;
    }
    if(y!=1)return 1;
    return 0;
}
bool miler(long long n,int T)
{
    if(n==1)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    long long m=n-1;
    int q=0;
    while((m&1)==0)m>>=1,q++;
    for(int i=1;i<=T;i++)
    {
        long long a=rand()%(n-2)+2;
        if(wintess(a,q,m,n))return 0;
    }
    return 1;
}
long long rho(long long n)
{
    long long x=rand()%n,y=x;
    int i=1,k=2;
    long long t;
    while(1)
    {
        i++;
        x=mult_mod(x,x,n)+1;
        if(x>=n)x-=n;
        t=gcd(y-x,n);
        if(t>1&&t<n)
        return t;
        if(x==y)
        return n;
        if(i==k)
        {
            y=x;
            k<<=1;
        }
    }
}
long long SQRT(long long n)
{
    long long ans=max(1LL,(long long)sqrt((double)n)-3);
    while((ans+1)*(ans+1)<=n)ans++;
    return ans;
}
long long SQUFOF(int k,long long n)
{
    int i;
    n = n * k;
    static long long temp,sqn,p[10001],q[10001],b[10001];
    sqn = SQRT(n);
    p[0] = sqn;
    q[0] = 1;
    q[1] = n - p[0]*p[0];
    if(q[1]==0)return 1;
    for(i = 1; i < 10000; ++i)
    {
        b[i] = (sqn + p[i - 1])/q[i];
        p[i] = b[i] * q[i] - p[i - 1];
        q[i + 1] = q[i - 1] + b[i]*(p[i - 1] - p[i]);
        temp = SQRT(q[i]);
        if(temp * temp == q[i])
            break;
    }
    if(i==10000)return 1;
    b[0] = ((sqn - p[i - 1])/temp);
    p[0] = b[0]*temp + p[i - 1];
    q[0] = temp;
    q[1] = (n - (p[0]*p[0]))/q[0];
    for(i = 1; i < 10000; ++i)
    {
        b[i] = (sqn + p[i - 1])/q[i];
        p[i] = b[i] * q[i] - p[i - 1];
        q[i + 1] = q[i - 1] + b[i]*(p[i - 1] - p[i]);
        if(p[i - 1] == p[i])
            break;
    }
    if(i==10000)return 1;
    return gcd(n/k,p[i]);
}
set <long long> p;
void fj(long long n)
{
    long long te,res = SQRT(n);
    while(res * res == n && n != 1)
    {
        n = res;
        res = SQRT(n);
    }
    if(n==1)return;
    if(miler(n,10))
    {
        p.insert(n);
        return;
    }
    int k=1;
    while(k<=10&&( (res = SQUFOF(k,n)) == 1 || res == n) ) ++k;
    while(res==n||res==1||n%res!=0)res=rho(n);
    fj(res);
    fj(n/res);
}

#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int w=16;
const int M=(1<<w)-1;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
void ext_gcd(int a,int b,int &x,int &y)
{
    if (!b){x=1,y=0;return;}
    ext_gcd(b,a%b,x,y);
    int t=x;x=y,y=t-a/b*y;
}
int inv(int a,int b,int n)
{
    int x,y,e;
    ext_gcd(a,n,x,y);
    e=(long long)x*b%n;
    return e<0?e+n:e;
}
int exp_mod(int a,int b,int m)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        ans=(long long)ans*a%m;
        a=(long long)a*a%m;
        b>>=1;
    }
    return ans;
}
struct node
{
    int k,num,nx;
}hash[100000];
int head[M+10],cnt;
int find(int x)
{
    int k=x>>w;
    for(int i=head[x&M];i!=-1;i=hash[i].nx)
    if(hash[i].k==k)return hash[i].num;
    return -1;
}
void insert(int x,int num)
{
    if(find(x)!=-1)return;
    hash[cnt].k=x>>w;
    hash[cnt].num=num;
    hash[cnt].nx=head[x&M];
    head[x&M]=cnt++;
}
int babystep(int a,int y,int p)
{
    for(int i=0;i<50;i++)if(exp_mod(a,i,p)==y)return i;
    int g=0,D=1,d;
    while((d=gcd(a,p))!=1)
    {
        if(y%d)return -1;
        y/=d;p/=d;g++;
        D=(long long)a/d*D%p;
    }
    int m=ceil(sqrt((double)p));
    cnt=0;memset(head,-1,sizeof(head));
    for(int i=0,cao=1;i<m;i++,cao=(long long)cao*a%p)insert(cao,i);
    for(int i=0,cao=exp_mod(a,m,p);i<m;i++,D=(long long)D*cao%p)
    {
        int t=inv(D,y,p);
        int j=find(t);
        if(j!=-1)return i*m+j+g;
    }
    return -1;
}
int main()
{
    int a,p,y;
    while(scanf("%d%d%d",&a,&p,&y))
    {
        if(!a&&!p&&!y)break;
        a%=p;y%=p;
        int ans=babystep(a,y,p);
        if(ans!=-1)
        printf("%d\n",ans);
        else
        puts("No Solution");
    }
}


long long FLOOR(long long A,long long B)
{
    if(B<0){A=-A;B=-B;}
    if(A%B==0||A>0)return A/B;
    return A/B-1;
}

//sigma(A*i+B)/n  0<=i<=a;
long long dfs(long long  a,long long  A,long long  B,long long  n)
{
    if(a<0)return 0;
    long long D=gcd(gcd(abs(A),abs(B)),n);A/=D;B/=D;n/=D;
    if(A%n==0)
    {
        A/=n;
        return a*(a+1)/2*A+(a+1)*FLOOR(B,n);
    }
    if(FLOOR(A,n)!=0) return a*(a+1)/2*FLOOR(A,n)+dfs(a,A-FLOOR(A,n)*n,B,n);
    if(FLOOR(B,n)!=0) return (a+1)*FLOOR(B,n)+dfs(a,A,B-FLOOR(B,n)*n,n);
    long long M=(A*a+B)/n;
    long long R=A*a+B-M*n;
    return dfs(M-1,n,R,A)+M;
}
