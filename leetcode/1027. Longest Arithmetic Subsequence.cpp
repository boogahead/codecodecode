class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>>table(nums.size(),vector<int>(1001,1));
        int answer=1;
        for(int right=1;right<nums.size();right++)
        {
            for(int left=0;left<right;left++)
            {
                int idx=nums[right]-nums[left]+500;
                // ^ maximum difference negativewise is -500, so change it to 0 for indexing purposes
                table[right][idx]=max(table[right][idx],table[left][idx]+1);
                /* 
                    "idx" is the difference counters that occured up to index "left".
                    adding 1 to table[left][idx] will show how many occurence of difference of "idx" between elements in
                    array have occured up to that point. 
                */
                answer=max(answer,table[right][idx]);
            }
        }
        return answer;
    }
};
