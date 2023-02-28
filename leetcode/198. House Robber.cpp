class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> table(nums.size(),0);
        table[0]=nums[0];
        if(nums.size()==1)return table[0];
        table[1]=nums[1];
        if(nums.size()==2)return max(table[0],table[1]);
        for(int i=2;i<nums.size();i++)
        {
            table[i]=max(table[i-2]+nums[i],table[i-1]+nums[i]-nums[i-1]);
            //cout<<table[i]<<"\n";
        }
        return max(table[nums.size()-1],table[nums.size()-2]);
    }
};
