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

class JanuszTheBusinessman {
public:
    int makeGuestsReturn(vector <int> a, vector <int> b) {
		int ans=0;
		bool vis[55];
		memset(vis,0,sizeof(vis));
		while(1)
		{
			int minr=1000;
			for(int i=0;i<b.size();i++)if(!vis[i])
				minr=min(minr,b[i]);
			if(minr==1000)break;
			int x=0;
			for(int i=0;i<a.size();i++)
				if(a[i]<=minr)
					x=max(x,b[i]);
			ans++;
			for(int i=0;i<a.size();i++)
			{
				if(max(minr,a[i])<=min(x,b[i]))
					vis[i]=1;
			}
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
			int arrivals[]            = {2, 10, 6} ;
			int departures[]          = {6, 11, 9};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = JanuszTheBusinessman().makeGuestsReturn(vector <int>(arrivals, arrivals + (sizeof arrivals / sizeof arrivals[0])), vector <int>(departures, departures + (sizeof departures / sizeof departures[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int arrivals[]            = {2, 10, 23, 34, 45, 123, 1};
			int departures[]          = {25, 12, 40, 50, 48, 187, 365};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = JanuszTheBusinessman().makeGuestsReturn(vector <int>(arrivals, arrivals + (sizeof arrivals / sizeof arrivals[0])), vector <int>(departures, departures + (sizeof departures / sizeof departures[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int arrivals[]            = {8, 12, 20, 30, 54, 54, 68, 75};
			int departures[]          = {13, 31, 30, 53, 55, 70, 80, 76};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = JanuszTheBusinessman().makeGuestsReturn(vector <int>(arrivals, arrivals + (sizeof arrivals / sizeof arrivals[0])), vector <int>(departures, departures + (sizeof departures / sizeof departures[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int arrivals[]            = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148};
			int departures[]          = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = JanuszTheBusinessman().makeGuestsReturn(vector <int>(arrivals, arrivals + (sizeof arrivals / sizeof arrivals[0])), vector <int>(departures, departures + (sizeof departures / sizeof departures[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int arrivals[]            = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6};
			int departures[]          = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13};
			int expected__            = 14;

			std::clock_t start__      = std::clock();
			int received__            = JanuszTheBusinessman().makeGuestsReturn(vector <int>(arrivals, arrivals + (sizeof arrivals / sizeof arrivals[0])), vector <int>(departures, departures + (sizeof departures / sizeof departures[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int arrivals[]            = ;
			int departures[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = JanuszTheBusinessman().makeGuestsReturn(vector <int>(arrivals, arrivals + (sizeof arrivals / sizeof arrivals[0])), vector <int>(departures, departures + (sizeof departures / sizeof departures[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int arrivals[]            = ;
			int departures[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = JanuszTheBusinessman().makeGuestsReturn(vector <int>(arrivals, arrivals + (sizeof arrivals / sizeof arrivals[0])), vector <int>(departures, departures + (sizeof departures / sizeof departures[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int arrivals[]            = ;
			int departures[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = JanuszTheBusinessman().makeGuestsReturn(vector <int>(arrivals, arrivals + (sizeof arrivals / sizeof arrivals[0])), vector <int>(departures, departures + (sizeof departures / sizeof departures[0])));
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
