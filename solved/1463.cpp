#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> info;
int main(void)
{
	int n;
	cin >> n;
	queue<info> qq;
	qq.push(info(n,0));
	while (!qq.empty())
	{
		auto tmp = qq.front();
		qq.pop();
		if (tmp.first == 1) { cout << tmp.second; return 0; }
		if (tmp.first % 3 == 0)
		{
			qq.push(info(tmp.first / 3, tmp.second + 1));
		}
		if (tmp.first % 2 == 0)
		{
			qq.push(info(tmp.first / 2, tmp.second + 1));
		}
		qq.push(info(tmp.first - 1, tmp.second + 1));
	}
	return 0;
}