//https://www.acmicpc.net/board/view/100687

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <map>
#include <string>

using namespace std;
int dy[4] = { 1,-1,0,0};
int dx[4] = { 0,0,-1,1 };
typedef pair<int, int> loc;
vector<vector<int>>table(20, vector<int>(20));
int answer = 0;
int sharksize = 2;
int eatcount = 0;
int n;
bool finder(loc& shark)
{
	queue<loc>qq;
	vector<vector<int>>distance(20, vector<int>(20, -1));
	qq.push(make_pair(shark.first, shark.second));
	distance[shark.first][shark.second] = 0;
	table[shark.first][shark.second] = 0;
	int y, x;
	while (!qq.empty())
	{
		tie(y, x) = qq.front(); qq.pop();
		//if (table[y][x] != 9 && table[y][x] != 0 && table[y][x] < sharksize)continue;
		for (int i = 0; i < 4; i++)
		{
			int my = y + dy[i];
			int mx = x + dx[i];
			if (my >= 0 && my < n && mx >= 0 && mx < n&&distance[my][mx]==-1&&table[my][mx]<=sharksize)
			{
				distance[my][mx] = distance[y][x] + 1;
				qq.push(make_pair(my, mx));
			}
		}
	}
	int ny = 99, nx = 99;
	int ndist = 401;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (table[i][j] != 0 && table[i][j] != 9 && table[i][j] < sharksize && distance[i][j] != -1 && distance[i][j] <= ndist)
			{
				ny = i, nx = j, ndist = distance[i][j];
			}
		}
	}
	if (ndist >= 401)return false;
	else
	{
		//cout << ny << " " << nx << "\n";
		table[ny][nx] = 0;
		shark.first = ny, shark.second = nx;
		eatcount++;
		if (eatcount == sharksize) {
			sharksize++, eatcount = 0;
		}
		table[ny][nx] = 9;
		answer += distance[ny][nx];
		//cout << "ANSWER " << answer << "\n";
		return true;
	}
}
int main(void)
{
	loc shark;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> table[i][j];
			if (table[i][j] == 9)
			{
				shark.first = i, shark.second = j;
			}
		}
	}
	while (true)
	{
		if (finder(shark))
		{
			continue;
		}
		else { break; }
	}
	cout << answer;
	return 0;
}