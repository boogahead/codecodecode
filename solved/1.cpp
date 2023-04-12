#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

typedef pair<int, int>coordinate;
coordinate leftreturn(vector<coordinate>loc)
{//returns leftmost
	int i;
	coordinate comp; comp.first = 0, comp.second = 999;
	for (i = 0; i < loc.size(); i++)
	{
		if (comp.second > loc[i].second)
		{
			comp = loc[i];
		}
	}
	return comp;
}
coordinate rightreturn(vector<coordinate>loc)
{
	int i;
	coordinate comp; comp.first = 0, comp.second = -1;
	for (i = 0; i < loc.size(); i++)
	{
		if (comp.second < loc[i].second)
		{
			comp = loc[i];
		}
	}
	return comp;
}
coordinate bottomreturn(vector<coordinate>loc)
{
	int i;
	coordinate comp; comp.first = -1, comp.second = 0;
	for (i = 0; i < loc.size(); i++)
	{
		if (comp.first < loc[i].first)
		{
			comp = loc[i];
		}
	}
	return comp;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   �������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� sample_input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("sample_input.txt", "r", stdin);

	/*
	   �Ʒ� �ڵ�� ����¼��� ���μ��� �ӵ��� ����Ű�� ���� ��ɾ��Դϴ�.
	   �Ʒ� �ڵ尡 ����� ��� scanf�� cin�� ȥ���ؼ� ����� �� �׽�Ʈ ���̽��� ���������� �Էµ��� ���� �� ������ �����Ͻʽÿ�.
	*/
	std::ios::sync_with_stdio(false);
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		typedef pair<int, int>coordinate;
		vector<coordinate> loc;

		int m, n;
		cin >> m >> n;
		int i, j,g;
		int x, y;
		for (g = 0; g < n; g++)
		{
			cin >> i >> j;
			coordinate tmp;
			tmp.first = i; tmp.second = j;
			loc.push_back(tmp);
		}
		coordinate leftmost=leftreturn(loc);
		coordinate rightmost=rightreturn(loc);
		coordinate bottom = bottomreturn(loc);
		//cout << leftmost.first << " " << leftmost.second << "\n";
		//cout << rightmost.first << " " << rightmost.second << "\n";
		//cout << bottom.first << " " << bottom.second << "\n";
		int bottomup = bottom.first-1;
		int leftall = rightmost.second-1;
		int rightall = m - leftmost.second;
		//cout << rightall << "\n";
		int sideways = min(leftall,rightall);
		int answer = bottomup + sideways;
		// ǥ�����(ȭ��)���� ����� ����մϴ�.
		cout << "#" << test_case <<" "<< answer<<"\n";
	}

	return 0; // ��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}
