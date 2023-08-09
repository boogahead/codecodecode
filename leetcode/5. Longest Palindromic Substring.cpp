class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>>table(s.length(),vector<bool>(s.length()));
        vector<int>ans(2);
        ans[0]=0;ans[1]=0;
        int n=s.length();
        for(int i=0;i<n;i++){//one character comparisons -always true
            table[i][i]=true;
            ans[0]=i;ans[1]=i;
        }
        for(int i=0;i<n-1;i++){//two character cases
            if(s[i]==s[i+1]){//compare if the character right next to it is equal
                cout<<i<<"\n";
                table[i][i+1]=true;
                ans[0]=i;ans[1]=i+1;//update answer range
                cout<<ans[0]<<" "<<ans[1]<<"\n";
            }
        }
        for(int diff=2;diff<n;diff++){//iterate through all possible size of palindrome
            for(int i=0;i<n-diff;i++){
                int j=i+diff;
                if((s[i]==s[j])&&table[i+1][j-1]){
                    //checks if s[i] and s[j] - the outermost characters of the substring we are checking is equal 
                    // AND
                    // if substring between i and j - table[i+1][j-1] is a palindrome
                    //if both are true, we have a new larger palindrome set
                    table[i][j]=true;
                    ans[0]=i;ans[1]=j;//since the palindromes size grows every loop, update answers each time 
                }
            }
        }
        string answer;
        for(int i=ans[0];i<=ans[1];i++){
            answer+=s[i];
        }return answer;
        //return ans[0]+" "+ans[1];
    }
};
