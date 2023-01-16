/*BFS 가 아니라 Union-Find로 풀것*/
class Solution {
public:
int table[200001];
    int find(int a)
    {
        if(table[a]==a)return a;
        return table[a]=find(table[a]);
    }
    void uni(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x!=y)
        {
            table[max(x,y)]=min(x,y);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int i,j;
        for(i=0;i<=n;i++)
        {
            table[i]=i;
        }
        int size=edges.size();
        for(i=0;i<size;i++)
        {
            uni(edges[i][0],edges[i][1]);
        }
        if(find(source)!=find(destination))
        {
            return false;
        }
        return true;
    }
};
