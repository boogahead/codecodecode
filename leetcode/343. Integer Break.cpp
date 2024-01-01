class Solution {
public:
    int answer=0;
    vector<int>memo;
    int dp(int n){
        if(n<=3)return n;
        /*
        left with 3- possible ways to split this up or leave it :  1+2 / 1+1+1 / 3
        3 is better than the other two
        we just return 3 since its the biggest number
        */
        if(memo[n]!=0)return memo[n]; // we already have the value in store so return
        int answer=0;
        for(int i=2;i<n;i++)answer=max(answer,i*dp(n-i)); 
        /*
        trying to fill up memo 
        */
        memo[n]=answer;
        return answer;
    }
    int integerBreak(int n) {
        if(n<=3)return n-1;
        memo.resize(n+1);
        return dp(n);
    }
};
