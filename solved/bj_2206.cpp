#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;
// vector<vector<int>>map;
// typedef tuple<int,int,int>solver;
typedef struct {
  int i;
  int j;
  int wall;
} st;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int answer = INT_MAX;
int n, m;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  // map.resize(n,vector<int>(m));
  int map[1000][1000];
  int result[1000][1000];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &map[i][j]);
    }
  }
  if (n == 1 && m == 1) {
    cout << "1";
    return 0;
  }
  bool visited[1000][1000][2];
  // vector<vector<int>>result(n,vector<int>(m));
  queue<st> qq;
  qq.push({0, 0, 0});
  result[0][0] = 1;
  visited[0][0][0] = visited[0][0][1] = true;
  while (!qq.empty()) {
    int curi, curj, wall;
    curi = qq.front().i, curj = qq.front().j, wall = qq.front().wall;
    qq.pop();
    // tie(curi,curj,wall)=qq.front();qq.pop();
    for (int dir = 0; dir < 4; dir++) {
      int newi = curi + dy[dir], newj = curj + dx[dir];
      if (newi < 0 || newi >= n || newj < 0 || newj >= m)
        continue;
      if (map[newi][newj] == 1 && wall == 0 && !visited[newi][newj][wall+1]) {
        visited[newi][newj][1] = true;
        result[newi][newj] = result[curi][curj] + 1;
        qq.push({newi, newj,wall+1});
      }
      if (map[newi][newj] == 0 && !visited[newi][newj][wall]) {
        visited[newi][newj][wall] = true;
        result[newi][newj] = result[curi][curj] + 1;
        qq.push({newi, newj, wall});
      }

      if (newi == n - 1 && newj == m - 1) {
        cout << result[n - 1][m - 1];
        return 0;
      }
    }
  }
  cout << "-1";
  // cout<<"------\n";
}

/*
벽을 한번 뚫고 간 케이스, 그리고 벽을 한번도 뚫고 가지 않고 간 케이스를 고려한다.

위의 struct st 의 wall 값은 벽을 한번 뚫었는지 안뚫고 거기까지 간건지 적어주는 플래그같은거

처음에 0,0 에서는 벽을 한번도 안뚫었으므로 wall 값이 0 이다.

그리고 bfs를 갈겨준다

만약 벽을 봤다. 근데 wall=0. 즉 한번도 벽을 뚫어보지 않았다. 그러면 얘는 뚫어도 되는거다.
그렇게 되면 해당 좌표값의 wall=1. 한번 뚫고 거기까지 간 거라고 하고 그걸 큐에 넣어준다.

만약 벽이 아니다. 그러면 그냥 일반적으로 하듯이 visited 해주면 된다

말이되고픈 원숭이 (bj 1600) 함 풀어볼것

*/
