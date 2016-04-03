#include<cstdio>
#include<cstring>
#include<algorithm>
#define captype int
using namespace std;
const int MAXN=100010;
struct Edge
{
    int s,e,nx;
    captype c;
}E[1000000];
int head[MAXN],cnt;
void add(int s,int e,captype c)
{
    E[cnt].s=s;
    E[cnt].e=e;
    E[cnt].c=c;
    E[cnt].nx=head[s];
    head[s]=cnt++;
    E[cnt].s=e;
    E[cnt].e=s;
    E[cnt].c=0;
    E[cnt].nx=head[e];
    head[e]=cnt++;
}
int d[MAXN],num[MAXN];
int Stack[MAXN],Top;
int H[MAXN];
int Q[MAXN];
captype isap(int N,int s,int t)
{
    memset(d,-1,sizeof(d));
    memset(num,0,sizeof(num));
    d[t]=0;num[0]++;
    int l=0,r=0;
    Q[r++]=t;
    while(l<r)
    {
        int x=Q[l++];
        for(int i=head[x];i!=-1;i=E[i].nx)
        if(E[i^1].c&&d[E[i].e]==-1)
        {
            d[E[i].e]=d[x]+1;
            num[d[x]+1]++;
            Q[r++]=E[i].e;
        }
    }
    captype ans=0;
    for(int i=0;i<=N;i++)H[i]=head[i];
    Top=0;
    int x;
    while(d[s]<N)
    {
        if(!Top)x=s;
        else x=E[Stack[Top-1]].e;
        if(x==t)
        {
            captype p=E[Stack[0]].c;
            for(int i=1;i<Top;i++)
            p=min(p,E[Stack[i]].c);
            ans+=p;
            for(int i=Top-1;i>=0;i--)
            {
                E[Stack[i]].c-=p;
                if(E[Stack[i]].c==0)Top=i;
                E[Stack[i]^1].c+=p;
            }
        }
        else
        {
            for(int i=H[x];i!=-1;i=E[i].nx)
            if(E[i].c>0&&d[E[i].e]==d[x]-1)
            {
                Stack[Top++]=i;
                H[x]=i;
                goto nx;
            }
            if(--num[d[x]]==0)return ans;
            int mi=N;
            for(int i=head[x];i!=-1;i=E[i].nx)
            if(E[i].c>0&&mi>d[E[i].e])
            {
               mi=d[E[i].e];
               H[x]=i;
            }
            d[x]=mi+1;
            num[d[x]]++;
            if(x!=s)Top--;
        }
        nx:;
    }
    return ans;
}
