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
int dp[55][55][55][55];
void add(int &a,int b)
{
	a+=b;
	if(a>=mod)
		a-=mod;
}
class OkonomiyakiParty {
public:
    int count(vector <int> a, int M, int K) {
		sort(a.begin(),a.end());
        memset(dp,0,sizeof(dp));
		dp[0][0][0][0]=1;
		int n=a.size();
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				for(int k=0;k<=i;k++)
					for(int p=k;p<=i;p++)
						if(dp[i][j][k][p])
						{
							add(dp[i+1][j][k][p],dp[i][j][k][p]);
							add(dp[i+1][j+1][k==0?i+1:k][i+1],dp[i][j][k][p]);
						}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(a[j-1]-a[i-1]<=K)
					add(ans,dp[n][M][i][j]);
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
			int osize[]               = {1,4,6,7,9};
			int M                     = 2;
			int K                     = 3;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = OkonomiyakiParty().count(vector <int>(osize, osize + (sizeof osize / sizeof osize[0])), M, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int osize[]               = {1,6,2,7,4,2,6,1,5,2,4};
			int M                     = 4;
			int K                     = 3;
			int expected__            = 60;

			std::clock_t start__      = std::clock();
			int received__            = OkonomiyakiParty().count(vector <int>(osize, osize + (sizeof osize / sizeof osize[0])), M, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int osize[]               = {1,4,5,7,10,11,13,16,18};
			int M                     = 4;
			int K                     = 5;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = OkonomiyakiParty().count(vector <int>(osize, osize + (sizeof osize / sizeof osize[0])), M, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int osize[]               = {55,2,7,232,52,5,5332,623,52,6,532,5147};
			int M                     = 6;
			int K                     = 10000;
			int expected__            = 924;

			std::clock_t start__      = std::clock();
			int received__            = OkonomiyakiParty().count(vector <int>(osize, osize + (sizeof osize / sizeof osize[0])), M, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int osize[]               = {5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727, 1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452, 5682,7775,4356,5140,8923,9801,3729};
			int M                     = 15;
			int K                     = 4003;
			int expected__            = 114514;

			std::clock_t start__      = std::clock();
			int received__            = OkonomiyakiParty().count(vector <int>(osize, osize + (sizeof osize / sizeof osize[0])), M, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int osize[]               = ;
			int M                     = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OkonomiyakiParty().count(vector <int>(osize, osize + (sizeof osize / sizeof osize[0])), M, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int osize[]               = ;
			int M                     = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OkonomiyakiParty().count(vector <int>(osize, osize + (sizeof osize / sizeof osize[0])), M, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int osize[]               = ;
			int M                     = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = OkonomiyakiParty().count(vector <int>(osize, osize + (sizeof osize / sizeof osize[0])), M, K);
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
