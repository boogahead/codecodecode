#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int>mindp(3);
  vector<int>maxdp(3);
  vector<int>input(3);
  cin>>input[0]>>input[1]>>input[2];
  for(int i=0;i<3;i++){
    maxdp[i]=input[i];
    mindp[i]=input[i];
  }
  for(int i=1;i<n;i++){
    cin>>input[0]>>input[1]>>input[2];
    int maxtmp_0=maxdp[0],maxtmp_2=maxdp[2],mindp_0=mindp[0],mindp_2=mindp[2];
    maxdp[0]=input[0]+max(maxdp[0],maxdp[1]);
    maxdp[2]=input[2]+max(maxdp[2],maxdp[1]);
    maxdp[1]=input[1]+max(maxtmp_0,max(maxtmp_2,maxdp[1]));
    mindp[0]=input[0]+min(mindp_0,mindp[1]);
    
    mindp[2]=input[2]+min(mindp_2,mindp[1]);
    mindp[1]=input[1]+min(mindp_0,min(mindp_2,mindp[1]));
  }
  int maxans=0,minans=INT_MAX;
  for(int i=0;i<3;i++){
    maxans=max(maxans,maxdp[i]);
    minans=min(minans,mindp[i]);
  }
  cout<<max(maxdp[0],max(maxdp[1],maxdp[2]))<<" "<<min(mindp[0],min(mindp[1],mindp[2]));
  //cout<<maxans<<" "<<minans;
}
