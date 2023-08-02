class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        if(m==1&&n==1)return 1;
        vector<vector<int>>table(m,vector<int>(n,0));
        int i;
        for(i=1;i<m;i++){
            if(obstacleGrid[i][0]==1)break;
            table[i][0]=1;
        }
        for(int i=1;i<n;i++){
            //cout<<"hi\n";
            if(obstacleGrid[0][i]==1)break;
            table[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                //cout<<"etestse\n";
                if(obstacleGrid[i][j]==1)continue;
                table[i][j]=table[i-1][j]+table[i][j-1];
            }
        }
        return table[m-1][n-1];
    }
};
