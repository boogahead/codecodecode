#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int blue = 0, white = 0;
bool recursion(int curi, int curj, int size, vector<vector<int>> &table,
               bool mode) {
  if (size == 1) {
    if (mode && table[curi][curj] == 1)
      return true;
    if (!mode && table[curi][curj] == 0)
      return true;
    return false;
  }
  bool q1, q2, q3, q4;
   //cout<<curi<<" "<<curj<<" "<<size<<"\n";
  q1 = recursion(curi, curj, size / 2, table, mode);
  q2 = recursion(curi, curj + size / 2, size / 2, table, mode);
  q3 = recursion(curi + size / 2, curj, size / 2, table, mode);
  q4 = recursion(curi + size / 2, curj + size / 2, size / 2, table, mode);
  if (q1 && q2 && q3 && q4)
    return true;
  else {
    if (mode) {
      if (q1)
        blue++;
      if (q2)
        blue++;
      if (q3)
        blue++;
      if (q4)
        blue++;
    } else if(!mode){

      if (q1)
        white++;
      if (q2)
        white++;
      if (q3)
        white++;
      if (q4)
        white++;
    }
    return false;
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> table(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> table[i][j];
    }
  }
  if(recursion(0, 0, n, table, true))blue++;
  if(recursion(0, 0, n, table, false))white++;
  cout << white << "\n" << blue << "\n";
}
