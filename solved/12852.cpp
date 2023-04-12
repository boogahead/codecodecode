#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
int main(void)
{
	int yes[1000001] ;
	int path[1000001];
	
	yes[1] = 0;
	yes[0] = 0;
	int cur = 1;
	int input;
	cin >> input;
	for (int i = 2; i <= input; i++)
	{
		yes[i] = yes[i - 1] + 1;
		path[i] = i - 1;
		if (i % 3 == 0)
		{
			//if (yes[i] != -1)
			{
				if (yes[i / 3] + 1 < yes[i])
				{
					path[i] = i / 3; yes[i] = yes[i / 3];
				}
			}
		}
		if (i % 2 == 0)
		{
			//if (yes[i] != -1)
			{
				if (yes[i / 2] + 1 < yes[i])
				{
					path[i] = i / 2; yes[i] = yes[i / 2];
				}
			}
		}
	}
	for (int i = 0; i <= input; i++)
	{
		cout << yes[i] << " ";
	}
	int jumps = 0;
	cur = path[input];
	/*while (cur != 1)
	{
		jumps++;
		cur = path[cur];
	}*/
	cout << jumps;
}