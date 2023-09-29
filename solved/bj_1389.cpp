#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <climits>
#include <queue>
#include <stack>


using namespace std;
int answercount=INT_MAX;
int answer=0;
typedef pair<int,int>info;
void bfs(int n,vector<bool>&alreadyknow,vector<vector<int>>&table){
    queue<info>qq;
    int bacon=0;
    qq.push({n,0});
    while(!qq.empty()){
        auto cur=qq.front();qq.pop();
        for(auto i:table[cur.first]){
            if(alreadyknow[i])continue;
            alreadyknow[i]=true;
            bacon+=cur.second+1;
            qq.push({i,cur.second+1});
        }
    }
    if(answercount>bacon){
        answercount=bacon;
        answer=n;
    }
} 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N,M;
    cin>>N>>M;
    vector<vector<int>>table(N+1);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        table[a].push_back(b);
        table[b].push_back(a);
    }
    for(int i=1;i<=N;i++){
        vector<bool>alreadyknow(N+1);
        alreadyknow[i]=true;
        bfs(i,alreadyknow,table);
    }
    cout<<answer;
}
