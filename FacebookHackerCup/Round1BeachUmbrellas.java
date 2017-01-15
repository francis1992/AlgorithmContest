package FacebookHackerCup;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Round1BeachUmbrellas {

	public static void main(String[] args) throws FileNotFoundException {
		InputStream inputStream = new FileInputStream("FacebookHackerCup/in.txt");
		OutputStream outputStream = new FileOutputStream("FacebookHackerCup/out.txt");
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		new Solver(in, out).solve();
		out.close();
	}

	static class Solver {
		private static final int mod = 1000000007;
		private InputReader in;
		private PrintWriter out;

		public Solver(InputReader in, PrintWriter out) {
			this.in = in;
			this.out = out;
		}

		/**
		 * 0 1 2 ..... M - 1
		 * x_0 = 0 x_1 x_2 .... x_n x_n+1 = M - 1
		 * x_i+1 - x_i = dx_i
		 * dx_1 dx_2 ... dx_n-1  dx_i >= r_i+1 + r_i
		 *
		 * dx_0 + dx_n + sigma(dx_i - (r_i+1 + r_i)) = M - 1 - sigma(r_i+1 + r_i)
		 *
		 * sigma x_i (0<=i<=n, x_i>=0) = M - 1 - (2*sum - r_1 - r_n)
		 * sigma x_i (0<=i<=n, x_i>=1) = M + n - (2*sum - r_1 - r_n) = S
		 *
		 * C{S-1}{n}
		 */
		public void solve() {
			int T = in.nextInt();
			for (int cas = 1; cas <= T; cas++) {
				int n = in.nextInt();
				int M = in.nextInt();
				int R[] = new int[n];
				for (int i = 0; i < n; i++) R[i] = in.nextInt();
				long ans = 0L;
				if (n == 1) {
					ans = M;
				} else {
					int cnt[] = new int[4001];
					for (int i = 0; i <= 4000; i++)cnt[i] = 0;
					for (int i = 0; i < n; i++)
						for (int j = 0;j < n; j++) {
							if (i != j) {
								cnt[R[i] + R[j]]++;
							}
						}
					int sum = 0;
					for (int i = 0; i < n; i++) sum += R[i];

					for (int i = 0; i <= 4000; i++)
						if (cnt[i] != 0) {
							int S = M - 1 + n - (2 * sum - i);
							ans = (ans + cnt[i] * C(S, n)) % mod;
						}
					ans = ans * inv(n) % mod * inv(n - 1) % mod;
				}
				out.print(String.format("Case #%d: %d\n", cas, ans));
			}
		}

		private long C(int n, int m) {
			if (n < m) return 0L;
			long ans = 1;
			for (int i = 0; i < m; i++) {
				ans = ans * (n - i) % mod;
			}
			return ans;
		}

		private long inv(long n) {
			return exp(n, mod - 2);
		}

		private long exp(long n, int m) {
			long ans = 1;
			n %= mod;
			while(m > 0) {
				if (m % 2 == 1) ans = ans * n % mod;
				n = n * n % mod;
				m /= 2;
			}
			return ans;
		}
	}


	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

	}

}
