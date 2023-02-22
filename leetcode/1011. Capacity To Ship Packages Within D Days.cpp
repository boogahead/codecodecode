class Solution {
public:
    bool possible(vector<int>& weights,int mid, int days)
    {
        int daysneeded=1, curweight=0;
        for(auto i:weights)
        {
            curweight+=i;
            if(curweight>mid)
            {
                daysneeded++;
                curweight=i;
            }
        }
        return daysneeded<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxload=-1;
        int totalload=0;
        for(auto i:weights)
        {
            totalload+=i;
            maxload=max(maxload,i);
        }
        int l=maxload, r=totalload;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(possible(weights,mid,days))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
