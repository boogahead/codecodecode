class Solution {
public:
    int dy[4]={0,-1,0,1};
    int dx[4]={1,0,-1,0};
    typedef pair<int,int>info; //y x
    int closedIsland(vector<vector<int>>& grid) {
        int gridi=grid.size();
        int gridj=grid[0].size();
        vector<vector<bool>>visited(gridi,vector<bool>(gridj,false));
        int count=0;
        for(int i=0;i<gridi;i++)
        {
            for(int j=0;j<gridj;j++)
            {
                if(!visited[i][j]&&grid[i][j]==0)
                {
                    bool closed=true;
                    queue<info>qq;
                    qq.push({i,j});
                    int y,x;
                    //cout<<"DDD "<<i<<" wefajew "<<j<<"\n";
                    while(!qq.empty())
                    {
                        tie(y,x)=qq.front();qq.pop();int ny,nx;
                        visited[y][x]=true;
                        for(int dir=0;dir<4;dir++)
                        {
                            ny=y+dy[dir];nx=x+dx[dir];
                            if(ny<0||ny>=gridi||nx<0||nx>=gridj)
                            {
                                closed=false;continue;
                            }
                            if(grid[ny][nx]==0&&!visited[ny][nx]){
                                visited[ny][nx]=true;
                                //cout<<ny<<nx<<"\n";
                                qq.push({ny,nx});
                            }
                        }
                    }
                    if(closed)count++;
                }
            }
        }
        return count;
    }
};
