package TopCoder;

public class ParenthesesDiv1Easy {
	public int[] correct(String s) {
		return new int[] {-1};
	}
// BEGIN CUT HERE
public static void main(String[] args) {
		if (args.length == 0) {
			ParenthesesDiv1EasyHarness.run_test(-1);
		} else {
			for (int i=0; i<args.length; ++i)
				ParenthesesDiv1EasyHarness.run_test(Integer.valueOf(args[i]));
		}
	}
// END CUT HERE
}
// BEGIN CUT HERE
class ParenthesesDiv1EasyHarness {
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
	
	static boolean compareOutput(int[] expected, int[] result) { if (expected.length != result.length) return false; for (int i=0; i<expected.length; ++i) if (expected[i] != result[i]) return false; return true; }

	static String formatResult(int[] res) {
		String ret = "";
		ret += "{";
		for (int i=0; i<res.length; ++i) {
			if (i > 0) ret += ",";
			ret += String.format(" %d", res[i]);
		}
		ret += " }";
		return ret;
	}
	
	static int verifyCase(int casenum, int[] expected, int[] received) { 
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
			int[] expected__          = {0, 0, 1, 1 };

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Easy().correct(s));
		}
		case 1: {
			String s                  = "))))))((((((";
			int[] expected__          = {0, 5, 6, 11 };

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Easy().correct(s));
		}
		case 2: {
			String s                  = "))()())()";
			int[] expected__          = {-1 };

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Easy().correct(s));
		}
		case 3: {
			String s                  = ")()(((";
			int[] expected__          = {0, 0, 3, 3, 5, 5 };

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Easy().correct(s));
		}
		case 4: {
			String s                  = "()";
			int[] expected__          = { };

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Easy().correct(s));
		}

		// custom cases

/*      case 5: {
			String s                  = ;
			int[] expected__          = ;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Easy().correct(s));
		}*/
/*      case 6: {
			String s                  = ;
			int[] expected__          = ;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Easy().correct(s));
		}*/
/*      case 7: {
			String s                  = ;
			int[] expected__          = ;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Easy().correct(s));
		}*/
/*      case 8: {
			String s                  = ;
			int[] expected__          = ;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Easy().correct(s));
		}*/
/*      case 9: {
			String s                  = ;
			int[] expected__          = ;

			return verifyCase(casenum__, expected__, new ParenthesesDiv1Easy().correct(s));
		}*/
		default:
			return -1;
		}
	}
}

// END CUT HERE
