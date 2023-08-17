class Solution {
public:
    int isize,jsize;
    vector<vector<int>> answer;
   
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        isize=mat.size();jsize=mat[0].size();
        answer.resize(mat.size(),vector<int>(mat[0].size()));
        for(int i=0;i<isize;i++){
            for(int j=0;j<jsize;j++){
                answer[i][j]=mat[i][j];
            }
        }
        for(int i=0;i<isize;i++){
            for(int j=0;j<jsize;j++){
                if(answer[i][j]==0)continue;
                int minneighbor=isize*jsize;
                if(i>0){//considering OOB
                    minneighbor=min(minneighbor,answer[i-1][j]);
                }
                if(j>0){v
                    minneighbor=min(minneighbor,answer[i][j-1]);
                }
                answer[i][j]=minneighbor+1;
            }
        }//go from 0 0 to isize jsize

        //now traverse in a reverse manner from isize jsize to 0 0
        for(int i=isize-1;i>=0;i--){
            for(int j=jsize-1;j>=0;j--){
                if(answer[i][j]==0)continue;
                int minneighbor=isize*jsize;
                if(i<isize-1){//considering OOB
                    minneighbor=min(minneighbor,answer[i+1][j]);
                }
                if(j<jsize-1){//considering OOB
                    minneighbor=min(minneighbor,answer[i][j+1]);
                }
                answer[i][j]=min(answer[i][j],minneighbor+1);//compare with the original traversal
            }
        }

        return answer;
    }
};
