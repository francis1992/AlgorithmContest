#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define sqr(x) ((x)*(x))
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-8;
int sgn(double x)
{
	return x<-eps?-1:x>eps;
}
struct point
{
	double x,y;
	point() {}
	point(double a,double b): x(a),y(b) {}
	void read()
	{
	    scanf("%lf%lf",&x,&y);
	}
	void show()
	{
	    printf("(%lf,%lf)\n",x,y);
	}
	point operator + (const point &b) const
	{
		return point(x+b.x,y+b.y);
	}
	point operator - (const point &b) const
	{
		return point(x-b.x,y-b.y);
	}
    point operator * (const double &b) const
	{
		return point(x*b,y*b);
	}
    point operator / (const double &b) const
	{
		return point(x/b,y/b);
	}
    bool operator == (const point &b) const
	{
		return (sgn(y-b.y)==0&&sgn(x-b.x)==0);
	}
	bool operator < (const point &b) const
    {
        if(sgn(y-b.y)==0)
        return x<b.x;
        return y<b.y;
    }
    double operator * (const point &b) const
	{
		return x*b.x+y*b.y;
	}
	double X (const point &b) const
	{
		return x*b.y-y*b.x;
	}
    point rot (const double &ta) const
	{
	    return point(cos(ta)*x-sin(ta)*y,sin(ta)*x+cos(ta)*y);
	}
    point rot90 (const double &d) const
	{
	    return point(-y,x) / len()*d;
	}
   	point unit()
	{
	    return point(x,y)/len();
	}
	double dis (const point &b) const
	{
	    return sqrt(fabs((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y)));
	}
    double dis2 (const point &b) const
	{
	    return fabs(sqr(x-b.x)+sqr(y-b.y));
	}
	double len() const
	{
		return sqrt(x*x+y*y);
	}
    double len2() const
	{
		return x*x+y*y;
	}
};

struct line
{
    point s,e;
    double ang;
    line () {}
    line(point a,point b): s(a),e(b),ang(atan2(e.y-s.y,e.x-s.x)) {}
    bool operator / (const line &l) const
	{
		return sgn((l.e-l.s).X(e-s))==0;
	}
    bool operator == (const line &l) const
	{
		return sgn((l.s-s).X(l.e-s))==0&&sgn((l.s-e).X(l.e-e))==0;
	}
    bool operator < (const line &b) const
	{
		if(sgn(b.ang-ang)!=0)return ang<b.ang;
		return sgn((b.e-b.s).X(e-b.s))>=0;
	}
	bool isright(const point &p) const
    {
        return sgn((p-s).X(e-s))>0;
    }
	bool ispointonline(const point &a) const
	{
	    return sgn((a-s).X(s-e))==0;
	}
    bool ispointonseg(const point &a) const
    {
        return sgn((a-s).X(s-e))==0&&sgn((a-s)*(a-e))<=0;
    }
    bool iscross(const line &l) const //严格相交
    {
        int  t1=sgn((l.s-s).X(e-s));
        int  t2=sgn((l.e-s).X(e-s));
        int  t3=sgn((s-l.s).X(l.e-l.s));
        int  t4=sgn((e-l.s).X(l.e-l.s));
        return t1*t2<0&&t3*t4<0;
    }
    point crosspoint(const line &l)
    {
        double a1 = (s-l.s).X(e-l.s), a2 = -(s-l.e).X(e-l.e);
        return (l.s * a2 + l.e * a1) / (a1 + a2);
    }
    point ref(const point &p) const
    {
        point pj =s+(e - s)*((e - s)*(p - s)/(e - s).len2());
        return pj * 2 - p;
    }
    double dis(const point &p) const
    {
        return fabs((e-s).X(p-s)/(e-s).len());
    }
};

