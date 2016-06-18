package ProjectEuler;

import java.util.ArrayList;
import java.util.List;

public class Problem495 extends EulerIsGod {

	private static boolean isPrime(int n) {
		for (int i = 2; i*i <=n; i++) {
			if(n % i == 0) {
				return false;
			}
		}
		return true;
	}

	@Override
	void solve() {
		int n = 100;
		int K = 10;
		List<Integer> primes = new ArrayList<Integer>();
		List<Integer> pow = new ArrayList<Integer>();
		for (int i = 2; i <= n; i++) {
			if (isPrime(i)) {
				primes.add(i);
				int cnt = 0;
				int N = n;
				while(N >= i) {
					cnt += N / i;
					N /= i;
				}
				pow.add(cnt);
			}
		}
	}

	public static void main(String[] args) {
		EulerIsGod solver = new Problem495();
		solver.solve();
	}
}
