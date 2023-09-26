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
		vector<int>table(n);
		for (int i = 0; i < n; i++) cin >> table[i];
		int q; cin >> q;
		vector<vector<int>>precalculate;
		for (int i = 0; i < n; i++) {
			//cout << "i " << i << "\n";
			vector<int>tmp;
			tmp.push_back(table[i]);
			for (int j = 1; j < n-i ; j++) {
				//cout << j << " ";
				//precalculate[i][j] = precalculate[i][j - 1] & table[j];
				tmp.push_back(tmp[j - 1] & table[j+i]);
			}//cout << "\n";
			precalculate.push_back(tmp);
			//cout << "done\n";
		}
		for (auto i : precalculate) {
			for (auto j : i)cout << j << " ";
			cout << "\n";
		}
		cout << "------\n";
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << precalculate[i][j] << " ";
			}cout << "\n";
		}*/
		vector<int>tmp;
		for (int i = 0; i < q; i++) {
			int l, k;
			cin >> l >> k;
			int idx = -1;
			l--;
			//cout << "l : " << l << "\n";
			for (int j = 0; j < precalculate[l].size(); j++) {
				if (precalculate[l][j] >= k)idx = max(idx, j);
			}
			if (idx == -1)tmp.push_back(idx);
			else tmp.push_back(idx+1+l);
		}
		answer.push_back(tmp);
	}
	for (auto i : answer) {
		for (auto j : i) {
			cout << j << " ";
		}cout << "\n";
	}
}