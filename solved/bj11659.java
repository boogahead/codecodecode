package day0802;

import java.io.*;

public class bj11659 {
	static int[]table;
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] tmp=br.readLine().split(" ");
		int n=Integer.parseInt(tmp[0]);
		int m=Integer.parseInt(tmp[1]);
		table=new int[n+1];
		String[]receiver=br.readLine().split(" ");
		for(int i=0;i<n;i++) {
			table[i+1]=Integer.parseInt(receiver[i]);
		}
		for(int i=1;i<=n;i++) {
			table[i]=table[i]+table[i-1];
		}
		int[][]cases=new int[m][2];
		for(int i=0;i<m;i++) {
			String[]indiv=br.readLine().split(" ");
			cases[i][0]=Integer.parseInt(indiv[0]);
			cases[i][1]=Integer.parseInt(indiv[1]);
			//System.out.println(table[to]-table[from-1]);
		}
		for(int i=0;i<m;i++) {
			System.out.println(table[cases[i][1]]-table[cases[i][0]-1]);
		}
	}

}
