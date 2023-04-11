class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto i:s)
        {
            if(i!='*')
            {
                st.push(i);
            }
            else
            {
                st.pop();
            }
        }
        string answer;
        answer.resize(st.size());
        for(int i=st.size()-1;i>=0;i--)
        {
            answer[i]=st.top();st.pop();
        }
        return answer;
    }
};
