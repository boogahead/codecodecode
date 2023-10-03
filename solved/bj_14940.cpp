#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int,int,int>info;//i j distance
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int starti,startj;
    vector<vector<int>>table(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>table[i][j];
            if(table[i][j]==2){
                starti=i;startj=j;
            }
        }
    }
    vector<vector<int>>distance(n,vector<int>(m));
    vector<vector<bool>>visited(n,vector<bool>(m));
    queue<info>qq;
    qq.push({starti,startj,0});
    visited[starti][startj]=true;
    while(!qq.empty()){
        int tmpi,tmpj,tmpdistance;
        tie(tmpi,tmpj,tmpdistance)=qq.front();qq.pop();
        for(int dir=0;dir<4;dir++){
            int newi=tmpi+dy[dir],newj=tmpj+dx[dir];
            if(newi<0||newi>=n||newj<0||newj>=m)continue;
            if(table[newi][newj]==0)continue;
            if(visited[newi][newj])continue;
            visited[newi][newj]=true;
            distance[newi][newj]=tmpdistance+1;
            qq.push({newi,newj,tmpdistance+1});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(table[i][j]==1&&!visited[i][j])distance[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<distance[i][j]<<" ";
        }cout<<"\n";
    }
}
