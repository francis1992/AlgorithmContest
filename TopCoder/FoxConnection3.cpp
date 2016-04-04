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

class FoxConnection3 {
public:
	long long ans;
	vector <int> X,Y;
	void dfs(vector <int> l,vector <int> r,int n)
	{
		if(n==0)
		{
			vector < pair<int,int> > p;
			for(int i=0;i<l.size();i++)
			{
				for(int j=l[i];j<=r[i];j++)
				{
					p.push_back(make_pair(i,j));
				}
			}
			sort(p.begin(),p.end());
			do
			{
				vector <int> xx,yy;
				for(int i=0;i<X.size();i++)
				{
					xx.push_back(p[i].first-X[i]);
					yy.push_back(p[i].second-Y[i]);
				}
				sort(xx.begin(),xx.end());
				sort(yy.begin(),yy.end());
				long long s=0;
				for(int i=0;i<xx.size();i++)s+=abs(xx[i]-xx[xx.size()/2]);
				for(int i=0;i<yy.size();i++)s+=abs(yy[i]-yy[yy.size()/2]);
				ans=min(ans,s);
			}while(next_permutation(p.begin(),p.end()));
			return;
		}
		int L=l[l.size()-1],R=r[r.size()-1];
		for(int i=L-n;i<=R+n;i++)
			for(int j=1;j<=n;j++)
				if(max(i,L)<=min(i+j-1,R))
				{
					l.push_back(i);
					r.push_back(i+j-1);
					dfs(l,r,n-j);
					l.pop_back();
					r.pop_back();
				}
	}
    long long minimalSteps(vector <int> x, vector <int> y) {
		X=x;Y=y;ans=1LL<<60;
		int n=x.size();
		for(int i=1;i<=n;i++)
		{
			vector <int> l,r;
			l.push_back(1);r.push_back(i);
			dfs(l,r,n-i);
		}
		return ans;
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
			int x[]                   = {0,0,1,-2};
			int y[]                   = {1,-1,0,0};
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = FoxConnection3().minimalSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,0,0,0,0,0};
			int y[]                   = {1,2,3,4,5,6};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = FoxConnection3().minimalSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {-123456789,-58585858,-47474747,123,456,789012345};
			int y[]                   = {0,0,0,0,0,0};
			long long expected__      = 1018530309;

			std::clock_t start__      = std::clock();
			long long received__      = FoxConnection3().minimalSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {1,7,3,5,2};
			int y[]                   = {2,7,5,3,7};
			long long expected__      = 12;

			std::clock_t start__      = std::clock();
			long long received__      = FoxConnection3().minimalSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {-3,0,1,-2,3,2};
			int y[]                   = {2,-3,0,1,-1,-1};
			long long expected__      = 10;

			std::clock_t start__      = std::clock();
			long long received__      = FoxConnection3().minimalSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {-96277832,507856257,-86306299,-806700273,-775932643,-273209838};
			int y[]                   = {-955536464,-599634138,399850429,-165706338,-537800480,738983556};
			long long expected__      = 5247213600LL;

			std::clock_t start__      = std::clock();
			long long received__      = FoxConnection3().minimalSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x[]                   = {0};
			int y[]                   = {0};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = FoxConnection3().minimalSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = FoxConnection3().minimalSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = FoxConnection3().minimalSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = FoxConnection3().minimalSteps(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
