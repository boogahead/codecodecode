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
		long long n,k,x;
		cin >> n>>k>>x;
		if (n < x) {
			int start = n - k + 1;
			//cout << "@@@ " << k * (start + n) / 2 << "\n";
			if (k * (start + n) / 2 >= x) {
				if (k * (1 + k) / 2 > x)answer.push_back("NO");
				else answer.push_back("YES");
			}
			else answer.push_back("NO");
		}
		else if (n >= x) {
			int end = k;
			if (k * (1 + end) / 2 <= x)answer.push_back("YES");
			else answer.push_back("NO");
		}
	}
	for (auto i : answer) {
		cout << i << "\n";
	}
}