struct polygon
{
	point p[1010];
	int n;
    double area()
    {
        double ans=0;
        for(int i=1;i<=n;i++)
        ans+=p[i-1].X(p[i%n]);
        return ans/2;
    }
	//任意多边形重心= =
    point center()
    {
        double sx=0,sy=0,sa=0;
        for(int i=2;i<n;i++)
        {
            point p0=p[0];
            point p1=p[i-1];
            point p2=p[i];
            double cx=p0.x+p1.x+p2.x;
            double cy=p0.y+p1.y+p2.y;
            double A=(p1-p0).X(p2-p0);
            sa+=A;
            sx+=cx*A;
            sy+=cy*A;
        }
        return point(sx/sa/3,sy/sa/3);
    }
    void grahanm(polygon &ans)
    {
        sort(p,p+n);
        ans.p[0]=p[0];ans.p[1]=p[1];
        int now=2;
        for(int i=2;i<n;i++)
        {
            while(now>1&&sgn((ans.p[now-1]-p[i]).X(ans.p[now-2]-p[i]))>=0)now--;
            ans.p[now++]=p[i];
        }
        int top=now;
        for(int i=n-2;i>=0;i--)
        {
            while(now>top&&sgn((ans.p[now-1]-p[i]).X(ans.p[now-2]-p[i]))>=0)now--;
            ans.p[now++]=p[i];
        }
        ans.n=--now;
    }
    bool isin(point a)
    {
        a=a-p[0];
        if(sgn((p[1]-p[0]).X(a))<0)return 0;
        int l=1,r=n-1;
        while(l<r)
        {
            int mid=(l+r)/2+1;
            double temp=(p[mid]-p[0]).X(a);
            if(sgn(temp)==0)
            {
			   line l1=line(p[0],p[mid]);
			   return l1.ispointonseg(a+p[0]);
            }
            if(temp>0)l=mid;
            else r=mid-1;
        }
        if(l==n-1)return 0;
        return sgn((p[l+1]-p[l]).X(a+p[0]-p[l]))>=0;
    }
    void cut(point p1,point p2)
    {
        p[n]=p[0];
        polygon q;
        line l1, l2;
        int t1, t2;
        q.n=0;
        for(int i=0;i<n;i++)
        {
            t1 =sgn((p2-p1).X(p[i]-p1));
            t2 =sgn((p2-p1).X(p[i+1]-p1));
            if(t1>=0)q.p[q.n++]=p[i];
            if(t1*t2<0)
            {
                l1=line(p1, p2);
                l2=line(p[i],p[i + 1]);
                q.p[q.n++]=l1.crosspoint(l2);
            }
        }
        n=q.n;
        for(int i=0;i<q.n;i++)p[i]=q.p[i];
        p[n]=p[0];
    }
};

//最小包围矩形
void solve()
{
    double minarea=1e20,minlen=1e20;
    int l=1,r=1,u=1;
    a.p[a.n]=a.p[0];
    for(int i=0;i<a.n;i++)
    {
        point vec=(a.p[i+1]-a.p[i]).unit();
        while((a.p[(r+1)%a.n]-a.p[i])*vec>(a.p[r%a.n]-a.p[i])*vec)r++;
        while(u<r||vec.X(a.p[(u+1)%a.n]-a.p[i])>vec.X(a.p[u%a.n]-a.p[i]))u++;
        while(l<u||(a.p[(l+1)%a.n]-a.p[i])*vec<(a.p[l%a.n]-a.p[i])*vec)l++;
        double aa=(a.p[r%a.n]-a.p[i])*vec-(a.p[l%a.n]-a.p[i])*vec;
        double bb=vec.X(a.p[u%a.n]-a.p[i]);
        minarea=min(minarea,aa*bb);
        minlen=min(minlen,(aa+bb)*2);
    }
    printf("%.2f %.2f\n",minarea,minlen);
}
//点是否在多边形内部
int isin(point p,point a[],int n)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    if(line(a[i],a[(i+1)%n]).ispointonseg(p))return 0;
    for(int i=0;i<n;i++)
    {
        point s=a[i],e=a[(i+1)%n];
        if(sgn(s.y-e.y)==0)continue;
        if(s.y>e.y)swap(s,e);
        if(sgn(s.y-p.y)<0&&sgn(e.y-p.y)>0&&(e-s).X(p-s)>0)cnt++;
        if(sgn(s.y-p.y)==0&&sgn(s.x-p.x)>0)cnt++;
    }
    if(cnt&1)return 1;
    return -1;
}

