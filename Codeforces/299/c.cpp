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

const int maxn=200001;

struct point
{
	int x,y,id;
	point(){}
	point(int _x,int _y)
	{
		x=_x;
		y=_y;
	}
	void read()
	{
		scanf("%d %d",&x,&y);
	}
	bool operator < (const point &b) const
	{
		if(x==b.x)
			return y<b.y;
		return x<b.x;
	}
}a[maxn];
bool cmp(int s1,int s2,int s3)
{
//	(1/a[s2].x-1/a[s1].x)*(1/a[s3].y-1/a[s2].y) - (1/a[s2].y-1/a[s1].y)*(1/a[s3].x-1/a[s2].x)
	return (1LL*a[s1].x*a[s3].x-1LL*a[s2].x*a[s3].x)*(1LL*a[s1].y*a[s2].y-1LL*a[s1].y*a[s3].y) 
			- (1LL*a[s1].y*a[s3].y-1LL*a[s2].y*a[s3].y)*(1LL*a[s1].x*a[s2].x-1LL*a[s1].x*a[s3].x) < 0;
}
int sta[maxn],top;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		a[i].read();
		a[i].id=i+1;
	}
	sort(a,a+n);
	top=0;
	sta[++top]=0;
	if(n>1)sta[++top]=1;
	for(int i=2;i<n;i++)
	{
		while(top>=2&&cmp(i,sta[top],sta[top-1]))top--;
		sta[++top]=i;
	}
	int tmp=top;
	for(int i=n-1;i>=0;i--)
	{
		while(top>tmp&&cmp(i,sta[top],sta[top]-1))top--;
		sta[++top]=i;
	}
	sort(sta+1,sta+1+top);
	top=unique(sta+1,sta+1+top)-(sta+1);
	vector <int> ans;
	for(int i=1;i<=top;i++)
	{
		ans.push_back(a[sta[i]].id);
	}
	sort(ans.begin(),ans.end());
	unique(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
	{
		if(i)printf(" ");
		printf("%d",ans[i]);
	}
	puts("");
}
