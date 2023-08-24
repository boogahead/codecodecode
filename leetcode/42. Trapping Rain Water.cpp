class Solution {
public:
    int dx[2]={-1,1};
    int trap(vector<int>& height) {
        int length=height.size();
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
        vector<bool>visited(length);
        pq.push({height[0],0});
        visited[0]=true;
        pq.push({height[length-1],length-1});
        visited[length-1]=true;
        int answer=0;
        while(pq.size()){
            int val=pq.top()[0];
            int idx=pq.top()[1];
            pq.pop();
            for(int i=0;i<2;i++){
                int newidx=idx+dx[i];
                if(newidx>=0&&newidx<length&&!visited[newidx]){
                    visited[newidx]=true;
                    answer+=max(0,val-height[newidx]);
                    pq.push({max(val,height[newidx]),newidx});
                }
            }
        }
        return answer;
    }
};
