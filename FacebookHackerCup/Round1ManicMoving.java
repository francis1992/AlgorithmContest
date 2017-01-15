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

public class Round1ManicMoving {

	public static void main(String[] args) throws FileNotFoundException {
		InputStream inputStream = new FileInputStream("FacebookHackerCup/in.txt");
		OutputStream outputStream = new FileOutputStream("FacebookHackerCup/out.txt");
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		new Solver(in, out).solve();
		out.close();
	}

	static class Solver {
		private static final int INF = 1000000000;
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
				int K = in.nextInt();
				int g[][] = new int[n][n];
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if (i == j) g[i][j] = 0;
						else g[i][j] = INF;
				for (int i = 0; i < m; i++) {
					int a = in.nextInt(); a--;
					int b = in.nextInt(); b--;
					int c = in.nextInt();
					g[a][b] = Math.min(g[a][b], c);
					g[b][a] = Math.min(g[b][a], c);
				}
				for (int k = 0; k < n; k++)
					for (int i = 0; i < n; i++)
						for (int j = 0; j < n; j++)
							g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);
				int s[] = new int[K + 1];
				int d[] = new int[K + 1];
				boolean ok = true;
				for (int i = 1; i <= K; i++) {
					s[i] = in.nextInt(); s[i]--;
					d[i] = in.nextInt(); d[i]--;
					if (g[1][s[i]] == INF || g[1][d[i]] == INF) ok = false;
				}

				int ans = -1;
				if (ok) {
					int dp[][][] = new int[K + 1][n][3];
					for (int i = 0; i < K + 1; i++)
						for (int j = 0; j < n; j++)
							for (int k = 0; k < 3; k++)
								dp[i][j][k] = INF;
					dp[0][0][0] = 0;
					for (int i = 0; i <= K; i++)
						for (int k = 2; k >=0; k--)
							for (int j = 0; j < n; j++)
								if (dp[i][j][k] != INF) {
									//System.err.printf("case:%d  dp[%d][%d][%d] = %d\n",cas, i, j, k, dp[i][j][k]);
									if (k == 2) {
										dp[i][d[i - 1]][1] = Math.min(dp[i][d[i - 1]][1], dp[i][j][k] + g[j][d[i - 1]]);
									} else if (k == 1) {
										if (i + 1 <= K) {
											dp[i + 1][s[i + 1]][2] = Math.min(dp[i + 1][s[i + 1]][2], dp[i][j][k] + g[j][s[i + 1]]);
										}
										dp[i][d[i]][0] = Math.min(dp[i][d[i]][0], dp[i][j][k] + g[j][d[i]]);
									} else {
										if (i + 1 <= K) {
											dp[i + 1][s[i + 1]][1] = Math.min(dp[i + 1][s[i + 1]][1], dp[i][j][k] + g[j][s[i + 1]]);
										}
									}
								}
					ans = dp[K][d[K]][0];
				}
				out.print(String.format("Case #%d: %d\n", cas, ans));
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
