#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> info; //number, original idx
int main(void)
{
	int n;
	cin >> n;
	vector<int> arr;
	vector<int> input(1000001);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		input[i]=tmp;
		arr.push_back(input[i]);
	}
	sort(arr.begin(), arr.end());
	//vector<int> answer(1000001);
	arr.erase(unique(arr.begin(), arr.end()),arr.end());
	for (int i = 0; i < n; i++)
	{
		//cout << "AAAAAAAAAAAAAA "<<input[i] << "\n";
		cout<<lower_bound(arr.begin(),arr.end(),input[i]) - arr.begin()<<" ";
	}
	/*for (int i = 0; i < n; i++)
	{
		cout << answer[i] << " ";
	}*/
}