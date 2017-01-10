// BEGIN CUT HERE
package TopCoder;
// END CUT HERE

import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

import javafx.util.Pair;


public class BearBall {
	public int countThrows(int[] x, int[] y) {
		int edge[][] = new int [2000][2000];
		int n = x.length;
		for (int i = 0; i < n; i++) {
			Map<Pair<Integer, Integer>, Integer> mp = new HashMap<>();
			for (int j = 0 ; j < n; j++) {
				if (j==i)continue;
				int dx = x[j] - x[i];
				int dy = y[j] - y[i];
				long dis = (long)dx*dx + (long)dy*dy;
				int g = BigInteger.valueOf(dx).gcd(BigInteger.valueOf(dy)).intValue();
				if (g < 0 ) g = -g;
				dx /= g;
				dy /= g;
				Pair<Integer, Integer> now = new Pair<Integer, Integer>(dx, dy);
				if (mp.containsKey(now)) {
					int id = mp.get(now);
					int dxx = x[id] - x[i];
					int dyy = y[id] - y[i];
					long dis1 = (long)dxx*dxx + (long)dyy*dyy;
					if(dis < dis1) {
						mp.remove(now);
						mp.put(now, j);
					}
				} else {
					mp.put(now, j);
				}
			}
			for(int id: mp.values()) {
				edge[i][++edge[i][0]] = id;
			}
		}
		int ans = 0;
		for (int i=0; i<n ;i++) {
			int[] dist = new int[2000];
			int[] q = new int[2000];
			q[0] = i;
			dist[i] = 0;
			int l = 0 , r= 0;
			while(l<=r) {
				int now =q[l];
				l++;
				for (int j = 1;j<=edge[now][0];j++) {
					int nx = edge[now][j];
					if (nx != i && dist[nx]==0) {
						dist[nx] = dist[now] + 1;
						q[++r] = nx;
					}
				}
			}
			for (int j = 0 ; j < n; j++) ans +=dist[j];
		}
		return ans;
	}
	// BEGIN CUT HERE
	public static void main(String[] args) {
		if (args.length == 0) {
			BearBallHarness.run_test(-1);
		} else {
			for (int i=0; i<args.length; ++i)
				BearBallHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class BearBallHarness {
	public static void run_test(int casenum) {
		if (casenum != -1) {
			if (runTestCase(casenum) == -1)
				System.err.println("Illegal input! Test case " + casenum + " does not exist.");
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = runTestCase(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			System.err.println("No test cases run.");
		} else if (correct < total) {
			System.err.println("Some cases FAILED (passed " + correct + " of " + total + ").");
		} else {
			System.err.println("All " + total + " tests passed!");
		}
	}

	static boolean compareOutput(int expected, int result) { return expected == result; }
	static String formatResult(int res) {
		return String.format("%d", res);
	}

	static int verifyCase(int casenum, int expected, int received) {
		System.err.print("Example " + casenum + "... ");
		if (compareOutput(expected, received)) {
			System.err.println("PASSED");
			return 1;
		} else {
			System.err.println("FAILED");
			System.err.println("    Expected: " + formatResult(expected));
			System.err.println("    Received: " + formatResult(received));
			return 0;
		}
	}

	static int runTestCase(int casenum__) {
		switch(casenum__) {
		case 0: {
			int[] x                   = {1,4,2};
			int[] y                   = {1,10,7};
			int expected__            = 6;

			return verifyCase(casenum__, expected__, new BearBall().countThrows(x, y));
		}
		case 1: {
			int[] x                   = {0,0,0,1,1};
			int[] y                   = {0,1,2,0,1};
			int expected__            = 22;

			return verifyCase(casenum__, expected__, new BearBall().countThrows(x, y));
		}
		case 2: {
			int[] x                   = {5,7,9,11};
			int[] y                   = {4,3,2,1};
			int expected__            = 20;

			return verifyCase(casenum__, expected__, new BearBall().countThrows(x, y));
		}
		case 3: {
			int[] x                   = {10,10,50,50,90,90};
			int[] y                   = {5,17,5,17,5,17};
			int expected__            = 34;

			return verifyCase(casenum__, expected__, new BearBall().countThrows(x, y));
		}
		case 4: {
			int[] x                   = {-100, -90, -80, -70, -85, -90, 0, 20};
			int[] y                   = {-5, -8, -13, -21, -13, -13, -13, -69};
			int expected__            = 68;

			return verifyCase(casenum__, expected__, new BearBall().countThrows(x, y));
		}

		// custom cases

		/*      case 5: {
			int[] x                   = ;
			int[] y                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new BearBall().countThrows(x, y));
		}*/
		/*      case 6: {
			int[] x                   = ;
			int[] y                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new BearBall().countThrows(x, y));
		}*/
		/*      case 7: {
			int[] x                   = ;
			int[] y                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new BearBall().countThrows(x, y));
		}*/
		/*      case 8: {
			int[] x                   = ;
			int[] y                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new BearBall().countThrows(x, y));
		}*/
		/*      case 9: {
			int[] x                   = ;
			int[] y                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new BearBall().countThrows(x, y));
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
