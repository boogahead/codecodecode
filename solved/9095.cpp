#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
int dyn[11];
using namespace std;
int main(void)
{
	queue<int>answ;
	int times;
	cin >> times;
	int z, j,i;
	fill(dyn, dyn + 11, 0);
	dyn[0] = 0;
	dyn[1] = 1;
	dyn[2] = 2;
	dyn[3] = 4;
	//dyn[4] = 7;
	for (i = 4; i < 11; i++)
	{
		dyn[i] = dyn[i - 1] + dyn[i - 2] + dyn[i - 3];
		//for (j = 0; j <= i; j++)
		//{
			//dyn[i] += dyn[j] + dyn[i - j];
		//}
	}
	for (z = 0; z < times; z++)
	{
		//fill(dyn, dyn + 12, 0);
		int tmp;
		cin >> tmp;
		answ.push(dyn[tmp]);
	}
	for (i = 0; i < times; i++)
	{
		cout << answ.front() << "\n";
		answ.pop();
	}
}