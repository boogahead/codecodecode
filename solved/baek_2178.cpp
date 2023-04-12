#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//bool vis[101][101];
int maze[101][101];
int pathval[101][101] ;
typedef pair<int, int>coord;

int main(void)
{
	int dist = 1;
	queue<coord> q;
	int n, m;
	int i, j;
	string tmp;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		//for (j = 0; j < m; j++)
		//{
		//	cin >> maze[i][j];
		//}
		cin >> tmp;
		for (j = 0; j < m; j++)
		{
			maze[i][j] = tmp[j]-'0';
		}
	}
	q.push(coord(0, 0));
	/*for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << maze[i][j]+1 << " ";
		}cout << "\n";
	}*/
	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			pathval[i][j] = -1;
		}
	}

	pathval[0][0] = 0;
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int mx = dx[dir] + x;
			int my = dy[dir] + y;
			if (mx <0  || mx >= m || my < 0 || my >= n)
			{
				continue;
			}
			if (maze[my][mx] != 1 || pathval[my][mx] >= 0)
			{
				continue;
			}
			pathval[my][mx] = pathval[y][x] + 1;
			//cout << "hi\n";
			//if (pathval[my][mx] == 0) { pathval[my][mx] = dist; }
			//else { pathval[my][mx] = min(dist, pathval[my][mx]); }
			//cout << "HI\n";
			q.push(coord(my, mx));
			//cout << my << " " << mx << "\n";
			//cout << my << " " << mx << "\n";
		}
		//dist++;
	}
	cout << pathval[n-1][m-1]+1;
}