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

unsigned int a[131072];

int nx[30*131072][2];
int cnt[30*131072];
int pt;
int newnode()
{
	memset(nx[pt],0,sizeof(nx[pt]));
	cnt[pt]=0;
	return pt++;
}
void init()
{
	pt=0;
	newnode();
}
void insert(int x,int n)
{
	int now=0;
	for(int i=n-1;i>=0;i--)
	{
		int v = x>>i&1;
		cnt[now]++;
		if(!nx[now][v])
			nx[now][v]=newnode();
		now=nx[now][v];
	}
	cnt[now]++;
}


class XorSequence {
public:
    long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R) {
		a[0]=A0;
		a[1]=A1;
		for(int i=2;i<sz;i++)
		{
			a[i]=(a[i-2]*P+a[i-1]*Q+R)&(N-1);
		}
		for(int i=0;;i++)if((1<<i)==N)
		{
			N=i;
			break;
		}
		long long ans[30][2];
		memset(ans,0,sizeof(ans));
		init();
		for(int i=0;i<sz;i++)
		{
			int now=0;
			for(int j=N-1;j>=0;j--)
			{
				int v=a[i]>>j&1;
				if(nx[now][v^1])ans[j][v^1]+=cnt[nx[now][v^1]];
				if(nx[now][v])now=nx[now][v];
				else break;
			}
			insert(a[i],N);
		}
        long long sum=0;
		for(int i=0;i<N;i++)sum+=max(ans[i][0],ans[i][1]);
		return sum;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int N                     = 4;
			int sz                    = 6;
			int A0                    = 3;
			int A1                    = 2;
			int P                     = 0;
			int Q                     = 1;
			int R                     = 3;
			long long expected__      = 8;

			std::clock_t start__      = std::clock();
			long long received__      = XorSequence().getmax(N, sz, A0, A1, P, Q, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 8;
			int sz                    = 8;
			int A0                    = 2;
			int A1                    = 5;
			int P                     = 3;
			int Q                     = 1;
			int R                     = 4;
			long long expected__      = 13;

			std::clock_t start__      = std::clock();
			long long received__      = XorSequence().getmax(N, sz, A0, A1, P, Q, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 8;
			int sz                    = 7;
			int A0                    = 3;
			int A1                    = 0;
			int P                     = 1;
			int Q                     = 2;
			int R                     = 4;
			long long expected__      = 12;

			std::clock_t start__      = std::clock();
			long long received__      = XorSequence().getmax(N, sz, A0, A1, P, Q, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 32;
			int sz                    = 15;
			int A0                    = 7;
			int A1                    = 9;
			int P                     = 11;
			int Q                     = 2;
			int R                     = 1;
			long long expected__      = 60;

			std::clock_t start__      = std::clock();
			long long received__      = XorSequence().getmax(N, sz, A0, A1, P, Q, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 131072;
			int sz                    = 131072;
			int A0                    = 7;
			int A1                    = 7;
			int P                     = 1;
			int Q                     = 0;
			int R                     = 0;
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = XorSequence().getmax(N, sz, A0, A1, P, Q, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 131072;
			int sz                    = 131070;
			int A0                    = 411;
			int A1                    = 415;
			int P                     = 398;
			int Q                     = 463;
			int R                     = 9191;
			long long expected__      = 4302679760LL;

			std::clock_t start__      = std::clock();
			long long received__      = XorSequence().getmax(N, sz, A0, A1, P, Q, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int sz                    = ;
			int A0                    = ;
			int A1                    = ;
			int P                     = ;
			int Q                     = ;
			int R                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = XorSequence().getmax(N, sz, A0, A1, P, Q, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int sz                    = ;
			int A0                    = ;
			int A1                    = ;
			int P                     = ;
			int Q                     = ;
			int R                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = XorSequence().getmax(N, sz, A0, A1, P, Q, R);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int sz                    = ;
			int A0                    = ;
			int A1                    = ;
			int P                     = ;
			int Q                     = ;
			int R                     = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = XorSequence().getmax(N, sz, A0, A1, P, Q, R);
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
