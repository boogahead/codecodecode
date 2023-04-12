#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
using namespace std;
int answer = -999999999;
int n;
string s;
int calculate(int a, int b, char op)
{
	if (op == '+')
	{
		return a + b;
	}
	if (op == '-')
	{
		return a - b;
	}
	if (op == '*')
	{
		return a * b;
	}
}
void dfs(int idx, int cur)
{
	if (idx >= n)
	{
		answer = max(answer, cur);
		return;
	}
	char op;
	if (op= idx == 0 ?  '+' : s[idx - 1]);
	if (idx + 2 < n)
	{
		int bracket = calculate(s[idx]-'0', s[idx+2] - '0', s[idx+1]);
		dfs(idx + 4, calculate(cur,bracket, op));
	}
	dfs(idx + 2, calculate(cur, s[idx] - '0', op));
}
int main(void)
{
	cin >> n >> s;
	dfs(0, 0);
	cout << answer;
}