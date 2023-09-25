#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <tuple>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <sstream>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    vector<int>answer(t);
    for(int testcase=0;testcase<t;testcase++){
        int n;
        cin>>n;
        vector<int>table(n);
        for(int i=0;i<n;i++){
            cin>>table[i];
        }
        int curmin=1;
        for(int i=0;i<n;i++){
            if(curmin==table[i]){
                curmin++;
            }
            curmin++;
        }
        answer[testcase]=curmin-1;
    }
    for(auto i:answer)cout<<i<<"\n";
}
