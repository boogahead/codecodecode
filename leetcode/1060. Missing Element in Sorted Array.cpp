class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int cur=0;
        for(int i=0;i<nums.size()-1;i++){
            cur=nums[i];
            if(nums[i+1]-nums[i]>k)return nums[i]+k;
            k-=(nums[i+1]-nums[i]-1);
        }
        return nums[nums.size()-1]+k;
       // return answer;
    }
};
