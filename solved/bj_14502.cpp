#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> info;
vector<info> virusloc;
int N, M;
int answer=0;
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int wallcount=0;
void spread(vector<vector<int>>table,vector<info>&realcoords){
    queue<info>qq;
    int viruscount=virusloc.size();
    for(auto i:realcoords){
        table[i.first][i.second]=1;
    }
    vector<vector<bool>>visited(N,vector<bool>(M));
    for(auto i:virusloc){
        qq.push({i.first,i.second});
        visited[i.first][i.second]=true;
    }
    while(!qq.empty()){
        info tmp=qq.front();qq.pop();
        for(int dir=0;dir<4;dir++){
            int newi=tmp.first+dy[dir],newj=tmp.second+dx[dir];
            if(newi<0||newi>=N||newj<0||newj>=M)continue;
            if(visited[newi][newj])continue;
            if(table[newi][newj]!=0)continue;
            visited[newi][newj]=true;
            table[newi][newj]=2;
            viruscount++;
            qq.push({newi,newj});
        }
    }
    int safe=N*M-viruscount-wallcount;
    //answer=max(answer,safe);
    if(answer<safe){
        answer=safe;
        /*cout<<"record broken: "<<safe<<"\n";
        for(auto i:table){
            for(auto j:i){
                cout<<j<<" ";
            }cout<<"\n";
        }cout<<"\n\n";*/
    }
}

void findcandidate(vector<vector<int>> &table, int count, int curval,
                   int target, vector<int> &candidates) {
  if (count == 3) {
    vector<info> realcoords;
    for (auto i : candidates) {
      realcoords.push_back({i / M, i % M});
    }
    /*
    for (auto i : realcoords) {
      cout << i.first << " " << i.second << " | ";
    }
    cout << "\n";*/
    spread(table,realcoords);
    return;
  }
  if (count < 3 && curval + 3 - count > target - 1)
    return;
  for (int i = curval + 1; i < target; i++) {
    if (table[i / M][i % M] != 1 && table[i / M][i % M] != 2) {
      candidates[count] = i;
      findcandidate(table, count + 1, i, target, candidates);
    }
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  vector<vector<int>> table(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> table[i][j];
      if(table[i][j]==1)wallcount++;
      if (table[i][j] == 2)
        virusloc.push_back({i, j});  
    }
  }
  /*cout<<"-------------------virus\n\n\n";
  for(auto i:virusloc){
    cout<<i.first<<" "<<i.second<<"\n";
  }*/
  wallcount+=3;
  vector<int> candidates(3);
  findcandidate(table, 0, -1, N * M, candidates);
  cout<<answer;
}
