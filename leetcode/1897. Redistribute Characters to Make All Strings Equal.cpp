class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>info;
        for(auto i:words){
            for(auto j:i){
                info[j]++;
            }
        }
        for(auto i:info){
            if(i.second%words.size()!=0)return false;
        }
        return true;
    }
};
