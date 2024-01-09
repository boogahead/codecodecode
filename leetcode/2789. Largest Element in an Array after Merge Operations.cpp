class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long answer=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<=answer)answer+=nums[i];
            else answer=nums[i];
        }
        return answer;
    }
};
/*
how do you come up with this
*/
