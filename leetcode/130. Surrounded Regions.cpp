class Solution {
public:
    typedef pair<int,int>info; //i j
    int dy[4]={0,-1,0,1};
    int dx[4]={1,0,-1,0};
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j]&&board[i][j]=='O')
                {
                //cout<<"HI\n";
                    queue<info> qq;
                    vector<info>region;
                    visited[i][j]=true;
                    bool safe=false;
                    qq.push({i,j});
                    int y,x;
                    while(!qq.empty())
                    {
                        tie(y,x)=qq.front();qq.pop();
                        region.push_back({y,x});
                        for(int dir=0;dir<4;dir++)
                        {
                            int ny=y+dy[dir];
                            int nx=x+dx[dir];
                            if(ny<0||ny>=m||nx<0||nx>=n){safe=true;continue;}
                            if(board[ny][nx]=='O'&&!visited[ny][nx])
                            {
                                visited[ny][nx]=true;qq.push({ny,nx});
                            }
                        }
                    }
                    if(!safe)//if not safe
                    {
                        for(auto yes:region)
                        {
                            tie(y,x)=yes;
                        board[y][x]='X';
                        }   
                    }
                }
            }
        }
    }
};
