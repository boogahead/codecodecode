#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};

typedef pair<int,int>info;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    vector<int>answer(t);
    for(int tc=0;tc<t;tc++){
        int m,n,k;
        cin>>m>>n>>k;
        vector<vector<int>>table(n,vector<int>(m));
        vector<vector<bool>>visited(n,vector<bool>(m));
        for(int gg=0;gg<k;gg++){
            int j,i;
            cin>>j>>i;
            table[i][j]=1;
        }
        int counter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(table[i][j]==1&&!visited[i][j]){
                    counter++;
                    visited[i][j]=true;
                    queue<info>qq;
                    qq.push({i,j});
                    while(!qq.empty()){
                        info tmp=qq.front();qq.pop();
                        int curi=tmp.first,curj=tmp.second;
                        for(int dir=0;dir<4;dir++){
                            int newi=curi+dy[dir],newj=curj+dx[dir];
                            if(newi<0||newi>=n||newj<0||newj>=m)continue;
                            if(visited[newi][newj])continue;
                            if(table[newi][newj]==0)continue;
                            visited[newi][newj]=true;
                            qq.push({newi,newj});
                        }
                    }
                }
            }
        }
        answer[tc]=counter;
    }
    for(auto i:answer){
        cout<<i<<"\n";
    }
}
