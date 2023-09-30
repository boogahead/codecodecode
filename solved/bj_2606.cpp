#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>>connection(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }
    vector<bool>visited(n+1);
    visited[1]=true;
    queue<int>qq;
    qq.push(1);
    int count=0;
    while(!qq.empty()){
        int tmp=qq.front();qq.pop();
        for(auto i:connection[tmp]){
            if(visited[i])continue;
            visited[i]=true;
            count++;
            qq.push(i);
        }
    }
    cout<<count<<"\n";
}
