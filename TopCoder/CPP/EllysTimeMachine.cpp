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

class EllysTimeMachine {
public:
    string getTime(string time) {
      int x = (time[0] - '0') * 10 + time[1] - '0';
	  int y = (time[3] - '0') * 10 + time[4] - '0';
	  y /= 5;
	  x *= 5;
	  string ans = "";
	  ans += y/10 + '0';
	  ans += y%10 + '0';
	  ans +=":";
	  ans += x/10 + '0';
	  ans += x%10 + '0';
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
			string time               = "11:20";
			string expected__         = "04:55";

			std::clock_t start__      = std::clock();
			string received__         = EllysTimeMachine().getTime(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string time               = "02:25";
			string expected__         = "05:10";

			std::clock_t start__      = std::clock();
			string received__         = EllysTimeMachine().getTime(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string time               = "06:30";
			string expected__         = "06:30";

			std::clock_t start__      = std::clock();
			string received__         = EllysTimeMachine().getTime(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string time               = "05:55";
			string expected__         = "11:25";

			std::clock_t start__      = std::clock();
			string received__         = EllysTimeMachine().getTime(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string time               = "03:45";
			string expected__         = "09:15";

			std::clock_t start__      = std::clock();
			string received__         = EllysTimeMachine().getTime(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string time               = "01:00";
			string expected__         = "12:05";

			std::clock_t start__      = std::clock();
			string received__         = EllysTimeMachine().getTime(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string time               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EllysTimeMachine().getTime(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string time               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EllysTimeMachine().getTime(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string time               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EllysTimeMachine().getTime(time);
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
