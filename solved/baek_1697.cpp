#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> info;
int main(void)
{
	queue<int> qqq;
	int farmer, cow;
	int map[100002];
	fill(map, map+100001, -1);
	cin >> farmer >> cow;
	if (cow <= farmer)	
	{
		cout << farmer - cow;
		return 0;
	}
	//cin >> farmer >> cow;
	int time = 0;
	map[farmer] = 0;
	qqq.push(farmer);
	//auto curpos = qqq.front();
	while (map[cow] == -1)
	{
		int current = qqq.front(); qqq.pop();
		for (int next : {current - 1, current + 1, current * 2})
		{
			if (next < 0 || next>100000)continue;
			if (map[next] != -1)continue;
			map[next] = map[current] + 1;
			qqq.push(next);
		}
	}
	cout << map[cow];
	return 0;
}