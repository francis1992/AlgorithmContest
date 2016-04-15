// BEGIN CUT HERE
package TopCoder;
// END CUT HERE

public class ParenthesesDiv1Medium {
	public int minSwaps(String s, int[] L, int[] R) {
		return -1;
	}
// BEGIN CUT HERE
public static void main(String[] args) {
		if (args.length == 0) {
			ParenthesesDiv1MediumHarness.run_test(-1);
		} else {
			for (int i=0; i<args.length; ++i)
				ParenthesesDiv1MediumHarness.run_test(Integer.valueOf(args[i]));
		}
	}
// END CUT HERE
}
// BEGIN CUT HERE
class ParenthesesDiv1MediumHarness {
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
			String s                  = ")(";
			int[] L                   = {0,0,0,0};
			int[] R                   = {1,1,1,1};
			int expected__            = 1;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}
		case 1: {
			String s                  = "(())";
			int[] L                   = {0,2};
			int[] R                   = {1,3};
			int expected__            = 1;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}
		case 2: {
			String s                  = "(((())";
			int[] L                   = {0,2};
			int[] R                   = {1,3};
			int expected__            = 2;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}
		case 3: {
			String s                  = "(((((((((";
			int[] L                   = {0,2};
			int[] R                   = {1,3};
			int expected__            = -1;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}
		case 4: {
			String s                  = "()()()()";
			int[] L                   = {0,0,0,0,2,2,2,4,4,6};
			int[] R                   = {1,3,5,7,3,5,7,5,7,7};
			int expected__            = 0;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}
		case 5: {
			String s                  = ")()(()()((())()()()()()()))(()())()()()(";
			int[] L                   = {3,5,17,25,35};
			int[] R                   = {12,10,30,30,38};
			int expected__            = 3;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}

		// custom cases

/*      case 6: {
			String s                  = ;
			int[] L                   = ;
			int[] R                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}*/
/*      case 7: {
			String s                  = ;
			int[] L                   = ;
			int[] R                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}*/
/*      case 8: {
			String s                  = ;
			int[] L                   = ;
			int[] R                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}*/
/*      case 9: {
			String s                  = ;
			int[] L                   = ;
			int[] R                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}*/
/*      case 10: {
			String s                  = ;
			int[] L                   = ;
			int[] R                   = ;
			int expected__            = ;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Medium().minSwaps(s, L, R));
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
