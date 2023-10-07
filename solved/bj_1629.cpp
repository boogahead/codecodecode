#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<vector<int>> table;
void prefix(int cur) { 
    if (cur==(int)'.')return;
    cout<<char(cur+'A');
    prefix(table[cur][0]);
    prefix(table[cur][1]);
}
void middlesth(int cur){
    if (cur==(int)'.')return;
    middlesth(table[cur][0]);
    cout<<char(cur+'A');
    middlesth(table[cur][1]);
}
void laststh(int cur){
    if (cur==(int)'.')return;
    laststh(table[cur][0]);
    
    laststh(table[cur][1]);
    cout<<char(cur+'A');
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  table.resize(N);
  for (int i = 0; i < N; i++) {
    char tmp, tmp1, tmp2;
    cin >> tmp >> tmp1 >> tmp2;
    if (tmp1 != '.')
      table[tmp - 'A'].push_back(tmp1 - 'A');
    else
      table[tmp - 'A'].push_back('.');
    if (tmp2 != '.')
      table[tmp - 'A'].push_back(tmp2 - 'A');
    else
      table[tmp - 'A'].push_back('.');
  }
  prefix(0);
  cout<<"\n";
  middlesth(0);
  cout<<"\n";
  laststh(0);

}
