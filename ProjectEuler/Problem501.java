package ProjectEuler;

import java.util.List;

public class Problem501 extends EulerIsGod {

	long phi(long n, List <Integer> primes, int pos) {
		return 0;
	}

	@Override
	void solve() {
		int n = 1000000;
		long N = 1000000L;
		List <Integer> primes = NumberTheory.getPrimes(n);
		// 8 = 2 * 2 * 2 = 4 * 2 = 8
		// p1 * p2 * p3
		// p1^3 * p2
		long ans = 0;
		for (int index1 = 0; index1 < primes.size(); index1++) {
			long p1 = primes.get(index1);
			if (p1 * p1 * p1 <= N) {
				for (int index2 = index1 + 1; index2 < primes.size(); index2++) {
					long p2 = primes.get(index2);
					if (p1 * p2 * p2 <= N) {
						long p = N / p1 / p2;

					} else {
						break;
					}
				}
			} else {
				break;
			}
		}

		for (int index1 = 0; index1 < primes.size(); index1++) {
			long p1 = primes.get(index1);
			if (p1 * p1 * p1 <= N) {
				for (int index2 = 0; index2 < primes.size(); index2++) {
					long p2 = primes.get(index2);
					if (p1 * p1 * p1 * p2 <= N) {
						if (p1 != p2) {
							ans++;
						}
					} else {
						break;
					}
				}
			} else {
				break;
			}
		}

		for (int index = 0; index < primes.size(); index++) {
			long p1 = primes.get(index);
			if (p1 * p1 * p1 * p1 * p1 * p1 * p1 <= N) {
				ans++;
			} else {
				break;
			}
		}

		this.out.println(ans);
	}

	public static void main(String[] args) {
		EulerIsGod solver = new Problem501();
		solver.solve();
	}
}
