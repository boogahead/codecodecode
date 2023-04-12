#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <time.h>

using namespace std;
int main(void)
{
	priority_queue<int,vector<int>,greater<int>> pq;
	int i;
	cin >> i;
	for (int j = 0; j < i; j++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	int ans = 0;
	int curpile=0;
	while (pq.size()>1)
	{
		//curpile += pq.top();
		int first = pq.top(); pq.pop();
		int second = pq.top(); pq.pop();
		ans += first + second;
		pq.push(first + second);
		//ans += pq.top();

	}
	cout << ans;
	return 0;
}