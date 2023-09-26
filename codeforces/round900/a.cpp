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
	vector<string>answer;
	for (int tc = 0; tc < t; tc++) {
		int n, k;
		cin >> n >> k;
		set<int>table;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			table.insert(tmp);
		}
		if (table.find(k) != table.end())answer.push_back("YES");
		else answer.push_back("NO");
	}
	for (auto i : answer) {
		cout << i << "\n";
	}
}