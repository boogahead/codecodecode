class Solution {
public:
    vector<long long>table;
    long long dfs(vector<vector<int>>&questions,int i)
    {
        if(i>=questions.size())return 0;
        if(table[i]!=0)return table[i];
        long long points=questions[i][0];
        long long skip=questions[i][1];
        table[i]=max(dfs(questions,i+1),points+dfs(questions,i+skip+1));
        //dfs(questions,i+1) -- skipping
        //points+dfs(questions,i+skip+1) -- solving and skipping few questions
        return table[i];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        table.resize(n);
        return dfs(questions,0);
    }
};
