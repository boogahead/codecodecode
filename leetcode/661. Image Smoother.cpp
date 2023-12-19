class Solution {
public:
    int dy[9]={-1,-1,-1,0,0,0,1,1,1};
    int dx[9]={-1,0,1,-1,0,1,-1,0,1};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int ilimit=img.size(),jlimit=img[0].size();
        vector<vector<int>>answer(ilimit,vector<int>(jlimit));
        for(int i=0;i<ilimit;i++){
            for(int j=0;j<jlimit;j++){
                int count=0,sum=0;
                for(int dir=0;dir<9;dir++){
                    int tmpi=i+dy[dir],tmpj=j+dx[dir];
                    if(tmpi<0||tmpj<0||tmpi>=ilimit||tmpj>=jlimit)continue;
                    count++;
                    sum+=img[tmpi][tmpj];
                }
                answer[i][j]=floor((double)sum/(double)count);
            }
        }
        return answer;
    }
};
