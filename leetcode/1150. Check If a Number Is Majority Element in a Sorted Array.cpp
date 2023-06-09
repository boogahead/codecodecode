class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unordered_map<int,int>table;
        for(auto i:nums)
        {
            if(table.find(i)==table.end())
            {
                table.insert({i,1});continue;
            }
            table[i]++;
        }
        if(table[target]>nums.size()/2)return true;
        return false;
    }
};
