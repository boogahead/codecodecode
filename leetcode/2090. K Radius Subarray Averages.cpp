class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>answer(nums.size(),-1);
        cout<<nums.size()<<"\n";
        if(2*k+1>nums.size())
        {
            return answer;
        }
        long long start=0;
        for(int i=0;i<=2*k;i++)
        {
            start+=nums[i];
        }
        //cout<<start<<"\n";
        for(int i=0;i<nums.size();i++)
        {
            //cout<<nums[i]<<"\n";
            if(i-k<0||i+k>=nums.size())
            {
                continue;
            }
            if(i==k)
            {
                answer[i]=(start/(k*2+1));continue;
            }
            start-=nums[i-k-1];
            start+=nums[i+k];
            //cout<<start<<"\n";
            answer[i]=(start/(k*2+1));
        }
        return answer;
    }
};
