#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
using namespace std;
stack<int>stck;
void dfs(int cur,vector<vector<int>>&table,vector<int>&parents)
{
	while (!stck.empty())
	{
		int tmp = stck.top(); stck.pop();
		for (auto i : table[tmp])
		{
			if (parents[tmp] == i)continue;
			stck.push(i);
			parents[i] = tmp;
		}
	}
	return;
}
int main(void)
{
	int n;
	cin >> n;
	//vector<bool> visited(n + 1);
	vector<int>parents(n + 1);
	vector<vector<int>>table(n + 1);
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		table[a].push_back(b);
		table[b].push_back(a);
	}
	parents[1] = 1;
	stck.push(1);
	/*for (int i = 0; i < n; i++)
	{
		for (auto c : table[i]) { cout << c << " "; }cout << "\n";
	}*/
	dfs(1,table,parents);
	for (int i = 2; i <= n; i++)
	{
		cout << parents[i] << "\n";
	}
}