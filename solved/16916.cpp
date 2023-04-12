#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(void)
{
	string s, p;
	cin >> s >> p;
	if (p.size() > s.size()) { cout << "0"; return 0; }
	for (int i = 0; i < s.size() - p.size();i++)
	{
		//cout << s.substr(i,  p.size()) << "\n";
		if (s.substr(i, p.size()) == p)
		{
			cout << "1"; return 0;
		}
	}
	cout << "0"; return 0;
}