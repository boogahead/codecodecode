class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<vector<bool>>table;
        int answer=0;
        for(int i=0;i<bank.size();i++){
            vector<bool>tmp;
            bool exist=false;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1')exist=true;
                tmp.push_back(bank[i][j]=='1'?1:0);
            }
            if(!exist)continue;
            table.push_back(tmp);
        }
        int counter=0;
        int prev=0;
        for(auto i:table){
            for(auto j:i){if(j)counter++;}
            answer+=(counter*prev);
            prev=counter;counter=0;
        }
        return answer;
    }
};
