#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <map>
#include <tuple>
using namespace std;
typedef pair <int, int> info;// row column of the head part of pipe
int answer = 0;
vector<vector<bool>>table(17, vector<bool>(17));
int n;
void dfs(info head,int direction,int movedir) 
{
	// direction :current direction  1 = right // 0 =  diag // -1 = down
	// movedir : move in which direction 1 = right // 0 = diag // -1 = down
	//cout << direction << " " << movedir << "\n";
	if (movedir == 1)
	{
		head.second += 1;
		direction = 1;
		if (!table[head.first][head.second]) { return; }
	}
	else if (movedir == 0)
	{
		head.first += 1; head.second += 1;
		direction = 0;
		if (!table[head.first][head.second] || !table[head.first - 1][head.second] || !table[head.first][head.second - 1]){return;}
	}
	else if (movedir == -1)
	{
		head.first += 1;
		direction = -1;
		if (!table[head.first][head.second]) { return; }
	}
	if (head.first == n - 1 && head.second == n - 1) { answer++; return; }
	for (int i = -1; i <= 1; i++)
	{
		if (direction == 1 && i == -1)continue;
		if (direction == -1 && i == 1)continue;
		dfs(head, direction, i);
	}
}
int main(void)
{
	info start = make_pair(0, 1);//starting location of head
	//vector<vector<bool>>table(n, vector<bool>(n));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			if (tmp) { table[i][j] = false; continue; }
			table[i][j]=true;
		}
	}

	int direction = 1;
	for (int i = -1; i <= 1; i++)
	{
		if (direction == 1)
		{
			if (i == -1)continue;
		}
		dfs(start, direction, i);
	}
	cout << answer;
}