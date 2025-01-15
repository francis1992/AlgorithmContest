package ProjectEuler;

import java.util.ArrayList;
import java.util.List;

public class NumberTheory {
	public static List<Integer> getPrimes(int n) {
		List<Integer> primes = new ArrayList<>();
		boolean[] vis = new boolean[n + 1];
		for (int i = 2; i <= n; i++) {
			if (!vis[i]) {
				primes.add(i);
			}
			for (Integer prime : primes) {
				if (prime * i > n) break;
				vis[prime * i] = true;
				if (i % prime == 0) break;
			}
		}
		return primes;
	}
}
