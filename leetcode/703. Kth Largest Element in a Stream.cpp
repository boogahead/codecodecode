class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>yes;
    int kk;
    //int kkth;
    KthLargest(int k, vector<int>& nums) {
        kk=k;
        for(auto i:nums)add(i);
    }
    
    int add(int val) {
        if(yes.size()<kk)yes.push(val);
        else
        {
            if(val>yes.top())
            {
                yes.pop();yes.push(val);
            }
        }
        return yes.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
