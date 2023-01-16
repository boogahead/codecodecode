class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int size=intervals.size(),i=0;
        while(i<size&&newInterval[0]>intervals[i][1])
        {//처음에 문제 없을때 막 넣기
            ans.push_back(intervals[i]);
            i++;
        }       
        while(i<size&&newInterval[1]>=intervals[i][0])
        {//만약 겹치는 구간 생기면, 겹치는 구간 커버하는 구간 한개 생성(계속 비교하면서 다음에 넣을 newInterval 수정)
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<size)
        {//마무리
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
