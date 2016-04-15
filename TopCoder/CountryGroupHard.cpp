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

class CountryGroupHard {
public:
	bool check(vector <int> a,int l,int r)
	{
		for(int i=l;i<=r;i++)
			if(a[i] != 0 && a[i] != r-l+1)
				return false;
		return true;
	}
    string solve(vector <int> a) {
		bool dp[111];
		memset(dp,0,sizeof(dp));
		dp[0]=true;
		for(int i=-1;i<(int)a.size()-1;i++)if(dp[i+1])
			for(int j=i+1;j<a.size();j++)
			{
				if(check(a,i+1,j))
					dp[j+1]=true;
			}
		int now = a.size()-1;
		while(now>=0)
		{
			int pre;
			int cnt=0;
			for(int i=now;i>=0;i--)
			{
				if(dp[i-1+1]&&check(a,i,now))
				{
					cnt++;
					pre=i-1;
				}
			}
			if(cnt>1)
				return  "Insufficient";
			now=pre;
		}
		return "Sufficient";
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int a[]                   = {0,2,3,0,0};
			string expected__         = "Sufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {0,2,0};
			string expected__         = "Insufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {0,3,0,0,3,0};
			string expected__         = "Sufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {0,0,3,3,0,0};
			string expected__         = "Insufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {2,2,0,2,2};
			string expected__         = "Sufficient";

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CountryGroupHard().solve(vector <int>(a, a + (sizeof a / sizeof a[0])));
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
