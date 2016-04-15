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

int dp[555][555];
long long s[555];
const int M=(int)1e9+7;

class HatParade {
public:
    int getPermutation(vector <int> value, vector <int> sum) {
		vector < pair<int,int> > a;
		for(int i=0;i<sum.size();i++)
			a.push_back(make_pair(sum[i],value[i]));
		sort(a.begin(),a.end());
		s[0]=0;
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i-1].first;
		memset(dp,0,sizeof(dp));
		int n=a.size();
		dp[0][n+1]=1;
		for(int i=0;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dp[i][j])
				{
					int p=j;
					for(int k=i+1;k<j;k++)
					{
						int de=a[k].first-a[i].first-a[k].second;
						while(p>k&&s[j-1]-s[p-1]<de&&a[p].first-a[p].second==a[p-1].first)p--;
						if(s[j-1]-s[p-1]==de)
						{

						}
					}
				}
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
			int value[]               = {2, 1, 3};
			int sum[]                 = {3, 1, 6};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = HatParade().getPermutation(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <int>(sum, sum + (sizeof sum / sizeof sum[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int value[]               = {1, 1, 1, 1};
			int sum[]                 = {9, 1, 2, 3};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = HatParade().getPermutation(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <int>(sum, sum + (sizeof sum / sizeof sum[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int value[]               = {4, 4, 4, 4};
			int sum[]                 = {16, 16, 8, 8};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = HatParade().getPermutation(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <int>(sum, sum + (sizeof sum / sizeof sum[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int value[]               = {1, 2, 3, 4, 5, 6, 7};
			int sum[]                 = {1, 27, 6, 22, 18, 21, 7};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = HatParade().getPermutation(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <int>(sum, sum + (sizeof sum / sizeof sum[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int value[]               = ;
			int sum[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HatParade().getPermutation(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <int>(sum, sum + (sizeof sum / sizeof sum[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int value[]               = ;
			int sum[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HatParade().getPermutation(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <int>(sum, sum + (sizeof sum / sizeof sum[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int value[]               = ;
			int sum[]                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = HatParade().getPermutation(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <int>(sum, sum + (sizeof sum / sizeof sum[0])));
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
