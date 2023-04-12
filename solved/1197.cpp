/*
MST - used Kruskal + Union Find
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <tuple>
using namespace std;
vector<int>ufind(10002);
tuple<int, int, int>  table[100001];
int find(int target)
{
	if (ufind[target] == target)return target;
	return find(ufind[target]);
}
void uni(int a, int b)
{
	int tmpa = find( a), tmpb = find(b);
	ufind[tmpb] = tmpa;
}
int main(void)
{
	int v, e;
	cin >> v >> e;
	for (int i = 1; i <= v; i++) { ufind[i] = i; }
	int start, end, cost;
	for (int i = 0; i < e; i++)
	{
		cin >> start >> end >> cost;
		table[i] = { cost, start, end };
	}
	sort(table, table + e);
	int tot = 1;
	int answer = 0;
	for (int i = 0; i < e; i++)
	{
		start = get<1>(table[i]);
		end= get<2>(table[i]);
		cost= get<0>(table[i]);
		//cout << start << " " << end << " " << cost << "\n";
		if (find(start) == find(end))continue;
		tot++;
		answer += cost;
		uni(start, end);
		if (tot == e)break;
	}
	cout << answer;
}