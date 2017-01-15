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
import java.util.Arrays;
import java.util.StringTokenizer;

public class Round1PieProgress {

	public static void main(String[] args) throws FileNotFoundException {
		InputStream inputStream = new FileInputStream("FacebookHackerCup/in.txt");
		OutputStream outputStream = new FileOutputStream("FacebookHackerCup/out.txt");
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		new Solver(in, out).solve();
		out.close();
	}

	static class Solver {
		private InputReader in;
		private PrintWriter out;

		public Solver(InputReader in, PrintWriter out) {
			this.in = in;
			this.out = out;
		}

		public void solve() {
			int T = in.nextInt();
			for (int cas = 1; cas <= T; cas++) {
				int n = in.nextInt();
				int m = in.nextInt();
				int dp[][] = new int[n + 1][n + 1];
				for (int i = 0; i <= n; i++)
					for (int j = 0; j <= n; j++)
						dp[i][j] = 1000000000;
				dp[0][0] = 0;
				for (int i = 1; i <= n; i++) {
					int p[] = new int[m];
					for (int j = 0; j < m; j++) {
						p[j] = in.nextInt();
					}
					Arrays.sort(p);
					for (int j = 0; j <= n - i; j++) {
						int s = 0;
						dp[i][j] = dp[i - 1][j + 1];
						for (int k = 1; k <= m && k <= j + 1; k++) {
							s += p[k - 1];
							dp[i][j] = Math.min(dp[i][j], dp[i - 1][j + 1 - k] + k * k + s);
						}
					}
				}
				out.print(String.format("Case #%d: %d\n", cas, dp[n][0]));
			}
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
