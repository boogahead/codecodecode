package day0802;

import java.io.*;
import java.util.StringTokenizer;

public class bj11660 {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tokens=new StringTokenizer(br.readLine());
		//String[] reader = br.readLine().split(" ");
		int N = Integer.parseInt(tokens.nextToken());
		int M = Integer.parseInt(tokens.nextToken());
		int[][] table = new int[N + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			//String[] tablereader = br.readLine().split(" ");
			tokens=new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				table[i][j] = Integer.parseInt(tokens.nextToken());
			}
		}
		int[][] iusethis = new int[N + 1][N + 1];
		iusethis[1][1] = table[1][1];
		for (int i = 2; i <= N; i++) {
			iusethis[i][1] = table[i][1] + iusethis[i - 1][1];
			iusethis[1][i] = table[1][i] + iusethis[1][i - 1];
		}
		for (int i = 2; i <= N; i++) {
			for (int j = 2; j <= N; j++) {
				iusethis[i][j] = iusethis[i - 1][j] + iusethis[i][j - 1] + table[i][j] - iusethis[i - 1][j - 1];
			}
		}
		int[][] inputtable = new int[M][4];
		for (int i = 0; i < M; i++) {
			//String[] casereader = br.readLine().split(" ");
			tokens=new StringTokenizer(br.readLine());
			for (int j = 0; j < 4; j++) {
				inputtable[i][j] = Integer.parseInt(tokens.nextToken());
			}
		}
		
//		 for(int i=0;i<=N;i++) { for(int j=0;j<=N;j++) {
//		 System.out.print(iusethis[i][j]+" "); }System.out.println(); }
		 StringBuilder answer=new StringBuilder();
		for (int i = 0; i < M; i++) {
			int fromi = inputtable[i][0];
			int fromj = inputtable[i][1];
			int toi = inputtable[i][2];
			int toj = inputtable[i][3];
			// System.out.println(fromj+" "+fromi+" "+toj+" "+toi);
			answer.append(iusethis[toi][toj]
					- (iusethis[fromi - 1][toj] + iusethis[toi][fromj - 1] - iusethis[fromi - 1][fromj - 1])+"\n");
//			System.out.println(iusethis[toi][toj]
//					- (iusethis[fromi - 1][toj] + iusethis[toi][fromj - 1] - iusethis[fromi - 1][fromj - 1]));
			// System.out.println(iusethis[fromi-1][toj]+" "+iusethis[toi][fromj-1]+"
			// "+iusethis[fromi-1][fromj-1]);
		}
		System.out.println(answer);
	}
}
