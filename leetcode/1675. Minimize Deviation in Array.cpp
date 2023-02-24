/*
makes use of priority_queue 
*/
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int answer=INT_MAX;
        priority_queue<int> pq;
        int minimum=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2)
            {
                pq.push(nums[i]*2);
                minimum=min(minimum,nums[i]*2);
                continue;
            }
            pq.push(nums[i]);
            minimum=min(minimum,nums[i]);
        }
        while(!pq.empty())
        {x
            int cur=pq.top();pq.pop();
            answer=min(answer,cur-minimum);
            if(cur%2==0)
            {
                pq.push(cur/2);
                minimum=min(minimum,cur/2);
            }
            else{break;}
        }
        return answer;
    }
};
