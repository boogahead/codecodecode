#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
char table[3][27];//0=lc 1=rc 2= root
//stack<char>order;
void preorder(char cur)
{
	if (cur == '.')return;
	cout << cur;
	preorder(table[0][cur-'A']);
	preorder(table[1][cur-'A']);
}
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		table[0][i] = b; table[1][i] = c; table[2][i] = a;
	}
	//preorder
	//order.push('A');
	preorder('A');

}