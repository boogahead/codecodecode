//vector을 array로 바꿔보자
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
typedef pair<int, int>loc;//y x
loc direction[9] = { make_pair(99,99),make_pair(-1,0),make_pair(-1,-1), make_pair(0,-1), make_pair(1,-1),
make_pair(1,0), make_pair(1,1), make_pair(0,1), make_pair(-1,1) };

int answer = 0;
struct s {
	int y;
	int x;
	int sharkdir;
}; //fishtable -1 값은 상어로 표현할 예정  
	// 0은 빈공간으로 표현할 예정
void printfishtable(vector<vector<int>>& table)
{
	cout << "\nfishtable\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << table[i][j] << " ";
		}cout << "\n";
	}
}
void printdirtable(vector<vector<int>>& table)
{
	cout << "\ndirtable\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << table[i][j] << " ";
		}cout << "\n";
	}
}
void fishmove(vector<vector<int>>&fishtable,vector<vector<int>>&dirtable)
{
	int fishidx = 1;
	while (fishidx < 17)
	{
		//cout << fishidx << "\n------------------------------\n";
		//printfishtable(fishtable);
		//printdirtable(dirtable);
		bool moved = false;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (fishtable[i][j] == fishidx)
				{
					while (!moved)
					{//goes around until fish finally moves
						int ny = i + direction[dirtable[i][j]].first;
						int nx = j + direction[dirtable[i][j]].second;
						if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4 && fishtable[ny][nx] != -1)
						{// if a moveable place
							if (fishtable[ny][nx] != 0)
							{//another fish in the direction
								int fishno = fishtable[ny][nx], tmpdir = dirtable[ny][nx];
								fishtable[ny][nx] = fishtable[i][j];
								dirtable[ny][nx] = dirtable[i][j];
								fishtable[i][j] = fishno, dirtable[i][j] = tmpdir;
								//finished swapping
							}
							else//jjust empty space
							{
								fishtable[ny][nx] = fishtable[i][j];
								dirtable[ny][nx] = dirtable[i][j];
								fishtable[i][j] = 0, dirtable[i][j] = 0;
							}
							moved = true;
						}
						//if(ny<0||ny>=4||nx<0||nx>=4||fishtable[ny][nx]==-1)
						else//not a moveable place
						{
							//dirtable[i][j] = (dirtable[i][j] + 1) % 9;
							dirtable[i][j]++;
							if (dirtable[i][j] == 9)dirtable[i][j] = 1;
						}//moves around
					}
					if (moved)break;
				}
			}
			if (moved)break;
		}
		fishidx++;
	}
}
void dfs(s shark,vector<vector<int>>fishtable, vector<vector<int>>dirtable,int curscore,int depth)
{
	cout << "X :" << shark.y << " Y :" << shark.x << "\n\n";
	cout << "DEPTH " << depth << "\n";
	fishmove(fishtable, dirtable);
	//return;
	printfishtable(fishtable);
	printdirtable(dirtable);
	bool edible = false;
	for (int i = 1; i <= 3; i++)
	{
		int ny = shark.y + direction[shark.sharkdir].first * i;
		int nx = shark.x + direction[shark.sharkdir].second * i;
		if (ny > 3 || ny < 0 || nx>3 || nx < 0)break;//out of bounds no need to calculate further
		if (fishtable[ny][nx] != 0) { edible = true; break; }//theres something to eat
	}
	if (!edible)
	{
		answer = max(answer, curscore);
		cout << "ANSWER " << answer << "\n";
		return;//if theres nothing to eat, go back
	}
	if (edible) {
		for (int i = 1; i <= 3; i++)
		{
			cout << "-------------------\n";
			cout << "Y X : " << shark.y << " " << shark.x << "\n";
			vector<vector<int>>fishtabletmp = fishtable;
			vector<vector<int>>dirtabletmp = dirtable;
			int ny = shark.y + direction[shark.sharkdir].first * i;
			int nx = shark.x + direction[shark.sharkdir].second * i;
			cout << "NY : " << ny << " NX : " << nx << "\n";
			if (ny > 3 || ny < 0 || nx>3 || nx < 0)break;//out of bounds
			if (fishtabletmp[ny][nx] == 0)continue;//nothing to eat
			cout << "I ATE " << fishtabletmp[ny][nx] << "\n";
			int curscoretmp = curscore + fishtabletmp[ny][nx];
			//curscore += fishtabletmp[ny][nx];
			fishtabletmp[shark.y][shark.x] = 0;
			dirtabletmp[shark.y][shark.x] = 0;
			shark.y = ny, shark.x = nx, shark.sharkdir = dirtabletmp[ny][nx];
			fishtabletmp[ny][nx] = -1;
			dfs(shark, fishtabletmp, dirtabletmp, curscoretmp,depth+1);
			cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
		}
	}
	return;
}
int main(void)
{
	s shark;
	vector<vector<int>>dirtable(4, vector<int>(4));//0 은 빈칸
	vector<vector<int>>fishtable(4, vector<int>(4));//0은 빈칸 -1 은 상어
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> fishtable[i][j] >> dirtable[i][j];
		}
	}
	shark.sharkdir = dirtable[0][0];
	shark.y = 0, shark.x = 0;
	answer += fishtable[0][0];
	fishtable[0][0] = -1;
	//printdirtable(dirtable);
	//printfishtable(fishtable);
	dfs(shark,fishtable,dirtable,answer,0);
	//printfishtable(fishtable);
	//printdirtable(dirtable);
	cout << answer;
	return 0;
}