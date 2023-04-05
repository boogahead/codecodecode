class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long answer=0,prefix=0;
        for(int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];
            answer=max(answer,(prefix+i)/(i+1));
            /*  ^ ceiling. e.g. ceiling(5+3) =2 SAME AS (5+3-1)/3 = 2
                so prefixsum + (prefix + 1) -1 / (i + 1) -> (prefixsum + i) / (i+1)
            */
        }
        return answer;
    }
};
