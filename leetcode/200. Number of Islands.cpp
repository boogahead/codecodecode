class Solution {
public:
    int dy[4]={0,-1,0,1};
    int dx[4]={1,0,-1,0};
    typedef pair<int,int>info;
    int numIslands(vector<vector<char>>& grid) {
        int answer=0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    answer++;
                    queue<info>qq;
                    qq.push({i,j});
                    visited[i][j]=true;
                    while(!qq.empty()){
                        info ttmp=qq.front();qq.pop();
                        int curi=ttmp.first,curj=ttmp.second;
                        for(int dir=0;dir<4;dir++){
                            int newi=curi+dy[dir],newj=curj+dx[dir];
                            if(newi<0||newi>=grid.size()||newj<0||newj>=grid[0].size())continue;
                            if(grid[newi][newj]=='0')continue;
                            if(visited[newi][newj])continue;
                            visited[newi][newj]=true;
                            qq.push({newi,newj});
                        }
                    }
                }
            }
        }
        return answer;
    }
};
