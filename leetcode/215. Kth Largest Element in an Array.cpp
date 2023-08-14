class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>> table;
        for(auto i:nums){
            if(table.size()<k){
                table.push(i);continue;
            }
            if(table.size()==k){
                if(table.top()<i){
                    table.pop();table.push(i);
                }
            }
        }
        return table.top();
    }
};
