#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef pair<int, int> info;
int main(void)
{
	vector<info> times;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		times.push_back(info(b, a));
	}
	sort(times.begin(), times.end());
	int count = 0, t = 0;
	for (int i = 0; i < n; i++)
	{
		if (t > times[i].second)continue;
		count++;
		t = times[i].first;
	}
	cout << count;
}