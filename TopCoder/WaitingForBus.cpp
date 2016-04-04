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

double dp[100001];
class WaitingForBus {
public:
    double whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
		dp[0]=1;
		for(int i=1;i<=s;i++)
		{
			dp[i]=0;
			for(int j=0;j<time.size();j++)
				if(i>=time[j])
					dp[i]+=dp[i-time[j]]*prob[j]/100;
		}
		double ans=0;
		for(int i=0;i<s;i++)
		{
			for(int j=0;j<time.size();j++)
				if(i+time[j]>s)
					ans+=(i+time[j]-s)*dp[i]*prob[j]/100;
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int time[]                = {5,100};
			int prob[]                = {90,10};
			int s                     = 5;
			double expected__         = 9.5;

			std::clock_t start__      = std::clock();
			double received__         = WaitingForBus().whenWillBusArrive(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(prob, prob + (sizeof prob / sizeof prob[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int time[]                = {5};
			int prob[]                = {100};
			int s                     = 101;
			double expected__         = 4.0;

			std::clock_t start__      = std::clock();
			double received__         = WaitingForBus().whenWillBusArrive(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(prob, prob + (sizeof prob / sizeof prob[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int time[]                = {5,10};
			int prob[]                = {50,50};
			int s                     = 88888;
			double expected__         = 3.666666666666667;

			std::clock_t start__      = std::clock();
			double received__         = WaitingForBus().whenWillBusArrive(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(prob, prob + (sizeof prob / sizeof prob[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int time[]                = {1,2,3,4};
			int prob[]                = {10,20,30,40};
			int s                     = 1000;
			double expected__         = 1.166666666666667;

			std::clock_t start__      = std::clock();
			double received__         = WaitingForBus().whenWillBusArrive(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(prob, prob + (sizeof prob / sizeof prob[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int time[]                = {10,100,1000,10000,100000};
			int prob[]                = {90,4,3,2,1};
			int s                     = 100000;
			double expected__         = 21148.147303578935;

			std::clock_t start__      = std::clock();
			double received__         = WaitingForBus().whenWillBusArrive(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(prob, prob + (sizeof prob / sizeof prob[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int time[]                = ;
			int prob[]                = ;
			int s                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = WaitingForBus().whenWillBusArrive(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(prob, prob + (sizeof prob / sizeof prob[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int time[]                = ;
			int prob[]                = ;
			int s                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = WaitingForBus().whenWillBusArrive(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(prob, prob + (sizeof prob / sizeof prob[0])), s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int time[]                = ;
			int prob[]                = ;
			int s                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = WaitingForBus().whenWillBusArrive(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <int>(prob, prob + (sizeof prob / sizeof prob[0])), s);
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
