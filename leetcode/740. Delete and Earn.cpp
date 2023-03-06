class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>table(10002);
        for(int i=0;i<nums.size();i++)
        {
            table[nums[i]]+=nums[i];
        }
        vector<int>dp(10002);
        dp[1]=table[1];
        dp[2]=max(table[1],table[2]);
        for(int i=3;i<10002;i++)
        {
            dp[i]=max(dp[i-2]+table[i],dp[i-1]);
        }
        return(max(dp[10000],dp[9999]));
    }
};
