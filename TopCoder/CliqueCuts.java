// BEGIN CUT HERE
package TopCoder;

// END CUT HERE

public class CliqueCuts {
	private static int MOD = 1000000007;
	private int add(int a,int b) {
		int ans = a + b;
		if (ans >= MOD) ans -= MOD;
		if (ans < 0) ans += MOD;
		return ans;
	}
	int findbit(int n) {
		for (int i =0 ;;i++)if ((1<<i)==n) return i;
	}
	public int sum(int n, int[] a, int[] b, int[] c) {
		int ans = 0;
		int l = n/2;
		int r = n - l;
		int ws[] = new int[n];
		long sta[] = new long[n];

		int SUM = 0;
		for (int i = 0; i < a.length; i++) {
			ws[a[i]] = add(ws[a[i]], c[i]);
			ws[b[i]] = add(ws[b[i]], c[i]);
			SUM = add(SUM, c[i]);
			sta[a[i]] |= 1L<<b[i];
			sta[b[i]] |= 1L<<a[i];
		}

		int lcnt[] = new int[1<<l];
		int rcnt[] = new int[1<<r];

		int lsum[] = new int[1<<l];
		int rsum[] = new int[1<<r];

		int lsta[] = new int[1<<l];
		int rsta[] = new int[1<<r];

		int ldp[] = new int[1<<l];
		int rdp[] = new int[1<<r];

		lcnt[0] = 1;
		lsta[0] = (1<<r) - 1;
		for (int i = 1; i < (1<<l); i++) {
			int lastpos = findbit(i&-i);
			int pre = i - (i & -i);
			lsum[i] = add(ws[lastpos], lsum[pre]);
			lsta[i] = (int)(sta[lastpos] >> l) & lsta[pre];
			if (lcnt[pre] == 1 && (sta[lastpos] & pre) == pre) {
				lcnt[i] = 1;
				ans = add(ans, lsum[i]);
				ans = add(ans, -SUM);
			}
			ldp[i] = lcnt[i];
		}
		System.out.println(ans);

		rcnt[0] = 1;
		rsta[0] = (1<<l) - 1;
		for (int i = 1; i < (1<<r); i++) {
			int lastpos = findbit(i&-i);
			int pre = i - (i & -i);
			rsum[i] = add(ws[lastpos + l], rsum[pre]);
			rsta[i] = (int)(sta[lastpos + l] & rsta[pre]);
			if (rcnt[pre] == 1 && ((sta[lastpos + l] >> l) & pre) == pre) {
				rcnt[i] = 1;
				ans = add(ans, rsum[i]);
				ans = add(ans, -SUM);
			}
			rdp[i] = rcnt[i];
		}
		System.out.println(ans);

		for (int i = 0 ; i < l; i++)
			for (int j = 0; j < (1<<l); j++)
				if((j & (1 << i)) > 0) {
					ldp[j] += ldp[j^(1<<i)];
				}

		for (int i = 0 ; i < r; i++)
			for (int j = 0; j < (1<<r); j++)
				if((j & (1 << i)) > 0) {
					rdp[j] += rdp[j^(1<<i)];
				}


		for (int i = 1; i < (1<<l); i++) if (lcnt[i] == 1) {
			ans = add(ans, (int)(1L * (lsum[i] - SUM) * rdp[lsta[i]] % MOD));
		}

		for (int i = 1; i < (1<<r); i++) if (rcnt[i] == 1) {
			ans = add(ans, (int)(1L * rsum[i] * ldp[rsta[i]] % MOD));
		}

		return ans;
	}
	// BEGIN CUT HERE
	public static void main(String[] args) {
		if (args.length == 0) {
			CliqueCutsHarness.run_test(-1);
		} else {
			for (int i=0; i<args.length; ++i)
				CliqueCutsHarness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}
// BEGIN CUT HERE
class CliqueCutsHarness {
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
			int[] a                   = {0};
			int[] b                   = {1};
			int[] c                   = {100};
			int expected__            = 100;

			return verifyCase(casenum__, expected__, new CliqueCuts().sum(n, a, b, c));
		}
		case 1: {
			int n                     = 5;
			int[] a                   = {0,0,0,0,1,1,1,2,2,3};
			int[] b                   = {1,2,3,4,2,3,4,3,4,4};
			int[] c                   = {0,1,2,3,4,5,6,7,8,9};
			int expected__            = 45;

			return verifyCase(casenum__, expected__, new CliqueCuts().sum(n, a, b, c));
		}
		case 2: {
			int n                     = 5;
			int[] a                   = {0,1,2,3};
			int[] b                   = {1,2,3,4};
			int[] c                   = {9,2,4,3};
			int expected__            = 999999941;

			return verifyCase(casenum__, expected__, new CliqueCuts().sum(n, a, b, c));
		}
		case 3: {
			int n                     = 10;
			int[] a                   = {0,1,2,9,5,3,4,7,3,4,1,5,2,3,0,7,8};
			int[] b                   = {6,7,4,5,6,2,6,3,1,8,2,0,9,9,8,2,5};
			int[] c                   = {10000,10000000,100000000,100,10,1,1000,100,10000,100,10000,1000,100,10,100,100000000,10};
			int expected__            = 209370454;

			return verifyCase(casenum__, expected__, new CliqueCuts().sum(n, a, b, c));
		}
		case 4: {
			int n                     = 45;
			int[] a                   = {};
			int[] b                   = {};
			int[] c                   = {};
			int expected__            = 0;

			return verifyCase(casenum__, expected__, new CliqueCuts().sum(n, a, b, c));
		}

		// custom cases

		/*      case 5: {
			int n                     = ;
			int[] a                   = ;
			int[] b                   = ;
			int[] c                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new CliqueCuts().sum(n, a, b, c));
		}*/
		/*      case 6: {
			int n                     = ;
			int[] a                   = ;
			int[] b                   = ;
			int[] c                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new CliqueCuts().sum(n, a, b, c));
		}*/
		/*      case 7: {
			int n                     = ;
			int[] a                   = ;
			int[] b                   = ;
			int[] c                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new CliqueCuts().sum(n, a, b, c));
		}*/
		/*      case 8: {
			int n                     = ;
			int[] a                   = ;
			int[] b                   = ;
			int[] c                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new CliqueCuts().sum(n, a, b, c));
		}*/
		/*      case 9: {
			int n                     = ;
			int[] a                   = ;
			int[] b                   = ;
			int[] c                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new CliqueCuts().sum(n, a, b, c));
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
