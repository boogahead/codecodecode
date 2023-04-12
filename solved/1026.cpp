#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
bool revers(int c, int d)
{
	return c > d;
}
int main(void)
{
	int n;
	cin >> n;
	vector<int>a;
	vector<int>b;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), revers);
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer += (a[i] * b[i]);
	}cout << answer;
}