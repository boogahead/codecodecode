#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
#include <string>

using namespace std;
string findkey(unordered_map<string, int>& table, int value)
{
	for (auto& k : table)
	{
		if (k.second == value)
		{
			return k.first;
		}
	}
}
int main(void)
{
	int n, problems;
	cin >> n >> problems;
	unordered_map<string, int> table;
	vector<string> list;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		table.insert(make_pair(tmp, i + 1));
		list.push_back(tmp);
	}
	vector<string>answer;
	for (int i = 0; i < problems; i++)
	{
		string tmp;
		cin >> tmp;
		if (!(isdigit(tmp[0])))
		{
			answer.push_back(to_string(table[tmp])); continue;
		}
		answer.push_back(list[stoi(tmp)-1]);
	}
	for (auto i : answer)
	{
		cout << i << "\n";
	}
}