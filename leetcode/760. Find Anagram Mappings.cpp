class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>table(100002);
        for(int i=0;i<nums1.size();i++)
        {
            table[nums1[i]].push_back(i);
            //cout<<i<<" "<<nums1[i]<<"\n";
        }
        vector<int>answer(nums1.size());
        for(int i=0;i<nums2.size();i++)
        {
            int j=nums2[i];
            int ithidxinnum=table[j].back();table[j].pop_back();
            answer[ithidxinnum]=i;
        }
        return answer;
    }
};
