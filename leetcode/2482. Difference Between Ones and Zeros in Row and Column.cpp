class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int>row,column;
        for(int i=0;i<grid.size();i++){
            int count=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j])count++;
                else count--;
            }
            row.push_back(count);
        }
        for(int i=0;i<grid[0].size();i++){
            int count=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i])count++;
                else count--;
            }
            column.push_back(count);
        }
        vector<vector<int>>answer(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<answer.size();i++){
            for(int j=0;j<answer[0].size();j++){
                answer[i][j]=row[i]+column[j];
            }
        }
        return answer;
    }
};
