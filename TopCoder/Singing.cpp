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
#define captype int
const int MAXN=100010;
const int oo=1000000;
struct Edge
{
    int s,e,nx;
    captype c;
}E[1000000];
int head[MAXN],cnt;
void add(int s,int e,captype c)
{
	cout<<s<<" "<<e<<" "<<c<<endl;
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
class Singing {
public:
    int solve(int n, int low, int high, vector <int> pitch) {
	   int s=0;	   
	   int t=n+1;
	   memset(head,-1,sizeof(head));
	   cnt=0;
	   for(int i=1;i<low;i++)add(s,i,oo);
	   for(int i=high+1;i<=n;i++)add(i,t,oo);
	   for(int i=0;i<pitch.size()-1;i++)
	   {
		   int a=pitch[i];
		   int b=pitch[i+1];
		   if(a!=b){
			   add(a,b,1);
			   add(b,a,1);
		   }
	   }
	   return isap(n+2,s,t);
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 3;
			int low                   = 2;
			int high                  = 2;
			int pitch[]               = {1,2,3,2,1,2};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 10;
			int low                   = 3;
			int high                  = 7;
			int pitch[]               = {4,4,5,5,6,5,3,6};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 6;
			int low                   = 2;
			int high                  = 5;
			int pitch[]               = {5,3,1,6,4,2};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 10;
			int low                   = 4;
			int high                  = 5;
			int pitch[]               = {1,4,3,5,2,5,7,5,9};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 100;
			int low                   = 20;
			int high                  = 80;
			int pitch[]               = {2,27,3,53,53,52,52,60,85,89,100,53,60,2,3,53,100,89,40,42,2,53,2,85};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int low                   = ;
			int high                  = ;
			int pitch[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int low                   = ;
			int high                  = ;
			int pitch[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int low                   = ;
			int high                  = ;
			int pitch[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Singing().solve(N, low, high, vector <int>(pitch, pitch + (sizeof pitch / sizeof pitch[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
