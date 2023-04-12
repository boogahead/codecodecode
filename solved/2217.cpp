#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main(void)
{
	vector<int>list;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		list.push_back(tmp);
	}
	sort(list.begin(), list.end());
	int maxweight = 0;
	int count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		count++;
		maxweight = max(list[i] * count, maxweight);
	}
	cout << maxweight;
}