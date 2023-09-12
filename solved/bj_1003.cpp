#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef pair<int,int>info;
vector<info>memo(41);
info fibonacci(int n) {
    if(memo[n].first>0||memo[n].second>0){
        //cout<<n<<"\n";
        return memo[n];
    }
    else {
        info tmp1=fibonacci(n-1);
        info tmp2=fibonacci(n-2);
        info returner;
        returner.first=tmp1.first+tmp2.first;
        returner.second=tmp2.second+tmp1.second;
        memo[n]=returner;
        //cout<<n<<" : "<<returner.first<<" "<<returner.second<<"\n";
        return returner;
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    vector<int>table(t);
    memo[0].first=1;memo[0].second=0;
    memo[1].first=0;memo[1].second=1;
    for(int i=0;i<t;i++){
        cin>>table[i];
    }
    fibonacci(40);
    for(int i=0;i<t;i++){
        cout<<memo[table[i]].first<<" "<<memo[table[i]].second<<"\n";
    }
}
