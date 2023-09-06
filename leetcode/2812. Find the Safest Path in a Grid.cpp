class Solution {
public:
    int dy[4]={0,-1,0,1};
    int dx[4]={1,0,-1,0};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return 0;
        int colcount=grid[0].size();
        vector<vector<int>>table(colcount,vector<int>(colcount));
        vector<vector<bool>>makevisited(colcount,vector<bool>(colcount));
        queue<pair<int,int>>qq;

        for(int i=0;i<colcount;i++){
            for(int j=0;j<colcount;j++){
                if(grid[i][j]==1){
                    makevisited[i][j]=true;
                    qq.push({i,j});
                }
            }
        }
        int step=0;
        while(!qq.empty()){
            int size=qq.size();
            while(size--){
                auto ttmp=qq.front();qq.pop();
                int curi=ttmp.first,curj=ttmp.second;
                table[curi][curj]=step;
                for(int dir=0;dir<4;dir++){
                    int newi=curi+dy[dir],newj=curj+dx[dir];
                    if(newi>=0&&newj>=0&&newi<colcount&&newj<colcount&&!makevisited[newi][newj]){
                        makevisited[newi][newj]=true;
                        qq.push({newi,newj});
                    }
                }
            }
            step++;
        }
        for(auto i:table){
            for(auto j:i){
                cout<<j<<" ";
            }cout<<"\n";
        }
        vector<vector<bool>>visited(colcount,vector<bool>(colcount));
        int answer=INT_MAX;
        priority_queue<pair<int,pair<int,int>>>pq;
        visited[0][0]=true;
        pq.push({table[0][0],{0,0}});
        while(!pq.empty()){
            auto ttmp=pq.top();pq.pop();
            int tmpval=ttmp.first,curi=ttmp.second.first,curj=ttmp.second.second;
            answer=min(answer,table[curi][curj]);
            if(curi==colcount-1&&curj==colcount-1)return answer;
            for(int dir=0;dir<4;dir++){
                int newi=curi+dy[dir],newj=curj+dx[dir];
                if(newi>=0&&newj>=0&&newi<colcount&&newj<colcount&&!visited[newi][newj]){
                    visited[newi][newj]=true;
                    pq.push({table[newi][newj],{newi,newj}});
                }
            }
        }
        return answer;
    }
};
/*
thanks to
https://leetcode.com/problems/find-the-safest-path-in-a-grid/solutions/3871112/why-and-how-of-the-solution-picture-explanation/
*/
