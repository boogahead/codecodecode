#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <climits>

using namespace std;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
typedef pair<int, int>info; // i j
int main(void)
{
	int n, m;
	cin >> m >> n;
	vector<vector<int>>table(n, vector<int>(m));
	vector<vector<int>>calculated(n, vector<int>(m,INT_MAX));
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++)
		{
			table[i][j] = tmp[j] - '0';
		}
	}
	priority_queue<tuple<int, int, int>,vector<tuple<int,int,int>>,
	greater<tuple<int,int,int>>>qq; //weight y x
	calculated[0][0] = 0;
	qq.push({ 0, 0, 0 });
	while (!qq.empty())
	{
		int w, y, x;
		tie(w, y, x) = qq.top(); qq.pop();
		if (w != calculated[y][x])continue;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
			int nw = w + table[ny][nx];
			if (nw < calculated[ny][nx])
			{
				calculated[ny][nx] = nw;
				qq.push({ nw,ny,nx });
			}
		}
	}
	cout << calculated[n - 1][m - 1];
}