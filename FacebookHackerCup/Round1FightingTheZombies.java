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

public class Round1FightingTheZombies {

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
				int r = in.nextInt();
				int x[] = new int[n];
				int y[] = new int[n];
				for (int i = 0; i < n; i++) {
					x[i] = in.nextInt();
					y[i] = in.nextInt();
				}
				int ans = 0;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						for (int ii = 0; ii < n; ii++)
							for (int jj = 0; jj < n; jj++) {
								int s = 0;
								for (int k = 0; k < n; k++)
									if (isIn(x[i], x[j], x[k], y[k], r) || isIn(x[ii], y[jj], x[k], y[k], r)) s++;
								if (s > ans) ans = s;
							}
				out.print(String.format("Case #%d: %d\n", cas, ans));
			}
		}

		private boolean isIn(int x0, int y0, int x, int y, int r) {
			return x - x0 >= 0 && x - x0 <= r && y - y0 >=0 && y - y0 <= r;
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
