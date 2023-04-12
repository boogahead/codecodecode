#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main(void)
{
	int n, k;
	vector<int> coins;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		coins.push_back(tmp);
	}
	int remainder = k;
	int count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (coins[i] <= remainder)
		{
			count += remainder / coins[i];
			remainder = remainder - (remainder / coins[i]) * coins[i];
		}
	}
	cout << count;
}