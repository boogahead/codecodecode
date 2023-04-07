class Solution {
public:
    typedef pair<int,int> info;//i j
    int dy[4]={0,-1,0,1};
    int dx[4]={1,0,-1,0};
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n));
        int answer=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&!visited[i][j])
                {
                    visited[i][j]=true;
                    queue<info>qq;
                    qq.push({i,j});
                    bool enclosed=true;
                    int count=1;int y,x;
                    while(!qq.empty())
                    {
                        tie(y,x)=qq.front();qq.pop();
                        for(int dir=0;dir<4;dir++)
                        {
                            int ny=y+dy[dir],nx=x+dx[dir];
                            if(ny<0||ny>=m||nx<0||nx>=n)
                            {
                                enclosed=false;continue;
                            }
                            if(grid[ny][nx]==1&&!visited[ny][nx])
                            {
                                count++;
                                visited[ny][nx]=true;
                                qq.push({ny,nx});
                            }
                        }
                    }
                    if(enclosed)answer+=count;
                }
            }
        }
        return answer;
    }
};
