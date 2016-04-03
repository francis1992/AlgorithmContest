#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace std;
const int maxn=100000010;
const int maxN=30000000;
int prime[maxn/10],flag[maxn],num;
int a;
bool vis[maxN];
long long P(long long n)
{
	long long ans=0;
	for(int i=a+1;1LL*prime[i]*prime[i]<=n;i++)ans+=flag[n/prime[i]]-i+1;
	return ans;
}
long long N;
vector <int> gao[1300];
long long dfs(long long s,int now)
{
	long long S=s;if(S<0)S=-S;
	if(now==0)return N/S;
	if(N/S<prime[now+1])return 1;
	if(N/S<maxN)
	{
		gao[now].push_back(N/s);
		return 0;
	}
	return dfs(s,now-1)-dfs(-s*prime[now],now-1);
}
int tree[maxN];
int read(int pos)
{
	int ans=0;
	while(pos)ans+=tree[pos],pos-=pos&-pos;
	return ans;
}
void insert(int pos)
{
	while(pos<maxN)tree[pos]++,pos+=pos&-pos;
}
long long cal(long long n)
{
	if(n<=1)return 0;
	if(n<maxn)return flag[n];
	N=n;
	a=1;
	while(1LL*prime[a]*prime[a]*prime[a]<=n)a++;
	for(int i=1;i<=a;i++)gao[i].clear();
	long long ans=dfs(1,a)-P(n)+a-1;
	memset(tree,0,sizeof(tree));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=a;i++)
	{
		for(int j=prime[i];j<maxN;j+=prime[i])
			if(!vis[j])
				insert(j),vis[j]=1;
		for(int j=0;j<gao[i].size();j++)
		{
			if(gao[i][j]>0)
				ans+=gao[i][j]-read(gao[i][j]);
			else ans-=-gao[i][j]-read(-gao[i][j]);
		}
	}
	return ans;
}
int main()
{
	for(int i=2;i<maxn;i++)
	{
		if(!flag[i])prime[++num]=i;
		for(int j=1;j<=num&&i*prime[j]<maxn;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=2;i<maxn;i++)flag[i]=flag[i-1]+(!flag[i]);
	long long n;
	while(cin>>n)
	{
		double sta=clock();
		cout<<cal(n)<<endl;
		printf("%.10f\n",clock()-sta);
	}
}
