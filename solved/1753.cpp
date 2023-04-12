#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <tuple>
const int INF = 1e9 + 10;
using namespace std;
typedef pair<int, int> info;//cost , edge
int main(void)
{
	int v, e;
	cin >> v >> e;
	int start;
	cin >> start;
	vector<vector<info>> table(v + 1);
	int from, to, cost;
	for (int i = 0; i < e; i++)
	{
		cin >> from >> to >> cost;
		table[from].push_back(make_pair(cost, to));
	}
	priority_queue<info,vector<info>,greater<info>> qq;
	vector<int>dist(v + 1,INF);
	dist[start] = 0;
	qq.push(make_pair(0, start));
	int dest, price;
	while (!qq.empty())
	{
		auto tmp = qq.top(); qq.pop();
		dest = tmp.second; price = tmp.first;
		//cout << "tmp price " << price << " " << dest << "\n";
		if (dist[dest] != price)continue;
		for (auto i : table[dest])
		{
			//cout << i.second << "\n";
			if (dist[dest]+i.first < dist[i.second])
			{
				dist[i.second] = dist[dest] + i.first;
				qq.push(make_pair(dist[i.second], i.second));
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] >= INF) { cout << "INF\n"; continue; }
		cout << dist[i] << "\n";
	}
}