class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int size=costs.size();
        int price=0;
        int cnt=0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<size;i++)
        {
            if(coins>=price+costs[i])
            {
                //coins-=costs[i];
                price+=costs[i];
                cnt++;
                continue;
            }
            return cnt;
        }
        return cnt;
    }
};
