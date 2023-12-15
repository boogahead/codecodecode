class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>info;//name,id
        int id=0;
        for(auto i:paths){
            for(auto j:i){
                if(info.find(j)==info.end()){
                    info.insert({j,id++});
                }
            }
        }
        vector<vector<bool>>road(info.size(),vector<bool>(info.size()));
        for(auto i:paths){
            road[info[i[0]]][info[i[1]]]=true;
        }
        for(int i=0;i<road.size();i++){
            int cnt=0;
            for(int j=0;j<road[i].size();j++){
                if(road[i][j])cnt++;
            }
            if(cnt==0){
                for(auto c:info){
                    if(c.second==i)return c.first;
                }
            }
        }
        return "";
    }
};
