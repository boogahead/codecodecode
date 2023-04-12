#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int table[1001];
	if (n == 1) { cout << "1\n"; return 0; }
	if (n == 2) { cout << "2\n"; return 0; }
	table[1] = 1;
	table[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		table[i] = 0;
		for (int j = 1; j < i; j++)
		{
			table[i] += table[j] + table[i - j];
		}
	}
	cout << table[n] << "\n";

}