// 半径r的圆是否能放到简单多边形内 n^3!
bool check(point p)
{
    if(isin(p)!=1)return 0;
    for(int i=0;i<n;i++)
    if(sgn(a[i].dis(p)-r)<0)return 0;
    for(int i=0;i<n;i++)
    {
        line l=line(a[i],a[i+1]);
        double d=l.dis(p);
        if(sgn(d-r)>=0)continue;
        point o=(l.ref(p)+p)/2;
        if(sgn((o-a[i])*(o-a[i+1]))<0)return 0;
    }
    return 1;
}
bool solve()
{
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
    {
        line l1,l2;
        point vec1=(a[i+1]-a[i]).rot90().unit()*r;
        point vec2=(a[j+1]-a[j]).rot90().unit()*r;
        for(int d1=0;d1<2;d1++)
        for(int d2=0;d2<2;d2++)
        {
            if(d1)l1=line(a[i]-vec1,a[i+1]-vec1);
            else l1=line(a[i]+vec1,a[i+1]+vec1);
            if(d2)l2=line(a[j]-vec2,a[j+1]-vec2);
            else l2=line(a[j]+vec2,a[j+1]+vec2);
            if(l1/l2)continue;
            point o=l1.crosspoint(l2);
            if(check(o))return 1;
        }
    }
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
    {
        double d=a[i].dis(a[j]);
        if(sgn(d-2*r)>0)continue;
        d=sqrt(r*r-d*d/4);
        point mid=(a[i]+a[j])/2;
        point vec=(a[i]-a[j]).rot90().unit()*d;
        if(check(mid+vec))return 1;
        if(check(mid-vec))return 1;
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        point vec=(a[i+1]-a[i]).rot90().unit()*r;
        line l;
        for(int d=0;d<2;d++)
        {
            if(d)l=line(a[i]+vec,a[i+1]+vec);
            else l=line(a[i]-vec,a[i+1]-vec);
            double d=l.dis(a[j]);
            if(sgn(d-r)>0)continue;
            point o=(l.ref(a[j])+a[j])/2;
            d=sqrt(r*r-d*d);
            point dir=(a[i+1]-a[i]).unit()*d;
            if(check(o+dir))return 1;
            if(check(o-dir))return 1;
        }
    }
    return 0;
}

//多圆面积并
struct cir
{
    point o;
    double r;
};
struct nima
{
    double ta;
    int num;
    bool operator < (const nima &b) const
    {
        if(sgn(ta-b.ta)==0)
        return num>b.num;
        return ta<b.ta;
    }
}gao[10000];

void add(cir a,cir b,int &cnt)
{
	double d=a.o.dis(b.o);
	if(sgn(d-(b.r-a.r))<=0)
	{
        gao[cnt].ta=0;gao[cnt++].num=1;
		gao[cnt].ta=2*pi;gao[cnt++].num=-1;
        return;
	}
	if(sgn(d-a.r-b.r)>=0||sgn(d-(a.r-b.r))<=0)return;
	d=acos((sqr(a.r)+sqr(d)-sqr(b.r))/2/a.r/d);
    double t1=atan2(b.o.y-a.o.y,b.o.x-a.o.x)-d;if(sgn(t1)<0)t1+=2*pi;
    double t2=atan2(b.o.y-a.o.y,b.o.x-a.o.x)+d;if(sgn(t2-2*pi)>=0)t2-=2*pi;if(sgn(t2)<0)t2+=2*pi;
    if(sgn(t1-t2)<=0)
    {
        gao[cnt].ta=t1;
        gao[cnt++].num=1;
        gao[cnt].ta=t2;
        gao[cnt++].num=-1;
    }
    else
    {
        gao[cnt].ta=t1;
        gao[cnt++].num=1;
		gao[cnt].ta=2*pi;
        gao[cnt++].num=-1;
        gao[cnt].ta=0;
        gao[cnt++].num=1;
        gao[cnt].ta=t2;
        gao[cnt++].num=-1;
    }
}
int n;
cir a[1010];
double ans[1010];
void solve()
{
    for(int i=0;i<1010;i++)ans[i]=0;
    for(int i=1;i<=n;i++)
    {
        int gn=0;
        for(int j=1;j<=n;j++)
        add(a[i],a[j],gn);
        sort(gao,gao+gn);
        int now=0;
        point cao1=point(cos(gao[0].ta),sin(gao[0].ta))*a[i].r+a[i].o;
        point cao2=point(cos(gao[1].ta),sin(gao[1].ta))*a[i].r+a[i].o;
        for(int j=0;j<gn-1;j++)
        {
            now+=gao[j].num;
            double cao=gao[j+1].ta-gao[j].ta;
            ans[now]+=sqr(a[i].r)*(cao-sin(cao));
            ans[now]+=cao1.X(cao2);
            cao1=cao2;
            cao2=point(cos(gao[j+2].ta),sin(gao[j+2].ta))*a[i].r+a[i].o;
        }
    }
    for(int i=1;i<=n;i++)ans[i]=(ans[i]-ans[i+1])/2;
}

