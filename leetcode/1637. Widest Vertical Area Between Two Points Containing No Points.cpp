class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        for(auto i:points){
            cout<<i[0]<<" "<<i[1]<<"\n";
        }
        int answer=0;
        for(int i=0;i<points.size()-1;i++){
            answer=max(answer,abs(points[i][0]-points[i+1][0]));
        }
        return answer;
    }
};
