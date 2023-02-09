/*think smart
*/
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>table[26];
        long long answer=0;
        for(auto idea:ideas)
        {
            table[idea[0]-'a'].insert(idea.substr(1));
        }
        for(int i=0;i<25;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                int nummutual=0;
                for(auto& idea : table[i])
                {
                    if(table[j].count(idea))
                    {
                        nummutual++;
                    }
                }
                answer+= (2* ((table[i].size()-nummutual)*(table[j].size()-nummutual)));
            }
        }
        return answer;
    }
};
