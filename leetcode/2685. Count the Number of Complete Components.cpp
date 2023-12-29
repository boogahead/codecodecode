class Solution {
public:
    vector<bool>visited;
    vector<vector<int>>connected;
    int node=1;
    int line=0;
    void recursion(int cur){
        for(auto i:connected[cur]){
            if(visited[i])continue;
            visited[i]=true;
            node++;
            line+=connected[i].size();
            recursion(i);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        connected.resize(n);
        for(auto i:edges){
            connected[i[0]].push_back(i[1]);
            connected[i[1]].push_back(i[0]);
        }
        int answer=0;
        visited.resize(n);
        for(int i=0;i<n;i++){
            if(visited[i])continue;
            visited[i]=true;
            line+=connected[i].size();
            recursion(i);
            //cout<<i<<" "<<line<<" "<<node<<"\n";
            if(node*(node-1)==line){answer++;}
            node=1;
            line=0;
        }
        return answer;
    }
};

/*
complete graph: ( ( # of edges ) * (# of edges-1) )/2 = # of lines between nodes
but since we added both ways into the connected graph,
skipped dividing by 2

*/
