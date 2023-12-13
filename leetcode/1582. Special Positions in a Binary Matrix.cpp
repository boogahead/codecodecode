class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int answer=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]){
                    bool flag=false;
                    for(int curi=i+1;curi<mat.size();curi++){
                        if(mat[curi][j]){
                            flag=true;break;
                        }
                    }
                    for(int curi=i-1;curi>=0;curi--){
                        if(mat[curi][j]){
                            flag=true;break;
                        }
                    }
                    for(int curj=j+1;curj<mat[0].size();curj++){
                        if(mat[i][curj]){
                            flag=true;break;
                        }
                    }
                    for(int curj=j-1;curj>=0;curj--){
                        if(mat[i][curj]){
                            flag=true;break;
                        }
                    }
                    if(!flag)answer++;
                }
            }
        }
        return answer;
    }
};
