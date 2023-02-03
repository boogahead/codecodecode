class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int answer=0;
        for(auto i:nums)
        {
            string tmp=to_string(i);
            if(to_string(i).length()%2==0)answer++;
            //cout<<numofeven<<"\n";
            //if(numofeven%2)answer++;
        }
        return answer;
    }
};
