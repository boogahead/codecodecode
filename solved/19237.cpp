#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
#include <map>
using namespace std;
struct s {
	int y;
	int x;
	int dir;
	bool alive = true;
};
struct space {
	int spaceof=0; //0 =empty -1 = smell left
	int smell=0; //0 = empty space 
	int timer=0; //how long left until smell vanishes
};
int dy[5] = {-2,-1,0,1,0 };
int dx[5] = {-2,0,-1,0,1 };//only use from index 1
vector<s>sharklist(401);
vector<int>goneshark; // place to store all the sharks that were kicked out
space table[20][20];
bool isitgone(int num)//check if the shark with following shark number is gone
{
	for (auto i : goneshark)
	{
		if (i == num)return true;
	}return false;
}
bool checkforbigger(int num, int i, int j)//check if theres any bigger shark return true if exist
{
	for (int i = 1; i < num && !isitgone(i); i++)
	{
		if (sharklist[i].y == i && sharklist[i].x == j)return true;
	}
	return false;
}
void degrade() // degrade timer on smell stuff
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (table[i][j].smell > 0)
			{
				table[i][j].timer--;
			}
			if (table[i][j].timer == 0)
			{
				table[i][j].spaceof = 0, table[i][j].smell = 0;
			}
		}
	}
}
int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<vector<int>>>priority(m+1, vector<vector<int>>(5, vector<int>(5)));
	// ^ fuckin huge lisg of all the prios
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			table[i][j].spaceof=tmp;
			if (tmp > 0) { sharklist[tmp].y = i, sharklist[tmp].x = j; }
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> sharklist[i].dir;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				cin >> priority[i][j][k];
			}
		}
	}
	int seconds = 0;
	while (goneshark.size() != m-1)//loops until all sharks are gone
	{
		degrade();
		for (int i = 1; i <= m && sharklist[i].alive; i++)
		{
			table[sharklist[i].y][sharklist[i].x].spaceof = -1;
			table[sharklist[i].y][sharklist[i].x].smell = i;
			table[sharklist[i].y][sharklist[i].x].timer = k;
		}//leave smell before leaving
		for (int i = 1; i <= m&& sharklist[i].alive; i++)
		{
			int facing = sharklist[i].dir;//shark facing which way
			int cury = sharklist[i].y, curx = sharklist[i].x; //cur location of shark i
			bool spacetogo = false;
			bool deadshark = false;
			for (int j = 1; j <= 4; j++)
			{//look for place to go
				int ny = cury + dy[priority[i][facing][j]];
				int nx = curx + dx[priority[i][facing][j]];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue; //out of bounds
				if (table[ny][nx].spaceof == 0)
				{
					if (checkforbigger(i, ny, nx))//overlaps with a higher prio shark
					{
						sharklist[i].alive = false;
						goneshark.push_back(i);
						deadshark = true; break;
					}spacetogo = true;
					sharklist[i].y = ny, sharklist[i].x = nx, sharklist[i].dir = j; break;
				}
			}if (deadshark)continue; if (spacetogo)continue; //if shark dead 

		}
		seconds++;
	}
}