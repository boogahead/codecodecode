class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return 1;
        sort(nums.begin(),nums.end());
        int answer=0;
        int cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<2)
            {
                //cout<<nums[i]<<"\n";
                if(nums[i]!=nums[i-1]){
                    cnt++;
                }
            }
            else
            {
                answer=max(answer,cnt);cnt=1;
            }
        }
        answer=max(answer,cnt);
        return answer;
    }
};
