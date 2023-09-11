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
    vector<vector<int>>answer;
    for(int tc=0;tc<t;tc++){
        int n;
        cin>>n;
        vector<int>output(n);
        priority_queue<pair<int,int>>inputs;
        int tmp;
        for(int i=0;i<n;i++){
            cin>>tmp;
            inputs.push({tmp,i});
        }
        int counter=1;
        while(!inputs.empty()){
            pair<int,int>tmp=inputs.top();
            inputs.pop();
            output[tmp.second]=counter++;
        }
        //cout<<"hi\n";
        /*for(auto i:output){
            cout<<i<<" ";
        }cout<<"\n";*/
        answer.push_back(output);
    }
    for(auto i:answer){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<"\n";
    }
}
