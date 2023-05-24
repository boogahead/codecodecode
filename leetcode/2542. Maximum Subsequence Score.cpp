class Solution {
public:
    typedef pair<int,int>info; //number,idx
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<info>yes; // nums2 nums1 stored respectively
        for(int i=0;i<nums1.size();i++)
        {
            yes.push_back({nums2[i],nums1[i]});
        }
        sort(yes.rbegin(),yes.rend());
        priority_queue<int,vector<int>,greater<int>>qq;
        long long ans=0,sum=0;
        for(int i=0;i<k;i++)
        {
            //cout<<yes[i].second<<"\n";
            sum+=yes[i].second;
            qq.push(yes[i].second);
        }
        ans=sum*yes[k-1].first;
        //cout<<"ans "<<ans<<"\n";
        for(int i=k;i<nums1.size();i++)
        {
            //cout<<yes[i].second<<"\n";
            //cout<<"top "<<qq.top()<<"\n";
            sum=sum+yes[i].second-qq.top();
            qq.pop();
            ans=max(ans,sum*yes[i].first);
            qq.push(yes[i].second);
            //qq.push(-yes[i].second);
        }
        return ans;
    }
};
