#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <time.h>
#include <stack>
#include <queue>
using namespace std;
int main(void)
{
	int yes[100001];
	yes[0] = 0;
	int count, times;
	cin >> count >> times;
	int i, j;
	for (i = 1; i <= count; i++)
	{
		cin >> yes[i];
		if (i != 1)
		{
			yes[i] += yes[i - 1];
		}
	}
	vector<int>ans;
	for (i = 1; i <= times; i++)
	{
		int start, end;
		cin >> start>>end;
		ans.push_back(yes[end] - yes[start - 1]);
	}
	for (i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}
}