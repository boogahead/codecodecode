class Solution {
public:
    double timereq(vector<int>&dist,int speed)
    {
        double time=0.0;
        for(int i=0;i<dist.size();i++)
        {
            double t= (double)dist[i]/(double)speed;
            time+=(i==dist.size()-1 ? t : ceil(t) );
        }
        //cout<<time<<"\n";
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left=1,right=1e7;
        int mid;
        int minspeed=-1;
        while(left<=right)
        {
            mid=(right+left)/2;
            //cout<<timereq(dist,mid)<<"\n";
            if(timereq(dist,mid)<=hour)
            {
                minspeed=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return minspeed;
    }
};
