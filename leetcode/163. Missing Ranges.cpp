class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>answer;
       if(nums.size()==0)
       {
           answer.push_back(vector<int>{lower,upper});
           return answer;
       }
       if(lower<nums[0])
       {
           answer.push_back(vector<int>{lower,nums[0]-1});
       }
       for(int i=0;i<nums.size()-1;i++)
       {
           if(nums[i+1]-nums[i]<=1)continue;
           answer.push_back(vector<int>{nums[i]+1,nums[i+1]-1});
       }
       if(upper>nums[nums.size()-1])
       {
           answer.push_back(vector<int>{nums[nums.size()-1]+1,upper});
       }

       return answer;
    }
};
