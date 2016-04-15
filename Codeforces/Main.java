package Codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    solve(in,out);
    out.close();
  }
  
  
  private static final int MOD = (int)1e9 + 7;
  
  private static boolean isPrime(int n) {
	  for (int i = 2; i*i <=n; i++) {
		  if(n % i == 0) {
			  return false;
		  }
	  }
	  return true;
  }
  
  private static void solve(InputReader in, PrintWriter out) {
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
