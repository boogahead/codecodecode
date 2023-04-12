#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
using namespace std;
int sorted[9];
int anstot = 0;
void recur(vector<int> list, int cnt,int icoord,int sum)
{
	if (cnt == 7)
	{
		if (sum == 100)
		{
			//sort(list.begin(), list.end());
			//cout << "\n";
			/*for (int i = 0; i < 7; i++)
			{
				cout << list.back()<<"\n";
				list.pop_back();
			}*/
			if (anstot < 1)
			{
				for (auto i = list.begin(); i != list.end(); i++)
				{
					cout << *i << "\n";
				}
				anstot++;
			}
			return;
		}
		return;
	}
	else
	{
		for (int i = icoord+1; i < 9; i++)
		{
			//cnt++;
			sum += sorted[i];
			list.push_back(sorted[i]);
			recur(list, cnt+1, i, sum);
			list.pop_back();
			sum -= sorted[i];
		}
	}
}
int main(void)
{
	vector<int> putin;
	for (int i = 0; i < 9; i++)
	{
		int tmp;
		cin >> tmp;
		putin.push_back(tmp);
	}
	sort(putin.begin(),putin.end());
	for (int i = 8; i >= 0; i--)
	{
		sorted[i] = putin.back();
		putin.pop_back();
	}
	int cnt = 1;
	int i;
	vector<int> listtmp;
	int sum = 0;
	for (i = 0; i < 9; i++)
	{
		sum += sorted[i];
		listtmp.push_back(sorted[i]);
		recur(listtmp, cnt,i,sum);
		listtmp.pop_back();
		sum -= sorted[i];
	}
}