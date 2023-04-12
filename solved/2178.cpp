#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
using namespace std;
int n, m;
string input[101];
int maze[101][101];
int counter[101][101];
bool visited[101][101];
int di[4]= { 0,-1,0,1 };
int dj[4]= { -1,0,1,0 };
typedef pair <int, int> coord;
queue<coord> bfstack;
//int cnt = 1;
int left(int i, int j)
{
	j -= 1;
	if (j < 0)return 0;
	else if (maze[i][j] == 0)return 0;
	if (i == n && j == m)return -1;
	return 1;
}
int right(int i, int j)
{
	j += 1;
	if (j >= m)return 0;
	else if (maze[i][j] == 0)return 0;
	if (i == n && j == m)return -1;
	return 1;
}
int up(int i, int j)
{
	i -= 1;
	if (i < 0)return 0;
	else if (maze[i][j] == 0)return 0;
	if (i == n && j == m)return -1;
	return 1;
}
int down(int i, int j)
{
	i += 1;
	if (i >= n)return 0;
	else if (maze[i][j] == 0)return 0;
	if (i == n && j == m)return -1;
	return 1;
}
int main(void)
{
	int i,j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			maze[i][j] = input[i][j];
		}
	}
	i = 0; j = 0;
	coord yes;
	yes.first = i, yes.second = j;;
	bfstack.push(yes);
	int cnt = 1;
	int befi = 0, befj = 0;
	while (!bfstack.empty())
	{
		//cout << "asldkfja\n";
		i = bfstack.front().first;
		j = bfstack.front().second;
		bfstack.pop();
		for (int g = 0; g < 4; g++)
		{
			int flag = 0;
			coord putin;
			int nexti = i + di[g];
			int nextj = j + dj[g];
			if ((nexti>=0&&nextj>=0)&& (nexti < n  && nextj < m ))
			{
				if (visited[nexti][nextj] == false&&maze[nexti][nextj]==1)
				{
					visited[nexti][nextj] = true;
					putin.first = nexti, putin.second = nextj;
					bfstack.push(putin);
					counter[nexti][nextj] = counter[i][j] + 1;
				}
			}
		}
	}
	cout << counter[n-1][m-1];
	return 0;
}