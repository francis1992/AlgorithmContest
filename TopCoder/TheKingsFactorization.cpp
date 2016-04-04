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

class TheKingsFactorization {
public:
    vector<long long> getVector(long long N, vector<long long> primes) {
		vector <long long> ans;
		for(int i=0;i<primes.size();i++)while(N%primes[i]==0)
		{
			ans.push_back(primes[i]);
			N/=primes[i];
		}
		for(int i=2;i<=1000000;i++)while(N%i==0)
		{
			ans.push_back(i);
			N/=i;
		}
		if(N!=1)ans.push_back(N);
		sort(ans.begin(),ans.end());
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector<long long> &expected, const vector<long long> &received, std::clock_t elapsed) { 
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
			long long N               = 12;
			long long primes[]        = {2, 3};
			long long expected__[]    = {2, 2, 3};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = TheKingsFactorization().getVector(N, vector<long long>(primes, primes + (sizeof primes / sizeof primes[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			long long N               = 7;
			long long primes[]        = {7};
			long long expected__[]    = {7};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = TheKingsFactorization().getVector(N, vector<long long>(primes, primes + (sizeof primes / sizeof primes[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			long long N               = 1764;
			long long primes[]        = {2, 3, 7};
			long long expected__[]    = {2, 2, 3, 3, 7, 7};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = TheKingsFactorization().getVector(N, vector<long long>(primes, primes + (sizeof primes / sizeof primes[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			long long N               = 49;
			long long primes[]        = {7};
			long long expected__[]    = {7, 7};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = TheKingsFactorization().getVector(N, vector<long long>(primes, primes + (sizeof primes / sizeof primes[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			long long N               = 210;
			long long primes[]        = {2, 5};
			long long expected__[]    = {2, 3, 5, 7};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = TheKingsFactorization().getVector(N, vector<long long>(primes, primes + (sizeof primes / sizeof primes[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			long long N               = 100000;
			long long primes[]        = {2, 2, 2, 5, 5};
			long long expected__[]    = {2, 2, 2, 2, 2, 5, 5, 5, 5, 5};

			std::clock_t start__      = std::clock();
			vector<long long> received__ = TheKingsFactorization().getVector(N, vector<long long>(primes, primes + (sizeof primes / sizeof primes[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			long long N               = ;
			long long primes[]        = ;
			long long expected__[]    = ;

			std::clock_t start__      = std::clock();
			vector<long long> received__ = TheKingsFactorization().getVector(N, vector<long long>(primes, primes + (sizeof primes / sizeof primes[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			long long N               = ;
			long long primes[]        = ;
			long long expected__[]    = ;

			std::clock_t start__      = std::clock();
			vector<long long> received__ = TheKingsFactorization().getVector(N, vector<long long>(primes, primes + (sizeof primes / sizeof primes[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			long long N               = ;
			long long primes[]        = ;
			long long expected__[]    = ;

			std::clock_t start__      = std::clock();
			vector<long long> received__ = TheKingsFactorization().getVector(N, vector<long long>(primes, primes + (sizeof primes / sizeof primes[0])));
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
