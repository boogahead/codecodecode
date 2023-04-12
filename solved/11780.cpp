#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <tuple>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
int main(void)
{
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int>>table(n+1, vector<int>(n+1, INF));
	vector<vector<int>>fromwhere(n+1, vector<int>(n+1));
	int from, to, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to >> cost;
		table[from][to] = min(table[from][to],cost);
		fromwhere[from][to] = to;
	}
	for (int i = 1; i <= n; i++)
	{
		table[i][i] = 0;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (table[i][k] + table[k][j] < table[i][j])
				{
					table[i][j] = min(table[i][k] + table[k][j],table[i][j]);
					fromwhere[i][j] = fromwhere[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (table[i][j] >= INF||table[i][j]==0) { cout << "0 "; continue; }
			cout << table[i][j] << " ";
		}cout << "\n";
	}
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			
			cout << fromwhere[i][j] << " ";
		}cout << "\n";
	}*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (table[i][j] >= INF || table[i][j] == 0) { cout << "0\n"; continue; }
			vector<int> path;
			int count = 1;
			int cur = i;
			while (cur != j) { count++; path.push_back(cur); cur = fromwhere[cur][j]; }
			path.push_back(j);
			cout << count;
			for (auto x : path)
			{
				cout << " "<<x;
			}
			cout << "\n";
		}
	}
}