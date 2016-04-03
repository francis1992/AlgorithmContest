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
const int oo=1000000000;
const int M=(int)1e9+7;

class KitayutaMart {
public:
	void checkmin(pair<int,int> &a,pair<int,int> b)
	{
		if(b.second-a.second>30)return;
		if(a.second-b.second>30)
		{
			a=b;
			return;
		}
		if(a.second<=b.second)
		{
			if(a.first>b.first*(1LL<<(b.second-a.second)))a=b;
		}
		else
		{
			if(a.first*(1LL<<(a.second-b.second))>b.first)a=b;
		}
	}
	long long cal(int i,int mid,long long K)
	{
		long long s=0;
		long long now=i;
		int p=mid;
		while(p>=1)
		{
			p--;
			s+=(p+1)*(min(K,2*now)-now);
			if(s>=oo)return s;
			now=min(K,2*now);
			if(now==K)break;
		}
		now=i;
		p=mid;
		while(now)
		{
			s+=(p+1)*(now-now/2);
			if(s>=oo)return s;
			p++;
			now/=2;
		}
		return s;
	}
	int lastPrice(int N, int K) {
		pair <int,int> ans=make_pair(1,N-1);
		if(K<=100000)
		{
			for(int i=1;i<=K;i++)
			{
				int l=0,r=N-1;
				while(l<r)
				{
					int mid=(l+r)/2;
					if(cal(i,mid,K)>=N)
					{
						r=mid;
					}
					else
					{
						l=mid+1;
					}
				}
				checkmin(ans,make_pair(i,l));
			}
		}
		else
		{
			for(int i=0;i<=100000;i++)
			{
				int l=1,r=K;
				while(l<r)
				{
					int mid=(l+r)/2;
					if(cal(mid,i,K)>=N)
					{
						r=mid;
					}
					else
					{
						l=mid+1;
					}
				}
				if(cal(l,i,K)>=N)
					checkmin(ans,make_pair(l,i));
			}
		}
		int ret=ans.first%M;
		long long a=2;
		while(ans.second)
		{
			if(ans.second&1)ret=a*ret%M;
			a=a*a%M;
			ans.second>>=1;
		}
		return ret;
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
			int K                     = 1;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = KitayutaMart().lastPrice(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int K                     = 2;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = KitayutaMart().lastPrice(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 5;
			int K                     = 3;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = KitayutaMart().lastPrice(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 1000000000;
			int K                     = 1;
			int expected__            = 570312504;

			std::clock_t start__      = std::clock();
			int received__            = KitayutaMart().lastPrice(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 987654321;
			int K                     = 876543210;
			int expected__            = 493827168;

			std::clock_t start__      = std::clock();
			int received__            = KitayutaMart().lastPrice(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = KitayutaMart().lastPrice(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = KitayutaMart().lastPrice(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = KitayutaMart().lastPrice(N, K);
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
