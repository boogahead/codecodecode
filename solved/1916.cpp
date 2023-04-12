#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <climits>
#include <map>
using namespace std;
typedef pair<int, int> info; //to //value
int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<info>>table(n+1);
	for (int i = 0; i < m; i++)
	{
		int start, to, value;
		cin >> start >> to >> value;
		table[start].push_back(make_pair(to, value));
	}
	int start, dest;
	cin >> start>>dest;
	vector<int> distance(n + 1,INT_MAX);
	distance[start] = 0;
	priority_queue<info,vector<info>,greater<info>>qq;
	qq.push({ 0,start });
	while (!qq.empty())
	{
		int dist, upto;
		tie(dist, upto) = qq.top(); qq.pop();
		if (distance[upto] != dist)continue;
		for (auto i : table[upto])
		{
			//cout << i.second << " ";
			if (distance[i.first] > i.second + distance[upto])
			{
				distance[i.first] = i.second + distance[upto];
				qq.push({ distance[i.first], i.first });
			}
		}
		//cout << "\n";
	}
	cout << distance[dest];
}