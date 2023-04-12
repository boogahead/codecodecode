#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <climits>
#define INF 0x3f3f3f
using namespace std;
typedef pair<int, int> info; // value , to
int main(void)
{
	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<int>>table(n + 1, vector<int>(n + 1,INF));
	vector<vector<info>>connection(n + 1);
	for (int i = 0; i < m; i++)
	{
		int from, to, value;
		cin >> from >> to >> value;
		connection[from].push_back({ value,to });
		//cout << "HI\n";
	}
	int value, to;
	for (int i = 1; i <= n; i++)
	{
		//cout << i << "\n";
		priority_queue<info, vector<info>, greater<info>>qq;
		table[i][i] = 0;
		qq.push({ 0,i });
		while (!qq.empty())
		{
			tie(value, to) = qq.top(); qq.pop();
			//cout << value << " " << to << "\n";
			if (table[i][to] != value)continue;
			for (int xx = 0; xx < connection[to].size(); xx++)
			{
				//cout << "TEST\n";
				if (table[i][connection[to][xx].second] > table[i][to] + connection[to][xx].first)table[i][connection[to][xx].second] = table[i][to] + connection[to][xx].first;
				//if (connection[to][xx].first+ >= table[i][connection[to][xx].second])table[i][connection[to][xx].second] = connection[to][xx].first;
				else { continue; }
				qq.push({ table[i][connection[to][xx].second], connection[to][xx].second });
			}
		}
	}
	int realanswer = -1;
	for (int i = 1; i <= n; i++)
	{
		realanswer = max(realanswer, table[i][x] + table[x][i]);
	}
	cout << realanswer;
	return 0;
}