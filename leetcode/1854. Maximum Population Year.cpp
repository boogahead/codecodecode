class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int>info;
        for(auto i:logs){
            info[i[0]]++;info[i[1]]--;
        }
        int maxi=0;
        int ansyear;
        int count=0;
        for(auto i:info){
            count+=i.second;
            if(count>maxi){
                maxi=count;
                ansyear=i.first;
            }
        }
        return ansyear;
    }
};
