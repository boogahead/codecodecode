#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;
vector<vector<int>> table;
int n;
int answer;
int furthest;
int furthestdistance=0;
void recursion(int cur, int distance, vector<bool> &visited) {
    if(visited[cur])return;
    if(distance>furthestdistance){
        furthest=cur;furthestdistance=distance;
    }
    visited[cur]=true;
    for(int i=0;i<table[cur].size();i+=2){
        recursion(table[cur][i],distance+table[cur][i+1],visited);
    }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  table.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int idx;
    cin>>idx;
    int tmp = 0;
    // bool value;
    while (true) {
      cin >> tmp;
      if (tmp == -1)
        break;
      table[idx].push_back(tmp);
    }
  }
  
  vector<bool> visited(n + 1);
  recursion(1,0,visited);
  for(auto i:visited)i=false;
  furthestdistance=0;
  recursion(furthest,0,visited);
  cout<<furthestdistance;
}
