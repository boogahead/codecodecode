#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <cmath>
#include <map>
#include <deque>
#include <unordered_map>
#include <set>

using namespace std;
typedef pair<int, int>info;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	vector<vector<int>>answer;
	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n;
		vector<int>tmp(n);
		tmp[0] = 1;
		tmp[1] = 3;
		for (int i = 2; i < n; i++) {
			int curval = tmp[i - 1] + 1;
			while ((curval * 3) % (tmp[i - 1] + tmp[i - 2])==0)curval++;
			tmp[i] = curval;
		}
		answer.push_back(tmp);
	}
	for (auto i : answer) {
		for (auto j : i) {
			cout << j << " ";
		}cout << "\n";
	}
}