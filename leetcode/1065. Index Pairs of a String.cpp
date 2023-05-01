class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>>answer;
        unordered_set<string>table;
        int maxlen=-1;
        for(auto i:words)
        {
            table.insert(i);
            maxlen=max(maxlen,(int)i.length());
        }
        for(auto i:table)cout<<i<<"\n";
        int curmax;
        for(int i=0;i<text.length();i++)
        {
            for(int j=0;j<=maxlen&&(i+j<=text.length());j++)
            {
                if(table.find(text.substr(i,j))!=table.end())
                {
                    vector<int>tmp;
                    tmp.push_back(i);tmp.push_back(i+j-1);answer.push_back(tmp);
                }
            }
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};
