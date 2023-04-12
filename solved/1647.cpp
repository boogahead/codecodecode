#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;
vector<int>ranked, parent;
int find(int a)
{
	if (parent[a] == a)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	int na = find(a), nb = find(b);
	if (na == nb)return;
	if (ranked[na] > ranked[nb])swap(na, nb);
	parent[na] = nb;
	if (ranked[na] == ranked[nb])ranked[nb]++;
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>>distance;
	ranked.resize(n+1);
	parent.resize(n+1);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	int from, to, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to >> cost;
		distance.push_back({ cost,from,to });
		//distance.push_back({ cost,to,cost });
	}
	sort(distance.begin(), distance.end());
	long long answer = 0;
	int count = 0;
	int maxi = -1;
	for (auto i : distance)
	{
		tie(cost, from, to) = i;
		int fromparent = find(from), fromto = find(to);
		if (fromparent == fromto)continue;
		merge(fromparent, fromto);
		count++;
		maxi = max(maxi, cost);
		answer += cost;
		if (count == n - 1)break;
	}
	cout << answer - maxi;
	
	return 0;
}