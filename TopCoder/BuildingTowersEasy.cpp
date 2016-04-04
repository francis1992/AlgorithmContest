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

class BuildingTowersEasy {
public:
    int maxHeight(int N, vector <int> x, vector <int> t) {
		int ans=0;
		for(int i=1;i<=N;i++)
		{
			int s=i-1;
			for(int j=0;j<x.size();j++)
				s=min(s,abs(x[j]-i)+t[j]);
			ans=max(ans,s);
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
			int N                     = 10;
			int x[]                   = {3,8};
			int t[]                   = {1,1};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 100000;
			int x[]                   = {};
			int t[]                   = {};
			int expected__            = 99999;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 2718;
			int x[]                   = {1,30,400,1300,2500};
			int t[]                   = {100000,100000,100000,100000,100000};
			int expected__            = 2717;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 20;
			int x[]                   = {4,7,13,15,18};
			int t[]                   = {3,8,1,17,16};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 447;
			int x[]                   = {32,35,55,60,61,88,91,97,128,151,181,186,192,196,198,237,259,268,291,314,341,367,389,390,391,428,435};
			int t[]                   = {81,221,172,641,25,953,330,141,123,440,692,394,200,649,78,726,50,810,501,4,216,407,2,172,0,29,14};
			int expected__            = 120;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 97638;
			int x[]                   = {8,1749,4550,5388,6752,7089,9737,14891,16671,16821,17691,19753,24589, 25348,30114,32213,34376,36467,37699,41490,44784,44893,57316,58275,58567, 61122,61489,63195,64776,65905,68788,69908,72853,78152,78784,82779,84488, 86277,88611,92793,93214,97583};
			int t[]                   = {16610,6,497,14,42892,31,79,1203,518,31147,597,7846,1396,8309,12,14,1148, 433,23693,13,1939,244,19,46,27,611,412,10,27023,19141,34,15667,588,10,229, 83,390,14,38441,16021,4,39386};
			int expected__            = 6343;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int x[]                   = ;
			int t[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int x[]                   = ;
			int t[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int x[]                   = ;
			int t[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingTowersEasy().maxHeight(N, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
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
