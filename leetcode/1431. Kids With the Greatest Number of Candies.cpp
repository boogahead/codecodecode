class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=-1;
        for(auto i:candies)
        {
            maxi=max(maxi,i);
        }
        vector<bool>answer;
        for(auto i:candies)
        {
            if(i+extraCandies>=maxi)
            {
                answer.push_back(true);continue;
            }
            answer.push_back(false);
        }
        return answer;
    }
};
