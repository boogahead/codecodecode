class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int modd=1000000007;
        vector<int>table(high+1);        
        table[0]=1;
        for(int i=1;i<=high;i++)
        {
            if(i>=zero)
            {
                table[i]+=table[i-zero];
            }
            if(i>=one)
            {
                table[i]+=table[i-one];
            }
            table[i]%=modd;
        }
        int answer=0;
        for(int i=low;i<=high;i++)
        {
            answer+=table[i];answer%=modd;
        }return answer;
    }
};
