class Solution {
public:
    vector<vector<int>>memo;
    int MOD=1e9+7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    int dp(int remain,int cur){
        if(remain==0)return 1;
        if(memo[remain][cur]!=0)return memo[remain][cur];
        int answer=0;
        for(auto i:jumps[cur]){
            answer=(answer+dp(remain-1,i))%MOD;
        }
        memo[remain][cur]=answer;
        return answer;
    }
    int knightDialer(int n) {
        memo.resize(n+1,vector<int>(10,0));
        int answer=0;
        for(int start=0;start<10;start++){
            answer=(answer+dp(n-1,start))%MOD;
        }
        return answer;
    }
};
