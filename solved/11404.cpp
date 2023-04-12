//warshall-floyd
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <stack>
#include <queue>
#include <string>
using namespace std;
const int INF = 0x3f3f3f3f;
int main(void)
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<vector<int>>table(n+1,vector<int>(n+1,INF));
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		table[a][b] = min(table[a][b],c);
		//table[b][a] = c;
	}
	for (int i = 1; i < n + 1; i++) { table[i][i] = 0; }
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			for (int k = 1; k < n + 1; k++)
			{
				table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
			}
		}
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (table[i][j] == INF) { cout << "0 "; continue; }
			cout << table[i][j] << " ";
		}cout << "\n";
	}
}