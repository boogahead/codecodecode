#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
// 2 know truth   1  heard truth   0 not yet    -1  heard lie
vector<vector<int>> partylist;
vector<int> parent;
vector<int> ranks;
int answer = -1;
int find(int a) {
  if (parent[a] == a)
    return a;
  return parent[a] = find(parent[a]);
}
void unify(int a, int b) {
  int aa = find(a);
  int bb = find(b);
  if (aa == bb) {
    // cout<<"equal\n";
    return;
  }
  // cout<<"notequal\n";
  if (ranks[aa] > ranks[bb])
    swap(aa, bb);
  parent[aa] = bb;
  if (ranks[aa] == ranks[bb])
    ranks[bb]++;
  return;
}
vector<int> knowingtruth;
int main(void) {
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  int truth;
  cin >> truth;
  vector<int> table(N + 1);
  parent.resize(N + 1);
  ranks.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    parent[i] = i;
    ranks[i] = 1;
  }
  for (int i = 0; i < truth; i++) {
    int tmp;
    cin >> tmp;
    // table[tmp] = 2;
    knowingtruth.push_back(tmp);
  } /*
   cout<<"\n";
   for(auto i:parent)cout<<i<<" ";
   cout<<"\n";*/
  for (int i = 0; i < M; i++) {
    vector<int> tmp;
    int tmpn;
    cin >> tmpn;
    for (int j = 0; j < tmpn; j++) {
      int tmpj;
      cin >> tmpj;
      tmp.push_back(tmpj);
    }
    int standard = tmp[0];
    // cout<<standard<<"\n";
    for (int j = 1; j < tmpn; j++) {
      // cout<<standard<<" "<<tmp[j]<<"\n";
      unify(standard, tmp[j]);
    }
    partylist.push_back(tmp);
  }
  int answer = M;
  for (int i = 0; i < M; i++) {
    bool saytruth = false;
    for (int j = 0; j < partylist[i].size(); j++) {
      //cout<<j<<"\n";
      if (saytruth)
        break;
      int cur = partylist[i][j];
      //cout<<"lsakdjflksajdflkdjsaf\n";
      if (knowingtruth.size() >= 1) {
        for (int k = 0; k < knowingtruth.size(); k++) {
          if (find(cur) == find(knowingtruth[k])) {
            //cout << i << "\n";
            saytruth = true;
            break;
          }
        }
      }
    }
    if (saytruth)
      answer--;
  }
  cout << answer << "\n";
}
