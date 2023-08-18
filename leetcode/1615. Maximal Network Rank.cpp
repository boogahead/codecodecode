class Solution {
public:
    int answer=0;
    void recursion(int idx,int count,vector<int>tmp,vector<vector<int>>& table,int n){
        if(count==2){
            int one=tmp[0],two=tmp[1];
            int count=0;
            bool connect=false;
            for(auto i:table[one]){
                if(i==two){
                    connect=true;break;
                }
            }
            
            count=(table[one].size()+table[two].size());
            if(connect)count--;
            if(answer<count){
                answer=count;
                //cout<<one<<" "<<two<<" count"<<count<<"\n";
            }
            return;
        }
        for(int i=idx+1;i<n;i++){
            tmp.push_back(i);
            recursion(i,count+1,tmp,table,n);
            tmp.pop_back();
        }
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>table(n);
        for(auto i:roads){
            table[i[0]].push_back(i[1]);
            table[i[1]].push_back(i[0]);
        }
        /*for(auto i:table){
            for(auto j:i){
                cout<<j<<" ";
            }cout<<"\n";
        }*/
        vector<int>tmp;
        recursion(-1,0,tmp,table,n);
        return answer;
    }
};
