class Solution {
public:
    int dp[101][1001];
    int solve(vector<int>&piles,int ind,int m)
    {
        if(ind>=piles.size())return 0;
        if(dp[ind][m]!=-1)return dp[ind][m];
        int sum=0;
        if(ind+2*m>=piles.size()) 
        {
            /*
            if the player is possible to take all the remaining stones without violating rules then the        
            player will take everything without any hesitation
            */
            for(int i=ind;i<piles.size();i++)
            {
                sum+=piles[i];
            }
            return dp[ind][m]=sum;
        }
        int value=-99999;
        for(int i=1;i<=m*2;i++)
        {
            sum+=piles[ind+i-1];
            value=max(value,sum-solve(piles,ind+i,max(m,i)));
        }
        /*
        value=max(value,sum-solve(piles,ind+i,max(m,i)));
        sum = current profit
        solve(piles,ind+i,max(m,i)) -> maximum profit of the opponent
        when the difference (value) becomes maximum, thats the answer
        */
        return dp[ind][m]=value;
    }
    int stoneGameII(vector<int>& piles) {
        int m=1;
        memset(dp,-1,sizeof(dp));
        int value=solve(piles,0,m);
        int totstone=0;
        for(int i=0;i<piles.size();i++)
        {
            totstone+=piles[i];
        }
        /*
        thought process:
        totstone = alice + bob     -(1)
        value = alice - bob        -(2)
        add (1) and (2) 
        totstone+value = 2 * alice
        */
        return (totstone+value)/2;
    }
};
