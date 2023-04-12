#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int>startdst;//from to
typedef pair<int, startdst>info; //val from to;
vector<info>paths;
vector<int>parent;
vector<int>ranked;
int find(int a)
{
	if (a == parent[a])return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	int u = find(a),v = find(b);
	if (u == v)return;
	if (ranked[u] > ranked[v])swap(u, v);
	parent[u] = v;
	if (ranked[u] == ranked[v])ranked[v]++;
}
int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>>table(n, vector<int>(n, 0));
	parent.resize(n);
	ranked.resize(n);
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> table[i][j];
			paths.push_back(make_pair(table[i][j],make_pair(i,j)));
		}
	}
	sort(paths.begin(), paths.end());
	int val, from, to;
	long long answer = 0;
	int cnt = 0;
	for (auto i : paths)
	{
		val = i.first; from = i.second.first; to = i.second.second;
		if (find(from) == find(to))continue;
		merge(from, to);
		answer += val;
		cnt++;
		if (cnt == n - 1)break;
	}
	cout << answer;
}