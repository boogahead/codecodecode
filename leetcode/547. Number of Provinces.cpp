class Solution {
public:
    vector<int>table,ranker;
    int finder(int a)
    {
        if(table[a]==a)return a;
        return table[a]=finder(table[a]);
    }
    void unify(int a,int b)
    {
        
        a=finder(a);b=finder(b);
        if(a==b)return;
        if(ranker[a]>ranker[b])swap(a,b);
        table[a]=b;
        if(ranker[a]==ranker[b])ranker[b]++;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        table.resize(isConnected.size()+1);
        ranker.resize(isConnected.size()+1,0);
        for(int i=0;i<=isConnected.size();i++)
        {
            table[i]=i;
        }
        int answer=isConnected.size();
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j]==1&&finder(i+1)!=finder(j+1))
                {
                    answer--;
                    unify(i+1,j+1);
                }
            }
        }
        return answer;
    }
};
