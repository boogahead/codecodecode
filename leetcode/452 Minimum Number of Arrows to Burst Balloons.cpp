class Solution {
public:
    static bool comparerer( vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int size=points.size();
        sort(points.begin(),points.end(),comparerer);
        int idx=0;
        //set initial
        int count=0;
        int i;
        for(i=0;i<size;i++)
        {
            cout<<points[i][0]<<"\n";
        }
        while(idx<size)
        {
            //int shootat=points[idx][1];
            count++;
            i=idx+1;
            if(i>=size){break;}
            while(points[idx][1]>=points[i][0])
            {
                i++;
                if(i>=size){break;}
            }
            idx=i;
        }
        return count;
    }
};
