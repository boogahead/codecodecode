#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
vector<vector<int>>seats;
vector < vector<int >> studentlist(21);
int n;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
typedef pair<int, int>coord; //y x
vector<coord>candidate;
vector<coord>candidate2;
bool compare(coord a, coord b)
{
	if (a.first == b.first)return a.second < b.first;
	return a.first < b.first;
}
void firsttest(int stuid)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//cout << "tesitjs\n";
			int cnt = 0;
			if (seats[i][j] != -1)continue;
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
				for (int g = 0; g < 4; g++)
				{
					if (seats[ny][nx] == studentlist[stuid][g])cnt++;
				}
			}
			if (cnt > max)
			{
				candidate.clear();
				candidate.push_back({ i,j });
				max = cnt; continue;
			}
			if (cnt == max)
			{
				candidate.push_back({ i,j });
			}
		}
	}
	return;//multiple / nothin
}
void secondtest(int stuid)
{
	int max = 0;
	int y, x;
	for (int i = 0; i < candidate.size(); i++)
	{
		tie(y, x) = candidate[i];
		//cout << "Y " << y << " X " << x << "\n";
		int cnt = 0;
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
			if (seats[ny][nx] == -1)cnt++;
		}
		if (cnt > max)
		{
			candidate2.clear();
			candidate2.push_back({ y,x });
			max = cnt; continue;
		}
		if (cnt == max)
		{
			candidate2.push_back({ y,x });
		}
	}
	return;
}
int main(void)
{
	cin >> n;
	seats.resize(n, vector<int>(n, -1));
	for (int i = 1; i <= n * n; i++)
	{
		//cout << "HI\n";
		candidate.clear();
		candidate2.clear();
		int stuno;
		int f1, f2, f3, f4;
		cin >> stuno>>f1>>f2>>f3>>f4;
		studentlist[stuno].push_back(f1);
		studentlist[stuno].push_back(f2);
		studentlist[stuno].push_back(f3);
		studentlist[stuno].push_back(f4);
		int y, x;
		firsttest(stuno);
		if (candidate.size() > 1)
		{
			//cout << "SECOND TEST\n";
			secondtest(stuno);
			if (candidate2.size() > 1)
			{
				//cout << "THIRD TEST\n";
				sort(candidate2.begin(), candidate2.end(), compare);
			}
			tie(y, x) = candidate2[0];
		}
		else if(candidate.size()==1)
		{
			tie(y, x) = candidate[0];
		}
		seats[y][x] = stuno;
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << seats[i][j] << " ";
		}cout << "\n";
	}*/
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = i + dy[dir];
				int nx = j + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
				for (int g = 0; g < 4; g++)
				{
					if (seats[ny][nx] == studentlist[seats[i][j]][g])cnt++;
				}
			}
			if (cnt == 1)answer += 1;
			if (cnt == 2)answer += 10;
			if (cnt == 3)answer += 100;
			if (cnt == 4)answer += 1000;
		}
	}
	cout << answer;
	return 0;
}