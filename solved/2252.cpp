#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
bool check(vector<int>& table,int n)
{
	for (int i = 0; i < n; i++) { if (table[i] != 0)return true; }
	return false;
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> table(n+1);
	vector<int>inout(n+1, 0);
	vector<int>answer;
	int front, back;
	for (int i = 0; i < m; i++)
	{
		cin >> front >> back;
		table[front].push_back(back);
		inout[back]++;
	}
	queue<int>qq;
	int cur;
		for (int i = 1; i < n + 1; i++)
		{
			if (inout[i] == 0) { qq.push(i); }
		}
		while (!qq.empty())
		{
			cur = qq.front(); qq.pop();
			answer.push_back(cur);
			for (int j = 0; j < table[cur].size(); j++)
			{
				inout[table[cur][j]]--;
				if (inout[table[cur][j]] == 0)qq.push(table[cur][j]);
			}
		}
	for (auto i : answer)
	{
		cout << i << " ";
	}
}