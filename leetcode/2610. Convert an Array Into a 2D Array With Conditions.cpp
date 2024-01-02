class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<bool>used(nums.size());
        vector<vector<int>>answer;
        int counter=0;
        int row=0;
        int n=nums.size();
        while(counter<nums.size()){
            set<int>checker;
            vector<int>tmp;
            for(int i=0;i<n;i++){
                if(used[i])continue;
                if(checker.find(nums[i])==checker.end()){
                    checker.insert(nums[i]);
                    used[i]=true;
                    tmp.push_back(nums[i]);
                    counter++;
                }
            }
            answer.push_back(tmp);
        }
        return answer;
    }
};
