#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <tuple>
#include <queue>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>>table(n,vector<int>(n,-1));
	vector<vector<int>>summer(n,vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1 ; j++)
		{
			//int tmp;
			cin >> table[i][j];
			if (i == 0) { summer[0][0] = table[i][j]; }
		}
		if (i > 0)
		{
			for (int j = 0; j < i + 1; j++)
			{
				for (int k = j - 1; k <= j; k++)
				{
					if (k <0 || k > i-1)continue;
					summer[i][j] = max(summer[i][j],summer[i - 1][k] + table[i][j]);
				}
			}
		}
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n && table[i][j] != -1; j++)
		{
			cout << summer[i][j] << " ";
		}cout << "\n";
	}*/
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, summer[n - 1][i]);
	}
	cout << ans;
}