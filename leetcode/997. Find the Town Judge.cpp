class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> list(n+1);
        for(int i=0;i<trust.size();i++)
        {
            list[trust[i][0]].push_back(trust[i][1]);
        }
        int candidate=-1;
        for(int i=1;i<list.size();i++)
        {
            //if(list[i].size()){return i;}
            if(list[i].size()==0&&candidate==-1){candidate=i;continue;}
            if(list[i].size()==0&&candidate!=-1)return -1;
            //cout<<i<<" : "<<list[i].size()<<"\n";
        }
        
        for(int j=1;j<list.size()&&j!=candidate;j++)
        {
            if(find(list[j].begin(),list[j].end(),candidate)==list[j].end()){return -1;}
        }
        return candidate;
        //return -1;
    }
};
