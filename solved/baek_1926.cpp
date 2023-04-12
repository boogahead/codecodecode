#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <map>
using namespace std;
typedef pair<int, bool> info;
typedef pair<int, int> coord;
int n, m;
vector<vector<info>> picture;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int maxarea = 0;
int piccnt = 0;
void findarea(int starti, int startj)
{
	queue<coord> q;
	int x;
	int area = 0;
	q.push(coord(starti, startj));
	while (!q.empty())
	{
		int i= q.front().first;
		int j = q.front().second;
		for (x = 0; x < 4; x++)
		{
			if ((dx[x] + j >= 0 && dx[x] + j < m) && (dy[x] + i >= 0 && dy[x] + i < n))
			{
				if (picture[dy[x] + i][dx[x] + j].first == 1 && picture[dy[x] + i][dx[x] + j].second == false)
				{
					picture[dy[x] + i][dx[x] + j].second == true;
					q.push(coord(dy[x] + i, dx[x] +j));
				}
			}
		}
		q.pop();
		area++;
		cout << "check\n";
	}
	maxarea = max(maxarea, area);
	return;
}
int main(void)
{
	cin >> n >> m;
	
	int i, j;
	
	for (i = 0; i < n; i++)
	{
		vector<info> row;
		for (j = 0; j < m; j++)
		{
			int tmp;
			cin >> tmp;
			row.push_back(info(tmp, false));
		}
		picture.push_back(row);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (picture[i][j].first == 1 && picture[i][j].second == false)
			{
				picture[i][j].second = true;
				piccnt++;
				findarea(i, j);
			}
		}
	}
	cout <<piccnt<<"\n"<< maxarea << "\n";
}