package day0802;

import java.io.*;

public class bj15650 {
	static int[] table;

	static void recur(int cnt, int n, int m, int cur) {
		if (cnt == m) {
			for (int i : table) {
				System.out.print(i + " ");
			}
			System.out.println();
			return;
		}
		for (int i = cur + 1; i <= n; i++) {
			table[cnt] = i;
			recur(cnt + 1, n, m, i);
		}
	}

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] tmp = br.readLine().split(" ");
		int n = Integer.parseInt(tmp[0]);
		int m = Integer.parseInt(tmp[1]);
		table = new int[m];
		if (m == 1) {
			for (int i = 1; i <= n; i++) {
				System.out.println(i);
			}
			return;
		}
		for (int i = 1; i <= n; i++) {
			table[0] = i;
			recur(1, n, m, i);
		}
		return;
	}
}
