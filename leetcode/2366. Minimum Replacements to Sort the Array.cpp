class Solution {
public:
  /*
  need to go backwards since going from - to nums.size() might force us to traverse the previous indices again
  */
    long long minimumReplacement(vector<int>& nums) {
        long long count=0;
        int leftmostvalue=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<=leftmostvalue){
                leftmostvalue=nums[i];
                continue;
            }
            if(nums[i]>leftmostvalue){
                /*
                e.g. if nums[i]=10 and leftmostvalue is 3,
                instead of dividing into 1 3 3 3,
                the optimal way is to divide into 2 2 3 3
                since we can have a larger margin of numbers to use
                after this
                */
                int tmpcounter=nums[i]/leftmostvalue;
                if(nums[i]%leftmostvalue)tmpcounter++;
                leftmostvalue=nums[i]/tmpcounter;
                count+=tmpcounter-1;
            }
        }
        return count;
    }
};
