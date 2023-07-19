bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
}
class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int from,to;
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        from=intervals[0][0];to=intervals[0][1];
        if(intervals.size()==1)return 0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=to)
            {
                to=intervals[i][1];
                
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};
