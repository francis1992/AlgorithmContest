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

class EllysTree {
public:
	vector <int> f;
	vector <int> e[1111];
	bool g[1111][1111];
	bool vis[1111];
	bool flag;
	int NOW;
	bool dfs(int x, int notvis) {
		int cnt = 0;
		for(int i = 0; i < e[x].size(); i++) {
			if(!vis[e[x][i]]) {
				if(dfs(e[x][i], notvis+1)) cnt++;
			} else {
				if(dfs(e[x][i], notvis)) cnt++;
			}
		}
		if(notvis < cnt) {
			flag = false;
		}
		if(g[x][NOW])return false;
		if(cnt || !vis[x]) return true;
		return false;
	}
	int pre;
	bool check(int now) {
		if(!g[now][pre] && !g[pre][now]) return false;
		flag = true;
		NOW = now;
		dfs(0, !vis[0]);
		return flag;
	}
    vector <int> getMoves(vector <int> parent) {
		f = parent;
		int n = parent.size();
		memset(g, 0, sizeof(g));
		for(int i = 0 ; i <= n ; i++) {
			e[i].clear();
			g[i][i] = 1;
		}
		for(int i = 0; i < n; i++) {
			e[parent[i]].push_back(i+1);
			int x = i + 1;
			while(true) {
				g[x][i+1] = 1;
				if ( x == 0) break;
				x = parent[x - 1];
			}
		}
		vector <int> ans;
		if(!check(0)) {
			return ans;
		}
		memset(vis, 0, sizeof(vis));
		vis[0] = 1;
		pre = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= n; j++) {
				if(!vis[j] && check(j)) {
					ans.push_back(j);
					pre = j;
					vis[j] = 1;
					break;
				}	
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int parent[]              = {9, 13, 7, 9, 8, 14, 14, 0, 6, 9, 2, 2, 5, 5, 7};
			int expected__[]          = {1, 5, 2, 11, 13, 12, 8, 3, 7, 15, 14, 4, 6, 9, 10 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int parent[]              = {0, 1};
			int expected__[]          = {1, 2};

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int parent[]              = {0, 0};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int parent[]              = {0, 6, 6, 2, 6, 1, 3, 5};
			int expected__[]          = {2, 4, 1, 3, 7, 6, 5, 8 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int parent[]              = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int parent[]              = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int parent[]              = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
