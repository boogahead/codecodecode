class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>table(matrix.size(),vector<int>(matrix[0].size()));
        int maxsize=0;
        for(int i=0;i<matrix.size();i++)
        {
            table[i][0]=matrix[i][0]-'0';
        }
        for(int j=0;j<matrix[0].size();j++){
            table[0][j]=matrix[0][j]-'0';
        }
        for(auto i:matrix){
            for(auto j:i){
                if(j=='1')maxsize=1;
            }
        }
        if(matrix.size()==1||matrix[0].size()==1)return maxsize;
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    table[i][j]=min(min(table[i-1][j],table[i][j-1]),table[i-1][j-1])+1;
                    maxsize=max(table[i][j],maxsize);
                }
            }
        }
        return maxsize*maxsize;
    }
};
/*
DP
should point out how many consecutive ones are on the left - up side of the current square

*/
