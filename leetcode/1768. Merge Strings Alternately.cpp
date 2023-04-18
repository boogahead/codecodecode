class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer;int i;
        for(i=0;i<min(word1.length(),word2.length());i++)
        {
            answer+=word1[i];
            answer+=word2[i];
        }
        if(word1.length()>word2.length())
        {
            for(int j=i;j<word1.length();j++)answer+=word1[j];
        }
        else if(word2.length()>word1.length())
        {
            for(int j=i;j<word2.length();j++)answer+=word2[j];
        }
        return answer;
    }
};
