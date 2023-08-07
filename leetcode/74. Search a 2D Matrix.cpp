class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=matrix.size()-1;i>=0;i--){
            if(target>=matrix[i][0]){
                int idx;
                if(find(matrix[i].begin(),matrix[i].end(),target)==matrix[i].end()){return false;}
                return true;
            }
        }
        return false;
    }
};
