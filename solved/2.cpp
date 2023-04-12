#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
using namespace std;
int minmovement = 0;
int dfs(vector<bool>map, int start);
int checkall(vector<bool>map);
int noexplode(vector<bool>map, int start);

int dfs(vector<bool>map,int start)
{
	while (checkall(map) == 0)
	{
		int next = noexplode(map, start);
		if (next == 0)return 0;//failed.try different one
		map[next] = false; start = next;
	}
	return 1;
}
int checkall(vector<bool>map)
{
	int i;
	for (i = 0; i < map.size(); i++)
	{
		if (map[i] == true) { return 0; }//still treasure left
	}
	return 1;//all acquired
}
int noexplode(vector<bool>map, int start)
{
	int i;
	int left;
	int right;
	for (i = start-1; i >= 0; i--)
	{
		if (map[i] == 1) { left = start - i; break; }
	}
	for (i = start + 1; i <= map.size(); i++)
	{
		if (map[i] == 1) { right = i - start; break; }
	}
	if (left == right) { return 0; }//exploded
	return min(left,right);//not exploded & gives next closest
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	std::ios::sync_with_stdio(false);

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		int totmap;
		int realstart;
		vector<int>only_treasure;
		vector<bool>map;
		cin >> totmap, realstart;
		int i, j;
		for (i = 0; i < totmap; i++)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 1)
			{
				map.push_back(true);
			}
			else { map.push_back(false); }
			only_treasure.push_back(i);
		}
		vector<bool>tester = map;
		//vector<int>treasure_tmp = only_treasure;
		realstart -= 1;// starting point
		int flip = 0;
		int next;
		for (i = 0; i < totmap; i++)
		{
			if (flip == 0&&i!=0) { i *= -1; }
			if (realstart + flip<0 || realstart + flip>totmap - 1) { continue; }
			if (dfs(tester, realstart + i) == 1) { if (i < 0) { i *= -1; }break; }
			if (flip == 0&&i!=0) { i *= -1; flip = 1; }//restore after flip
		}
		cout << "#" << test_case << " "<<i<<"\n";
	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
