class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string res;
        for(int i=0;i<path.length();i++)
        {
          string tmp;
          if(path[i]=='/')continue;
          while(i<path.length()&&path[i]!='/')
          {
            tmp+=path[i];
            i++;
          }
          if(tmp==".")continue;
          if(tmp==".."){
            if(!st.empty())st.pop();
          }
          else
          {
            st.push(tmp);
          }
        }
        while(!st.empty())
        {
          res='/'+st.top()+res;st.pop();
        }
        if(res.length()==0)return "/";
        return res;
    }
};
