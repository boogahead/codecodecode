class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>table(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(table[i]==-1)
            {
                stack<int>stck;
                stck.push(i);
                table[i]=0;
                while(!stck.empty())
                {
                    int tmp=stck.top();stck.pop();
                    for(auto j:graph[tmp])
                    {
                        if(table[j]==-1){
                            stck.push(j);
                            table[j]=table[tmp]^1;
                        }
                        else if(table[j]==table[tmp])return false;
                    }
                }
            }
        }        
        return true;
    }
};
