class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)return 0;
        int answer=0;
        int mini=INT_MAX;
        int maxi=-1;
        for(auto i: prices)
        {
            mini=min(mini,i);
            //maxi=max(maxi,i);
            answer=max(i-mini,answer);
        }
        return answer;
    }
};
