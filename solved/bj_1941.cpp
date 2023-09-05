#include <algorithm>
#include <iostream>
#include <map>
#include <pthread.h>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
using namespace std;
int answer = 0;
void checker(vector<int> &list, vector<vector<int>> &table) {
  vector<bool> visited(25);
  vector<vector<int>> tmptable(5, vector<int>(5, 0));
  for (auto i : list) {
    tmptable[i / 5][i % 5] = 2;
  }
  // cout<<"hi\n";
  queue<int> qq;
  qq.push(list[0]);
  visited[list[0]] = true;
  int counter = 1;
  while (!qq.empty()) {
    int tmp = qq.front();
    qq.pop();
    int curi = tmp / 5, curj = tmp % 5;
    for (int dir = 0; dir < 4; dir++) {
      int newi = curi + dy[dir], newj = curj + dx[dir];
      if (newi < 0 || newi >= 5 || newj < 0 || newj >= 5)
        continue;
      if (visited[newi * 5 + newj])
        continue;
      visited[newi * 5 + newj] = true;
      if (tmptable[newi][newj] == 2) {
        counter++;
        qq.push(newi * 5 + newj);
      }
    }
  }
  if (counter == 7)
    answer++;
  return;
}
void cases(vector<int> &list, int count, int cur, int idx,
           vector<vector<int>> &table) {
  if (count == 7) {
    int scnt = 0;
    for (auto i : list) {
      // cout<<i<<"\n";
      int curi = i / 5, curj = i % 5;
      // cout<<curi<<" "<<curj<<"\n";
      if (table[curi][curj] == 1)
        scnt++;
    }
    if (scnt >= 4) {
      checker(list, table);
    }
    return;
  }
  for (int i = cur + 1; i <= 24; i++) {
    list[idx] = i;
    cases(list, count + 1, i, idx + 1, table);
  }
}
int main(void) {
  vector<vector<int>> table(5, vector<int>(5, 0));
  vector<vector<bool>> visited(5, vector<bool>(5));
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      char tmp;
      cin >> tmp;
      if (tmp == 'S') {
        table[i][j] = 1;
      }
    }
  }
  vector<int> list(7);
  cases(list, 0, -1, 0, table);
  cout << answer << "\n";
}
