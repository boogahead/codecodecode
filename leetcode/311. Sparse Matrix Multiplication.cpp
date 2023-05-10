class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<vector<int>>answer(mat1.size(),vector<int>(mat2[0].size()));
        for(int i=0;i<mat1.size();i++)
        {
            for(int j=0;j<mat1[0].size();j++)
            {
                if(mat1[i][j]!=0){
                    for(int k=0;k<mat2[0].size();k++)
                    {
                        answer[i][k]+=(mat1[i][j]*mat2[j][k]);
                    }
                }
            }
        }
        return answer;
    }
};
