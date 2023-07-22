class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto i:asteroids)
        {
            if(st.empty()){st.push(i);continue;}
            int top=st.top();
            int flag=1;
            while(top>0&&i<0)
            {
                if(abs(top)<abs(i))
                {
                    st.pop();
                    if(st.empty()){break;}
                    top=st.top();continue;
                }
                else if(abs(top)==abs(i)){st.pop();}
                flag=0;break;
            }
            if(flag)st.push(i);
        }
        vector<int>answer(st.size());
        for(int i=st.size()-1;i>=0;i--)
        {
            answer[i]=st.top();st.pop();
        }
        return answer;
    }
};
