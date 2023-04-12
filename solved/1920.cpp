#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> yes;
	vector<int> checker;
	vector<int> answer;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		yes.push_back(tmp);
	}
	int nn;
	cin >> nn;
	for (int i = 0; i < nn; i++)
	{
		int tmp;
		cin >> tmp;
		checker.push_back(tmp);
	}
	sort(yes.begin(), yes.end());
	for (int i = 0; i < nn; i++)
	{
		bool found = false;
		int start = 0, end = n - 1,middle;
		while (start<=end)
		{
			middle = (end + start) / 2;
			if (checker[i] == yes[middle]) { cout << "1\n"; found = true; break; }
			if (checker[i] > yes[middle])
			{
				start = middle + 1;
			}
			else
			{
				end = middle - 1;
			}
		}
		if (found == false) { cout << "0\n"; }
		//cout << binary_search(yes.begin(), yes.end(), checker[i]) << "\n";
	}
	
}