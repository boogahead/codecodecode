class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int answer=INT_MAX;
        int previdx=-1;
        for(int i=0;i<wordsDict.size();i++)
        {
            if(wordsDict[i]==word1||wordsDict[i]==word2){//if currently hovering on either word1 or word2
            if(previdx!=-1&&(wordsDict[previdx]!=wordsDict[i]||word1==word2))
            {//previdx!=-1 -> we already have recorded event of either word1/word2
             //wordsDict[previdx]!=wordsDict[i] -> previous word does not equal to current word
             // || word1==word2 -> or word1 is same as word2
                answer=min(answer,i-previdx);
            }
            previdx=i;
            }
        }
        return answer;
    }
};
