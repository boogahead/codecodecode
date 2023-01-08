/*dont erase things to consider when solving this problem
use unordered map for hash
consider all points. let there be a point p1 and calculate the slope to all the other points. 
If the slope is of the same value, they must be on the same line (since there cant be ax+b and ax+c existing at the same time)
add them all to the 
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int i,j,k;
        int size=points.size();
        //slope = (y2-y1)/(x2-x1)
        //3rd point = (y3-y1)/(x3-x1)
        //(y2-y1)*(x3-x1)==(y3-y1)*(x2-x1)
        if(size==1)return 1;
        int maxcnt=0;
        for(i=0;i<size-1;i++)
        {
            for(j=i+1;j<size;j++)
            {
                int count=2;
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                for(k=0;k<size&&k!=i&&k!=j;k++)
                {
                    int x3=points[k][0];
                    int y3=points[k][1];
                    if((y2-y1)*(x3-x1)==(y3-y1)*(x2-x1))
                    {
                        count++;
                    }
                }
                maxcnt=max(count,maxcnt);
            }
        }
        return maxcnt;
    }
};
