#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int arr[1002];
	vector<int> two;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			two.push_back(arr[i] + arr[j]);
		}
	}
	sort(two.begin(), two.end());
	int maxi = 0;
	for(int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (binary_search(two.begin(),two.end(),arr[i]-arr[j]))
			{
				cout << arr[i]; return 0;
			}
		}
	}
	//cout << maxi;
}