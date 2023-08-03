class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if(matrix.size()==1)return matrix[0][0];
        vector<vector<int>>table(matrix.size(),vector<int>(matrix.size(),0));
        for(int i=0;i<matrix.size();i++){
            table[0][i]=matrix[0][i];
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(j-1<0){
                    table[i][j]=min(table[i-1][j],table[i-1][j+1])+matrix[i][j];continue;
                }
                if(j+1>=matrix.size()){
                    table[i][j]=min(table[i-1][j],table[i-1][j-1])+matrix[i][j];continue;
                }
                table[i][j]=min(min(table[i-1][j-1],table[i-1][j]),table[i-1][j+1])+matrix[i][j];
            }
        }
        int answer=INT_MAX;
        for(auto i:table[table.size()-1]){
            if(answer>i)answer=i;
        }
        return answer;
    }
};
