#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
class Compare {
public:
	bool operator()(int a, int b)
	{
		if (abs(a) != abs(b))return abs(a) > abs(b);
		return a > 0 && b < 0; //���� ���밪���� ��쿡�� a(���)�� b(����)���� ũ�� b ���� �־��ֱ�
		//return false;
	}
};
int main(void)
{
	int n;
	cin >> n;
	bool once = false;
	priority_queue<int,vector<int>,Compare> list;
	vector<int>answer;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		
		if(tmp==0)
		{
			if (list.size() == 0) {
				answer.push_back(0); continue;
			}
			answer.push_back(list.top()); list.pop();
		}
		if (tmp != 0)
		{
			list.push(tmp);
		}
	}
	for (auto i : answer)
	{
		cout << i << "\n";
	}
}