#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int main(void)
{
	set<string> table;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, enter;
		cin >> name >> enter;
		if (table.count(name)==0&& enter == "enter")
		{
			table.insert(name);
		}
		if (table.count(name) > 0 && enter == "leave")
		{
			table.erase(name);
		}
	}
	for (auto i =table.rbegin();i!=table.rend();i++)
	{
		cout << *i << "\n";
	}
}