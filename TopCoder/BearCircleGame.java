// BEGIN CUT HERE
package TopCoder;

import java.math.BigInteger;

// END CUT HERE

public class BearCircleGame {
	static int M = 1000000007;
	static int exp(long inv2, long inv) {
		int ans = 1;
		while(inv > 0) {
			if(inv % 2 == 1) {
				ans = (int) (ans * inv2 %M);
			}
			inv2 = (int) (inv2 * inv2 % M);
		}
		return ans;
	}
	public int winProbability(int n, int k) {
		long[] now = new long[2000];
		long[] pre = new long[2000];
		long M = 1000000007;
		pre[0] = 1;
		long inv2 = (M+1)/2;
		for (int i = 2; i<=n; i++) {
			int g = BigInteger.valueOf(k).gcd(BigInteger.valueOf(i)).intValue();
			if (k%n==0) {
				now[0] = inv2 * pre[0];
				for (int j = 1 ; j < i ; j++) now[j] = 1;
			} else {
				long inv = 1;
				while(inv*(k/g) % (i/g) != 1) inv++;
			}
		}
		return 0;
	}
	// BEGIN CUT HERE
	public static void main(String[] args) {
		if (args.length == 0) {
			BearCircleGameHarness.run_test(-1);
		} else {
			for (int i=0; i<args.length; ++i)
				BearCircleGameHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}
// BEGIN CUT HERE
class BearCircleGameHarness {
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
			int n                     = 2;
			int k                     = 1;
			int expected__            = 333333336;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}
		case 1: {
			int n                     = 2;
			int k                     = 2;
			int expected__            = 1;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}
		case 2: {
			int n                     = 3;
			int k                     = 2;
			int expected__            = 142857144;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}
		case 3: {
			int n                     = 3;
			int k                     = 1;
			int expected__            = 238095240;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}
		case 4: {
			int n                     = 4;
			int k                     = 4;
			int expected__            = 142857144;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}
		case 5: {
			int n                     = 5;
			int k                     = 1000000000;
			int expected__            = 142857144;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}
		case 6: {
			int n                     = 2000;
			int k                     = 123;
			int expected__            = 429232785;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}
		case 7: {
			int n                     = 1987;
			int k                     = 987654321;
			int expected__            = 623410299;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}

		// custom cases

		/*      case 8: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}*/
		/*      case 9: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}*/
		/*      case 10: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}*/
		/*      case 11: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}*/
		/*      case 12: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new BearCircleGame().winProbability(n, k));
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
