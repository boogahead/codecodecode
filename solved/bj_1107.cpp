#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
int minval;
int target;


vector<bool>used(11);

bool check(int n){
  string s=to_string(n);
  for(int i=0;i<s.size();i++){
    if(used[s[i]-'0'])return false;
  }
  return true;
}
int main(void) {
  ios::sync_with_stdio(false);
  vector<bool> usage(10);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin>>n;
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int tmp;
    cin>>tmp;
    used[tmp]=true;
  }
  int answer=abs(n-100);
  for(int i=0;i<1000000;i++){
    if(check(i)){
      int ttmp=abs(n-i)+to_string(i).size();
      answer=min(ttmp,answer);
    }
  }
  cout<<answer;
}
