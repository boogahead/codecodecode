class Solution {
public:
    void dfs(int node,vector<int>& edges,vector<int>& dist,vector<bool>& visited)
    {
        visited[node]=true;
        int neighbor=edges[node];
        if(neighbor!=-1&&visited[neighbor]==false)
        {
            dist[neighbor]=dist[node]+1;
            dfs(neighbor,edges,dist,visited);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n,0),dist2(n,0);
        vector<bool>visited1(n,false),visited2(n,false);
        dfs(node1,edges,dist1,visited1);
        dfs(node2,edges,dist2,visited2);
        int maxdist=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(visited1[i]&&visited2[i]&& maxdist>max(dist1[i],dist2[i]))
            {
                maxdist=max(dist1[i],dist2[i]);
                ans=i;
            }
        }return ans;
    }
};
