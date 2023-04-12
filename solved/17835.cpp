#include <iostream>
#include <vector>
#include <utility>
#include<algorithm>
#include <queue>
#include <map>
#include<climits>
using namespace std;
typedef pair<int, int> info; //dest ,cost
vector<vector<info>>connection;
vector<int> interview;
int n, m, k;
info answer; // townnmber, cost;
void calculate(int interview)
{
	vector<int>distance(n+1,INT_MAX);
	distance[interview] = 0;
	priority_queue<info, vector<info>, greater<info>>qq;
	qq.push({ 0,interview });
	while (!qq.empty())
	{
		int cost, dest;
		tie(cost, dest) = qq.top(); qq.pop();
		if (distance[dest] != cost)continue;
		for (auto i : connection[dest])
		{
			int nw, nt;
			tie(nw, nt) = i;
			nw = cost + nw;
			if (nw < distance[nt])
			{
				distance[nt] = nw;
				qq.push({ nw,nt });
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (answer.second < distance[i])
		{
			answer.second = distance[i]; answer.first = i; continue;
		}
		if (answer.second == distance[i])
		{
			if (answer.first > i)answer.first = i;
		}
	}
}
int main(void)
{
	cin >> n >> m >> k;
	//vector<vector<info>>connection(n+1);
	connection.resize(n + 1);
	answer.first=answer.second = -1;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		connection[from].push_back({ to,cost });
	}
	for (int i = 0; i < k; i++)
	{
		int tmp; cin >> tmp;
		interview.push_back(tmp);
	}
	for (int i = 0; i < k; i++)
	{
		calculate(i);
	}
	cout << answer.first << "\n" << answer.second;
}