//最小圆覆盖
point a[510];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
        scanf("%lf%lf",&a[i].x,&a[i].y);
        random_shuffle(a+1,a+1+n);
        point o=a[1];
        double r=0;
        for(int i=1;i<=n;i++)
        if(sgn(a[i].dis(o)-r)>0)
        {
            o=a[i];r=0;
            for(int j=1;j<i;j++)
            if(sgn(a[j].dis(o)-r)>0)
            {
                o=(a[i]+a[j])/2;
                r=a[j].dis(o);
                for(int k=1;k<j;k++)
                if(sgn(a[k].dis(o)-r)>0)
                {
                    o=cal(a[i],a[j],a[k]);//外接圆圆心
                    r=a[k].dis(o);
                }
            }
        }
        printf("%.2f %.2f %.2f\n",o.x,o.y,r);
    }
}

//(x,y,z)向量射进眼睛 逆时针转
ma ROTATE()
{
    double x,y,z,ta;
    scanf("%lf%lf%lf%lf",&x,&y,&z,&ta);
    ta=ta/180*pi;
    ma ans;
    ans.init();
    double len = sqrt(x * x + y * y + z * z);
    x /= len;
    y /= len;
    z /= len;
    ans.a[0][0] = x * x + (1 - x * x) * cos(ta);
    ans.a[0][1] = x * y * (1 - cos(ta)) - z * sin(ta);
    ans.a[0][2] = x * z * (1 - cos(ta)) + y * sin(ta);
    ans.a[1][0] = y * x * (1 - cos(ta)) + z * sin(ta);
    ans.a[1][1] = y * y + (1 - y * y) * cos(ta);
    ans.a[1][2] = y * z * (1 - cos(ta)) - x * sin(ta);
    ans.a[2][0] = z * x * (1 - cos(ta)) - y * sin(ta);
    ans.a[2][1] = z * y * (1 - cos(ta)) + x * sin(ta);
    ans.a[2][2] = z * z + (1 - z * z) * cos(ta);
    return ans;
}
//三维凸包
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
const int MAXN=10001;
const double eps=1e-8;
struct _3DCH
{
    struct point
    {
        double x, y, z;
        point() {}
        point(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
        void read()
        {
            scanf("%lf %lf %lf",&x,&y,&z);
        }
        point operator - (const point p1)
        {
            return point(x - p1.x, y - p1.y, z - p1.z);
        }
        point operator * (point p)
        {
            return point(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);
        }
        double operator ^ (point p)
        {
            return x*p.x+y*p.y+z*p.z;
        }
    };
    struct fac
    {
        int a, b, c;
        bool ok;
    };
    int n;
    point P[MAXN];
    int cnt;
    fac F[MAXN*8];
	map < pair<int,int> ,int > to;
	double totalvolume;
    double vlen(point a)
    {
        return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
    }
    double area(point a, point b, point c)
    {
        return vlen((b-a)*(c-a));
    }
    double volume(point a, point b, point c)
    {
        return (b-a)*(c-a)^a;
    }
    double pointof(point &p, fac &f)
    {
        point m = P[f.b]-P[f.a], n = P[f.c]-P[f.a], t = p-P[f.a];
        return (m * n) ^ t;
    }
    void deal(int p, int a, int b)
    {
        int f = to[make_pair(a,b)];
        fac add;
        if (F[f].ok)
        {
            if (pointof(P[p], F[f]) > eps)
                dfs(p, f);
            else
            {
                add.a = b, add.b = a, add.c = p, add.ok = 1;
                to[make_pair(p,b)] = to[make_pair(a,p)] = to[make_pair(b,a)] = cnt;
                F[cnt++] = add;
				totalvolume+=volume(P[F[cnt-1].a],P[F[cnt-1].b],P[F[cnt-1].c]);
            }
        }
    }
    void dfs(int p, int cur)
    {
        F[cur].ok = 0;
		totalvolume-=volume(P[F[cur].a],P[F[cur].b],P[F[cur].c]);
        deal(p, F[cur].b, F[cur].a);
        deal(p, F[cur].c, F[cur].b);
        deal(p, F[cur].a, F[cur].c);
    }
	void init()
	{
		n=cnt=0;
		totalvolume=0;
	}
	bool add(point p)
	{
		P[n++]=p;
		if(n<4)return 0;
		if(!cnt)
		{
			bool sb = 1;
			for (int i = 1; i < n; i++)
			{
				if (vlen(P[0] - P[i]) > eps)
				{
					swap(P[1], P[i]);
					sb = 0;
					break;
				}
			}
			if (sb)return 0;
			sb = 1;
			for (int i = 2; i < n; i++)
			{
				if (vlen((P[0] - P[1]) * (P[1] - P[i])) > eps)
				{
					swap(P[2], P[i]);
					sb = 0;
					break;
				}
			}
			if (sb)return 0;
			sb = 1;
			for (int i = 3; i < n; i++)
			{
				if (fabs((P[0] - P[1]) * (P[1] - P[2]) ^ (P[0] - P[i])) > eps)
				{
					swap(P[3], P[i]);
					sb = 0;
					break;
				}
			}
			if (sb)return 0;



			fac add;
			for (int i = 0; i < 4; i++)
			{
				add.a = (i+1)%4, add.b = (i+2)%4, add.c = (i+3)%4, add.ok = 1;
				if (pointof(P[i], add) > 0)
					swap(add.b, add.c);
				to[make_pair(add.a,add.b)] = to[make_pair(add.b,add.c)] = to[make_pair(add.c,add.a)] = cnt;
				F[cnt++] = add;
				totalvolume+=volume(P[F[cnt-1].a],P[F[cnt-1].b],P[F[cnt-1].c]);
			}


			for(int i=4;i<n;i++)
			{
				for (int j = 0; j < cnt; j++)
					if (F[j].ok && pointof(P[i], F[j]) > eps)
					{
						dfs(i, j);
						break;
					}
			}
			return 1;
		}
		else
		{
            for (int j = 0; j < cnt; j++)
				if (F[j].ok && pointof(P[n-1], F[j]) > eps)
                {
                    dfs(n-1, j);
                    return 1;
                }
			return 0;
		}
	}

	void solve(int _n)
	{
		init();
		double ans=0;
		int id=1;
		for(int i=1;i<=_n;i++)
		{
			point now;now.read();
			totalvolume=0;
			if(add(now)&&(totalvolume-ans)>eps)
			{
				id=i;
				ans=totalvolume;
			}
		}
		if(ans<eps)ans=0;
		printf("%d %.2f\n",id,ans/6);
	}
}gao;


int main()
{
	int n,cas=0;
	while(~scanf("%d",&n))
	{
		printf("Case #%d:\n",++cas);
		gao.solve(n);
	}
}
