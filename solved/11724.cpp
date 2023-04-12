#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>

using namespace std;
int cnt = 0;
bool visited[1001] = { false };
/*void dfs(int cur, vector<vector<int>>& table)
{
	//visited[cur] = true;
	for (int i = 0; i < table[cur].size() ; i++)
	{
		if (visited[table[cur][i]] == false)
		{
			visited[table[cur][i]] = true;
			cout << "I am " << table[cur][i] << "\n";
			dfs(i, table);
		}
	}
	return;
}*/
int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> table(n+1);
	stack<int> stck;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		table[a].push_back(b);
		table[b].push_back(a);
	}
	/*for (vector<int> i : table)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}cout << "\n";
	}*/
	for (int i = 1; i <= n; i++)
	{
		//if (table[i].size() == 0)continue;
		if (visited[i] == false)
		{
			cnt++;
			visited[i] = true;
			stck.push(i);
			while (!stck.empty())
			{
				int cur = stck.top(); stck.pop();
				for (int j = 0; j < table[cur].size(); j++)
				{
					if (!visited[table[cur][j]])
					{
						visited[table[cur][j]] = true;
						stck.push(table[cur][j]);
					}
				}
			}
		}
	}
	cout << cnt;
}