class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>table(s.length(),vector<int>(s.length()));
        //table [ from ] [ to ]
        for(int i=n-1;i>=0;i--){
            table[i][i]=1; //substring consisting only of one character - i to i = 1
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    table[i][j]=table[i+1][j-1]+2;
                    // if the first and last characters of substring same, we add 2 ( two characters s[i] and s[j] to the palindromic length of substing i+1 to j-1 )
                }
                else
                {
                    table[i][j] = max( table[i+1][j] , table[i][j-1]);
                    // if first and last characters are not the same, we set the longest substing of table [ i ] [ j ] as 
                    // instances when either one of them are missing - 
                    // therefore table [ i + 1 ] [j ] (not considering s[i])
                    // or table [ i ] [ j - 1 ] ( not considering s[j] )
                }
            }
        }
        return table[0][n-1]; // substring length possible from 0 to n-1 
    }
};
