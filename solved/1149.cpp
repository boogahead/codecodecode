#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;
int findmin(int a, int b, int c)
{
	int answer = a;
	if (a > b)answer = b;
	if (answer > c)answer = c;
	return answer;
}
int main(void)
{
	int number;
	cin >> number;
	//vector<vector<int>> table;
	int table[1001][3];
	for (int i = 1; i <= number; i++)
	{
		vector<int>tmp;
		int r, g, b;
		cin >> r >> g >> b;
		table[i][0] = r;
		table[i][1] = g; table[i][2] = b;
	}
	int pyo[1001][3];
	pyo[1][0] = table[1][0];
	pyo[1][1] = table[1][1];
	pyo[1][2] = table[1][2];
	for (int i = 2; i <= number; i++)
	{
		pyo[i][0] = min(pyo[i - 1][1], pyo[i - 1][2]) + table[i][0];
		pyo[i][1] = min(pyo[i - 1][0], pyo[i - 1][2]) + table[i][1];
		pyo[i][2] = min(pyo[i - 1][0], pyo[i - 1][1]) + table[i][2];
	}
	cout << findmin(pyo[number][0], pyo[number][1], pyo[number][2]);
}