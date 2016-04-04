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
const int M=(int)1e9+7;
class TaroFillingAStringDiv1 {
public:
    int getNumber(int N, vector <int> position, string value) {		
		vector < pair<int,char> > a;
		for(int i=0;i<position.size();i++)
		{
			a.push_back(make_pair(position[i],value[i]));
		}
		sort(a.begin(),a.end());
		int ans=1;
		for(int i=0;i<a.size()-1;i++)
		{
			int len=a[i+1].first-a[i].first-1;
			if(len==0)continue;
			if((a[i].second==a[i+1].second && len%2==0) || (a[i].second!=a[i+1].second && len%2==1))
			{
				ans=1LL*ans*(len+1)%M;
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
			int N                     = 3;
			int position[]            = {1, 3};
			string value              = "AB";
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv1().getNumber(N, vector <int>(position, position + (sizeof position / sizeof position[0])), value);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 4;
			int position[]            = {2, 1, 3, 4};
			string value              = "ABBA";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv1().getNumber(N, vector <int>(position, position + (sizeof position / sizeof position[0])), value);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 25;
			int position[]            = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13};
			string value              = "ABBBBABABBAAABA";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv1().getNumber(N, vector <int>(position, position + (sizeof position / sizeof position[0])), value);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 305;
			int position[]            = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246};
			string value              = "ABAABBABBAABABBBBAAAABBABBBA";
			int expected__            = 43068480;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv1().getNumber(N, vector <int>(position, position + (sizeof position / sizeof position[0])), value);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int position[]            = ;
			string value              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv1().getNumber(N, vector <int>(position, position + (sizeof position / sizeof position[0])), value);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int position[]            = ;
			string value              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv1().getNumber(N, vector <int>(position, position + (sizeof position / sizeof position[0])), value);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int position[]            = ;
			string value              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TaroFillingAStringDiv1().getNumber(N, vector <int>(position, position + (sizeof position / sizeof position[0])), value);
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
