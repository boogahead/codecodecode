class Solution {
public:
    vector<vector<int>> answer;
    void recursion(vector<int>&cur,vector<bool>&visited,int cnt,int limit,vector<int>&nums){
        if(cnt==limit){
            answer.push_back(cur);
        }
        for(int i=0;i<limit;i++){
            if(!visited[i]){
                visited[i]=true;
                cur.push_back(nums[i]);
                recursion(cur,visited,cnt+1,limit,nums);
                cur.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>visited(nums.size(),false);
        vector<int>table;
        recursion(table,visited,0,nums.size(),nums);
        return answer;
    }
};
