class Solution {
public:
    vector<vector<int>>answer;
    void recur(int cnt,vector<int>&cur,int n,int k,int lastvalused){
        if(cnt==k){
            answer.push_back(cur);
        }
        for(int i=lastvalused+1;i<=n;i++){
            cur.push_back(i);
            recur(cnt+1,cur,n,k,i);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>table;
        if(n==k){
            for(int i=1;i<=n;i++){
                table.push_back(i);
            }answer.push_back(table);
            return answer;   
        }
        recur(0,table,n,k,0);
        return answer;
    }
};
/*
we dont need to check whether we have added the number
since we go through all occurences of a newewst inserted number,
we can go through + depth of recursion and start the for loop from THAT number

*/
