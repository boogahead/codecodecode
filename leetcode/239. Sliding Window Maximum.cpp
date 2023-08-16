class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;//stores the index
        vector<int>answer;
        int count=0;
        for(auto i:nums){
            if(dq.front()==count-k){dq.pop_front();}
            while(!dq.empty()&&i>nums[dq.back()])dq.pop_back();
            dq.push_back(count++);
            if(count>=k)answer.push_back(nums[dq.front()]);
        }
        return answer;
    }
};
