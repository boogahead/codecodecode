class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int>st;
        int j=0;
        for(auto i:pushed)
        {
            st.push(i);
            while(!st.empty()&&j<n&&st.top()==popped[j])//pop stack while it spews out the same way popped is set up
            {
                st.pop();
                j++;
            }
        }
        return j==n;
    }
};
/*
greedy stack
*/
