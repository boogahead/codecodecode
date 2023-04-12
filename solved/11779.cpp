#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 10;
typedef pair<int, int>info;//cost.dest
int main(void)
{
	priority_queue<info, vector<info>, greater<info>>qq;
	int n, m;
	cin >> n;
	cin>>m;
	int start, end;
	vector<int>dist(n + 1, INF);
	vector<int>prev(n+1,-1);
	vector<vector<info>>table(n+1);
	int from, dest, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> from>>dest>>cost;
		table[from].push_back(make_pair(cost, dest));
	}
	cin >> start >> end;
	qq.push(make_pair(0, start));
	dist[start] = 0;
	while (!qq.empty())
	{
		info tmp = qq.top(); qq.pop();
		int price = tmp.first, dst = tmp.second;
		if (dist[dst] != price)continue;
		for (auto i : table[dst])
		{
			if (dist[dst] + i.first < dist[i.second])
			{
				prev[i.second] = dst;
				dist[i.second] = dist[dst] + i.first;
				qq.push(make_pair(dist[i.second], i.second));
			}
		}
	}
	/* for (auto i : prev)
	{
		cout << i << " ";
	}*/
	//cout << "\n-------------------------\n";
	cout << dist[end] << "\n";
	int cnt = 1;
	int cur = end;
	vector<int>route;
	while (cur != start)
	{
		route.push_back(cur);
		cnt++;
		cur = prev[cur];
	}
	route.push_back(cur);
	cout << cnt << "\n";
	for (int i = route.size()-1 ; i >= 0; i--)
	{
		cout << route[i] << " ";
	}
}