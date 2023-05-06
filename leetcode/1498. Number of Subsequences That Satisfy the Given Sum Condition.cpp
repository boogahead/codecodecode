class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int modder=1000000007;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>powah(n);
        powah[0]=1;
        for(int i=1;i<n;i++)
        {
            powah[i]=(powah[i-1]*2)%modder;
        }
        long long answer=0;
        int left=0,right=n-1;
        while(left<=right)
        {
            if(nums[left]+nums[right]<=target)
            {
                answer+=powah[right-left];
                answer%=modder;
                left++;
            }
            else{
                right--;
            }
        }
        return answer;
    }
};
