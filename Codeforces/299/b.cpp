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

using namespace std;
const int mod=(int)1e9+7;
int base=33;
const int maxn=1000001;
int n,m;
char s[maxn];
int pos[maxn];
long long haha[maxn];
long long po[maxn];
long long get_hahaval(int l,int r)
{
	long long ans=haha[r];
	if(l)
	{
		ans=((ans-haha[l-1]*po[r-l+1])%mod+mod)%mod;
	}
	return ans;
}
int main()
{
	while(~scanf("%d %d %s",&n,&m,s))
	{
		for(int i=0;i<m;i++)
			scanf("%d",&pos[i]);
		sort(pos,pos+m);
		int len=strlen(s);
		po[0]=1;
		haha[0]=(s[0]-'a')%mod;
		for(int i=1;i<len;i++)
		{
			po[i]=po[i-1]*base%mod;
			haha[i]=(haha[i-1]*base+(s[i]-'a'))%mod;
		}
		bool ok=1;
		for(int i=1;i<m;i++)
		{
			if(pos[i-1]+len-1>=pos[i])
			{
				int cover=pos[i-1]+len-1-pos[i]+1;
				if(get_hahaval(0,cover-1)!=get_hahaval(len-cover,len-1))
				{
					ok=0;
					break;
				}
			}
		}
		if(!ok)
		{
			puts("0");
		}
		else
		{
			int ma=-1;
			int cnt=0;
			for(int i=0;i<m;i++)
			{
				int l=pos[i];
				int r=l+len-1;
				if(l>ma)
				{
					cnt+=len;
					ma=r;
				}
				else
				{
					cnt+=r-ma;
					ma=r;
				}
			}
			cnt=n-cnt;
			int ans=1;
			int b=26;
			while(cnt)
			{
				if(cnt&1)
					ans=1LL*b*ans%mod;
				b=1LL*b*b%mod;
				cnt>>=1;
			}
			printf("%d\n",ans);
		}
	}
}
