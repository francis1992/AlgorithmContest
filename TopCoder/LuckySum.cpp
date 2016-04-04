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

class LuckySum {
public:
	void checkmin(long long &a,long long b)
	{
		if(a==-1||b<a)
			a=b;
	}
    long long construct(string note) {
		long long dp[20][2][2];
		long long po[20];
		po[0]=1;
		for(int i=1;i<20;i++)po[i]=po[i-1]*10;
		memset(dp,-1,sizeof(dp));
		int n = note.size();
		dp[n][0][0]=0;
		for(int i=n;i>0;i--)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					if(dp[i][j][k]!=-1)
					{
						if(!k)
						{
							for(int x=4;x<=7;x+=3)
								for(int y=4;y<=7;y+=3)
								{
									int v=x+y+j;
									if(note[i-1]=='?' || note[i-1]-'0' == v%10)
									{
										checkmin(dp[i-1][v/10][0],(v%10)*po[n-i]+dp[i][j][k]);
									}
								}
						}
						if(i!=n)
						for(int x=4;x<=7;x+=3)
						{
							int v=x+j;
							if(note[i-1]=='?' || note[i-1]-'0' == v%10)
							{
								checkmin(dp[i-1][v/10][1],(v%10)*po[n-i]+dp[i][j][k]);
							}
						}
					}
		long long ans=-1;
		if(dp[0][0][0]!=-1)
			checkmin(ans,dp[0][0][0]);
		if(dp[0][0][1]!=-1)
			checkmin(ans,dp[0][0][1]);
		if(note[0]=='?' || note[0] == '1')
		{
			if(dp[1][1][0]!=-1)
				checkmin(ans,dp[1][1][0]+po[n-1]);
			if(dp[1][1][1]!=-1)
				checkmin(ans,dp[1][1][1]+po[n-1]);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			string note               = "?";
			long long expected__      = 8;

			std::clock_t start__      = std::clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string note               = "?1";
			long long expected__      = 11;

			std::clock_t start__      = std::clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string note               = "4?8";
			long long expected__      = 448;

			std::clock_t start__      = std::clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string note               = "2??";
			long long expected__      = -1;

			std::clock_t start__      = std::clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string note               = "??????????????";
			long long expected__      = 11888888888888LL;

			std::clock_t start__      = std::clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string note               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string note               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = LuckySum().construct(note);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string note               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = LuckySum().construct(note);
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
