#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<int>table(n+1);
	table[1] = 1;
	table[2] = 3;
	for (int i = 3; i <=n; i++)
	{
		table[i] = (table[i - 2]*2 + table[i - 1])%10007;
	}
	cout << table[n];
}