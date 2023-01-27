/*need a dry run for this
DP reachability problem
*/
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       unordered_set<string> table(words.begin(),words.end());
       vector<string>answer;
       for(string&word : words)
       {
           int length=word.length();
           vector<bool>dp(length+1);
           dp[0]=true;
           for(int i=0;i<=length;i++)
           {
               for(int j=(i==length? 1:0);!dp[i]&&j<i;j++)
               {
                   dp[i]=dp[j]&&table.count(word.substr(j,i-j));
               }
           }
           if(dp[length])answer.push_back(word);
       }
       return answer;
    }
};
