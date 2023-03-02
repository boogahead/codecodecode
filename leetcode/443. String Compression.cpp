class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> answerchar;
        unordered_map<char,int>table;
        int answer=0;
        for(int i=0;i<chars.size();i++)
        {
            table[chars[i]]++;
            if(i>0&& chars[i]!=chars[i-1])
            {
                answerchar.push_back(chars[i-1]);
                if(table[chars[i-1]]==1){table[chars[i-1]]=0;continue;}
                string tmp=to_string(table[chars[i-1]]);
                for(auto g:tmp)
                {
                    answerchar.push_back(g);
                }
                table[chars[i-1]]=0;
            }
        }
        for(auto i:table)
            {
                if(i.second>0)
                {
                    //cout<<i.first<<"\n";
                    answerchar.push_back(i.first);
                    if(i.second==1)break;
                    string tmp=to_string(i.second);
                    for(auto g:tmp)
                    {
                        answerchar.push_back(g);
                    }
                }
            }
        chars=answerchar;
        return answerchar.size();
    }
};
