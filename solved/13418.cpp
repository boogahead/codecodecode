#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <tuple>
using namespace std;
typedef tuple<int, int, int>info; // cost from to
vector<int>ranked, parent;
vector<info>routes;
int ans = 0;
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
void solve(bool isitupdown,int n)
{
	parent.clear();
	ranked.clear();
	parent.resize(n + 1);
	ranked.resize(n + 1);
	for (int i = 0; i <= n; i++)parent[i] = i;
	int sum = 0;
	int count = 0;
	int from, to, cost;
	for (auto i : routes)
	{
		tie(cost, from, to) = i;
		if (find(from) == find(to))continue;
		merge(from, to);
		//cout << from << " " << to << "\n";
		count++;
		sum+=cost;
		if (count == n)break;
	}
	//cout << sum << "\n";
	if (!isitupdown)
	{
		ans -= (sum * sum);
	}
	else
	{
		ans += (sum * sum);
	}
	return;
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	ranked.resize(n + 1,0);
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++)parent[i] = i;
	int from, to, cost;
	//int startval;
	for (int i = 0; i <=m; i++)
	{
		cin >> from >> to >> cost;
		routes.push_back({ !cost,from,to });
	}
	sort(routes.begin(), routes.end());
	solve(false, n);
	sort(routes.rbegin(), routes.rend());
	solve(true, n);
	cout << ans;
}