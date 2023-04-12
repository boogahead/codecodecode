#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<int>arr;
	//int arr[500003];
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
		//arr[i] = tmp;
	}
	int m;
	cin >> m;
	vector<int> check;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		check.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < m; i++)
	{
		cout<< upper_bound(arr.begin(), arr.end(), check[i]) - lower_bound(arr.begin(), arr.end(), check[i]) << " ";
	}
}