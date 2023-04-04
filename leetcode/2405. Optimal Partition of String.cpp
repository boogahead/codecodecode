class Solution {
public:
    int partitionString(string s) {
        bool character[26]={false};
        int answer=1;
        for(auto i :s)
        {
            if(!character[i-'a'])//
            {
                character[i-'a']=true;
            }
            else
            {
                for(int i=0;i<26;i++)character[i]=false;
                character[i-'a']=true;
                answer++;
            }
        }
        return answer;
    }
};
