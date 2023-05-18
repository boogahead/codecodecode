class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>table(n);
        vector<int>answer;
        for(auto i:edges)
        {
            table[i[1]]=true;
        }
        for(int i=0;i<n;i++)
        {
            if(!table[i])answer.push_back(i);
        }
        return answer;
    }
};
