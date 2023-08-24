class Solution {
public:
    int dy[4]={0,-1,0,1};
    int dx[4]={1,0,-1,0};
    /*
    intuition : pick out the points with the lowest height, fill them up when up against the wall thats right next to them, and turn them into a wall of the same length after calculation
    */
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        int ilen=heightMap.size(),jlen=heightMap[0].size();
        vector<vector<bool>>visited(ilen,vector<bool>(jlen));
        for(int i=0;i<ilen;i++){
            for(int j=0;j<jlen;j++){
                if(i==0||i==ilen-1||j==0||j==jlen-1){
                    visited[i][j]=true;
                    pq.push({heightMap[i][j],i,j});
                }
            }
        }
        int answer=0;
        while(pq.size()){
            int val=pq.top()[0];
            int tmpi=pq.top()[1];
            int tmpj=pq.top()[2];
            pq.pop();
            for(int dir=0;dir<4;dir++){
                int newi=tmpi+dy[dir],newj=tmpj+dx[dir];
                if(newi>=0&&newj>=0&&newi<ilen&&newj<jlen&&!visited[newi][newj]){
                    visited[newi][newj]=true;
                    answer+=max(0,val-heightMap[newi][newj]);
                    pq.push({max(val,heightMap[newi][newj]),newi,newj});
                }
            }
        }
        return answer;
    }
};
