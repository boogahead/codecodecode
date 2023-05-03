class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>numone,numtwo; //present in num1 and num2
        bool numonetable[2002]={false},numtwotable[2002]={false};
        vector<vector<int>>answer(2); 
        for(auto i:nums1)
        {
            numone.insert({i,true});
        }
        for(auto i:nums2)
        {
            if(numone.find(i)==numone.end()&&!numtwotable[i+1000])
            {
                answer[1].push_back(i);
                numtwotable[i+1000]=true;
            }
            numtwo.insert({i,true});
        }
        for(auto i:nums1)
        {
            if(numtwo.find(i)==numone.end()&&!numonetable[i+1000])
            {
                answer[0].push_back(i);
                numonetable[i+1000]=true;
            }
        }
        return answer;
    }
};
