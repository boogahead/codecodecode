#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <climits>
#include <deque>
#include <stack>


using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    for(int testcase=0;testcase<tc;testcase++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>minleft(26);
        for(int i=0;i<26;i++){
            minleft[i]=i+1;
        }
        int cnt=0;
        for(auto i:s){
            minleft[i-'A']--;
        }
        for(auto i:minleft){
            if(i<=0)cnt++;
        }
        cout<<cnt<<"\n";
    }
    
}
