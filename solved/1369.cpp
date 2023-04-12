#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <tuple>
#include <map>
#include <string>
using namespace std;
vector<int>ufind(100001);
tuple<int, int, int> table[100002];//cost start end
int find(int a)
{
	if (ufind[a] == a)return a;
	return find(ufind[a]);
}
void uni(int a, int b)
{
	int tmpa = find(a), tmpb = find(b);
	ufind[tmpb] = tmpa;
	return;
}
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n+1; i++)
	{
		ufind[i] = i;
	}int yes = 0;
	int tmp;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		table[yes++] = { tmp,n + 1,i };
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> tmp;
			if (i >= j)continue;
			table[yes++] = { tmp,i,j };
		}
	}
	sort(table, table + yes);
	int cnt = 0;
	int price, start, end;
	int answer = 0;
	for (int i = 0; i < yes; i++)
	{
		tie(price, start, end) = table[i];
		if (find(start) == find(end))continue;
		cnt++;
		//cout << "pirce start end " << price << start << end << "\n";
		answer += price;
		uni(start, end);
		if (cnt == n )break;
	}
	/*for (int i = 1; i <= n + 1; i++)
	{
		cout << ufind[i] << " ";
	}cout << "\n";*/
	cout << answer;
}