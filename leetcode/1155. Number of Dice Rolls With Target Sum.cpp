class Solution {
public:
    long long modulo=1e9+7;
    long long answer=0;
    int recursion(vector<vector<int>>&dp,int cur,int n,int k,int sum,int target){
        //if all n dices used, check if sum equlals taget
        if(cur==n){
            return sum==target;
        }

        //if we already know the answer return
        if(dp[cur][sum]!=-1)return dp[cur][sum];


        int count=0;
        //iterate over all the face values of the dice - up until target-sum
        for(int i=1;i<=min(k,target-sum);i++){
            count=(count+recursion(dp,cur+1,n,k,sum+i,target))%modulo;
        }
        return dp[cur][sum]=count;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return recursion(dp,0,n,k,0,target);
    }
};
