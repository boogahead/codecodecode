class Solution {
public:
    bool checker(char i)
    {
        if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int end=k-1;
        int start=0;
        int answer=-1;
        int cur=0;
        for(int i=0;i<=end;i++)
        {
            if(checker(s[i]))cur++;
        }
        answer=max(answer,cur);
        end++;start++;
        while(end<s.length())
        {
            if(checker(s[start-1]))cur--;
            if(checker(s[end]))cur++;
            answer=max(answer,cur);
            end++;start++;
        }
        answer=max(answer,cur);
        return answer;
    }
};
