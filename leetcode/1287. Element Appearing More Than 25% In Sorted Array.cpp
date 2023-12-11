class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>counter;
        for(auto i:arr){
            counter[i]++;
        }
        for(auto i:counter){
            if(i.second>=(arr.size()*0.25))return i.first;
        }
        return 0;
    }
};
