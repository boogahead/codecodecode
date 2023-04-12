#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };
int bat[1000][1000];
typedef pair<int, int>coord;  //y,x 
typedef pair<coord, int>info;
queue<info> qq;
int main(void)
{
	int n, m;
	cin >> m >> n;
	int i, j;
	int gamcnt=0;
	int startgam = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> bat[i][j];
			if (bat[i][j] == 1)
			{
				startgam++;
				qq.push(info(coord(i, j),0));
			}
			if (bat[i][j] == 1 || bat[i][j] == 0)
			{
				gamcnt++;
			}
		}
	}
	int dir;
	int days = 0;
	int end=0;
	int chooga = startgam;
	while (!qq.empty())
	{
		auto tmp = qq.front();
		qq.pop();
		//days++;
		for (dir = 0; dir < 4; dir++)
		{
			int mx = tmp.first.second + dx[dir];
			int my = tmp.first.first + dy[dir];
			if (mx < 0 || mx >= m || my < 0 || my >= n) { continue; }
			if (bat[my][mx] == 0)
			{
				chooga++;
				//cout << my << " " << mx << "\n";
				qq.push(info(coord(my, mx), tmp.second+1));
				bat[my][mx] = 1;
				end = tmp.second + 1;
			}
		}
	}
	//cout << "\n"<< chooga << "\n" << gamcnt << "\n";
	if (chooga != gamcnt)
	{
		cout << "-1\n"; return 0;
	}
	cout << end << "\n";
	return 0;
}