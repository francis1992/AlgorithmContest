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

int a,b,n;
int l,t,m;
bool check(int r)
{
	long long L=a+1LL*(l-1)*b;
	long long R=a+1LL*(r-1)*b;
	long long s=1LL*(L+R)*(r-l+1)/2;
	return 1LL*t*m>=s && t>=R;
}
int main()
{
	cin>>a>>b>>n;
	while(n--)
	{
		cin>>l>>t>>m;
		int L=l,R=t;
		while(L<R)
		{
			int mid=(L+R)/2+1;
			if(check(mid))
			{
				L=mid;
			}
			else
			{
				R=mid-1;
			}
		}
		if(!check(L)||L!=R)L=-1;
		cout<<L<<endl;
	}
}
