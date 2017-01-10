// BEGIN CUT HERE
package TopCoder;
// END CUT HERE

public class GroupSRMDiv2 {
	public int FindGroups(int[] t) {
		int[] number = new int[501];
		for (int x : t) {
			number[x]++;
		}
		int ans = 0;
		for (int i = 1; i<=500;i++) {
			if (number[i]%i!=0) return -1;
			ans += number[i]/i;
		}
		return ans;
	}
	// BEGIN CUT HERE
	public static void main(String[] args) {
		if (args.length == 0) {
			GroupSRMDiv2Harness.run_test(-1);
		} else {
			for (int i=0; i<args.length; ++i)
				GroupSRMDiv2Harness.run_test(Integer.valueOf(args[i]));
		}
	}
	// END CUT HERE
}
// BEGIN CUT HERE
class GroupSRMDiv2Harness {
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
			int[] t                   = {1,1};
			int expected__            = 2;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}
		case 1: {
			int[] t                   = {1,2};
			int expected__            = -1;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}
		case 2: {
			int[] t                   = {2,2};
			int expected__            = 1;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}
		case 3: {
			int[] t                   = {2,2,3,3,3};
			int expected__            = 2;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}
		case 4: {
			int[] t                   = {3,3,2,2,2};
			int expected__            = -1;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}
		case 5: {
			int[] t                   = {2,3,2,3,2,3,2,1,1,2,2};
			int expected__            = 6;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}

		// custom cases

		/*      case 6: {
			int[] t                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}*/
		/*      case 7: {
			int[] t                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}*/
		/*      case 8: {
			int[] t                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}*/
		/*      case 9: {
			int[] t                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}*/
		/*      case 10: {
			int[] t                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new GroupSRMDiv2().FindGroups(t));
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
