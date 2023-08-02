class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>table=triangle;
        if(triangle.size()==1)return triangle[0][0];
        for(auto i:table){
            for(auto j:i){
                j=0;
            }
        }
        table[0][0]=triangle[0][0];
        for(int i=1;i<table.size();i++){
            for(int j=0;j<table[i].size();j++){
                if(j+1>=table[i].size()){
                    table[i][j]=table[i-1][j-1]+triangle[i][j];
                    continue;
                }
                if(j-1<0){
                    table[i][j]=table[i-1][j]+triangle[i][j];continue;
                }
                table[i][j]=min(table[i-1][j-1],table[i-1][j])+triangle[i][j];
            }
        }
        int answer=INT_MAX;
        for(auto i:table[table.size()-1]){
            if(i<answer)answer=i;
        }
        return answer;
    }
};
