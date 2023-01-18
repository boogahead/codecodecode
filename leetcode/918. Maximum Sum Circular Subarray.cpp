/*
kadane's algorithm - a fast way to find the maximum sum value of subarray.
but this algo only works in non-circular array.
So here, we will find the maximum one using normal kadane's algo (and find the minimum subarray sum on the way as well)
and after we find the maximum sum, we check if we are correct by subtracting totalsum with the minimum subarray sum
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int totsum=0,maxsum=INT_MIN,minsum=INT_MAX,curmin=0,curmax=0;
       for(auto i:nums)
       {
           curmax=max(i,curmax+i);
           maxsum=max(maxsum,curmax);
           curmin=min(i,curmin+i);
           minsum=min(minsum,curmin);
           totsum+=i;
       }
       if(maxsum>0)return max(maxsum,totsum-minsum);//if maxsum is over 0, it will have to beat the case when minsum is a negative value, thus pumping totsum's value up.
       return maxsum;
    }
};
