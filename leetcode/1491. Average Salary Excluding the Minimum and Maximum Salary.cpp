class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0;
        long mini=INT_MAX;
        long maxi=-1;
        for(auto i:salary)
        {
            sum+=i;
            if(i<mini)mini=i;
            if(i>maxi)maxi=i;
        }
        sum=(sum-mini-maxi)/(salary.size()-2);
        return sum;
    }
};
